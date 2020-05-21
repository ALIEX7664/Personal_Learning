var route = require('./router');
var server = require('./server')

server.start(route.route());