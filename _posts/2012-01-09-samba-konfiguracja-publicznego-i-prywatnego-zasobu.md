---
layout: post
title: Samba – konfiguracja publicznego i prywatnego zasobu
category: ServerSide
tags: ['samba','konfiguracja samba','server samba','zasoby współdzielone','smb.conf','smbpasswd']
type: post
description: 'Przewodnik krok po kroku jak skonfigurować Samba Server. Tworzenie publicznych i prywatnych zasobów.'
---
Po montażu karty CF w swoim [HP t5720](/2011/11/29/hp-t5720-montaz-karty-compact-flash/) przyszedł czas na skonfigurowanie serwera plików Samba. Zależało mi na stworzeniu jednego publicznego zasobu o nazwie “warez” do którego dostęp posiadać miałby każdy, bez konieczności podawania nazwy użytkownika i hasła. Natomiast drugi zasób (“private”) miał być dostępny tylko dla jednego wybranego systemowego użytkownika. Po kilku próbach i restartach konfiguracja wygląda następująco:

{% highlight bash %}
cat /etc/samba/smb.conf

[global]
netbios name = HP
workgroup = WORKGROUP
server string = HP
log file = /var/log/samba/log.%m
security = user
create mask = 0666
force create mode = 0666
force directory mode = 0777
follow symlinks = yes
encrypt passwords = true
map to guest = bad user
guest account = nobody

[warez]
comment = Warez
path = /home/user/warez
writeable = yes
read only = no
guest ok = yes
guest only = yes

[private]
comment = Private
path = /home/user/private
writeable = yes
browsable = no
read only = no
valid users = user
{% endhighlight %}

Do poprawnego działania prywatnego zasobu niezbędne jest jeszcze dodanie użytkownika:

{% highlight bash %}smbpasswd -a user{% endhighlight %}
