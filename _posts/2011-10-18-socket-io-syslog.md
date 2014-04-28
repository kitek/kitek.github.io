---
layout: post
title: Socket.io + syslog
category: NodeJS
tags: ['ain', 'logger', 'socket.io', 'syslog']
type: post
description: 'Przykład wykorzystanie sysloga wraz z Socket.io'
---
Gdy korzystamy z biblioteki Socket.io w pewnym momencie zauważamy, że wszystkie logi wypluwane są na standardowe wyjście zamiast gdzieś ładnie do logów. Aby zmusić Socket.io by wszystkie logi trafiały np do syslog’a trzeba wykonać poniższe kroki:

- Skorzystać z dodatkowej biblioteki umożliwiającej w łatwy sposób logować do sysloga. Polecam tutaj paczkę ain.
- Musimy napisać własną klasę loggera np coś na poniższy styl:

{% highlight javascript %}
var MojLogger = function(opts) {
	opts = opts || {}
	this.tag = opts.tag || __filename;
	this.facility = opts.facility || 'local5';
	this.logger = require('ain').set(this.tag,this.facility,os.hostname());
	this.level = ((typeof(opts.level) == 'undefined') ? 3 : opts.level);
	
	this.error = function(type) {
		if(0 > this.level) {
			return this;
		}
		this.logger.error(('[ERROR] '+ type + ': ')
			.concat(toArray(arguments).slice(1)));
		return this;
	}
	
	this.warn = function(type) {
		if(1 > this.level) {
			return this;	
		}
		this.logger.warn(('[WARN] '+ type + ': ')
			.concat(toArray(arguments).slice(1)));
		return this;
	}
	
	this.info = function(type) {
		if(2 > this.level) {
			return this;
		}
		this.logger.info(('[INFO] '+ type + ': ')
			.concat(toArray(arguments).slice(1)));
		return this;
	}
	
	this.debug = function(type) {
		if(3 > this.level) {
			return this;
		}
		this.logger.info(('[DEBUG] '+ type + ': ')
			.concat(toArray(arguments).slice(1)));
		return this;
	}
	
	this.log = function(type) {
		if(3 > this.level) {
			return this;
		}
		this.logger.info(('[LOG] '+ type + ': ')
			.concat(toArray(arguments).slice(1)));
		return this;
	}
}
{% endhighlight %}

- Powiedzieć bibliotece socket.io by korzystała z naszego loggera:

{% highlight javascript %}io.set('logger', new MojLogger());{% endhighlight %}

Po wykonaniu powyższych punktów nasze logi z biblioteki socket.io trafiać będą do syslog’a.
