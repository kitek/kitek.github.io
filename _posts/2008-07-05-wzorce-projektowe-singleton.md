---
layout: post
title: Wzorce projektowe – Singleton
category: PHP
tags: ['PHP', 'singleton', 'wzorce projektowe']
type: post
description: 'Przykład zastosowania i objaśnienie wzorca Singleton w języku PHP'
---
__Singleton__

Wzorzec typu Singleton pozwala na proste kontrolowanie liczby obiektów danej klasy. Możliwe jest utworzenie tylko jednego egzemplarza klasy opartej na wzorcu Singleton.

Ten typ wzorca wykorzystywany jest w sytuacjach gdy tworzenie obiektu danej klasy wiąże się z dużym obciążeniem lub gdy istnienie większej liczby tego typu obiektów nie jest po prostu potrzebne.

Poniżej kod źródłowy prostej klasy realizującej obsługę bazy danych MySQL wykorzystującej model Singleton:

{% highlight php %}
<?php
class db {
	private $link;
	private $result;

	private function __construct() {
		$this->link = new mysqli(DBHOST,DBUSER,DBPASSWORD,DBNAME);
		if (!$this->link) {
			throw new Exception(mysqli_connect_error());
		}
	}

	public function __destruct() {
		$this->link->close();
	}

	public static function getInstance() {
		static $db;
		if(!isset($db)) {
			$db = new db();
		}
		return $db;
	}

	public function query($sql) {
		if(empty($sql)) {
			return false;
		}
		if($this->result=$this->link->query($sql)) {
			return $this->result->fetch_assoc();
		} else {
			throw new Exception($this->link->error);
		}
	}
}
{% endhighlight %}
W powyższym przykładzie wykorzystany został prywatny konstruktor który uniemożliwia stworzenie nowego obiektu za pomocą kodu: _$db = new db();_.
Do stworzenia obiektu wykorzystamy statyczną metodę getInstance():

{% highlight php %}
<?php
try {
	$db = db::getInstance();
} catch (Exception $e) {
	die("Brak polaczenia z baza.");
}

$rs = $db->query("SELECT * FROM tabela");
var_dump($rs);
{% endhighlight %}

Dzięki temu zabiegowi stworzyliśmy klasę mogącą posiadać tylko jeden egzemplarz – w naszym przypadku obsługujący zapytania do bazy danych MySQL. Warto pamiętać również o tym, że statyczne zmienne zachowują swoje wartości pomiędzy kolejnymi wywołaniami funkcji.

Linki:

- [Opis rozszerzenia mysqli](http://pl.php.net/manual/en/book.mysqli.php){:target="_blank"}{:rel="nofollow"}
