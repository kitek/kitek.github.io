---
layout: post
title: Instalacja PHPUnit w Ubuntu
category: ServerSide
tags: php-pear phpunit ubuntu
type: post
---
PHPUnit’a w Ubuntu zainstalować możemy za pomocą poniższych komend (zakładając, że mamy już wcześniej zainstalowanego php5):

{% highlight bash %}
sudo apt-get install php-pear
sudo pear channel-update pear.php.net
sudo pear upgrade-all
sudo pear channel-update pear.php.net
sudo pear install -a phpunit/PHPUnit
{% endhighlight %}

Od tej chwili możemy uruchamiać zainstalowaną aplikację wpisując:

{% highlight bash %}phpunit{% endhighlight %}
