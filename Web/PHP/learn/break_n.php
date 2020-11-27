<?php

// break 可以指定跳出层数,最内层循环为第一层
// 最外层循环为最后一层
    while(true){
        for(;;){
            for($i = 0; $i < 4 ;$i++){
                if($i == 3){
                    echo "break";
                    break 3;
                }
            }
        }
    }

    echo "<br>break out";
?>