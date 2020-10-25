const Base = require('../base.js');
//继承于Base
module.exports = class extends Base {
    indexAction() {
        return this.json({ msg: 'Login Page' });
    }

    // 异步 - 与数据库请求
    // this指向请求该函数的对象
    async loginAction() {
        // GET 会使账号密码显示在路径上
        if (this.method == 'POST') {
            //获取用户提交的用户名和密码
            let username = this.post('username');
            let password = this.post('password');
            //查询数据库,记得要同步查询，否则找不到
            let user = await this.model('member').where({ username: username }).find();
            console.log(user);
            //判断密码一致
            if (user.password === this.verifyPassword(password)) {
                //登录更新token
                const token = this.updateAuth(username);
                this.json({ state: 'Login Succeed',token: token });
            } else {
                return this.json({ state: 'Login Failed' });
            }
        }
    }

    // 密码加密,多次加密可使密码难以破解 —— 加密加盐
    verifyPassword(password) {
        //cmswing 固定的加密格式，不能更改
        return think.md5(think.md5("www.cmswing.com") + think.md5(password) + think.md5("Arterli"));
    }
};
