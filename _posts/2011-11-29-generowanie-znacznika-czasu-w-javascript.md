---
layout: post
title: Generowanie znacznika czasu w JavaScript
category: JavaScript
tags: ['timestamp', 'znacznik czasu']
type: post
description: 'Banalny przykład jak generować znacznik czasu (timestamp) w JavaScript.'
---
Banalny przykład jak generować znacznik czasu (timestamp) w JavaScript:

{% highlight javascript %}
var dt = Math.round(new Date().getTime() / 1000);
{% endhighlight %}
