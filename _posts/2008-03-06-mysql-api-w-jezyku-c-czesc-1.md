---
layout: post
title: MySQL API w języku C – część 1
category: 'C / C++ / C#'
tags: ['C / C++ / C#', 'GCC', 'MySQL C API']
type: post
description: 'Programowanie w C z wykorzystaniem MySQL API'
---
__Programowanie w C z wykorzystaniem MySQL API__

W kilku odcinkach chciałbym zaprezentować możliwość użycia bazy danych MySQL w języku C na platformie Linux.

Co będzie nam do tego potrzebne:

- podstawowa znajomość języka C
- zainstalowana lokalnie baza danych MySQL

__Szkielet programu__

Poniżej przestawiam model wyjściowy dla naszych przykładowych programów:

{% highlight c++ %}
#include <stdio.h>
#include "mysql/mysql.h"

int main() {
    MYSQL mysql;

    return 1;
}
{% endhighlight %}

Do standardowej biblioteki _stdio.h_ dołączamy również _mysql.h_ stanowiącą podstawę obsługi MySQL w C. Jest ona dostarczana wraz z serwerem MySQL.

__Kompilowanie i uruchamianie__

Wszystkie napisane przez nas programy wykorzystujące bibliotekę mysql.h muszą być kompilowane w specjalny sposób:

{% highlight bash %}gcc my.c -o my -I/usr/local/include -L/usr/local/lib/mysql -lmysqlclient{% endhighlight %}

- __gcc__ – kompilator (tak naprawdę jest to zestaw kilku kompilatorów – więcej..)
- __my.c__ – program w C
- __o my__ – nazwa pliku wynikowego (jest to parametr opcjonalny, jeżeli go nie podamy kompilator zapisze nasz program pod nazwą domyślną np. a.out)
- __I/usr/local/include__ – wskazuje jaki katalog ma zostać uwzględniony w poszukiwaniu plików nagłówkowych
- __L/usr/local/lib/mysql__ -lmysqlclient – wskazuje jakie katalogi/pliki mają zostać podlinkowane podczas kompilacji programu

__Inicjalizacja MySQL API__

W tym momencie wiemy już jaki wstępny model będą miały nasze programy, a także jak je kompilować – przystąpmy więc do napisania pierwszego prostego programu sprawdzającego czy w naszym środowisku możemy wykorzystywać API MySQL.

{% highlight c++ %}
#include <stdio.h>
#include "mysql/mysql.h"

int main() {
    MYSQL mysql;

    if(mysql_init(&mysql)==NULL) {
        printf("\nBlad inicjalizacji\n");
    } else {
        printf("\nWyglada ze jest ok ;)\n");
    }

    mysql_close(&mysql);
    return 1;
}
{% endhighlight %}

W powyższym programie inicjalizujemy MySQL API – zmienne globalne, obsługę wątków itp. Warto wspomnieć w tym miejscu, że po ostatnim nawiasie klamrowym musimy przejść dodatkowo do następnej linii w przeciwnym razie otrzymamy ostrzeżenie od kompilatora: warning: _no newline at end of file_.

__Tworzenie połączenia z bazą MySQL__

W naszym drugim przykładzie wykorzystamy trzy nowe funkcje:

- __mysql_real_connect__ – nawiązuje połączenie z bazą
- __mysql_get_client_info__ – pobiera wersję zainstalowanego klienta
- __mysql_get_server_info__ – pobiera wersję serwera

{% highlight c++ %}
#include <stdio.h>
#include "mysql/mysql.h"

int main() {
    MYSQL mysql;

    if(mysql_init(&mysql)==NULL) {
        printf("\nBlad inicjalizacji\n");
        return 0;
    }

    mysql_real_connect(&mysql,"localhost","user","pass","dbname",0,NULL,0);

    printf("Wersja klienta: %s",mysql_get_client_info());
    printf("\nWersja serwera: %s",mysql_get_server_info(&mysql));
    mysql_close(&mysql);
    return 1;
}
{% endhighlight %}

W ten sposób udało nam się połączyć i zalogować z bazą danych. Do tego celu wykorzystaliśmy serwer działający na localhost-cie, użytkownika o loginie _user_, hasła _pass_ i bazę danych o nazwie _dbname_.

Linki:

- [MySQL C API](http://dev.mysql.com/doc/refman/5.0/en/c.html){:target="_blank"}{:rel="nofollow"}
