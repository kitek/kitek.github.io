---
layout: post
title: Random od-do w JavaScript
category: JavaScript
tags: dokumentacja wyszukiwarka
type: post
redirect_from: "/javascript/2011/12/23/random-od-do-w-javascript/"
---
Poniżej przedstawiam prostą funkcję umożliwiająca generowanie losowych całkowitych liczb w JavaScript z podanego zakresu:

{% highlight javascript %}
var randomFromTo = function(from, to){
    return Math.floor(Math.random() * (to - from + 1) + from);
};​
{% endhighlight %}
