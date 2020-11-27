<?php
// 常用预定义变量

    // $GLOBALS —— 全局作用域可用变量，不包含静态和局部变量
    $title="Hello";
    function example(){
        static $str = "String";
        $msg = "Msg";
    }
    echo "<pre>";
    var_dump($GLOBALS);

    // $_SERVER —— 包含Web服务器创建的所有信息
    var_dump($_SERVER);

// $_REQUEST：包含了 $_GET，$_POST 和 $_COOKIE 的所有信息；
// $_POST：通过 POST 方法提交的数据；
// $_GET：通过 GET 方法提交的数据；
// $_FILES：通过 POST 方式上传到服务器的文件数据；
// $_ENV：通过环境方式传递给当前脚本的变量组成的数组；
// $_COOKIE：通过 HTTP Cookies 方式传递给当前脚本的变量所组成的数组；
// $_SESSION：当前脚本可用 SESSION 变量组成的数组。






?>