---
layout: post
title: Prosty parser linków w PHP
category: PHP
tags: ['parser', 'preg', 'wyrażenia regularne']
type: post
description: 'Prosty parser linków wyszukujący i zamieniający wszystkie ciągi znaków posiadające w sobie .pl .com .org .net na wersje HTML.'
---
{% highlight php %}
<?php
$html = preg_replace(
     '#(([^ \'\"\< ]+)?[^ \'\"\.\<]+\.(pl|com|net|org)(\/[^ \'\"\<]+)?)#',
     '$1',
     $html
);
{% endhighlight %}
__UWAGA__ Parser zamienia również ścieżki do obrazków (w niektórych przypadkach takie działanie może być niepożądane).
