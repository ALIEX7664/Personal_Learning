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

    async productlistAction() {
        //传回所有可用角色清单
        let page = this.get('page') ? this.get('page') : 1;
        let productlist = await this.model('product').order('id').page(page, 10).select();
        let total = await this.model('product').count();
        return this.json({ productlist, total })
    }

    async delproductAction() {
        let productid = this.get('id');
        await this.model('product').where({ id: productid }).delete();
        return this.json({ msg: 'delete succeed' });
    }


    async addproductAction() {
        if (this.method == 'POST') {
            let postproduct = this.get();
            console.log('Product:',postproduct)
            await this.model('product').add(postproduct);

            return this.json({ msg: '添加成功' });
        }

    }

    async editproductAction() {
        if (this.method == 'POST') {
            let postproduct = this.get();

            
            // 写法一
            // 解构数据postproduct再赋值
            // 直接赋值会导致修改temp时同时修改postproduct
            // 因为获取到的是postproduct对象‘

            let temproduct = {...postproduct};
            delete temproduct.id;

            // 写法二
            
            // postproduct.status = 1;
            // await this.model('product').where({ id: postproduct.id }).update( {
            //     title: postproduct.title ,
            //     imgs: postproduct.imgs,
            //     categoryid: postproduct.categoryid,
            //     price: postproduct.price,
            //     sku: postproduct.sku,
            //     content: postproduct.content
            // })

            await this.model('product').where({id: postproduct.id}).update(temproduct);


            this.json({ msg: "修改成功" })
        }
    }
}
