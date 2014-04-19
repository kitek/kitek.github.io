---
layout: post
title: Obliczanie wieku w JavaScript
category: JavaScript
tags: age 'data urodzin' wiek javascript
type: post
description: 'Przykład funkcji w JavaScript obliczającej wiek na podstawie daty urodzenia'
---
Prosta funkcja przetwarzająca datę urodzin na wiek np:  _1985-04-11 –> 26 lat_

{% highlight javascript %}
var getAgeStr = function(dateString) {
    var myDate = new Date(dateString), 
        now = new Date(),
        month_of_birth=myDate.getMonth(),
        day_of_birht=myDate.getDay(),
        year_of_birth=myDate.getYear(),
        now_month = now.getMonth(),
        now_day = now.getDay(),
        now_year = now.getYear(),
        age = now_year - year_of_birth;
    if (now_month < month_of_birth) {
        age--;
    } else if ((now_month == month_of_birth) && (now_day < day_of_birht)) {
        age--;
        if (age < 0) {
            age = 0;
        }
    }
    return age;
}
{% endhighlight %}
