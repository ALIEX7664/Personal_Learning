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

    async rulelistAction() {
        //传回所有可用角色清单
        let page = this.get('page') ? this.get('page') : 1;
        let rulelist = await this.model('auth_rule').order('id').page(page, 10).select();
        let total = await this.model('auth_rule').count();
        return this.json({ rulelist, total })
    }

    async delruleAction() {
        let ruleid = this.get('id');
        await this.model('auth_rule').where({ id: ruleid }).delete();
        this.json({ msg: 'delete succeed' });
    }

    async addruleAction() {
        if (this.method == 'POST') {
            let postRule = this.get();
            console.log(postRule)
            let user = await this.model('auth_rule').where({ desc: postRule.desc }).find();
            if (user.desc) {
                return this.json({ msg: "添加失败，规则已存在" })
            } else {
                //修改状态
                postRule.status = postRule.status === "true" ? "1": "0";

                // 根据字段和对象匹配将结果添加到表中
                await this.model('auth_rule').add(postRule);
            }

        }
    }

    async editruleAction() {
        if (this.method == 'POST') {
            let postRule = this.get();
        
            postRule.status = postRule.status === "true" ? "1": "0";
            
            await this.model('auth_rule').where({ id: postRule.id }).update({ name: postRule.name, desc: postRule.desc, status: postRule.status });
            return this.json({ msg: "更新成功" })
        }
    }
}