const Base = require('../base.js');
//继承于Base
module.exports = class extends Base {
    __before() {
        //在获取信息前进行权限校验
        return this.checkAuth();
    }

    indexAction() {
        return this.json({ msg: 'userlist' });
    }

    // 获取列表接口
    async userlistAction() {
        //通过前端传参来进行切页
        let page = this.get('page') ? this.get('page') : 1;
        // model.page(page, pagesize)
        // * `page` {Number} 设置当前页数
        // * `pagesize` {Number} 每页条数，默认值为 `this.config.pagesize`
        let userlist = await this.model('member').order('id').page(page, 10).select();
        //获取总数
        let total = await this.model('member').count();
        this.json({ userlist, total, page });

    }

    // 删除接口
    async deluserAction() {
        let userid = this.get('id');
        await this.model('member').where({ id: userid }).delete();
        this.json({ msg: 'delete succeed' });
    }

    // 查找单条信息接口
    async userinfoAction() {
        // 连表查询，实现权限检查
        // 先通过userid找到member表里的用户信息
        // 再通过member的id找到auth_user_role中相匹配（二者相等）的user_id对应的那条数据，
        // 再由该数据找到auth_role中id与该数据role_id匹配的数据
        let userid = this.get('id');    // 获取get方式传输的id
        let user = await this.model('member').where({
            'cmswing_member.id': userid
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
        }).field('username, desc, password, mobile, email, role_id').find();
        this.json({ user });

        // find 方法：查询符合条件的第一条数据。
        // select 方法：查询符合条件的所有数据。
        // select()返回二维数组,find()返回一维数组。
    }

    async updateuserAction() {
        // 不加参数获取所有提交内容
        let postUser = this.get();
        console.log(postUser)
        // 判断用户是否修改密码
        if (this.method == 'POST' && postUser.password !== "") {
            //查找对应的id,加加密后的密码更新到数据库中
            await this.model('member').where({ id: postUser.id }).update(
                {
                    password: this.verifyPassword(postUser.password),
                    email: postUser.email,
                    mobile: postUser.mobile
                }
            );
        } else {
            // 查找对应的id,加加密后的密码更新到数据库中
            await this.model('member').where({ id: postUser.id }).update(
                {
                    email: postUser.email,
                    mobile: postUser.mobile
                }
            );
        }
        // 查找对应的角色id权限，只有部分角色在此表中
        let role = await this.model('auth_user_role').where({ user_id: postUser.id }).find();
        if (role.id) {
            // 找到则更新
            await this.model('auth_user_role').where({ user_id: postUser.id }).update({ role_id: postUser.role_id });
        } else {
            // 否则添加
            await this.model('auth_user_role').add({ user_id: postUser.id, role_id: postUser.role_id })
        }
        this.json({ msg: "更新成功" })
    }

    async adduserAction() {
        if (this.method == 'POST') {
            let postUser = this.get();
            let user =await this.model('member').where({username: postUser.username}).find();
            if(user.username){
                return this.json({msg: "添加失败，用户名已存在"})
            }else{
                //添加成员
                postUser.status = 1;
    
                if(postUser.password !== ""){
                    postUser.password = this.verifyPassword(postUser.password);
                }
                
                // 根据字段和对象匹配将结果添加到表中
                await this.model('member').add(postUser);

                
                //查找成员再添加到角色表中
                let user =await this.model('member').where({username: postUser.username}).find();
                await this.model('auth_user_role').add({ user_id: user.id, role_id: postUser.role_id });
                return this.json({msg: "添加成功"})
            }
           
        }
    }

    verifyPassword(password) {
        //cmswing 固定的加密格式，不能更改
        return think.md5(think.md5("www.cmswing.com") + think.md5(password) + think.md5("Arterli"));
    }

   
}