---
layout: post
title: Google Webmaster Tools
category: 'SEO'
tags: ['Google Webmaster Tools', 'Narzędzia Google dla webmasterów', 'SEO', 'wordpress', 'XML Sitemaps Generator']
type: post
description: 'Narzędzia Google dla webmasterów - przedstawienie narzędzia jakim jest Google Webmaster Tools i garść przydatnych wskazówek SEO.'
---
__Narzędzia Google dla webmasterów__

Google [Webmaster Tools](http://www.google.com/webmasters/sitemaps/?hl=pl){:target="_blank"}{:rel="nofollow"} jest pakietem narzędzi dla osób które chcą kontrolować stan za indeksowania swojej witryny przez wyszukiwarkę Google. Do głównych funkcjonalności tej usługi można zaliczyć m.in:

- sprawdzanie czy nasze witryny są poprawnie uwzględniane w indeksie Google, kiedy ostatni raz miała miejsce indeksacja naszej strony i czy wystąpiły jakieś błędy
- statystyki zapytań które powodują wyświetlenie naszej witryny w wyszukiwarce Google, informacje o tym jakie dane znalazł [googlebot](http://pl.wikipedia.org/wiki/Googlebot){:target="_blank"}{:rel="nofollow"} na naszej stronie
- pozycję w rankingu Page Rank, strony z linkami prowadzącymi do naszej witryny, mapę naszej strony widzianej przez Google

__Zaczynamy zabawę__

Do skorzystania z Narzędzi Google dla webmasterów niezbędne jest posiadanie gmail’a. Jeżeli takiego konta jeszcze nie mamy musimy założyć je w [tym miejscu](http://gmail.com/){:target="_blank"}{:rel="nofollow"}.
Kolejnym krokiem będzie dodanie omawianej usługi do naszego konta gmail. Otwieramy stronę: [https://www.google.com/webmasters/tools/](https://www.google.com/webmasters/tools/){:target="_blank"}{:rel="nofollow"}, jeżeli nie jesteśmy aktualnie zalogowani to zostaniemy poproszeni o login i hasło.
Ostatnim krokiem będzie dodanie i zweryfikowanie naszej domeny. Weryfikacja jest możliwa na dwa sposoby: umieszczenie specjalnego pliku w głównym katalogu naszej witryny lub modyfikacja sekcji head w stronie głównej naszego portalu.

To w sumie już wszystko – od tej chwili możemy cieszyć się statystykami indeksowania naszej witryny przez Google.

__Mapa strony__

Mapą naszej witryny jest plik [XML’a](http://www.kitek.pl/sitemap.xml) zawierający wszystkie linki z naszego portalu. Tak stworzona mapa bardzo pomaga w indeksowaniu informacji przez wyszukiwarki. Oczywiście stworzony plik mapy musi zostać zapisany w pewnym standardzie – jednak posiadacze WordPress’a nie muszą zaprzątać sobie tym głowy ponieważ istnieje wtyczka o nazwie [XML Sitemaps Generator](http://www.arnebrachhold.de/projects/wordpress-plugins/google-xml-sitemaps-generator/){:target="_blank"}{:rel="nofollow"} która całą tę pracę wykona za nas.

__Instalacja wtyczki XML Sitemaps Generator dla WordPress__

Zaczynamy od ściągnięcia potrzebnych plików ze strony [http://www.arnebrachhold.de/](http://www.arnebrachhold.de/projects/wordpress-plugins/google-xml-sitemaps-generator/){:target="_blank"}{:rel="nofollow"}. Następnie wypakowujemy je do _/wp-content/plugins/_, po czym w głównym katalogu naszej strony([kitek.pl/sitemap.xml](http://kitek.pl/sitemap.xml)) tworzymy pliki o nazwach: sitemap.xml, sitemap.xml.gz i nadajemy im prawa zapisu (np. chmod 666).

Uruchamiamy tworzenie naszej mapy strony poprzez opcję znajdującą się w: "Opcje" -> "XML Sitemap" w panelu administracyjnym WordPress’a.

Jeżeli nasza nowo dodana wtyczka nie jest w języku polskim – sprawdzamy ustawienia w pliku _wp-config.php_:

{% highlight php %}
<?php
// Twój WordPress jest standardowo nastawiony na jezyk polski!
define ('WPLANG', 'pl');{% endhighlight %}

W moim przypadku mam ustawione 'pl' – więc pliki lokalizacji pluginu również muszą posiadać nazwy: _sitemap-pl.mo_ i _sitemap-pl.po_

Tak przygotowaną mapę naszej witryny możemy dodać w "Narzędziach Google dla webmasterów" w sekcji "Mapa strony".

Linki:

- [Narzędzia Google dla webmasterów](https://www.google.com/webmasters/tools/){:target="_blank"}{:rel="nofollow"}
- [XML Sitemaps Generator](http://www.arnebrachhold.de/projects/wordpress-plugins/google-xml-sitemaps-generator/){:target="_blank"}{:rel="nofollow"}
- [WordPress](http://wordpress.org/){:target="_blank"}{:rel="nofollow"}
- [Moja mapa strony](http://kitek.pl/sitemap.xml)

