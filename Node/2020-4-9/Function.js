/*
* 1.call function in another function
*  */
function say(word) {
    console.log(word)
}

function execute(functions,value) {
    functions(value);
}

execute(say,'Hello world');

execute(function (word) {
    console.log(word);
},'Hello');     //第一个参数被称为匿名函数，没有函数名