<template>
	<view>
		<button @click="eventFn" type="default">addUser</button>
		<button @click="queryFn" type="default">queryUser</button>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				
			}
		},
		methods: {
			eventFn:function(){
			
	
				uniCloud.callFunction({
					name:"addUser",
					data:{
						username:"Aliex1",
						password:"123456"
					},
					success: (res) => {
						console.log("success",res);
					}
				})
			},
			
			queryFn:function(){
				
				uniCloud.callFunction({
					name:"queryUser",
					data:{
						username:"Aliex1",
					},
					
					success(res) {
						console.log(res);
					}
					
				})
			}
		}
	}
</script>

<style>

</style>
