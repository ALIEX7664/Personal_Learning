const fs = require('fs');

function addMapping(router, mapping) {
    for (var url in mapping) {
        if (url.startsWith('GET ')) {         //get 处理
            var path = url.substring(4);
            router.get(path, mapping[url]); //以url作为mapping对象的key，执行key对应的函数调用，替换原来的(ctx,next)函数
            console.log(`register URL mapping: GET ${path}`);
        } else if (url.startsWith('POST ')) {        //post 处理
            var path = url.substring(5);
            router.post(path, mapping[url]);
            console.log(`register URL mappinh: POST ${path}`);
        } else {    
            console.log(`invalid URL: ${url}`)
        }
    }
}

function addConterllers(router,dir){
    //读取目录项
    var files = fs.readdirSync(__dirname + '/'+dir);

    //筛选.js结尾的文件
    var js_files = files.filter((file)=>{
        return file.endsWith('.js');
    })

    //请求目录中的每一个js文件
    js_files.forEach((val)=>{
        console.log(`Process controller: ${val}...`);
        //mapping作为对象存储多个函数调用
        let mapping = require(__dirname+'/controllers/'+val);
        addMapping(router,mapping);
    })
}


//此时没有输出名称，以文件名为作为输出调用名称，在被调用时执行函数的内容
module.exports=function(dir){
    let 
        controllers_dir = dir||'controllers',
        router = require('koa-router')();
    addConterllers(router,controllers_dir);
    return router.routes();
}