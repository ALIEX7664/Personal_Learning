const koa = require('koa');
const bodyParser = require('koa-bodyparser');
const controller = require('./contoller');


// //is a function
// const router = require('koa-router')();


const app = new koa();

app.use(bodyParser());
app.use(controller());
app.listen(3000);

console.log('on 3000')
