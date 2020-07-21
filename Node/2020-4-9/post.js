var http = require('http');
var querystring = require('querystring');

var postHTML =
    '<html><head><meta charset="utf-8"><title>菜鸟教程 Node.js 实例</title></head>' +
    '<body>' +
    '<form method="post">' +
    '网站名： <input name="name"><br>' +
    '网站 URL： <input name="url"><br>' +
    '<input type="submit">' +
    '</form>' +
    '</body></html>';

http.createServer(function (req, res) {
    var body = "";
    req.on('data', function (chunk) {
        body += chunk;
        console.log('chunk：'+chunk);
    });
    req.on('end', function () {
        console.log('请求结束');
        // 解析参数
        body = querystring.parse(body);
        // 设置响应头部信息及编码
        res.writeHead(200, {'Content-Type': 'text/html; charset=utf8'});

        if(body.name && body.url) { // 输出提交的数据,若有输入的话
            res.write("网站名：" + body.name);
            console.log(body.name);
            res.write("<br>");
            res.write("网站 URL：" + body.url);
            console.log(body.url);
        } else {  // 输出表单，无输入的时候，直接显示
            res.write(postHTML);
        }

        res.end();// 结束响应,再出发一次end,但这次不会执行if语句，因为已经被写入;postHTML输出的是已经写完的情况
        console.log('写入完毕');
    });
}).listen(3000);