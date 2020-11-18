package com.example.activitytest;

import android.app.Activity;

import java.util.ArrayList;
import java.util.List;

public class AcitvityCollector {

    public  static List<Activity> activities = new ArrayList<>();

    public static void addActivity(Activity activity){
       activities.add(activity);
    }

    public static void removeActivity(Activity activity){
        activities.remove(activity);
    }

//    销毁所有活动
    public static void finishAll(){
        for(Activity activity:activities){
            if(!activity.isFinishing()){
                activity.finish();
            }
        }
    }
}
