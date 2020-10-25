const Base = require('../base.js');
const path = require('path');
const fs = require('fs');
module.exports = class extends Base {
    indexAction() {
        return this.display();
    }

    upImgsAction() {
        // 获取上传后前端传回的路径
        // uploadFile是前端提交表单时，图片上传组件的name属性值
        let uploadfile = this.file('uploadFile');
        let filepath = uploadfile.path;

        // 获取系统总路径并以此创建文件夹
        let uploadpath = think.ROOT_PATH + '/www/static/upload';
        think.mkdir(uploadpath);

        // 获取路径里的文件名称，提取出'/'隔开的最后一部分
        let basename = path.basename(filepath);

        // 创建读写流并写入
        var readStream = fs.createReadStream(filepath);
        var writeStream = fs.createWriteStream(uploadpath + '/' + basename);
        readStream.pipe(writeStream);

        this.success({filename:basename,orginName:uploadfile.name});
    }
};
