---
layout: post
title: 'Password hint'
category: Android
tags: ['bugs','password','hint','inny font','android']
type: post
description: 'Krótki poradnik opisujący jak poradzić sobie z problemem wyświetlania hinta w EditText textPassword.'
---
Budując prosty formularz logowania w aplikacji Android możemy natknąć się na problem wyświetlania hint’ów przy użyciu różnych fontów. Ma to miejsce w przypadku zwykłego EditText’a i takiego, w którym ustawiono <code>android:inputType</code> na wartość <code>"textPassword"</code>.

{:.center}
![Android password hint bug](/public/uploads/2015/02/android-password-hint-bug.jpg){:alt="Android password hint bug"}

Buga można ominąć usuwając z XML'a <code>android:inputType="textPassword"</code> i dodając w Javie poniższy kod:

{% highlight java %}
EditText passwordEdit = (EditText) findViewById(R.id.passwordText);
passwordEdit.setTransformationMethod(new PasswordTransformationMethod());
{% endhighlight %}
