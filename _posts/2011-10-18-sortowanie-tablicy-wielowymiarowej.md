---
layout: post
title: Sortowanie tablicy wielowymiarowej
category: PHP
tags: ['sortowanie w PHP', 'usort']
type: post
description: 'Proste sortowanie tablicy wielowymiarowej w obiekcie w języku PHP.'
---
Proste sortowanie tablicy wielowymiarowej w obiekcie (w tym przypadku sortujemy malejąco po wymiarze "similar") z wykorzystaniem funkcji [usort](http://www.php.net/manual/en/function.usort.php){:target="_blank"}.
{% highlight php %}
<?php
class MojaKlasa {
    public sortuj() {
        usort($tablicaDoSortowania, array('MojaKlasa','compare'));
    }
 
    public static function compare($a, $b) {
        if ($a['similar'] == $b['similar']) {
            return 0;
        }
        return ($a['similar'] > $b['similar']) ? -1 : 1;
    }
}
{% endhighlight %}
