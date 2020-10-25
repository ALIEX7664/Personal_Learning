const jsonwebtoken = require('jsonwebtoken');

module.exports = class extends think.Controller {
  __before() {

  }

  // section --> cookie section本身不能跨域
  // JWT跨域身份验证方案 —— JSON WEB TOKEN
  // 1.用户发送用户名和密码
  // 2.验证用户名和密码，保存验证信息
  // 3.返回口令到前端
  // 4.前端将口令保存起来
  // 5.下次发送请求在把口令发给服务器 
  // 6.服务器可验证口令判断用户信息和登陆状态，以及口令有效时间
  // 7.更新口令

  // 所有的controller都继承于base,所以在base更新token
  authFail() {
    this.json({ err: 'jwt Varify Failed' });
    return false;
  }

  checkAuth() {
    let token = this.ctx.headers['x-token'];
    console.log('token',token)
    //config/config.js调用
    const { secret, cookie, expire } = this.config('jwt');

    try {
      var tokenObj = token ? jsonwebtoken.verify(token, secret) : {};
      this.ctx.state.username = tokenObj.name;
      console.log(tokenObj);

    } catch (err) {
      return this.authFail();
    }

    if (!tokenObj.name) {
      return this.authFail();
    }
    
    this.updateAuth(tokenObj.name);
  }

  //1. 在登陆时,会进行更新/生成(此时已经获取了用户信息)
  //2. 在检查token时,会进行更新
  updateAuth(userName){
    const userInfo = {
      name: userName
    }

    // 获取JWT配置信息
    const { secret, cookie, expire } = this.config('jwt');
    // 生成加密token
    // 使用config.js中的配置去生成jwt
    const token = jsonwebtoken.sign(userInfo,secret,{expiresIn: expire});

    this.cookie(cookie,token);
    // !!!
    this.header('authorization',token);

    return token;
  }
};
