<?php

// 回调函数
// 结合可变函数的概念，将函数声明为函数参数
// 在函数中调用函数并返回
function add($a,$b){
    return $a+$b;
}

function funcCall($func,$a,$b){
    return $func($a,$b);
}

$sum = funcCall('add',3,2);
echo "sum = $sum";

// 内置回调函数
// call_user_func($callback,[$params,...])
function add2($a, $b)
{
    return $a + $b;
}

$sum =call_user_func('add', 3, 2);
echo "sum = $sum";

// call_user_func_array
// 使用数组存储回调函数参数

function add3($a, $b)
{
    return $a + $b;
}

$sum =call_user_func_array('add', array(3,2));
echo "sum = $sum";

?>
