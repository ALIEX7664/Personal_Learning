let express = require('express')

let app = express()

app.get('/',(req,res)=>{
    res.send("home")
})

app.listen(8080,()=>{
    console.log("start","http://localhost:8080")
})