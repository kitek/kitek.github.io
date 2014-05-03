---
layout: post
title: 'Node.js + Memcached = ciekawa przypadłość'
category: NodeJS
tags: ['memcached', 'node-memcached']
type: post
description: 'Ciekawa przypadłość przy wykorzystaniu bilbioteki memchaced w NodeJS'
---
Korzystając z biblioteki [node-memcached](https://github.com/3rd-Eden/node-memcached){:target="_blank"} natrafiłem na "ficzer" polegający na tym, że jeżeli nie ustawimy parametru “timeout” to biblioteka w przypadku “idle” sama będzie zamykała połączenie. Jest to szczególnie wkurzające gdy myślimy, że tworzone jest stałe połączenie z serwerem Memcached.

{:.center}
![Sprite Cow](/public/uploads/2011/10/2011-10-18_1434.png)

Potencjalnym rozwiązaniem tego problemu jest ustawienie timeout : 0
