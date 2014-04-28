---
layout: post
title: Node.js wysyłanie HTTP POST
category: NodeJS
tags: ['http', 'post', 'request']
type: post
description: 'Proste wysyłanie danych POST’em w NodeJS.'
---
Proste wysyłanie danych POST’em w NodeJS:

{% highlight javascript %}
var http = require('http');

exports.sendPost = function(options,data,callback) {
	var post_data = querystring.stringify(data);
	var opts = {
		host: options.host,
		port: options.port,
		maxSockets : 100,
		path: options.path,
		method: 'POST',
		headers: {
			'Host': options.host_name,
			'Connection' : 'close',
			'Content-Type': 'application/x-www-form-urlencoded',
			'Content-Length': post_data.length
		}
	};
	http.globalAgent.maxSockets = 100;
	var req = http.request(opts, function(res) {
		var data = '';
		res.setEncoding('utf8');
		res.on('data', function (chunk) {
			data+=chunk;
		});
		res.on('end', function () {
			if(typeof callback == 'function') {
				callback(false,data);
			}
		});
	});
	req.on('error', function(e) {
		if(typeof callback == 'function') {
			callback(e,false);
		}
	});
	req.write(post_data);
	req.end();
};
{% endhighlight %}
Poniżej przykład użycia:

{% highlight javascript %}
sendPost({
	'host': 'www.google.pl',
	'port': 80,
	'host_name': 'www.google.pl',
	'path': '/typing'
},{
	'klucz': 'wartosc',
	'klucz2': 'wartosc2'
},function(err, response) {
	if(err) return false;
	console.log(response);
});
{% endhighlight %}
