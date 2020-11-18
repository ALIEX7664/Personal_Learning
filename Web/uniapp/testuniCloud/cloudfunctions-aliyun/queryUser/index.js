'use strict';
exports.main = async (event, context) => {
	//event为客户端上传的参数
	console.log('event : ', event)
	
	//返回数据给客户端
	let db = uniCloud.database();
	let col = db.collection('users');
	console.log(event.username)
	let result = await col.where({username:event.username}).get();
	
	return result;
};
