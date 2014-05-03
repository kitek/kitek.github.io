---
layout: post
title: 'mod_expires – HTTP 304 Not Modified'
category: ServerSide 
tags: ['apache', 'cache', 'http 304', 'mod_expires', 'not modified']
type: post
description: 'Przykład konfiguracji mod_expires dla plików statycznych.'
---
__mod_expires__ jest modułem serwera Apache umożliwiającym wysłanie dodatkowych nagłówków HTTP informującym przeglądarkę o "terminie wygaśnięcia ważności" wszystkich lub konkretnych typów plików.

Dzięki takiemu zabiegowi jesteśmy w stanie w znaczący sposób zmniejszyć liczbę zapytań do naszego serwera. Przeglądarka zamiast pobierać ponownie plik z serwera odczyta go ze swojego kesza.

Poniższy fragment kodu należy umieścić w pliku .htaccess w katalogu głównym naszej strony WWW:

{% highlight text %}
ExpiresActive On
FileETag none
ExpiresByType image/jpg "access plus 1 month"
ExpiresByType image/jpeg "access plus 1 month"
ExpiresByType image/png "access plus 1 month"
ExpiresByType image/gif "access plus 1 month"
ExpiresByType text/javascript "access plus 1 month"
ExpiresByType application/x-javascript "access plus 1 month"
ExpiresByType text/css "access plus 1 month"
{% endhighlight %}

__Linki:__

- [Więcej informacji na temat mod_expires na stronie apache.org](http://httpd.apache.org/docs/2.0/mod/mod_expires.html){:target="_blank"}

