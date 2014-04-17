---
layout: post
title: Konfiguracja phpmyadmin'a
category: ServerSide
tags: config phpmyadmin
---

Mogło by się wydawać sprawą banalną skonfigurowanie [phpMyAdmin'a](http://www.phpmyadmin.net/home_page/index.php){:target="_blank"} jednak dla potomności przedstawiam podstawowy config:

{% highlight php %}
<?php
$cfg['blowfish_secret'] = 'super_tajny_hash';
$cfg['Servers'][1]['auth_type'] = 'cookie';
$cfg['Servers'][1]['host'] = 'localhost';
$cfg['Servers'][1]['connect_type'] = 'tcp';
$cfg['Servers'][1]['compress'] = true;
$cfg['Servers'][1]['extension'] = 'mysql';
$cfg['UploadDir'] = '';
$cfg['SaveDir'] = '';
$cfg['Servers'][1]['SignonURL']='http://example.com/twoj_katalog_do_mpa';
$cfg['PmaAbsoluteUri']='http://example.com/twoj_katalog_do_mpa';
{% endhighlight %}

Jest to zawartość pliku config.inc.php w naszym katalogu z phpMyAdmin’em.
