<template>
	<view>
		<image :src="imgUrl" mode=""></image>
		<button @click="uploadFn" type="default">upload</button>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				imgUrl:""
			}
		},
		methods: {
			uploadFn(){
				
				uni.chooseImage({
					count:1,
					success: (res) => {
						console.log("chooseImg",res);
						if(res.tempFilePaths.length>0){
							let filePath = res.tempFilePaths[0];
		
							console.log("upload",filePath);
							
							uniCloud.uploadFile({
								filePath:filePath,
								cloudPath:filePath+".jpg",
								onUploadProgress(e){
									console.log(e);
									var percentComplete = Math.round(
										event.loaded/event.total*100 
									);
									
									console.log(percentComplete);
								},
							    success: (res) => {
							    	this.imgUrl = res.fileID;
							    },
								fail(res) {
									console.log('error',res);
								}
							})
						}
					}
				})
			}
		}
	}
</script>

<style>

</style>
