---
layout: post
title: 'Zend Framework Autoloader'
category: PHP 
tags: ['autoloader php', 'class loader', 'zend framework autoloader']
type: post
description: 'Od wersji 1.8 ZF wychodzi z użycia klasa Loader jej miejsce zajmie Autoloader. Zobacz jak poprawnie dokonać refaktoryzacji kodu.'
---
Od wersji 1.8 ZF wychodzi z użycia klasa _Loader_ jej miejsce zajmie _Autoloader_.
Jeżeli z upgdate’owałeś wersję swojej biblioteki Zend Frameworka i jednocześnie używałeś klasy Loader otrzymasz na dzień dobry komunikat:

{% highlight text %}
Notice: Zend_Loader::Zend_Loader::registerAutoload is deprecated 
as of 1.8.0 and will be removed with 2.0.0; 
use Zend_Loader_Autoloader instead in ...
{% endhighlight %}

W większości przypadków wystarczy fragment:

{% highlight text %}
require_once("Zend/Loader.php");
Zend_Loader::registerAutoload();
{% endhighlight %}

zastąpić następującym:

{% highlight text %}
require_once 'Zend/Loader/Autoloader.php';
$loader = Zend_Loader_Autoloader::getInstance();
$loader->setFallbackAutoloader(true);
{% endhighlight %}
w bootstrap’ie naszego projektu.

Możliwości klasy _Zend_Loader_Autoloader_ są oczywiście dużo większe i opisane zostały szczegółowo w [dokumentacji ZF](http://framework.zend.com/manual/en/zend.loader.autoloader.html){:target="_blank"}{:rel="nofollow"}.
