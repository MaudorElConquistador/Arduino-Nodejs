var socket = io.connect('http://localhost:4800');
    	//recibiendo un numero random cada dos segundos	
	socket.on('server/random', function(num){
	document.getElementById('num').innerHTML=num;
});