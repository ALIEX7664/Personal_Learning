let express = require('express')

//实例化服务器应用
let app = express();

//实现静态资源服务
app.use(express.static('static'))

//自定义接口
app.get('/api/list',(req,res)=>{
    //请求信息:req
    //响应信息:res
    res.json({
        state:'ok',
        list:[
            {usr:'A'},
            {usr:'B'},
            {usr:'C'}
        ]
    })
})

//监听端口
app.listen(3000,()=>{
    console.log('server on',"http://127.0.0.1:3000");
})



