---
layout: post
title: HP t5720 montaż karty Compact Flash
category: Others
tags: cf 'compact flash' hdd 'hp t5720' t5720
type: post
description: 'Montaż karty CF w terminalu HP t5720'
---
W końcu znalazłem odrobinę czasu by zabrać się za mój terminalek i zakupioną wcześniej kartę CF zamontować wewnątrz obudowy. Zacznijmy pierw od przedstawienia samego pudełka.

Specyfikacja sprzętu:

- procesor: AMD Geode NX 1500 1 GHz
- pamięć RAM: 512 RAM DDR, 333, CL 2.5
- hdd: DYSK 512 MB FLASH Apacer na kości Samsunga

Jak widać maszynka dość żwawa. Szczególnie gdy przeznaczona jako zabawka do:

- transmission
- serwer samba
- serwer developerski (apache, php, python, mysql, memcached, nodejs, git..)

Poniżej zamieszczam zdjęcia z całej operacji:

<div class="thumb">
	<a href="/public/uploads/2011/11/HP-t5720-widok-na-bebechy.jpg">
		<img src="/public/uploads/2011/11/HP-t5720-widok-na-bebechy-thumb.jpg" alt="HP t5720 widok na bebechy" title="HP t5720 widok na bebechy"/>
	</a>
</div>
<div class="thumb">
	<a href="/public/uploads/2011/11/HP-t5720-wnetrze.jpg">
		<img src="/public/uploads/2011/11/HP-t5720-wnetrze-thumb.jpg" alt="HP t5720 wnętrze" title="HP t5720 wnętrze"/>
	</a>
</div>
<div class="thumb">
	<a href="/public/uploads/2011/11/HP-t5720-radiatory-RAM-kontroler-dysku.jpg">
		<img src="/public/uploads/2011/11/HP-t5720-radiatory-RAM-kontroler-dysku-thumb.jpg" alt="HP t5720 radiatory, pamięć RAM, kontroler dysku" title="HP t5720 radiatory, pamięć RAM, kontroler dysku"/>
	</a>
</div>
<div class="thumb">
	<a href="/public/uploads/2011/11/HP-t5720-adapter-i-karta-cf.jpg">
		<img src="/public/uploads/2011/11/HP-t5720-adapter-i-karta-cf-thumb.jpg" alt="Adapter CF i karta CF" title="Adapter CF i karta CF"/>
	</a>
</div>
<div class="thumb">
	<a href="/public/uploads/2011/11/HP-t5720-po-montazu-karty-cf.jpg">
		<img src="/public/uploads/2011/11/HP-t5720-po-montazu-karty-cf-thumb.jpg" alt="HP t5720 po montażu karty CF" title="HP t5720 po montażu karty CF"/>
	</a>
</div>
<div class="thumb">
	<a href="/public/uploads/2011/11/HP-t5720-kabelek-do-karty-cf.jpg">
		<img src="/public/uploads/2011/11/HP-t5720-kabelek-do-karty-cf-thumb.jpg" alt="HP t5720 po montażu karty CF" title="HP t5720 po montażu karty CF"/>
	</a>
</div><div class="clear"></div>

Wynik testu przeprowadzonego przez hdparm:

{% highlight bash %}
sudo hdparm -t /dev/sda
/dev/sda:
 Timing buffered disk reads:  52 MB in  3.02 seconds =  17.19 MB/sec
{% endhighlight %}

Generalnie montaż oceniam na bardzo prosty i szybki. Dużym ułatwieniem jest skorzystanie z pistoletu z grzałką i klejem.
