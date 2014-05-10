---
layout: post
title: 'Eclipse dark theme'
category: Tools
tags: ['eclipse','dark theme','logcat','android eclipse','MoonRise','UI Theme']
type: post
description: 'Krótki tutorial jak zainstalować i ustawić w Eclipse ciemny theme wraz z dodatkowymi wskazówkami i usprawnieniami.'
---
Od zawsze byłem zwolenikiem ciemnego tła i jasnego tekstu w IDE. Mam wrażenie, że dzięki temu oczy męczą się wolniej i pracuje się przyjemniej. W niniejszym poście chciałbym polecić [MoonRise UI Theme](https://github.com/guari/eclipse-ui-theme){:target="_blank"}{:rel="nofollow"} zmieniające kolorystycznie całego Eclipse'a.

__Instalacja__

Do poprawnej instalacji i działania wymagany jest [Eclipse 4.2+](https://www.eclipse.org/downloads/){:target="_blank"}{:rel="nofollow"}. Istnieją [trzy sposoby instalacji](https://github.com/guari/eclipse-ui-theme#installation){:target="_blank"}{:rel="nofollow"} motywu, wg. mnie najłatwiejszym jest opcja ``Install New Software...`` z menu ``Help``.

{:.center}
![Eclipse instalacja nowego oprogramowania](/public/uploads/2014/05/eclipse_install_new_software.jpg)

{% highlight text %}https://raw.github.com/guari/eclipse-ui-theme/master/com.github.eclipseuitheme.themes.updatesite{% endhighlight %}
W nowym okienku wpisujemy powyższy URL, zaznaczamy checkbox przy ``Eclipse UI themes``, wciskamy ``Next``, ``Finish``, a następnie restartujemy Eclipse'a. Po uruchomieniu programu wchodzimy w preferencje, a następnie ``Window > Preferences > General > Appearance``. Z listy wybieramy ``MoonRise (standalone)``.

{:.center}
![Eclipse apperance](/public/uploads/2014/05/eclipse_apperance.png)

Po ponownym restarcie Eclipse'a powinien zostać zastosowany nowy szablon kolorystyczny.

__Schemat kolorów dla tekstu/składni kodu__

Do nowego ciemnego theme polecam zastosować odpowiedni schemat kolorów tekstów. Do tego potrzebne będzie zainstalowanie [The Eclipse Color Theme Plugin](http://eclipsecolorthemes.org/?view=plugin){:target="_blank"}{:rel="nofollow"}. Postępujemy podobnie jak przy poprzedniej instalacji podająć URL: ``http://eclipse-color-theme.github.io/update/``. Po zainstalowaniu pluginu ściągamy motyw [RainbowDrops.xml](https://github.com/guari/eclipse-ui-theme/blob/master/com.github.eclipseuitheme.themes.plugin/bin/color-scheme/RainbowDrops.xml?raw=true){:target="_blank"}{:rel="nofollow"} i importujemy go na stronie ustawień: ``Window > Preferences > General > Appearance > Color Theme`` (lub wybieramy inny odpowiadający naszym gustom).

__Ulepszenia__

Wykorzystując powyżej omówione schematy kolorystyczne zauważyłem kilka elementów wymagających poprawy:

- Zmodyfikowane pliki na liście Package Explorer'a (Git)

{:.center}
![Eclipse modified files in Package Explorer](/public/uploads/2014/05/eclipse_modified_files_color.jpg){:width="80%"}

- LogCat (Android)

{:.center}
![Eclipse logcat colors](/public/uploads/2014/05/eclipse_logcat_colors.jpg){:width="80%"}



