---
layout: post
title: Ciasteczka w JavaScript
category: JavaScript
tags: ciasteczka cookies 'create cookie' 'read cookie'
type: post
description: 'Proste funkcje umożliwiające odczytanie, zapisanie i usunięcie ciasteczek przeglądarki z poziomu JavaScript'
---
Proste funkcje operujące na ciasteczkach w JavaScript:

{% highlight javascript %}
function createCookie(name,value,days) {
    var date = new Date(),
        expires = "";
    if (days) {
        date.setTime(date.getTime()+(days*24*60*60*1000));
        expires = "; expires="+date.toGMTString();
    }
    document.cookie = name+"="+value+expires+"; path=/";
}

function readCookie(name) {
    var nameEQ = name + "=",
        ca = document.cookie.split(';');
    for(var i=0;i < ca.length;i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1,c.length);
        if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length,c.length);
    }
    return null;
}

function eraseCookie(name) {
    createCookie(name,"",-1);
}
{% endhighlight %}

Poniżej klika przykładów użycia:

{% highlight javascript %}
// Tworzymy ciasteczko o nazwie "koszyk", wartości "niespodzianka" i ważności 3 dni
createCookie('koszyk','niespodzianka',3);

// Odczytujemy nasze wcześniej stworzone ciastko:
var zawartosc = readCookie('koszyk');

// Na sam koniec czyścimy nasze ciasteczko:
eraseCookie('koszyk');
{% endhighlight %}
