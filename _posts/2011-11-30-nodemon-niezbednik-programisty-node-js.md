---
layout: post
title: Nodemon – niezbędnik programisty Node.js
category: JavaScript
tags: monitor node nodemon
type: post
description: 'Nodemon - opis programu wspomagającego tworzenie na platformie NodeJS'
---
Jeżeli dopiero co zaczynasz przygodę z JavaScriptem server-side to prędzej czy później zauważysz, że każda zmiana w twoim kodzie wymaga restartowania całej pisanej aplikacji. Jest to bardzo wkurzające gdy jesteś przyzwyczajony do wciskania F5 po każdej zmianie (wiem, wiem, zboczenie z PHP/HTML). Inny przykład to praca z wykorzystaniem biblioteki Socket.io – raz uruchomiona aplikacja powinna “sama” restartować się po zmianach w kodzie. W rzeczywistości tak nie jest, ale nic straconego!

Z pomocą przychodzi programik o nazwie **nodemon**. Instalacja programu jest banalna (pod warunkiem, że wcześniej mamy zainstalowane już Node.js + npm) i wymaga od nas wpisania w konsoli: **npm install nodemon** lub jeżeli posiadamy uprawnienia root’a: **npm install nodemon -g**.

Od teraz nie musimy troszczyć się o restartowanie naszej aplikacji po każdej zmianie, zrobi to za nas nodemon. Wystarczy odpalić nasz główny plik poleceniem: **nodemon nazwaPliku.js**

Więcej informacji:

- [http://github.com/remy/nodemon/](http://github.com/remy/nodemon/){:target="_blank"}
- [https://npmjs.org/package/nodemon](https://npmjs.org/package/nodemon){:target="_blank"}
