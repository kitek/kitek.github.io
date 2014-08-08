---
layout: post
title: 'Redis - ogranicznone kolekcje'
category: JavaScript
tags: ['redis','nodeJS','capped collection','logi']
type: post
description: 'Sposób na tworzenie i przechowywanie ograniczonych kolekcji przy pomocy wbudowanych w Redisa list.'
---
Pracując nad aplikacją wykorzystującą Redis'a potrzebowałem prostego mechanizmu umożliwiającego przechowywanie kilkuset ostatnich logów. Istotne było ograniczenie maksymalnej ich liczby, a także zapewnienie odpowiedniej rotacji.
Dzięki zastosowaniu [list](http://redis.io/topics/data-types){:target="_blank"}{:rel="nofollow"} i poleceń: [lpush](http://redis.io/commands/lpush){:target="_blank"}{:rel="nofollow"} i [ltrim](http://redis.io/commands/ltrim){:target="_blank"}{:rel="nofollow"} możliwe jest stworzenie ograniczonej kolekcji.


{% highlight javascript %}
var rc = redis.createClient("host", "port"),
    cacheName = "my-logs",
    maxLogSize = 100,
    logData = {"key":"value"};

rc.lpush(cacheName, JSON.stringify(logData));
rc.ltrim(cacheName, 0, maxLogSize);

{% endhighlight %}
