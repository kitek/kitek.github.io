---
layout: post
title: Kopiowanie tablicy w JavaScript
category: JavaScript
tags: ['array slice', 'clone array', 'copy array']
type: post
description: 'Przykład kopiowania tablicy w języku JavaScript'
---
Dzisiaj zaszła mnie potrzeba kopiowania (klonowania) całej tablicy w JavaScript. Sam problem, który rozwiązywałem był troszkę bardziej skomplikowany i polegał na rekurencyjnym uruchamianiu tej samej funkcji, która operowała na kopii tablicy przekazywanej następnie jako parametr. Po wykonaniu pewnej liczby operacji skrypt miał na nowo kopiować wcześniej przygotowaną tablicę _(czy to co napisałem w ogóle ma jakiś sens? :] )_.

Poniżej prosty przykład kopiowania całej tablicy w JavaScript’cie:

{% highlight javascript %}
var tablica = ["ala", "basia", "zosia"];
var nowaTablica = tablica.slice();

console.log(nowaTablica);
{% endhighlight %}
