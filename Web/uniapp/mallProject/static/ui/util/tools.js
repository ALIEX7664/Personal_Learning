
let _tool= {
	
	// 获取字符串真实长度
	strLeng(str){
		if(str){
			let 
				len = str.length,
				truelen = 0;
				for(let x = 0 ; x < len; x++){
					if(str.charCodeAt(X) > 128){
						truelen +=2;
					}else{
						truelen +=1;
					}
				}
				return truelen;
		}else{
			return 0;
		}
	}
	
	// 获取页数
	getPageNum(total,row){
		let num = Number(total)/Number(row);
		
		if(num%1 !== 0){
			let b = num.toString();
			llet a = parseInt(b.substring(0,b.indexOf('.')));
			let s = b.replace(/\d+\.(\d*)/,'$1'); //取小数点后
			if(s>)0){
				num = a+1;
			}
		}
		return num;
	}
	
	// 设置通知栏颜色
	setBarColor(black = false){
		if(black){
			uni.setNavigationBarColor({
				frontColor:'#000000',
				backgroundColor:'#FAFAFA'
			});
		}else{
			uni.setNavigationBarColor({
				frontColor:'#FFFFFF',
				backgroundColor:'#FAFAFA'
			});
		}
	}
}

export default _tool;