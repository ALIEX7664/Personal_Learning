function product(arr) {
  return  arr.reduce((x,y) => {
        return x*y
    })
}

console.log(product([1,2,3,4]))