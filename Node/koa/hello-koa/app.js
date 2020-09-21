const koa = require('koa');

const app = new koa();

// app.use(async (ctx,next)=>{
//     await next();
//     //设置Content-Type
//     ctx.response.type='text/html';
//     //设置内容
//     ctx.response.body='<h1> Hello koa2 </h1>';
// })

// app.listen(3000)
// console.log('app.started at port 3000...')

app.use(async (ctx,next)=>{
    console.log(`${ctx.method} ${ctx.url}`);
    await next();
});

app.use(async (ctx,next)=>{
    //读取当前时间
    const start = new Date().getDate();
     next();
    //判断第三个函数执行完毕的时间
    const ms = new Date().getTime() - start;
    console.log(`Time:${ms}ms`);

});

app.use(async(ctx,next)=>{
    await next();
    ctx.response.type ='text/html';
    ctx.response.body = '<h1> Hello </h1>'
    console.log('A')
})

app.listen(3000)
console.log('port 3000')