const Base = require('../base.js');
//继承于Base
module.exports = class extends Base {
    __before() {
        //在获取信息前进行权限校验
        return this.checkAuth();
    }

    indexAction() {
        return this.dispay();
    }

    async rolelistAction() {
        //传回所有可用角色清单
        let page = this.get('page') ? this.get('page') : 1;
        let rolelist = await this.model('auth_role').order('id').page(page, 10).select();
        let total = await this.model('auth_role').count();
        return this.json({ rolelist, total })
    }

    async delroleAction() {
        let roleid = this.get('id');
        await this.model('auth_role').where({ id: roleid }).delete();
        return this.json({ msg: 'delete succeed' });
    }


    async addroleAction() {
        if (this.method == 'POST') {
            let postRole = this.get();
            postRole.status = 1;
            // 根据字段和对象匹配将结果添加到表中
            await this.model('auth_role').add(postRole);

            return this.json({ msg: '添加成功' });
        }

    }

    async editroleAction(){
        if(this.method == 'POST'){
            let postRole = this.get();
            
            postRole.status = 1;
            this.model('auth_role').where({id: postRole.id}).update({desc: postRole.desc, rule_ids: postRole.rule_ids})

            this.json({msg:"修改成功"})
        }
    }
}
