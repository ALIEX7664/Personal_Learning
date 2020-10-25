//文件删除

let fs = require('fs')

fs.unlink('ooO.jpg', (err) => {
    if (!err) {
        console.log('Delete Succeed')
    }
    else {
        console.log('err',err)
    }
})
