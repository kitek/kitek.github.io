---
layout: post
title: JSLint will hurt your feelings.
category: JavaScript 
tags: ode quality tool Douglas Crockford jslint
---
[JSLint](http://www.jslint.com/lint.html){:target="_blank"} jest programem sprawdzający kod JavaScript pod kątem kilkunastu zasad dobrego programowania. Jeżeli programujesz lub robisz review w kodzie JavaScript to narzędzie jest dla Ciebie obowiązkowe.

Do kilku podstawowych zasad dobrego pisania kodu JavaScript wg. Douglas’a Crockford’a należy:

- definiowanie zmiennych w jednym miejscu (np. na początku funkcji) przy użyciu tylko jednej dyrektywy var (np. var zmienna1, zmienna2, zmienna3;)
- stawianie średników wszędzie gdzie są one wymagane
- obowiązkowe stosowanie nawiasów {} w konstrukcjach if, while, do, for
- w pętlach for in sprawdzanie własności przez zastosowanie metody hasOwnProperty
- unikanie funkcji eval
- stosowanie w porównaniach === zamiast ==

O wszystkich zasadach można przeczytać na stronie [jslint.com](http://www.jslint.com/lint.html){:target="_blank"}. Polecam również obejrzenie filmu [Crockford on JavaScript – Section 8: Programming Style & Your Brain](http://www.youtube.com/watch?v=taaEzHI9xyY){:target="_blank"}.

Z JSLint’a możemy skorzystać online wklejając nasz kod na stronie jednak dużo wygodniejsze będzie zainstalowanie odpowiedniego plugin’a do naszego IDE. W moim przypadku jest to NetBeans (Tools -> Plugins -> Available plugins -> Search: "JSLint"). Gdy wciśniemy CTRL+6 pojawi nam się panel "Task" z wszystkimi błędami znalezionymi (w otwartych plikach) przez JSLint'a.
