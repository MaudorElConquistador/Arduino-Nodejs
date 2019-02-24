var express = require('express');
var router = express.Router();
var server = require('../bin/www');
var io = require('socket.io')(4800);

/* GET home page. */
router.get('/', function(req, res, next) {
	res.render('index', { title: 'Express' });
});

io.on('connection', function(socket){
  //enviando numero aleatorio cada dos segundo al cliente
  setInterval(() => {
    socket.emit('server/random', Math.random())
	  
  }, 500)
  
});
/*io.on('connection', function (socket) {
	console.log("Ya se conecto");
});*/
	

module.exports = router;
