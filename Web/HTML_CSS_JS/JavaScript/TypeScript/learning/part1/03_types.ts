

//1. 字面量声明限定可声明内容

let a: 10;

a = 10;
// a = 11; //报错

let b: "world";

//2. 联合类型
// 或运算符增加限定
let str: "hello" | "typescript" ;

//3. 类型限定
let types: boolean | string;
types = false;
types = "hello";


//4. 关闭类型检测，不推荐 let val = let val: any
let val: any;


// 未知类型，安全类型any,不能直接赋值给其他变量
let val2:unknown;
val2 = 'hello';


//any可以赋值给任意类型
let str2: string;
str2 = val;

// unknown 不可随意赋值给其他类型
// str = val2;

//5. unknown类型判断
if(typeof  val2 === 'string'){
    str2 = val2;
}

//6. 类型断言,使编译器知道当前类型
str2 = val2 as string;
str2 = <string > val2;


//7. 函数
// 默认函数类型均为void
function fn(): void{
    if(true){
        return null;
    }else if(false){
        return undefined;
    }

    return ;


}

//never用来抛出错误
function err(): never {
    throw new Error("error");
}
