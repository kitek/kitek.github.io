---
layout: post
title: 'Sublime Text 2 - snippets'
category: Tools
tags: ['sublime text 2','sublime','snippets','snipety','sublime scope','tabTrigger']
type: post
description: 'Przewodnik po tym jak tworzyć własne snippety dla Sublime Text 2.'
---
Jak wspomniałem w moim [poprzednim poście](/2012/10/05/sublimeText2/) Sublime Text 2 to pozornie prosty edytor plików tekstowych. Pozory mogą mylić. Poniżej przedstawiam potężne narzędzie jakim są "snippet'y" wbudowane w omawiany edytorek.

Snippets w Sublime Text 2 to proste skrypty uruchamiane po wpisaniu określonych znaków i wciśnięciu klawisza [TAB].
Umożliwiają wstawienie w miejscu gdzie aktualnie znajduje się kursor zdefiniowanego wcześniej fragmentu tekstu (np.: szablon pustej funkcji / metody, konstrukcja programistyczna, fragment HTML'a). Dodatkowo pozwalają na podanie miejsc w tekście po których będziemy mogli się poruszać wciskając przycik tabulatora.

__Tworzenie nowych Snippet'ów__

Tworzenie rozpoczynamy wybierając z menu _"Tools"_ -> _"New Snippet..."_. Po kliknięciu zostanie utworzony nowy dokument o podobnej treści:

{% highlight html %}<snippet>
<content><![CDATA[
Hello, ${1:this} is a ${2:snippet}.
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>
{% endhighlight %}

Sekcja _"content"_ reprezentuje tekst, który zostatnie wstawiony w wybranym przez nas miejscu. Należy pamiętać, że wszelkie białe znaki również zostaną umieszczone. Dynamiczne parametry określamy przez dyrektywy ``{$numerek}`` (np. ``${1}, ${2}``). W przypadku gdy chcemy posiadać wartość domyślną argumentu wstawiamy ``${1:Wartość domyślna}``.

Dodatkowo możemy zdefiniować tzw. _tabTrigger_ czyli kombinację znaków + [TAB] uruchamiającą nasz snippet (np.: ``<tabTrigger>div</tabTrigger>``).

Ostatnią opcją jest _scope_, który określa w jakiego typu dokumentach zastosowany może zostać snippet:

- ActionScript: source.actionscript.2
- AppleScript: source.applescript
- ASP: source.asp
- Batch FIle: source.dosbatch
- C#: source.cs
- C++: source.c++
- Clojure: source.clojure
- CoffeeScript: source.coffee
- CSS: source.css
- D: source.d
- Diff: source.diff
- Erlang: source.erlang
- Go: source.go
- GraphViz: source.dot
- Groovy: source.groovy
- Haskell: source.haskell
- HTML: text.html(.basic)
- JSP: text.html.jsp
- Java: source.java
- Java Properties: source.java-props
- Java Doc: text.html.javadoc
- JSON: source.json
- Javascript: source.js
- BibTex: source.bibtex
- Latex Log: text.log.latex
- Latex Memoir: text.tex.latex.memoir
- Latex: text.tex.latex
- LESS: source.css.less
- TeX: text.tex
- Lisp: source.lisp
- Lua: source.lua
- MakeFile: source.makefile
- Markdown: text.html.markdown
- Multi Markdown: text.html.markdown.multimarkdown
- Matlab: source.matlab
- Objective-C: source.objc
- Objective-C++: source.objc++
- OCaml campl4: source.camlp4.ocaml
- OCaml: source.ocaml
- OCamllex: source.ocamllex
- Perl: source.perl
- PHP: source.php
- Regular Expression(python): source.regexp.python
- Python: source.python
- R Console: source.r-console
- R: source.r
- Ruby on Rails: source.ruby.rails
- Ruby HAML: text.haml
- SQL(Ruby): source.sql.ruby
- Regular Expression: source.regexp
- RestructuredText: text.restructuredtext
- Ruby: source.ruby
- SASS: source.sass
- Scala: source.scala
- Shell Script: source.shell
- SQL: source.sql
- Stylus: source.stylus
- TCL: source.tcl
- HTML(TCL): text.html.tcl
- Plain text: text.plain
- Textile: text.html.textile
- XML: text.xml
- XSL: text.xml.xsl
- YAML: source.yaml

Jężeli nie możesz znaleźć swojego typu pliku, możesz to sprawdzić wciskając kombinację klawiszy: [ctrl] + [shift] + [p] na Macu lub [ctrl] + [shift] + [alt] + [p] na Windows. Na dolnym pasku po lewej stronie zostanie wyświetlony _scope_ aktualnie otwartego pliku.

Tak przygotowany plik zapisujemy z roszerzeniem ``.sublime-snippet`` w katalogu: 

{% highlight text %}na OSX:
/Users/{userName}/Library/Application Support/Sublime Text 2/Packages/User

na Windows:
C:\Users\{userName}\AppData\Roaming\Sublime Text 2\Packages\User{% endhighlight %}

__Przykładowe snippets dla kramdown__

Wyśrodkowany obrazek (mc-ic.sublime.snippet)
{% highlight xml %}<snippet>
<content><![CDATA[
{:.center}
![${2:alt}](${1:url})
]]></content>
	<tabTrigger>ic</tabTrigger>
	<scope>text.html.markdown</scope>
</snippet>{% endhighlight %}

Kod źródłowy (mc-ss.sublime.snippet) - _ps. usuń spacje_
{% highlight xml %}<snippet>
<content><![CDATA[
{ % highlight ${1:html} % }${2:tutaj wstaw kod}{ % endhighlight % }
]]></content>
	<tabTrigger>ss</tabTrigger>
	<scope>text.html.markdown</scope>
</snippet>{% endhighlight %}

Link na zewnątrz (md-lo.sublime.snippet)
{% highlight xml %}<snippet>
<content><![CDATA[
[$1]($2){:target="_blank"}{:rel="nofollow"}
]]></content>
	<tabTrigger>lo</tabTrigger>
	<scope>text.html.markdown</scope>
</snippet>
{% endhighlight %}
