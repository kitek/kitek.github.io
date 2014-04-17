---
layout: post
title: Hosts w Mac OS X
category: ServerSide
tags: hosts 'mac os x'
---
Jak dodać nowy host w systemie Mac OS X (10.6.8)?
Otwieramy Terminal i wpisujemy (wymagane będzie podanie naszego hasła):

{% highlight bash %}sudo nano /private/etc/hosts{% endhighlight %}

Dodajemy nasze ustawienia w następujący sposób:

{% highlight bash %}
127.0.0.1	localhost testowa.domena.pl
192.168.1.16	testowy.projekt.pl
{% endhighlight %}

Aby zapisać wprowadzone zmiany wciskamy: "CTRL+X" a następnie "y+ENTER".
Jeżeli z jakiś przyczyn nasz adres nie chce działać możemy ręcznie odświeżyć hosty wpisując:

{% highlight bash %}dscacheutil -flushcache{% endhighlight %}
