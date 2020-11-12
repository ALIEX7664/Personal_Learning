// pages/request/weather.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    temp:undefined
  },
  searchCity:function(e){
    let city = e.detail.value.city;
    // 拿取外部this指针
    let that = this;
    wx.request({
      url: 'https://free-api.heweather.net/s6/weather/now',
      data:{
        location:city,
        key:"7436b4c80234451e85b63c837f7cb2e1",
      },
      success(res){
          console.log(res)
          that.temp = res.data.HeWeather6[0].now.tmp;
          that.setData({
            temp:that.temp
          })
      }
    })
    
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

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