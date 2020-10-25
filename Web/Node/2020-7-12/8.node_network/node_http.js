let http = require('http')

//创建服务器实例
let server = http.createServer();

//服务器监听请求数据
server.on('request',(req,res)=>{
    console.log(req.url)

    //根据返回的url地址来判断当前在什么页面
    if(req.url == '/')
    {
        res.end('index')
    }else if(req.url == '/login'){
        res.end('login page')
    }else{
        res.end('404')
    }
    res.end('Hello World')
})

//设置监听端口号
server.listen(3000,()=>{
    console.log('server on:',"http://127.0.0.1:3000")
})