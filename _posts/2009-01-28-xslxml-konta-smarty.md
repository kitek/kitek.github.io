---
layout: post
title: 'XSL+XML konta SMARTY'
category: Others 
tags: ['smarty', 'xml', 'xsl', 'smarty vs xsl+xml']
type: post
description: 'XSL+XML jest lepszy niż SMARTY! Sprawdź dlaczego.'
---
### XSL+XML jest lepszy niż SMARTY!
Naturalnym pytaniem wielu z Was jest: __"Dlaczego?"__

W celu potwierdzenia tezy i odpowiedzi na pytanie przedstawię krótkie porównanie obu technologii:

### Czym jest Smarty?
Smarty to system szablonów, jest to oprogramowanie server-side służące rozdzieleniu projektu (aplikacji www) na warstwy [MVC](http://pl.wikipedia.org/wiki/MVC){:target="_blank"}{:rel="nofollow"} tworząc rozdzielenie pomiędzy warstwą prezentacji ("view") a warstwą sterującą ("controller") i warstwą danych ("model").  Sposób działania smarty najprościej wytłumaczyć można jako system który w szablony z odpowiednio przygotowanym HTML’em oraz kodem smarty wstawia odpowiednio przekazane przez PHP dane.

Nie będę tłumaczył oczywistego według mnie sensu dzielenia projektu na wymienione warstwy, można jednak powiedzieć, że podstawowym plusem korzystania z tego typu rozwiązania jest "upiększenie" kodu pozbywając się, zaśmiecającego logikę działania aplikacji, kodu html. Smarty stworzony został miedzy innymi dla tego właśnie celu.

### Czym jest XML?
XML z ang. Extensible Markup Language jest językiem znaczników, który służy do przechowywania, przesyłania informacji zachowujących pewną nie narzuconą strukturę. Pomimo, że nie jest najbardziej optymalnym sposobem wysyłania informacji, pod względem stosunku ilości danych i metadanych,  to w dziedzinie stron WWW jest jednym z niewielu standardów obsługiwanym przez większość przeglądarek.

### Czym jest XSL?
XSL z ang. Extensible Stylesheet Language jest językiem szablonów służącym, najprościej mówiąc, do zamiany danych przesłanych do przeglądarki w postaci XML’a na kod HTML.

{:.center}
![XML + XSL = HTML](/public/uploads/2009/01/screenshot007.jpg)

Kod który jest po stronie serwera odpowiedzialny jest tylko za utworzenie odpowiednich gałęzi z danymi, które następnie mogą zostać wysłane do klienta-przeglądarki, tworząc rozdzielanie warstw podobnie jak w SMARTY.

### No i gdzie ta różnica?
Oprócz stosunkowo oczywistych różnic w implementacji,  czy sposobie używania i działania, obie technologie są stosunkowo łatwe i szybkie do opanowania na podstawowym poziomie pozwalającym na swobodne postawienie małego serwisu. Artykuł postaram się skupić wokół 2 głównych różnic: oszczędności łącza oraz problematyce.

### 1. Oszczędność łącza
Jak wspomniałem SMARTY jest jedynie sposobem na "przemielenie" danych po stroni serwera i  "wklejenie" ich odpowiednio do szablonu, zamienianego w ten sposób na HTML i wysłanego w tej postaci do przeglądarki.  SMARTY de facto nie oszczędza łącza ani trochę.

Translacja XML’a za pomocą szablonu XSL przebiega natomiast __po stronie przeglądarki__, a szablony XSL zostają w jej cache’u. Z jednej strony mamy zawsze ten sam kod html wysyłany do klienta, który zawsze jest dość "ciężki", z drugiej strony zaś, jednorazowe przesłanie szablonu XSL, a następnie wysyłanie samych danych XML’em, co znacznie oszczędza nasze łącze. Tabelka przedstawia przykładową oszczędność na podstawie [mojego profilu](http://www.fotka.pl/profil/pejot){:taget="_blank"}{:rel="nofollow"} na serwisie fotka.pl:

<table style="margin-left:auto;margin-right:auto;border:1px solid black;" border="1">
<tbody>
<tr>
<th>Co?</th>
<th>Rozmiar w kB</th>
</tr>
<tr>
<td>xHTML mojego profilu</td>
<td><strong>68</strong></td>
</tr>
<tr>
<td>XML profilu</td>
<td><strong>18</strong></td>
</tr>
<tr>
<td>XSL profilu</td>
<td><strong>200</strong></td>
</tr>
</tbody>
</table>

Dane przedstawione nie muszą oczywiście odpowiadać każdemu serwisowi, są więc poglądowa lecz rzeczywiste. Na pierwszy rzut oka widać, że rozmiar szablonu XSL prawie trzykrotnie większy niż wysyłanego kodu HTML, jednak same dane zawarte w formie XML są znowu od HTML’a ponad trzykrotnie mniejsze. Należy zastanowić się ile możemy zyskać?

Wykres przedstawia różnicę ilości danych wysyłanych za pomocą zwykłego HTML i XML+XSL w funkcji ilości zapytań. Widać, że w tym konkretnym przypadku już po czterech zapytaniach wyrównujemy różnicę, która wynika z potrzeby zaciągnięcia dość dużych szablonów XSL. Ważną uwagą jest to, że oszczędność nie jest prostolinijna. Po zmianie szablonu, przeglądarka zmuszona zostaje do ponownego jego pobrania co powoduje widoczny na środku wykresu spadek oszczędności.

{:.center}
![Wykres oszczędności łącza przy wykorzystaniu XML + XSL](/public/uploads/2009/01/screenshot009.jpg)

Praktyka pokazuje, że pomimo stosunkowo dużych szablonów oraz stosunkowo częstych zmian szablonów ( raz dziennie ), stosunek ilości danych wysyłanych HTML’em oraz XML’em, czyli oszczędność jest po prostu __olbrzymia__.

### 2. Problematyka
SMARTY jest silnikiem, który udostępnia dość dużo dodatkowych narzędzi pomocnych w tworzeniu aplikacji, wszelkie problemy kończą się na wysłaniu treści do przeglądarki, wszystkie mi znajome obsługują HTML bez większych problemów :).  Z XSL’em jest nieco większy problem:

Po pierwsze nie wszystkie przeglądarki obsługują XSLT, a niektóre obsługują. ale błędnie. Przykładem przeglądarki nie obsługującej XSLT jest Ie5, ale nie tylko. Chcą współpracować z najpopularniejszą wyszukiwarką w polskim internecie – google oraz jej botem musimy już po stronie serwera przeprowadzać XSLT. Googlebot jest tylko jednym z przykładów klientów, którym trzeba “dać” zwykły HTML, innymi sa na przykład urządzenia mobilne, którym nie dość, że trzeba wysyłać HTML to jeszcze z innym doctype. Brzmi dość trudno do opanowania, ale wcale takie być nie musi. Rozpoznając User-Agenty łączących się z naszym serwerem klientów można ze sporą dokładnością wybrać sposób wysyłania danych.

Nie tylko brak obsługi XSLT może wymuszać na nas server-side’owe XSLT. Przeglądarka Opera, z jakiegoś powodu, podczas korzystania z tej technologii nie wysyła danych za pomocą POST’a, jest więc następnym klientem, któremu trzeba parsować treść,chociażby tylko na stronach posiadających formularze.

Przeglądarkę łatwo można zmusić do odświeżenia cache z zawartym HTML’em. Szablony XSL są dość problematyczne w odświeżeniu. Różne przeglądarki różnie reagują na nagłówek ważności pliku, jednak w efekcie końcowym nasi klienci, czy też nasi użytkownicy narzekać będą na to, że mają starą treść z szablonów. Z pomocą przychodzi nam wersjonowanie plików, czyli oszukiwanie przeglądarki, co rozwiązuje 99% problemów, bo zawsze znajdzie sie jakaś zbłąkana owieczka (przeglądarka z epoki kamienia łupanego), która nie poradzi sobie z zadaniem. W wersji uproszczonej wersjonowanie szablonów polega na wysyłaniu w XML’u podpiętych urli szablonów z kolejnymi numerami/hashami np.:

{% highlight xml %}<?xml-stylesheet type=”text/xsl” href=”/xsl/strona_glowna.123.xsl”?>{% endhighlight %}

Przy zapytaniu o plik w danym katalogu musimy skonfigurować serwer w taki sposób aby wycinał ".123" i wysyłał plik “/xsl/strona_glowna.xsl”. Jest to łatwe do osiągnięcia.

### Podsumowanie
Pomimo zawartych w artykule minusów technologii XSL+XML względem SMARTY szczerze zalecam jednak stosowanie tej pierwszej, co wynika z mojej praktyki zawodowej. Oszczędność łącza to nic innego jak oszczędność pieniędzy. Im więcej użytkowników wchodzi na nasz serwis tym większa oszczędność łącza, a więc pieniędzy, dzięki której stać nas na dodatkowe inwestycje związane z naszym serwisem. Pamiętać należy o tym, że oszczędność jest jednak nieprostolinijna, lecz licząc sumarycznie i tak jest olbrzymia.

Autor: Piotr Jasiulewicz
