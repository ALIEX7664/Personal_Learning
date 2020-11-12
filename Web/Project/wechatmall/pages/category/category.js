// pages/category/category.js
const app = getApp()
let api = require('../../config/api')

Page({

  /**
   * 页面的初始数据
   */
  data: {
    height: app.globalData.height * 2 + 90,
    active: 1,
    items: [{
      text: '手机'
    }, {
      text: '平板'
    }, {
      text: '笔记本'
    }],
    list:[],
    plist:[],
    UrlPath:api.ApiRootUrl
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    let that = this;
    wx.request({
      url: api.GoodsList,
      success(res) {
        let productlist = res.data.productlist;
        productlist.forEach((item, i) => {
          // 解析完要存储返回值
          item.imgs = JSON.parse(item.imgs);
        })
        that.data.plist = productlist;
        that.setData({
          list: that.data.plist.slice(0,2)
        })
      }
    })
  },
  onClickNav(event){
    console.log(event.detail);
    let index = event.detail.index;
    this.setData({
      list :this.data.plist.slice(index*2,index*2+2)
    })
  },
  onChange(event) {
    console.log(event)
    this.setData({
      active: event.detail
    });
    // 页面切换
    switch (event.detail) {
      case 0:
        wx.navigateTo({
          url: '/pages/index/index'
        });
        break;
      case 1:
        console.log("to");
        wx.navigateTo({
          url: '/pages/category/category'
        });
        break;
      case 2:
        wx.navigateTo({
          url: '/pages/shopcart/shopcart'
        });
        break;
      case 3:
        wx.navigateTo({
          url: '/pages/mine/mine'
        });
        break;
    }
  },
  goBack(){
    wx.navigateBack({
    
    })
  },  
  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})