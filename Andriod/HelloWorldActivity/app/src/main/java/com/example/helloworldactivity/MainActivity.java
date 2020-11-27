package com.example.helloworldactivity;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    private  EditText editText;
    private ImageView imageView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d("data","onCreate execute");

        setContentView(R.layout.activity_main);
        Button button = (Button) findViewById(R.id.button);
        editText = (EditText)findViewById(R.id.edit_text);
        imageView = (ImageView) findViewById(R.id.image_view);
//        匿名类方式
//        button.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                Toast.makeText(MainActivity.this,"Click  1",Toast.LENGTH_SHORT).show();
//            }
//        });

//      接口监听
        button.setOnClickListener(this);
    }

//    接口方式
    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.button:
//                Toast.makeText(MainActivity.this,"Click 2",Toast.LENGTH_SHORT).show();
//                String inputText = editText.getText().toString();
//                Toast.makeText(MainActivity.this,inputText,Toast.LENGTH_SHORT).show();
                    imageView.setImageResource(R.drawable.star);
                break;
                default:
                    break;
        }
    }


    private static final String TAG = "MainActivity";
}
