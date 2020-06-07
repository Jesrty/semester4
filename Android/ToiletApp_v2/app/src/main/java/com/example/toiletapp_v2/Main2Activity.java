package com.example.toiletapp_v2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class Main2Activity extends AppCompatActivity {

    ListView listView;
    static int arrayIndex;
    TextView textView;

    static ArrayAdapter arrayAdapter;
    private static boolean adapterCreated = false;

    static ArrayList<String> thisList = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        arrayIndex = getIntent().getIntExtra("indexValue", -1);

        listView = findViewById(R.id.listView);
        textView = findViewById(R.id.textView2);
        textView.setText(MainActivity.toilets.get(arrayIndex).getName() + "'s toilet kø");

        thisList = MainActivity.toilets.get(arrayIndex).getToiletQList();
        arrayAdapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, thisList);
        listView.setAdapter(arrayAdapter);
        adapterCreated = true;




    }

    public static void adapterNotify(){
        if (adapterCreated) {
            /*
            for (int i = 0; i < MainActivity.toilets.get(arrayIndex).getToiletQList().size(); i++){
                System.out.println("11112222 " + MainActivity.toilets.get(arrayIndex).getToiletQList().get(i));
            }
            */
            thisList.clear();
            thisList.addAll(MainActivity.toilets.get(arrayIndex).getToiletQList());
            arrayAdapter.notifyDataSetChanged();
        }
    }

    @Override
    public void onPause() {
        super.onPause();
        adapterCreated = false;
    }
}
