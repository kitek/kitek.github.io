---
layout: post
title: IE6 && javascript:void(null) && img.src
category: JavaScript
tags: ['IE6', 'IE6 bug', 'img.src', 'javascript', 'podmiana source', 'void(null)']
type: post
description: 'Opis buga w IE6 polegającym na tym, że źródło obrazka nie podmieniało się poprawnie przy zastosowaniu prostego kodu JavaScript'
---
__Podmiana source’a obrazka pod IE6 z href="javascript:void(null);"__

Ostatnio spotkałem się z błędem przeglądarki Internet Explorer 6 polegającym na tym, że źródło obrazka nie podmieniało się poprawnie przy zastosowaniu prostego kodu JavaScript.

Jak się później okazało diabeł tkwi w szczegółach i wszystkiego winne były linki, które na atrybucie __href__ posiadały wartości __"javascript:void(null)"__, a do zdarzenia __onclick__ podczepione były funkcje JS rotujące obrazki.

Mój skrypt miał za zadanie podmieniać obrazki po naciśnięciu linka "poprzedni" lub "następny".

Kod JavaScript’u wyglądał podobnie do poniższego:

{% highlight javascript %}
var pozycja = 0;
var obrazki = new Array();
obrazki[0] = 'obrazek1.jpg';
obrazki[1] = 'obrazek2.jpg';
obrazki[2] = 'obrazek3.jpg';
obrazki[3] = 'obrazek4.jpg';

function next() {
	if(pozycja+1 > obrazki.length-1) {
		pozycja = 0;
	} else {
		pozycja++;
	}
	showImage();
}

function prev() {
	if(pozycja-1 < 0) {
		pozycja = obrazki.length-1;
	} else {
		pozycja--;
	}
	showImage();
}

function showImage() {
	// jQuery
	$('#obrazek').attr('src',obrazki[pozycja]);
	// no-framework JS
	obrazek = getElementById('obrazek');
	obrazek.src = obrazki[pozycja];
}
{% endhighlight %}
Kod HTML:

{% highlight html %}
<a href="javascript:void(null);" onclick="prev();">poprzedni</a>
<img id="obrazek" src="obrazek1.jpg" />
<a href="javascript:void(null);" onclick="next();">następny</a>
{% endhighlight %}
Rozwiązanie:

- zastosowanie href="#" zamiast "javascript:void(null);"
- zastosowanie href="javascript:mojaFunkcja();" zamiast "javascript:void(null);"
