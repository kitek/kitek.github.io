---
layout: post
title: 'Android - własne czcionki'
category: Android
tags: ['textview','custom fonts','android','Typeface']
type: post
description: 'Tutorial objaśniający jak wykorzystać własne czcionki (np. w TextView) w aplikacjach Android.'
---
W przypadkach gdy nadworny grafik wymyśli sobie fantazyjne napisy na wizualizacji aplikacji lub domyślny systemowy font nam się znudził możemy wgrać własną czcionkę i trochę poszaleć. Poniżej przedstawiam prosty sposób na zastosowanie dowolnych czcionek z TextView.

1. Nasze fonty umieszczamy w katalogu `assets/fonts` (jeżeli nie mamy takiego tworzymy go)
2. Na wybranym `TextView` ustawiamy `Typeface` z naszą czcionką:

{% highlight java %}
Typeface tf = Typeface.createFromAsset(getAssets(), "fonts/GloriaHallelujah.ttf");
		
TextView tx1 = (TextView) findViewById(R.id.tx1);
tx1.setTypeface(tf);
{% endhighlight %}

Czcionki możemy ściągnąć ze strony [Google Fonts](https://www.google.com/fonts){:target="_blank"}{:rel="nofollow"}.

{:.center}
![fonts](/public/uploads/2014/08/android-custom-fonts.png){:width="50%"}{:alt="Android TextView - Przykład zastosowania różnych fontów"}
Przykład zastosowania różnych czcionek
