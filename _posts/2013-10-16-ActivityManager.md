---
layout: post
title: ActivityManager
---

W pewnych przypadkach zachodzi potrzeba sprawdzenia czy w naszej aplikacji znajdują się inne “działające” Activity niż to, które obecnie jest na froncie. Można to osiągnąć za pomocą klas ActivityManager i RunningTaskInfo.

{% highlight java %}

ActivityManager mngr = (ActivityManager)getSystemService(ACTIVITY_SERVICE);
List<RunningTaskInfo> taskList = mngr.getRunningTasks(10);
if (taskList.get(0).numActivities == 1 
	&& taskList.get(0)
		.topActivity
		.getClassName()
		.equals(this.getClass().getName())) {

		// Tylko jedno activity, te które obecnie jest na froncie
		
}

{% endhighlight %}

