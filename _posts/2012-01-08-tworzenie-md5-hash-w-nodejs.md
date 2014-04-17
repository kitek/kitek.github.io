---
layout: post
title: Tworzenie md5 hash w NodeJS
category: NodeJS
tags: samba
---
Przydatne np. przy hash’owaniu haseł:

{% highlight javascript %}
var crypto = require('crypto'), wynik, data = "do shash'owania";
wynik = crypto.createHash('md5').update(data).digest("hex");​
{% endhighlight %}
