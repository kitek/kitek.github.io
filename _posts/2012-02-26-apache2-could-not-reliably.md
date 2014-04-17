---
layout: post
title: 'apache2: Could not reliably determine the servers fully qualified domain name'
category: ServerSide
tags: apache2 ServerName ubuntu
---
Jeżeli przy restartowaniu / przeładowaniu ustawień serwera Apache widzisz komunikat:

{% highlight bash %}apache2: Could not reliably determine the server's fully qualified domain name, using 127.0.1.1 for ServerName{% endhighlight %}

To zapewne nie masz ustawionej wartości "ServerName" w pliku "apache2.conf". W Ubuntu dodajemy ją za pomocą następujących komend:

{% highlight bash %}
sudo su
echo "ServerName localhost" >> /etc/apache2/apache2.conf
service apache2 reload
{% endhighlight %}
