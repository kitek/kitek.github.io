---
layout: post
title: Headless fragments
category: Android
tags: ['asyncTask','fragment','headless fragment','retain fragment']
type: post
description: 'Fragment w roli AsyncTaska? Z powodzeniem do takich zadań możemy wykorzystać fragmenty nie posiadające swoich widoków. W artykule przedstawiam prosty przykład samego fragmentu jak i sposobu jego uruchamiania.'
redirect_from: '/android/2013/10/13/Headlessfragments/'
---
Android udostępnia świetne rozwiązanie w postaci fragmentów, które może zostać wykorzystane również jako narzędzie do obejścia "resetowania" naszego Activity przy zmianie orientacji/konfiguracji urządzenia. W sytuacjach gdy potrzebujemy wykonać pewne zadanie w tle (np. AsyncTask: autoryzujący użytkownika przez HTTP Api lub wysyłający duże dane do zewnętrznego serwera) każde obrócenie urządzenia wywoła naszego AsyncTask’a ponownie. Oczywiście możemy zablokować na stałe możliwość zmiany orientacji ekranu lub nadpisać metodę obsługującą zmiany w konfiguracji jednak w większości przypadków nie są to rozwiązania dobre lub odpowiadające naszym wymaganiom.
Z powodzeniem do takich zadań możemy wykorzystać fragmenty nie posiadające swoich widoków. Poniżej przedstawiam prosty przykład samego fragmentu jak i sposobu jego uruchamiania.

HeadlessFragments.java

{% highlight java %}
public class HeadlessFragments extends Fragment {

	public static final String TAG = "HeadlessFragments";

	// Pomocniczy interfejs do raportowania zdarzen AsyncTask'a
	public static interface TaskCallbacks {
		void onPreExecute();

		void onProgressUpdate(int percent);

		void onCancelled();

		void onPostExecute();
	}

	private TaskCallbacks mCallbacks;
	private MyTask myTask;

	@Override
	public void onAttach(Activity activity) {
		super.onAttach(activity);
		// W tym miejscu przypisujemy activity w ktorym nasz fragment zostal
		// utworzony.
		// Oczywiscie te Activity musi implementowac powyzej zdefiniowany
		// interfejs
		mCallbacks = (TaskCallbacks) activity;
	}

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		// Ta linijka jest bardzo istotna, dzieki niej nasz fragment zostanie
		// zachowany (a nie tworzony od nowa) przy zmianie orientacji ekranu
		setRetainInstance(true);
		// Uruchom nasze zadanie
		myTask = new MyTask();
		myTask.execute();
	}

	@Override
	public void onDetach() {
		super.onDetach();
		mCallbacks = null;
	}

	private class MyTask extends AsyncTask {

		@Override
		protected void onPreExecute() {
			super.onPreExecute();
			if (null != mCallbacks) {
				mCallbacks.onPreExecute();
			}
		}

		@Override
		protected Void doInBackground(Void... params) {
			// TODO Tutaj wykonuje zadanie
			return null;
		}

		@Override
		protected void onProgressUpdate(Void... values) {
			super.onProgressUpdate(values);
			if (null != mCallbacks) {
				// mCallbacks.onProgressUpdate(values[0]);
			}
		}

		@Override
		protected void onPostExecute(Void result) {
			super.onPostExecute(result);
			if (null != mCallbacks) {
				mCallbacks.onPostExecute();
			}
		}

		@Override
		protected void onCancelled() {
			super.onCancelled();
			if (null != mCallbacks) {
				mCallbacks.onCancelled();
			}
		}
	}
}
{% endhighlight %}

MainActivity.java

{% highlight java %}
public class MainActivity extends FragmentActivity implements
		HeadlessFragments.TaskCallbacks {

	public static final String TAG = "MainActivity";

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		FragmentManager fragmentManager = getSupportFragmentManager();
		HeadlessFragments taskFragment = (HeadlessFragments) fragmentManager
				.findFragmentByTag(HeadlessFragments.TAG);
		if (taskFragment == null) {
			taskFragment = new HeadlessFragments();
			fragmentManager.beginTransaction()
				.add(taskFragment, HeadlessFragments.TAG).commit();
		}
	}

	@Override
	public void onPreExecute() {
	}

	@Override
	public void onProgressUpdate(int percent) {
	}

	@Override
	public void onCancelled() {
	}

	@Override
	public void onPostExecute() {
	}

}
{% endhighlight %}
