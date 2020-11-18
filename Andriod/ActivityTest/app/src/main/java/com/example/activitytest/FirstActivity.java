package com.example.activitytest;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class FirstActivity extends BaseActivity {

    public  static final  String TAG = "FirstActivity";
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
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
//        通过设置不同请求码来对应不同活动的返回
        switch(requestCode){
            case 1:
                if(resultCode == RESULT_OK){
                    String returnData = data.getStringExtra("data_return");
                    Log.d("Return data",returnData);
                }
                break;
            default:
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.first_layout);
//        获取的是View对象，强转为Button
        Button button1 = (Button) findViewById(R.id.button_1);
//        输出当前活动信息
        Log.d(TAG+"DATA", this.toString());

//        启动方法
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
               SecondAcitvity.actionStart(FirstActivity.this,"data1","data2");
            }
        });
//
////        singleTop模式测试
//        button1.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                Intent intent = new Intent(FirstActivity.this,SecondAcitvity.class);
//                startActivity(intent);
//            }
//        });



//        standard模式测试
//        button1.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                Intent intent = new Intent(FirstActivity.this,FirstActivity.class);
//                startActivity(intent);
//
//            }
//        });

//        活动穿梭
//        button1.setOnClickListener(new View.OnClickListener(){
//            @Override
//            public  void onClick(View v){
////                String data = "Hellow China";
////                Intent intent = new Intent(FirstActivity.this,ThirdActivity.class);
////                intent.putExtra("extra_data",data);
//                Intent intent = new Intent("com.example.activitytest.ACTION_START");
//                intent.addCategory("com.example.activitytest.MY_CATEGORY");
//                startActivityForResult(intent,1);   //设置请求码给下个活动
////                Toast.makeText(FirstActivity.this ,"You clicked Button1",
////                        Toast.LENGTH_SHORT).show();
////                finish();
//
//            }
//        });


    }
}
