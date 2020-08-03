//导入子进程模块
const child_proc = require('child_process')

for (var i = 0; i < 3; i++) {
    //根据文件内容创建新进程
    var worker_proc = child_proc.exec('node child_proc.js ' + i , function(err,stdout,stderr){
        if(err){
            //执行失败报错
            console.log('err:',err)
        }else{
            //输出子进程缓冲区内容
            console.log('stdout:',stdout)
            //输出子进程错误
            console.log('stderr:',stderr)
        }
    })

    //监听退出状态，根据状态码判断是否正常
    worker_proc.on('exit',(code)=>{
        console.log('proc exit,code:'+code)
    })
}