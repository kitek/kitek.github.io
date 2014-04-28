---
layout: post
title: Zliczanie elementów w obiekcie JavaScript
category: JavaScript
tags: ['count', 'lenght', 'object.keys']
type: post
description: 'Proste zliczanie elementów w obiekcie w JavaScript.'
---
Proste zliczanie elementów w obiekcie w JavaScript:

{% highlight javascript %}
var obiekt = {'1':'ala','2':'basia','3':'zosia'};
var ile = Object.keys(obiekt).length;
console.log(ile);
{% endhighlight %}
Wynik:
{% highlight text %}3{% endhighlight %}

Powyższe zliczanie ma kilka wad (dlatego jest "proste"):

- nie działa w IE < 9
- oprócz zwykłych kluczy zliczy również metody (co w niektórych sytuacjach może być nie chciane)

Więcej info o metodzie [Object.keys](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/keys){:target="_blank"}.
