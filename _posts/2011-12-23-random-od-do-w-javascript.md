---
layout: post
title: Random od-do w JavaScript
category: JavaScript
tags: dokumentacja wyszukiwarka
type: post
---
Poniżej przedstawiam prostą funkcję umożliwiająca generowanie losowych całkowitych liczb w JavaScript z podanego zakresu:

{% highlight javascript %}
var randomFromTo = function(from, to){
    return Math.floor(Math.random() * (to - from + 1) + from);
};​
{% endhighlight %}
