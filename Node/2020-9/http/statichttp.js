
var fs = require('fs')
var path = require('path')
var url = require('url')
var http = require('http')

//格式化参数路径，一般为文件夹路径
var argv = path.resolve(process.argv[2] ||'.')

//建立http服务器，发起请求(url变化)时执行函数
var server = http.createServer((req,res)=>{
    
    //解析url为文件路径
    var pathname = url.parse(req.url).pathname
    
    //拼接路径
    var filepath = path.join(argv,pathname)

    //获取文件状态
    fs.stat(filepath,(err,stat)=>{

        //判断文件是否存在
        if(!err && stat.isFile()){

            //req.url显示请求内容
            console.log('200' + req.url)

            //发送响应头,404表示失败
            res.writeHead(200)
            //创建读写流，将文件内容发送给浏览器
            fs.createReadStream(filepath).pipe(res)
        }else{
            // console.log('404' + req.url)

            //发送错误响应头
            res.writeHead(404)

            //发送错误信息给浏览器
            res.end('404 not found')
        }

        
    })
})

server.listen(8080)

console.log('http://127.0.0.1:8080/')