---
layout: post
title: ActivityManager
category: Android
tags: ['activity','GET_TASKS','ActivityManager','RunningTaskInfo','android']
type: post
description: 'Przykład wykorzystania ActivityManager i RunningTaskInfo na platformie Android.'
redirect_from: "/android/2013/10/16/ActivityManager/"
---
W pewnych przypadkach zachodzi potrzeba sprawdzenia czy w naszej aplikacji znajdują się inne "działające" Activity niż to, które obecnie jest na froncie. Można to osiągnąć za pomocą klas [ActivityManager](http://developer.android.com/reference/android/app/ActivityManager.html){:target="_blank"}{:rel="nofollow"} i [RunningTaskInfo](http://developer.android.com/reference/android/app/ActivityManager.RunningTaskInfo.html){:target="_blank"}{:rel="nofollow"}.

{% highlight java %}
ActivityManager m = (ActivityManager) getSystemService(ACTIVITY_SERVICE);
List<RunningTaskInfo> taskList = m.getRunningTasks(10);
if (taskList.get(0).numActivities == 1 && taskList.get(0).topActivity.getClassName()
		.equals(this.getClass().getName())) {
	// Tylko jedno activity, te które obecnie jest na froncie
}
{% endhighlight %}

Możliwe jest również pobranie szerszej informacji:

{% highlight java %}
Iterator<RunningTaskInfo> itr = taskList.iterator();
while (itr.hasNext()) {
	RunningTaskInfo runningTaskInfo = (RunningTaskInfo) itr.next();
	// Informacje
	int id = runningTaskInfo.id;
	CharSequence desc = runningTaskInfo.description;
	String topActivity = runningTaskInfo.topActivity.getShortClassName();
	int numOfActivities = runningTaskInfo.numActivities;
}
{% endhighlight %}

Do poprawnego uruchomienia powyższych przykładów wymagane jest zdefiniowania uprawnienia GET_TASKS.

{% highlight xml %}
<uses-permission android:name="android.permission.GET_TASKS"/>
{% endhighlight %}
