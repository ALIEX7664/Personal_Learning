// default config
module.exports = {
  workers: 1,
  jwt:{
    secret:'Aliex-password',
    cookie:'jwt-token',
    expire:3000 //口令有效时间
  },
  hostIpPort:"http://127.0.0.1:8360"
};
