---
layout: post
title: 'Google ajax libs. Czy warto?'
category: Others 
tags: ['hosted js', 'jquery from google', 'cdn', 'ajax libs api']
type: post
description: 'Czy warto wykorzystywać CDN z bibliotekami JavaScriptu Google?'
---
Od jakiegoś czasu Google pozawala na serwowanie od siebie coraz popularniejszych frameworków javascriptowych za pomocą [Ajax Libs API](https://developers.google.com/speed/libraries/){:target="_blank"}{:rel="nofollow"}. Do dyspozycji mamy sporo ciekawych pozycji:

{:.center}
![Ajax Libs API](/public/uploads/2009/02/screenshot013.jpg)

Z regulaminu wynika, że nawet gdyby nasza-klasa.pl zaciągała od nich skrypty i tak by się nie czepiali ;-). 

W mojej głowie rodzi się jednak jedno pytanie:

## Czy warto?
Odpowiedź na to pytanie nie jest do końca oczywista.

Z jednej strony oszczędzamy sporo łącza, w końcu takie frameworki jak jquery-ui są dość ciężkie i zrzucenie to na łącza Google może zaoszczędzić nam trochę gorsza. Popularność usług Google są jednak jednym z ich minusów ponieważ nie zawsze nadążają za rosnącym popytem i w efekcie końcowym przy testach wydajnościowych serwisu okazuje się, że często skrypty zaciągane z API są jedną z najdłużej zciąganych przez użytkownika elementów strony.

To jest oczywiście tylko przykład badany w konkretnym środowisku testowym i każdy musi niestety sam przetestować jak to będzie wyglądało u niego.

## Pod uwagę trzeba wziąć takie parametry jak:
- Jak szybkie są nasze serwery? Może się okazać, że na ogół szybka usługa Google nie jest tak szybka jak nasze własne zaplecze i zależy nam na user-expirience na pierwszym miejscu.
- Ile możemy zaoszczędzić? Serwując pliki rzadko (mało UU), kiedy nasza strona nie osiągnęła jeszcze odpowiedniej popularności ciężko tak naprawdę coś testować na dużych obciążeniach.

Po odpowiedzeniu sobie na te pytania można brać pod uwagę użycie API, w moim skromnym zdaniu, serwisy niszowe, nie majace farm serwerów powinny w zasadzie wszystkie korzystać z darmowej usługi Google :-)

Autor: Piotr Jasiulewicz
