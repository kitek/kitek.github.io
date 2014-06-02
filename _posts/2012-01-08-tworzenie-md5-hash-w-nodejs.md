---
layout: post
title: "Tworzenie md5 hash w NodeJS"
category: NodeJS
tags: ['md5','hash','crypto']
type: post
description: 'Szybki sposób na wygenerowanie hash md5.'
redirect_from: "/nodejs/2012/01/08/tworzenie-md5-hash-w-nodejs/"
---
Przydatne np. przy hash’owaniu haseł:

{% highlight javascript %}
var crypto = require('crypto'), wynik, data = "do shash'owania";
wynik = crypto.createHash('md5').update(data).digest("hex");​
{% endhighlight %}
