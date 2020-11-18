package com.example.activitytest;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

public class ThirdActivity extends BaseActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.third_layout);
//        Intent intent1 = getIntent();
//        String data = intent1.getStringExtra("extra_data");
//        Log.d("Third",data);


        Button btn3 = (Button) findViewById(R.id.button_3);

        btn3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                    AcitvityCollector.finishAll();
//                    获取当前进程id并杀死
                    android.os.Process.killProcess(android.os.Process.myPid());
//                Intent intent = new Intent(Intent.ACTION_DIAL);
//                intent.setData(Uri.parse("tel:10086"));
//                startActivity(intent);
            }
        });


    }
}
