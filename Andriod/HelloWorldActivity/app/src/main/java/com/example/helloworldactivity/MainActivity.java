package com.example.helloworldactivity;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d("data","onCreate execute");

        setContentView(R.layout.activity_main);
    }

    private static final String TAG = "MainActivity";
}
