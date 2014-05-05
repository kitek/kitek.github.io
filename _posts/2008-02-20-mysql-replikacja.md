---
layout: post
title: 'MySQL replikacja'
category: MySQL
tags: ['konfiguracja replikacji', 'master', 'MySQL', 'replikacja', 'slave']
type: post
description: 'Wprowadzenie i konfiguracja krok po kroku do replikacji baz danych mySQL.'
---
__Replikacja w MySQL__

Baza danych MySQL oferuje asynchroniczną replikację między serwerem nadrzędnym a podrzędnym. Serwer nadrzędny prowadzi dziennik aktualizacji, a serwer podrzędny odczytuje dziennik i kolejno stosuje aktualizacje.

Dziennik aktualizacji (nazywany również dziennikiem binarnym) zawiera pewne informację przeznaczone dla serwera podrzędnego, które umożliwiają mu wykonanie aktualizacji dokładnie tak samo jak zrobił to serwer nadrzędny. Serwer podrzędny łączy się do serwera nadrzędnego w celu odczytania kolejnej porcji danych z dziennika, a następnie na podstawie tych danych wykonuje lokalnie aktualizację. Odbywa się to za pomocą dwóch wątków: wejścia-wyjścia i SQL. Pierwszy z nich odpowiada za pobranie danych i zapisanie ich lokalnie w plikach tymczasowych nazywanych dziennikami przekazywania (relay-log). Drugi wątek natomiast odczytuje dane z lokalnego dziennika przekazywania i wykonuje aktualizację danych.

__Rodzaje replikacji__

W MySQL replikacja może opierać się na trzech sposobach: na poziomie instrukcji, wierszy lub trybu mieszanego. Metoda oparta na instrukcjach polega na tym, że serwer nadrzędny rejestruje każdą instrukcję modyfikującą dane np. INSERT, DELETE, która następnie wykonywana jest przez serwer podrzędny. W metodzie opartej na wierszach rejestrowana jest każda zmiana wiersza tabeli. W trybie mieszanym wykorzystywane są obie metody – serwer nadrzędny decyduje który tryb zastosować dla każdego zapytania.

Początkowo stosowano replikację opartą na wierszach lecz od wersji 5.0 wyparto ją dużo wydajniejszą replikacją na poziomie instrukcji. Zalety replikacji opartej na instrukcjach:

- wymaga przesłania mniejszej ilości danych
- ogranicza rozmiar dziennika aktualizacji
- nie musi uwzględniać formatu wiersza

__Konfiguracja replikacji__

Proces konfiguracji replikacji w MySQL jest względnie nieskomplikowany. Zaczniemy od przygotowania serwera pełniącego rolę nadrzędną (MASTER). W pliku _my.cnf_ (domyślnie znajdującym się w _/etc/mysql/_) ustawiamy następujące opcje:

{% highlight text %}[mysqld]
log-bin = mysql-bin
server-id = 1
max_binlog_size = 20M
binlog-do-db = blog

#bind-address = 127.0.0.1
#skip-networking{% endhighlight %}

Poniżej przedstawiam opis powyższych ustawień:

- __log-bin__ – powoduje włączenie logowania wszystkich zmian i zapisywanie ich do pliku dziennika replikacji o podanej nazwie np. mysql-bin
- __server-id__ – określa unikatowy numer naszego serwera – w naszym przykładzie przyjmiemy, że serwer nadrzędny będzie posiadał server-id = 1, a natomiast serwer podrzędny 2
- __max_binlog_size__ - określa maksymalny rozmiar dziennika replikacji
- __binlog-do-db__ – wskazuje którą bazę danych chcemy replikować, jeżeli nie ustawimy tej opcji będziemy replikować wszystkie bazy znajdujące się na naszym serwerze
- __bind-address, skip-networking__ – opcje, które musimy wyłączyć by możliwe były połączenia do naszego serwera z zewnątrz

Po zapisaniu zmian w naszym _my.cnf_ restartujemy serwer MySQL i wykonujemy następujące polecenia:

{% highlight bash %}mysql -u root -p
SHOW MASTER STATUS\G{% endhighlight %}

Pierwsze polecenie służy do zalogowania nas na naszym serwerze jako użytkownik root (wymagane będzie podanie hasła), drugie natomiast wyświetli nam dane podobne do poniższych:

{% highlight bash %}mysql> SHOW MASTER STATUS\G
*************************** 1. row ***************************
File: mysql-bin.000012
Position: 463666
Binlog_Do_DB: blog
Binlog_Ignore_DB:{% endhighlight %}

- __File__ – wskazuje plik gdzie aktualnie zapisywane są dane dziennika replikacji
- __Position__ – to pozycja w powyższym pliku
- __Binlog_Do_DB__ - replikowana baza danych
- __Binlog_Ignore_DB__ – nazwa bazy której replikować nie chcemy

Dane które nas najbardziej interesują to File i Position: są to współrzędne replikacji, które pozwolą serwerowi podrzędnemu replikować dane właśnie od tego momentu – zapisujemy je sobie ponieważ przydadzą się nam przy konfigurowaniu serwera podrzędnego.

Ostatnim elementem konfiguracji serwera nadrzędnego będzie nadanie uprawnień dla konta użytkownika replikacji:

{% highlight sql %}GRANT REPLICATION SLAVE ON *.*
TO 'uzytkownik-replikacji'@'ip-serwera-nadzędnego'
IDENTIFIED BY 'haslo-uzytkownika-replikacji';{% endhighlight %}

__Konfiguracja serwera podrzędnego (SLAVE):__

W pliku _my.cnf_ ustawiamy:

{% highlight text %}[mysqld]
server-id = 2
replicate-do-db = blog{% endhighlight %}

i wykonujemy następujące polecenia:

{% highlight sql %}CHANGE MASTER TO
MASTER_HOST='ip-serwera-nadrzędnego',
MASTER_USER='użytkownik-replikacji',
MASTER_PASSWORD='haslo-uzytkownika-replikacji',
MASTER_LOG_FILE='nazwa-pliku-odczytana-z-File',
MASTER_LOG_POS='pozycja-odczytana-z-Position';{% endhighlight %}

Kopiujemy pliki naszej bazy z serwera nadrzędnego na serwer podrzędny. Domyślnie w Gentoo znajdują się one w: _/var/lib/mysql/{nazwa_naszej_bazy}_.

Uruchamiamy replikację na serwerze podrzędnym, a następnie sprawdzamy czy wszystko poszło po naszej myśli:

{% highlight text %}START SLAVE;
SHOW SLAVE STATUS\G{% endhighlight %}

wyniki tych operacji powinny być podobne do poniższych:

{% highlight text %}*************************** 1. row ***************************
             Slave_IO_State: Waiting for master to send event
                Master_Host: ip-serwera-nadrzędnego
                Master_User: uzytkownik-replikacji
                Master_Port: 3306
              Connect_Retry: 20
            Master_Log_File: mysql-bin.000012
        Read_Master_Log_Pos: 664823
             Relay_Log_File: benq-relay-bin.000002
              Relay_Log_Pos: 664960
      Relay_Master_Log_File: mysql-bin.000012
           Slave_IO_Running: Yes
          Slave_SQL_Running: Yes
            Replicate_Do_DB: blog
        Replicate_Ignore_DB:
         Replicate_Do_Table:
     Replicate_Ignore_Table:
    Replicate_Wild_Do_Table:
Replicate_Wild_Ignore_Table:
                 Last_Errno: 0
                 Last_Error:
               Skip_Counter: 0
        Exec_Master_Log_Pos: 664823
            Relay_Log_Space: 664960
            Until_Condition: None
             Until_Log_File:
              Until_Log_Pos: 0
         Master_SSL_Allowed: No
         Master_SSL_CA_File:
         Master_SSL_CA_Path:
            Master_SSL_Cert:
          Master_SSL_Cipher:
             Master_SSL_Key:
      Seconds_Behind_Master: 0{% endhighlight %}

Opis wybranych parametrów:

- __Slave_OI_State__ – opis słowny operacji wykonywanych przez serwer podrzędny
- __Master_User__ – nazwa użytkownika replikacji
- __Master_Port__ – port na którym łączymy się z serwerem nadrzędnym
- __Connect_Retry__ – czas wyrażony w sekundach po którym serwer podrzędny spróbuje nawiązać połączenie z serwerem nadrzędnym w przypadku utraty komunikacji
- __Master_Log_File__ – nazwa pliku dziennika replikacji który jest aktualnie przetwarzany
- __Read_Master_Log_Pos__ – aktualna pozycja w dzienniku replikacji
- __Relay_Log_File__ – nazwa pliku dziennika przekazywania
- __Relay_Log_Pos__ – aktualna pozycja w dzienniku przekazywania
- __Slave_OI_Running__ – określa czy wątek wejścia-wyjścia działa
- __Slave_SQL_Running__ – określa czy wątek SQL działa
- __Relay_Log_Space__ – ilość zajętego miejsca przez dziennik przekazywania
- __Seconds_Behind_Master__ – opóźnienie serwera podrzędnego w stosunku do serwera nadrzędnego wyrażone w sekundach

W ten oto sposób skonfigurowaliśmy i uruchomiliśmy replikację – możemy sprawdzić czy wszystko działa zmieniając wpis w bazie danych na serwerze nadrzędnym i obserwować co dzieje się na serwerze podrzędnym.

Linki:

- [MySQL Replication](http://dev.mysql.com/doc/refman/5.0/en/replication.html){:target="_blank"}{:rel="nofollow"}
- [MySQL w Gentoo](http://www.gentoo.org/doc/pl/mysql-howto.xml){:target="_blank"}{:rel="nofollow"}
