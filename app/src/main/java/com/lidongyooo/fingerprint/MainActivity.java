package com.lidongyooo.fingerprint;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.widget.TextView;

import com.lidongyooo.fingerprint.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'fingerprint' library on application startup.
    static {
        System.loadLibrary("fingerprint");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());
        boolean result = fridaPortCheck(27042); // 确保返回 boolean，不是 Boolean
        Log.e("fingerprintxxx", String.valueOf(result));
        new Handler(Looper.getMainLooper()).postDelayed(new Runnable() {
            @Override
            public void run() {
                boolean isFridaDetected = fridaMapsCheck();
                Log.e("fingerprintxxx", String.valueOf(isFridaDetected));
            }
        }, 3000); // 3000 毫秒 = 3 秒
    }

    /**
     * A native method that is implemented by the 'fingerprint' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native boolean fridaPortCheck(int port);

    public native boolean fridaMapsCheck();
}