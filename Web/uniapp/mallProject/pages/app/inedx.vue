<template>
	<view>
		<!-- v-if使加载时才渲染 -->
		<home :scrollY="scrollY" :scrollBottom="scrollBottom" :show="tabID==0?true:false" v-if ="loadOn.home" />
		
		<find :scrollY="scrollY" :scrollBottom="scrollBottom" :show="tabID==1?true:false" v-if ="loadOn.find" />
		
		<sell :scrollY="scrollY" :scrollBottom="scrollBottom" :show="tabID==2?true:false" v-if ="loadOn.sell" @closeTap="sellCloseTap"/>
		
		<news :scrollY="scrollY" :scrollBottom="scrollBottom" :show="tabID==3?true:false" v-if ="loadOn.news" />
		
		<my :scrollY="scrollY" :scrollBottom="scrollBottom" :show="tabID==4?true:false" v-if ="loadOn.my" />
		
		<footer-tabbar :tabID='tabID' :msgDot='true' @tavTap ='tabTap'/>
	</view>
</template>

<script>
	import home from '@/components/lc-common/view/home';
	import find from '@/components/lc-common/view/find';
	import sell from '@/components/lc-common/view/sell';
	import news from '@/components/lc-common/view/news';
	import my from '@/components/lc-common/view/my';
	
	import footerTabbar from '@components/lc-common/footer/footer-tabbar';
	
	import _tool from '@/static/ui/util/tools.js';
	export default{
		components:{
			home,find,sell,news,my,footerTabbar
		},
		data(){
			return{
				loadOn:{home:true,find:false,sell:false,news:false,my:false},
				scrollY:0,
				scrollBottom:0,
				tabIndex:0,
			}
		},
		onReady() {
			_tool.setBarColor(true);
		},
		methods:{
			tabTab(index){
				this.tabIndex = this.tabID;
					
				if(index == 1 && !this.loadon.find){
					this.loadOn.find = true;
				}
				if(index == 2 && !this.loadon.sell){
					this.loadOn.sell = true;
				}
				if(index == 3 && !this.loadon.news){
					this.loadOn.news = true;
				}
				if(index == 4 && !this.loadon.my){
					this.loadOn.my = true;
				}
				// 切换显示
				this.tabID = index;
				// 切换颜色
				if(index == 0){
					_tool.setBarColor(false);	
				}
				if(index ==1 || index == 2 || index == 3){
					_tool.setBarColor(true);
				}
				if(index ==4){
					_tool.setBarColor(false);
				}
				// 切换页面时滚的动到头部
				uni.pageScrollTo({
					scrollTop:0,
					duration:0;
				})	
			},
			setCloseTap(){
				this.tabTap(this.tabIndex);
			},
	
		},
		onPageScroll(e){
			this.scrollY = e.scrollTop;
		},
		onReachBottom(e){
			let timestamp = new Data().getTime();
			this.scrollBottom = timestamp;
		}
	}
</script>

<style>
</style>
