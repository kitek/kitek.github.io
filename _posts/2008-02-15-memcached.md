---
layout: post
title: Memcached
category: Others
tags: cache kesz memcached optymalizacja PHP
type: post
---
Memcached jest systemem keszowania obiektów opracowanym przez [Danga Interactive](http://www.danga.com/){:target="_blank"}. Dzięki niemu możemy przechować w pamięci dowolne dane: zaczynając od zwykłych liczb, ciągów znaków a kończąc na obiektach. Dane umieszczane są w pamięci współdzielonej dostępnej dla innych programów.

Memcached jest bardzo szybki i wydajny – działa jako aplikacja rozproszona, typu klient-serwer. Jego głównym zadaniem jest przyspieszenie działania serwisu internetowego poprzez odciążenie bazy danych. Sam system jest bardzo popularny i używany np. w takich portalach jak: YouTube, LiveJournal, SourceForge, GameFAQs, Facebook, Digg, Fotolog, BoardGameGeek, Kayak, Fotka.pl.

**Instalacja memcached w systemie Gentoo Linux**

Pierwsza i podstawowa rzecz jaka będzie nam niezbędna to w kompilowana obsługa PEAR’a w naszego PHP.

{% highlight bash %}
brama ~ # pear version
PEAR Version: 1.6.2
PHP Version: 5.2.5-p20080206-pl0-gentoo
Zend Engine Version: 2.2.0
Running on: Linux brama 2.6.23-gentoo-r6 #1 SMP
{% endhighlight %}

Jeżeli zamiast powyższego komunikatu zobaczymy: -bash: pear: command not found – oznacza to że PEAR’a nie mamy i musimy go skompilować. Do poprawnego zainstalowania wymagane są następujące biblioteki: cli pcre xml zlib. Dodajemy je zatem do flag USE w pliku /etc/make.conf i uruchamiamy kompilacje PHP:

{% highlight bash %}emerge dev-lang/php{% endhighlight %}

Gdy proces instalacji się zakończy instalujemy PEAR’a:

{% highlight bash %}emerge dev-php/PEAR-PEAR{% endhighlight %}

Świetnie! Mamy już dobrze przygotowane środowisko pod obsługę memcache’a. Następnym krokiem będzie zainstalowanie modułu do obsługi memcached w środowisku PHP:

{% highlight bash %}pecl install memcache{% endhighlight %}

Po zakończeniu tego kroku włączamy obsługę dopiero co zainstalowanego modułu poprzez dodanie następującej linii:

{% highlight bash %}extension=memcache.so{% endhighlight %}

w pliku /etc/php/apache2-php5/php.ini w sekcji "Dynamic Extensions".

Na sam koniec zostawiłem najlepsze czyli instalacja samego memcached. Równie prosto jak poprzednim razem instalujemy nasz program wydając następujące polecenie:

{% highlight bash %}emerge net-misc/memcached{% endhighlight %}

Po zakończeniu instalacji nie pozostaje nam nic innego jak zrestartowanie apache’a.

**Konfiguracja memcached**

Sam program nie ma żadnego pliku konfiguracyjnego i wszystkie ustawienia musimy podać jako parametry uruchomieniowe:

{% highlight bash %}memcached -d -m 64 -p 11211{% endhighlight %}

Oto niektóre z nich:

- d – uruchamia program jako deamon
- m {liczba} – ustala maksymalną przestrzeń pamięci zdefiniowaną w MB
- p {liczba} – na jakim porcie ma pracować memcached
- u {nazwa} – pod nazwą jakiego użytkownika ma być identyfikowany proces memcached (używane tylko w przypadkach uruchamiania memcached z poziomu root’a)

**Implementacja memcached w PHP**

Poniżej została przedstawiona bardzo prosta klasa do obsługi memcache w PHP:

{% highlight php %}
<?php

class kesz {
  private $host="localhost";
  private $port="11211";
  private $mem;	

  /**
  * Konstruktor naszej klasy
  * tworzymy połączenie do naszego memcache
  */
   function __construct() {
      $this->mem = new Memcache;
      $this->mem->connect($this->host,$this->port) or
      die("Brak polaczenia do memcache.");
   }

   /**
   * Metoda odczytująca obiekty zapisane w memcache
   *
   * @param string $nazwa
   * @return unknown
   */
   function get($nazwa) {
      return $this->mem->get($nazwa);
   }

   /**
  * Metoda zapisująca dane do memcache
  *
  * @param string $nazwa - identyfikator
  * @param unknown_type $data - dane które checemy skeszować
  * @param int $czas - czas jaki chcemy trzymać dane w pamięci
  */
   function set($nazwa,&$data,$czas=60) {
      $this->mem->set($nazwa,$data,$czas);
   }

   /**
  * Metoda usuwająca z pamięci kesza o podanym identyfikatorze
  *
  * @param string $nazwa
  */
   function del($nazwa) {
      $this->mem->delete($nazwa);
   }

   /**
  * Metoda usuwająca wszystkie zapisane w memcache dane
  *
  */
  function delall() {
     $this->mem->flush();
   }
}
{% endhighlight %}

Przykład użycia:

{% highlight php %}
<?php
$kesz = new kesz();

$obiekt = new stdClass;
$obiekt->imie="Jasiek";
$obiekt->wiek=12;

$kesz->set("moje_dane",$obiekt);
$z_memcache = $kesz->get("moje_dane");
var_dump($z_memcache);
{% endhighlight %}

**Linki**

- [PHP Memcache Manual](http://pl2.php.net/manual/pl/ref.memcache.php){:target="_blank"}
- [Memcached](http://www.danga.com/memcached/){:target="_blank"}
- [PEAR](http://pear.php.net/){:target="_blank"}
