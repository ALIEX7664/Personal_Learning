//异步写入

let fs = require('fs')

fs.open('text2.html','w',(err,fd)=>{    //回调函数为写入
    fs.writeFile(fd,'Aliex',function(err){  //回调函数关闭文件
        if(!err)
        {
            console.log('succeed');
            fs.close(fd,()=>{
                console.log('close succeed')
            });
        }else{
            console.log('error');
        }
    });
}) 

console.log('123') //提前执行