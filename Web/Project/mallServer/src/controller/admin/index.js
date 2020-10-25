const Base = require('../base.js');
//继承于Base
module.exports = class extends Base {
    __before() {
        //在获取信息前进行权限校验
        return this.checkAuth();
    }
    
    indexAction(){
        return this.dispay();
    }

    //获取用户信息,此时校验成功
    async userInfoAction() {

        let username = this.ctx.state.username;

        let user = await this.model('member').where({ username: username }).find();

        //返回用户信息，包括用户规则列表
        let userInfo = await this.model('member').where({
            'cmswing_member.username': username
        }).join({
            table: 'auth_user_role',
            join: 'left',   // '左连接方式,返回第一个表的匹配内容，即使当前表没有匹配on'
            as: 'l',    //给表取别名
            on: ['id', 'user_id'] // ['不加前缀即是第一个表的属性', '当前表的属性']

        }).join({
            table: 'auth_role',
            join: 'left',
            as: 'c',
            on: ['l.role_id', 'id']
        }).field('username, desc, password, mobile, email, role_id, rule_ids').find();

         let rulelist = await this.model('auth_rule').order('id').select();

        let filepath = think.ROOT_PATH + '/www/static/image/avatar/avatar' + user.id + '.png';
        console.log(user.id)
        //检测文件是否存在，不存放在数据库中
        if (think.isFile(filepath)) {
            //将路径赋给user
            userInfo.avatar = this.config('hostIpPort') + '/static/image/avatar/avatar' + user.id + '.png';
        } else {
            //赋给默认头像路径
            userInfo.avatar = this.config('hostIpPort') + '/static/image/avatar/avatar.png';
        }
        return this.json({ userinfo: userInfo ,rulelist});
    }
}