//app.js
App({
  onLaunch: function () {
      wx:wx.getSystemInfo({
        // 在调用结束或不管成功失败都返回结果
        complete: (res) => {
          console.log(res);
          this.globalData.height = res.statusBarHeight;
        },
      })
      wx.getUserInfo({
        success:(res)=>{
         this.globalData.userInfo = res.userInfo
         console.log(res.userInfo)
        }
      })
  },
  // 全局共享数据，类似于Vue中的vuex中的state
  globalData: {
    userInfo: null,
    height:0,
    goodsCart:[]
  }
})