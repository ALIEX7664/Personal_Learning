---
 title: Vue
 date: 2019-08-13 09:39:50  
---


## 简介

##### **MVC**（设计模式，前后端兼备）

Model -> 模型 -> 数据（js变量）

View ->视图 -> 用户交互的页面（HTML,CSS）

Control -> 控制器 -> 通过用户视图根据事件进行数据交互(同过DOM对象绑定事件，对变量进行修改)‘


##### **MVVM**

Model：数据存储

View：页面显示

View Model：负责业务逻辑处理，对数据进行加工后交给视图展示（即框架如Vue）



##### **JQuery**

只能称为库，不能称为框架

可以和框架混搭

适合中小型项目

不适合大型项目：需要不停的去获取DOM对象



##### **框架**

提供一套完整的解决性方案，但换框架要重构整个项目

Vue.js/React.js/Angular.js：减少DOM操作，实现数据的双向绑定，动态渲染



##### **虚拟DOM**

在JS内存里构建类似DOM对象，拼装数据后整体解析，一次性将内容插入HTML中

在JQ的DOM操作非常消耗资源



## v-if条件渲染

##### **v-if 和 v-show 的区别**

v-if： 条件不满足时，会直接在DOM中直接去除，实现懒加载，需要消耗性能。

适用于只需一次渲染的情况（登录界面：是否为会员）

v-show： 只是添加了`display：none` 属性，会渲染在DOM上，需要占用空间。

适用与需要反复切换的情况（切换图片的显示情况）

![](E:\大三\个人学习\Front-end\Vue\v-if.png)



## v-for列表渲染

类似与for循环，通常用于列表的渲染

##### **1. 可以输出数组的内容**

###### 例如：

下面数组name

```vue
names:['a','b','c','d']
```

可以由下面的代码渲染

```vue
<li v-for="item in names">{{item}}</li>
```

此时会渲染出Students中的所有元素

![](E:\大三\个人学习\Front-end\Vue\v-for - 1.png)



##### **2. 可以输出多个对象构成的数组**

###### 例如

```vue
students:[
			{
				name:'小明',
				age:17,
            },
			{
				name:'小亮',
				age:16
			}

```
可用以下方式渲染

```vue
<li v-for="student in students">{{student.name}} --{{student.age}}</li>
```

###### ![image-20200507145357498](E:\大三\个人学习\Front-end\Vue\v-for - 2.png)

###### 错误示例

```vue
<li v-for="student in students">{{student}}</li>
```

渲染结果

![image-20200507145828170](E:\大三\个人学习\Front-end\Vue\v-for - 3.png)



##### **3. 可以渲染单个对象里的所有元素**

使用上方的例子

```vue
<li v-for="student in students[0]">{{student}}</li>
```

渲染了students的第一个对象的所有元素

![image-20200507150110680](E:\大三\个人学习\Front-end\Vue\v-for - 4.png)



**4.与v-if配合使用**

还是使用上方的例子

 v-if搭配使用，先循环，再判断,所以索引值key是不变的

```vue
<li  v-if="stu.age%2==0" v-for="stu,key in students" >{{key}}--{{stu}}</li>
```

下面是渲染后的效果

![image-20200507150453171](E:\大三\个人学习\Front-end\Vue\v-for - 5.png)

通过运算age输出相应的对象



## 计算属性

> **计算属性是基于它们的响应式依赖进行缓存的**。只在相关响应式依赖发生改变时它们才会重新求值。

对于复杂的数学运算还是逻辑运算，都应使用计算属性

计算属性的方法写在computed中

相关数据

```vue
data:{
				firstName:'Harry',
				lastName:'Potter',
				word:'world',
				students:[
					{
						name:'小明',
						age:17,
					},
					{
						name:'小亮',
						age:16
					},
				],
				
		}
```

在不使用计算属性的情况下，可以使用下列的方法进行运算

**1.元素拼接**

```vue
<!-- 无论是否修改都会进行计算,性能低 -->
<span>{{firstName+lastName}}</span>
```

若使用计算属性

###### HTML

```html
<!-- 若不修改只会进行一次计算,性能较高 -->
<span>{{fullName}}</span>
```

###### Script

```javascript
/* 计算属性,可以用于计算变量的赋值,会将计算结果进行缓存 
*  不能使用箭头函数来计算变量的值
* 使用	变量:function(){}
*/ 
computed:{
			fullName:function(){
				return (this.firstName+this.lastName)
			}
		 }
```

以两个例子上渲染效果相同

![image-20200507152040773](E:\大三\个人学习\Front-end\Vue\计算属性 - 1.png)



**2.字符串倒置**

###### HTML

```html
<!-- 单词逆序 -->
<p>{{word.split('').reverse('').join('')}}</p>
<!-- 高性能 -->
<p>{{fullWord}}</p>
```

###### Script

```javascript
computed:{
			fullWord:function(){
			return this.word.split('').reverse('').join('')
			}
		}
```

**渲染后**

![image-20200507152528977](E:\大三\个人学习\Front-end\Vue\计算属性 - 2.png)



**3.显示偶数年龄学生**

###### HTML

```html
<h1>students</h1>
<ul>
	<li v-for="item,index in oddStudents" :key="index">{{item.name}}----{{item.age}}</li>
</ul>
```

###### Script

```javascript
oddStudents:function(){
		// 需包含item参数
		let result = this.students.filter((item)=>{
		return item.age %2==1 
		})
		return result
		},
```
这里使用ES6箭头函数，传入了item函数

filter()是过滤器，用来过滤掉不符合以上计算要求的Student对象

![image-20200507153819803](E:\大三\个人学习\Front-end\Vue\计算属性 - 5.png)



要注意的是，时间渲染是不能动态更新的

###### HTML

```html
<h1>{{now}}</h1>
```

###### Script

```javascript
/* 时间计算不是响应式依赖，所以不会更新 ，只有重新渲染时才会触发更新*/ 
now:function(){
	return Date.now();
}
```

![image-20200507153621197](E:\大三\个人学习\Front-end\Vue\计算属性 - 3.png)

刷新页面前并不更新，刷新页面后才更新

![image-20200507153733714](E:\大三\个人学习\Front-end\Vue\计算属性 - 4.png)



## v-bind数据绑定

可以实现数据的绑定 

使用方法：

**1.获取数据**

```html
<img v-bind:src="link" style="width:30%;">
```

简写方式：

```html
<img :src="link" style="width:30%;">
```

###### 此时在Javascript中

```javascript
	var app = new Vue({
				el:'#app', //外层div的id属性
				data:{
					link:'https://picsum.photos/360/460?random=1'
                	}
    })
```

src会获取link元素的内容，将它注入到src属性中

渲染后如下

![image-20200507164327224](E:\大三\个人学习\Front-end\Vue\v-bind.png)



**2.实现CSS样式绑定的判断**

###### HTML

```html
<div :class="{my:isTrue}">{{isTrue}}</div>
```

###### CSS

```css
.my{
		width: 100px;
		height: 100px;
		background-color: #0000FF;
}
```

###### JavaScript

```js
//只展示data
data:{
		isTrue:true
	 }
```

这里把isTrue对象赋值为true，那么CSS样式就会被渲染、

![image-20200507172708923](E:\大三\个人学习\Front-end\Vue\v-bind -2.png)

此时我在控制台修改isTrue的属性

```js
> app.isTrue="flase"
< "flase"
```

但是会发现方块并没有消失，但是文字改变了

![image-20200507172756372](E:\大三\个人学习\Front-end\Vue\v-bind -3.png)

> 这里可以发现，class属性中CSS样式渲染绑定的真值判断，只能作用一次，在后续修改都无法起作用，只有页面重新渲染时才会起作用
>
> 但这并不代表说**v-bind**绑定的值只能作用一次，例如上面的**img**样式，若修改其link对象，那么图片还是会不见的！

此时我们修改JS代码的isTrue

```js
isTrue:false
```

![image-20200507173520269](E:\大三\个人学习\Front-end\Vue\v-bind -4.png)

那么CSS样式就消失了



## v-model双向数据绑定

v-model一般用于输入框

可以实现对对象数据的双向绑定

比如将一个对象绑定到输入框的value时

当输入框的内容改变时

使用此对象的所有内容都会随着改变

比如下面的例子：

###### HTML

```html
<h1>输入框</h1>
<input type="text"  v-model:value="word" />
<p>{{word}}</p>
```

###### Javascript

```js
var app = new Vue({
	el:"#app",
	data:{
		word:'',
			}
		})
```
这里需要创建一个word的字符串对象，这样value才不会出现内容

使用v-model双向数据绑定后，当向输入框中输入内容，绑定了word对象的标签也会同样改变

![image-20200507180044438](E:\大三\个人学习\Front-end\Vue\v-model - 1.png)

此时在控制台查看word的值，可以发现word也已经被相应的修改了

```js
> app.word
< "Hello"
```



###### 完整代码

```vue
<!doctype html>
<html>

	<head>
		<meta charset="utf-8">
		<title></title>
		<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js">
		</script>
	</head>

	<body>
		<div id="app">
			<h1>输入框</h1>
			<input type="text"  v-model:value="word" />
			<p>{{word}}</p>
			
			<h1>选择框</h1>
			<input list="options" v-model:value="word2" />
			<datalist id="options">
				<option value="A">
				<option value="B">
				<option value="C">
			</datalist>
			<p>{{word2}}</p>
		</div>
		
		<script type="text/javascript">
			var app = new Vue({
				el:"#app",
				data:{
					word:'',
					word2:'',
				}
			})
		</script>
        
	</body>
</html>

```

> 对于刚刚v-bind的CSS属性绑定判断的修改，能否使用v-model呢？
>
> 答案是否定的，v-model只支持数据之间的修改，但无法支持像CSS这样的属性判断
>
> 所以说只能用于数据修改



## v-on

可以用于绑定各种事件触发时执行的方法

方法写在methods中

或者可以直接在事件处理上写一个方法

在过去我们写事件触发方法都是用

```html
<button type="button" onclick="wordInput()">cilck</button>
```

但这在Vue是行不通的

![image-20200507183236726](E:\大三\个人学习\Front-end\Vue\v-on - 1.png)

在Vue下要采用这种方法

```html
<button type="button" v-on:click="wordInput()">cilck</button>
```

即v-on代替了前面的on部分

下面是例子

**1.计数器**

###### HTML

```html
<button type="button" v-on:click="count++">cilck</button>
<p>{{count}}</p>
```

###### Javascript

```js
var app = new Vue({
				el:"#app",
				data:{
					count:1
				},
```

当点击click时，数值会增加

![image-20200507184305112](E:\大三\个人学习\Front-end\Vue\v-on - 2.png)

> 这里是把count的加法写在了click中，这里会把它识别为一个变量，也是一个对象，对其进行加1操作
>
> 但对于复杂的操作，写一个方法来保存才是明智之选

**2.改变内容**

###### HTML

```HTML
<button type="button" v-on:click="wordInput()">cilck</button>
<div>{{word}}</div>	
```

###### Javascript

```js
	var app = new Vue({
				el:"#app",
				data:{
					word:'Hi'	//这里定义了数据内容
				},
				methods:{	//这里写方法
					wordInput:function(){	//方法
						this.word = 'Hello'
						console.log(this.word)
					}
				}
```

当我按下click时，内容就会发生改变

![image-20200507184548837](E:\大三\个人学习\Front-end\Vue\v-on - 3.png)

![image-20200507184627582](E:\大三\个人学习\Front-end\Vue\v-on - 4.png)

例子完整代码

```vue
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
	</head>
	
	<body>
		<div id="app">
		<h1>计数器</h1>
		<button type="button" v-on:click="count++">cilck</button>
		<p>{{count}}</p>
		
		<h1>内容改变</h1>
		<button type="button" v-on:click="wordInput()">cilck</button>
		<div>{{word}}</div>	
		</div>
		<script type="text/javascript">
			var app = new Vue({
				el:"#app",
				data:{
					word:'Hi',
					count:1
				},
				methods:{
					wordInput:function(){
						this.word = 'Hello'
						console.log(this.word)
					}
				}
			})
		</script>
	</body>
	
</html>


```

