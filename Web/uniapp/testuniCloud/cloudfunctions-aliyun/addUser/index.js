'use strict';
exports.main = async (event, context) => {
	//event为客户端上传的参数
	console.log('event : ', event)
	
	let db = uniCloud.database();
	
	// db.createCollection("user");
	
	let con = db.collection("users");
	let res = await con.add(event);
	console.log("res",res);
	
	
	//返回数据给客户端
	return event
};
