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

    async categoryalllistAction(){
        let categorylist = await this.model('category').order('id').select();
        return this.json({categorylist});
    }

    async categorylistAction() {
        //传回所有可用角色清单
        let page = this.get('page') ? this.get('page') : 1;
        let categorylist = await this.model('category').order('id').page(page,10).select();
        let total = await this.model('category').count();
        return this.json({ categorylist, total })
    }

    async delcategoryAction() {
        let categoryid = this.get('id');
        await this.model('category').where({ id: categoryid }).delete();
        return this.json({ msg: 'delete succeed' });
    }


    async addcategoryAction() {
        if (this.method == 'POST') {
            let postCategory = this.get();
            postCategory.status = 1;
            postCategory.name = postCategory.title;
            // 根据字段和对象匹配将结果添加到表中
            await this.model('category').add(postCategory);

            return this.json({ msg: '添加成功' });
        }

    }

    async editcategoryAction() {
        if (this.method == 'POST') {
            let postCategory = this.get();

            postCategory.status = 1;
            this.model('category').where({ id: postCategory.id }).update({name: postCategory.title, title: postCategory.title })

            this.json({ msg: "修改成功" })
        }
    }
}
