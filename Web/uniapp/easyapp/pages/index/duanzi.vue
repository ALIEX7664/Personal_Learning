<template>
</template>

<script>
	export default {
		data() {
			return {

			}
		},
		methods: {

		},
		mounted(){
			uni.request({
				// url: 'https://api.apiopen.top/getJoke?page=18&count=10&type=text', //仅为示例，并非真实接口地址。
				url: 'https://api.apiopen.top/getJoke',
				methods: 'GET',
				data: {
					page: 1,
					count: 20,
					type: 'text'
				},
				header: {
					'custom-header': 'hello' //自定义请求头信息
				},
				success: (res) => {
					console.log(res.data);
					this.text = 'request success';
				},
				fail: (err) => {
					console.log(err);
				}
			});
		}
	}
</script>

<style>
</style>
