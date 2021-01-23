
//特殊类型不要用类型限定,无意义

//1 . Object
//常用TS 对象声明,? - 表示属性可选
let a:{name:string,age?:number};

// 结构与对象需一模一样
a = {name:'aliex',age:13};

// 声明属性名为string类型,其属性值为任意类型,[]可以有多个键值
let b:{name:string,[prop:string]:any}

b = {name:'aliex',age:13,gender:'male'}

//2 . Function
//函数类型限定
let fn:(a:number,b:number)=>number;

fn = (a1,a2)=>{
    return a1+a2;
}
fn = function(num1,num2):number{
    return num1+num2;
}

//3 . Array

// 数组类型限定
let arr1:string[];

// 另一种方法，类似Java泛型限定
let arr2:Array<number>;

// 元组 - 固定长度的数组,效率高,长度短
let arr3:[string,number];


//4. Enum

//枚举由TS自动生成相应的值或手动编写，在编写时可以采用命名来编写

enum Gender{
    Mail,
    FeMail
}

//在编写时自动匹配
let enumobj:{name:string,gender:Gender}={
    name:'ALiex',
    gender:Gender.FeMail
};


//5 . &

let objAnd:{name:string} & {age:number};

//6 . type
//对类型起别名，简化书写
type myType = 1|2|3|4|5
let numType1:myType;
let numType2:myType;
