---
layout: post
title: Socket.io disconnect
category: JavaScript
tags: connect disconnect nodejs socket.io
type: post
description: 'Przykład rozłączenia się z serwerem opartym o Socket.io'
---
Jeżeli z jakiś powodów potrzebujemy rozłączyć się z serwerem opartym o Socket.io, a następnie ponownie do niego się połączyć (np. jako inny użytkownik) najlepiej zrobić to w następujący sposób:

{% highlight javascript %}
this.disconnect = function() {
	socket.disconnect();
	socket.removeAllListeners('connect'); 
	io.sockets = {};
};
{% endhighlight %}
