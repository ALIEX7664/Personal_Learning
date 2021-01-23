// Dom解决方案 DOM Level 1
function showPic(whichpic){
    document.getElementById("placeholder").setAttribute("src",whichpic.getAttribute("href"));
    document.getElementById("description").childNodes[0].nodeValue = 
    whichpic.getAttribute("title");
}

// DOM Level 1 前解决方案
function showPic_2(whichpic){
    document.getElementById("placeholder").src = whichpic.getAttribute("href");
}


// 返回body子元素个数,chilidNodes为子元素数组
function countBodyChildren(){
    console.log(document.getElementsByTagName("body")[0].childNodes[0]);
}

window.onload = countBodyChildren;