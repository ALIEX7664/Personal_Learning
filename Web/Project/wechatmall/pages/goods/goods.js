// pages/goods/goods.js

const app = getApp()
let api = require('../../config/api')
Page({
  data: {
    // iphone6: 1px = 2rpx
    // 90rpx = 45px = 胶囊高度
    height: app.globalData.height * 2 + 90,
    swipers: ['swipper1', 'swipper2', 'swipper3'],
    active: 0,
    plist: [],
    UrlPath: api.ApiRootUrl,
    page: 1,
    goods:{},
    swipers:[],
    sku:{}
  },

  // 底部触发函数
  reachBottom(e) {
    this.page++;
    let that = this;
    wx.request({
      url: api.GoodsList,
      success(res) {
        let productlist = res.data.productlist;
        productlist.forEach((item, i) => {
          // 解析完要存储返回值
          item.imgs = JSON.parse(item.imgs);
        })
        // 拼接旧数据与新数据
        productlist = that.data.plist.concat(productlist);

        that.setData({
          plist: productlist
        })
      }
    })
  },
  onChange(event) {
    // event.detail 的值为当前选中项的索引
    console.log(event)
    this.setData({
      active: event.detail
    });

    // 页面切换
    switch (event.detail) {
      case 0:
        wx.navigateTo(
          {
            url: '/pages/index/index'
          });
        break;
      case 1:
        wx.navigateTo(
          {
           url: '/pages/category/category'
          });
        break;
      case 2:
        wx.navigateTo({
          url:'/pages/shopcart/shopcart'
        });
        break;
      case 3:
        wx.navigateTo({
          url:'/pages/mine/mine'
        });
        break;

    }
  },
  //事件处理函数
  bindViewTap: function () {
    wx.navigateTo({
      url: '../logs/logs'
    })
  },

  // 打开网页时触发
  onLoad: function (options) {
    console.log(options)
    let id = options.id;
    wx.request({
      url: api.Goods,
      data:{
        id
      },
      success:(res)=>{
        this.data.goods = res.data.goods;
        this.data.goods.content =  this.data.goods.content.replace(/\<img/g,'<img style="width:100%;height:auto;display:block;"');
        this.data.sku =JSON.parse(this.data.goods.sku);
        console.log('good',this.data.goods)
        this.setData({
          goods: this.data.goods,
          swipers: JSON.parse(this.data.goods.imgs),
          sku: this.data.sku
        })
        console.log(this.data.sku)
      }
    })


  },
  goBack(){
    wx.navigateBack({
    })
  },
  onClick(){
    let Exist = false;
    app.globalData.goodsCart.forEach((item,i)=>{
      if(item.id === this.data.goods.id){
        item.num = ++item.num;
        Exist= true;
      }
    })
    if(!Exist){
      this.data.goods.num = 1;
      app.globalData.goodsCart.push(this.data.goods);
    }
    wx.navigateTo({
      url: '/pages/shopcart/shopcart',
    })
  }
})