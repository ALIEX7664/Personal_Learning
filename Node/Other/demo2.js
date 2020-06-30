let express = require('express')

let app = express()

app.get('/',(request,ressss) =>{
    ressss.send("首页")
})

app.listen(8080,()=>{
    console.log("服务启动:",'http://localhost:8080')
})