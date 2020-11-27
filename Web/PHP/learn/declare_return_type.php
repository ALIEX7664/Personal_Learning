<?php

// 函数后:datatype 声明返回类型
// 若未指定严格模式,会对在返回结果时转换为声明类型，否则报错:Fatal error

    declare(strict_types = 1);
    function sum($a,$b):int{
        return $a+$b;
    }
    var_dump(sum(3.1,2));
?>