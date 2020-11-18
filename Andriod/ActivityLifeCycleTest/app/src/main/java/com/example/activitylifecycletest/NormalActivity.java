package com.example.activitylifecycletest;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

public class NormalActivity extends AppCompatActivity {

    public static final String TAG = "NormalActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.normal_layout);

        Intent intent = getIntent();
        Bundle bundleData= intent.getBundleExtra("bundle_key");
        String normalData = bundleData.getString("msg");
        String helloData = bundleData.getString("msg_2");
        Log.d(TAG, "onCreate: Normal");
        Log.d(TAG,normalData);
        Log.d(TAG,helloData);
    }
}
