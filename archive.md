---
layout: page
title: Archiwum
tags: ['Marcin Kitowicz','kitek','programowanie','php','javascript','android','mysql','nodejs']
description: 'Archiwum bloga. Lista wszystkich opublikowanych postów.'
redirect_from: "/archive/"
---
{% for post in site.posts %}
  * {{ post.date | date_to_string }} &raquo; [ {{ post.title }} ]({{ post.url }})
{% endfor %}
