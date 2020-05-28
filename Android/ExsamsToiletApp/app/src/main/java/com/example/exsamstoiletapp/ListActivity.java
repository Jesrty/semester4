package com.example.exsamstoiletapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class ListActivity extends AppCompatActivity {

    ListView listView;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list_acticity);

        //listView = findViewById(R.id.listView);

        Intent intent = getIntent();
        int arrayIndex = intent.getIntExtra(MainActivity.EXSTRA_ARRAY_INDEX, 0);



        ArrayAdapter arrayAdapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, MainActivity.toilets.get(arrayIndex).getToiletQList());
        listView.setAdapter(arrayAdapter);


    }
}
