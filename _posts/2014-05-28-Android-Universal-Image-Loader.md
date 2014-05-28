---
layout: post
title: 'Android Universal Image Loader'
category: Android
tags: ['ImageView','load image','display image']
type: post
description: 'Android Universal Image Loader - biblioteka usprawniająca ładowanie i wyświetlanie obrazów w ImageView zaciągniętych z Internetu na platformie Android.'
---
Gdy rozpoczynałem przygodę z platformą Android nie spodziewałem się, że pobranie i wyświetlenie obrazka będzie w jakiś sposób bardziej skomplikowane. Okazało się, że bez użycia dodatkowych bibliotek nie jest to sztuka łatwa (jak dla początkującej osoby). Z pomocą przyszła biblioteka [Android-Universal-Image-Loader](https://github.com/nostra13/Android-Universal-Image-Loader){:target="_blank"}{:rel="nofollow"}, którą z powodzeniem wykorzystuje w kilku projektach. Poniższy artykuł dotyczy wersji [v1.9.2](https://github.com/nostra13/Android-Universal-Image-Loader/tree/v1.9.2){:target="_blank"}{:rel="nofollow"}.

__Instalacja__

Najprostszym sposobem jest sciągnięcie biblioteki w postaci pliku [jar](https://github.com/nostra13/Android-Universal-Image-Loader#downloads){:target="_blank"}{:rel="nofollow"} i umieszczenie go w katalogu _libs_ naszego projektu. Wymagane również będzie zdefiniowanie dodakowych uprawnień w pliku _AndroidManifest.xml_:

{% highlight xml %}<uses-permission android:name="android.permission.INTERNET" />
<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />{% endhighlight %}

Zalecene jest umieszczenie konfiguracji _ImageLoader'a_ w klasie [_Application_](http://developer.android.com/reference/android/app/Application.html){:target="_blank"}{:rel="nofollow"} w ten sposób będziemy mieli pewność, że biblioteka zostanie skonfigurowana tylko raz i dostępna będzie w całym naszym projekcie. Do tego niezbędne będzie umieszczenie atrybutu ``android:name="pl.kitek.MojaAplikacja"`` w manifeście:

{% highlight xml %}<application android:name="pl.kitek.MojaAplikacja">...</application>{% endhighlight %}

Oczywiście musimy stworzyć tak podaną klasę i umieścić ją we wskazanym pakiecie:

{% highlight java %}
import android.app.Application;
import com.nostra13.universalimageloader.core.ImageLoader;
import com.nostra13.universalimageloader.core.ImageLoaderConfiguration;

public class MojaAplikacja extends Application {

	@Override
	public void onCreate() {
		super.onCreate();
		
		// Domyślna konfiguracja ImageLoader'a
		ImageLoaderConfiguration config = new ImageLoaderConfiguration
			.Builder(getApplicationContext())
			.build();

		ImageLoader.getInstance().init(config);
	}
}{% endhighlight %}

Od tego momentu biblioteka jest gotowa do użycia. Będzie działać na domyślnych ustawieniach, które możemy [modyfikować](#konfiguracja).

__Wyświetlanie obrazków__

Dopuszczalne jest stosowanie następujących typów adresów:

{% highlight java %}
String url = "http://kitek.pl/public/uploads/2014/05/flux.jpg";
String url = "file:///mnt/sdcard/obrazek.png";
String url = "content://media/external/audio/albumart/13";
String url = "assets://obrazek.png";
{% endhighlight %}

Dostępnych jest kilka sposobów załadowania i wyświetlenia obrazka. Sposób pierwszy:

_/res/layout/activity_main.xml_
{% highlight xml %}
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity" >

    <ImageView
        android:id="@+id/obrazek"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:contentDescription="@string/app_name" />

</RelativeLayout>
{% endhighlight %}

_MainActivity.java_
{% highlight java %}
public class MainActivity extends Activity {
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		String url = "http://kitek.pl/public/uploads/2014/05/flux.jpg";
		ImageView obrazek = (ImageView) findViewById(R.id.obrazek);
		
		ImageLoader.getInstance().displayImage(url, obrazek);
	}
}
{% endhighlight %}

Drugi sposób wykorzystuje _SimpleImageLoadingListener_ i wymaga własnej obłsugi _Bitmap_:

{% highlight java %}
ImageLoader.getInstance().loadImage(url, new SimpleImageLoadingListener() {
	@Override
	public void onLoadingStarted(String uri, View view) {
		Log.d("Loader", "Loading Started");
	}

	@Override
	public void onLoadingComplete(String uri, View view, Bitmap loadedImage) {
		Log.d("Loader", "Loading Complete");
		if (null != loadedImage && null != obrazek) {
			obrazek.setImageBitmap(loadedImage);
		}
	}

	@Override
	public void onLoadingCancelled(String uri, View view) {
		Log.d("Loader", "Loading Cancelled");
	}

	@Override
	public void onLoadingFailed(String uri, View view, FailReason failReason) {
		Log.d("Loader", "Loading Failed");
	}
});
{% endhighlight %}

__Konfiguracja__{:id="konfiguracja"}

Biblioteka posiada bardzo szerokie możliwości konfiguracyjne. Ustawienia podzielone zostały na dwie kategorie: ``DisplayImageOptions`` i ``ImageLoaderConfiguration``. Konfiguracja biblioteki powinna zostać zrealizowana w klasie `Application`. Poniżej przedstawiono tylko wybrane opcje ([większość dostępna jest na stronie autora](https://github.com/nostra13/Android-Universal-Image-Loader#configuration-and-display-options){:target="_blank"}{:rel="nofollow"}).
{% highlight java %}
DisplayImageOptions displayOptions = new DisplayImageOptions.Builder()
	// Umożliwia wyświetlenie "zaślepek" na czas: 
	// ładowania, braku Uri lub błędu załadowania docelowego obrazka
	.showImageOnLoading(R.drawable.ic_stub)
	.showImageForEmptyUri(R.drawable.ic_empty)
	.showImageOnFail(R.drawable.ic_error)

	// Zezwala na korzystanie z buforów
	.cacheInMemory(true)
	.cacheOnDisc(true)

	.build();
{% endhighlight %}

{% highlight java %}
ImageLoaderConfiguration config = new ImageLoaderConfiguration.Builder(context)
	// Określa kolejność ładowania kolejnych obrazków
	.tasksProcessingOrder(QueueProcessingType.FIFO)
	// Blokuje ładowanie do pamięci tego samego obrazka w kilku wymiarach
	.denyCacheImageMultipleSizesInMemory()
	
	// Strategia buforowania obrazków w pamięci.
	.memoryCache(new LruMemoryCache(2 * 1024 * 1024))
	// Maksymalny rozmiar bufora (2 MB)
	.memoryCacheSize(2 * 1024 * 1024)
	// Maksymalny rozmiar bufora (13% dostępnej pamięci)
	.memoryCacheSizePercentage(13)
	
	// Strategia buforowania obrazków w systemie plików.
	.discCache(new UnlimitedDiscCache(cacheDir))
	// Maksymalny rozmiar plików (50 MB)
	.discCacheSize(50 * 1024 * 1024)
	// Maksymalna liczba plików (100)
	.discCacheFileCount(100)

	// Ustawia domyślne ustawienia wyświetlania (patrz DisplayImageOptions)
	.defaultDisplayImageOptions(displayOptions)

	.build();
{% endhighlight %}

Dostępnych jest kilka gotowych implementacji dla `memoryCache(..)`:

- `LruMemoryCache` w pierwszej kolejności usunięte z bufora zostną najdawniej wykorzystane bitmapy.
- `UsingFreqLimitedMemoryCache` bufor zostanie czyszczony począwszy od najrzadziej używanych obrazków
- `FIFOLimitedMemoryCache` wykorzystuje kolejkę [FIFO](http://pl.wikipedia.org/wiki/FIFO){:target="_blank"}{:rel="nofollow"} przy usuwaniu bitmap z bufora.
- `LargestLimitedMemoryCache` usuwanie zaczyna się od największych obrazków.
- `WeakMemoryCache` wykorzystuje słabe referencje do przechowywania bitmap.

Strategie bufora dyskowego `diskCache(..)`:

- `UnlimitedDiscCache` brak ograniczeń dla plików bufora, jest to najszybszy mechanizm (domyślnie).
- `LruDiskCache` umożliwia wprowadzenie ograniczenia rozmiaru lub/i maksymalnej liczby plików. W pierwszej kolejności usunięte zostną najdawniej wykorzystane pliki.
- `LimitedAgeDiscCache` umożliwia wprowadzenie ograniczenia czasowego po jego przekroczeniu plik zostatnie usunięty.

__Dodatkowe informacje__

Buforowanie domyślnie jest wyłączone. Należy o tym pamiętać przy konfiguracji biblioteki. W celu minimalizacji wystąpień wyjątka `OutOfMemoryError` warto zastosować poniższe ustawienia:

- Zmniejszenie wartości `.threadPoolSize(..)`.
- Użycie `.bitmapConfig(Bitmap.Config.RGB_565)` jeżeli nie wykorzystujemy przeźroczystości PNG.
- Wykorzystanie `.memoryCache(new WeakMemoryCache())` lub całkowite wyłączenie buforowania w pamięci `.cacheInMemory(false)`.
- Wybranie trybu `.imageScaleType(ImageScaleType.IN_SAMPLE_INT)`.
- Przy korzystaniu z ViewPager'a warto ustawić minimalną wartość `.setOffscreenPageLimit(1)`.

Jeżeli w projekcie potrzebujemy kilka wersji ImageLoader'a (o różnych konfiguracjach: duże zdjęcia, miniaturki, itd.) możemy rozszerzyć klasę `ImageLoader`:

{% highlight java %}
import com.nostra13.universalimageloader.core.ImageLoader;

public class BigPhotosLoader extends ImageLoader {

	private volatile static BigPhotosLoader instance;

	/** Returns singletone class instance */
	public static BigPhotosLoader getInstance() {
		if (instance == null) {
			synchronized (ImageLoader.class) {
				if (instance == null) {
					instance = new BigPhotosLoader();
				}
			}
		}
		return instance;
	}
}
{% endhighlight %}

