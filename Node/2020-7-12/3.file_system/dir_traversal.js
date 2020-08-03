let fs = require('fs')

delDir('dir')

//目录递归删除（非空目录删除）
function delDir(dirPath) {
    //同步读取目录
    var filesArr = fs.readdirSync(dirPath)
    for (var i in filesArr) {
        //拼接路径
        var filePath = dirPath + '/' + filesArr[i];

        //读取文件信息
        var stat = fs.statSync(filePath)

        //判断文件类型
        if (stat.isFile()) {
            fs.unlinkSync(filePath)
        } else if (stat.isDirectory()) {
            //递归调用
            delDir(filePath)
        }
    }
    //删除自身
    fs.rmdirSync(dirPath)
}