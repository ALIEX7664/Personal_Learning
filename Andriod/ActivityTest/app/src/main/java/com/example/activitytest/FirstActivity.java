package com.example.activitytest;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class FirstActivity extends AppCompatActivity {

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
//        获取MenuInflater对象
        getMenuInflater().inflate(R.menu.main,menu);
//        返回false不显示菜单
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
//         判断点击菜单项
        switch(item.getItemId()){
            case R.id.add_item:
                Toast.makeText(this,"Click Add", Toast.LENGTH_SHORT).show();
                break;
            case R.id.remove_item:
                Toast.makeText(this,"Click Remove",Toast.LENGTH_SHORT).show();
                break;
                default:
        }
        return true;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.first_layout);
//        获取的是View对象，强转为Button
        Button button1 = (Button) findViewById(R.id.button_1);
        button1.setOnClickListener(new View.OnClickListener(){
            @Override
            public  void onClick(View v){
                Toast.makeText(FirstActivity.this ,"You clicked Button1",
                        Toast.LENGTH_SHORT).show();
                finish();
            }


        });
    }
}
