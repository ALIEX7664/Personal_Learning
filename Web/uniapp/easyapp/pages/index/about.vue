<template>
	<view>
	
		<image src="../../static/logo.png" mode=""></image>
		<image src="../../static/logo.png" mode=""></image>
		
		<navigator url="index">index1</navigator>
		<button type="default" @click="toNavigate">index2</button>
		<button type="default" @click="toRedirect">index3</button>
		
		
	</view>

</template>

<script>
	export default{
		methods:{
			toNavigate:function(){
				uni.navigateTo({
					url:'me'
				});
			},
				
			toRedirect:function(){
				uni.redirectTo({
					url:'index'
				})
			}
		}
	}
</script>

<style>
	image{
		width: 375rpx;
		height: 375rpx;
	}
</style>
