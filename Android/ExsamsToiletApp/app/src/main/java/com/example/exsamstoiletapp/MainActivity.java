package com.example.exsamstoiletapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;

import java.util.ArrayList;


public class MainActivity extends AppCompatActivity {

    public static final String EXSTRA_ARRAY_INDEX = "EXSTRA_INDEX";


    public static ArrayList<Tiolet> toilets = new ArrayList<>();
    EditText editText;

    double myPosLon = 10;
    double myPosLat = 10;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        editText = findViewById(R.id.editText);



        toilets.add(new Tiolet("Big ben", 0, 0));
        toilets.add(new Tiolet("McD Glostrup", 50, 50));
        toilets.add(new Tiolet("McD KBH V", 100, 100));
    }

    public void addMan(View view){
        if(!editText.getText().toString().equals("")){
            int tempCloseIndex=999;
            int tempArrayIndex = -1;
            double distance;
            for (int i = 0; i<toilets.size(); i++){
                distance = Math.sqrt(
                        ((myPosLat - toilets.get(i).getLat())*(myPosLat - toilets.get(i).getLat()))+
                        ((myPosLon - toilets.get(i).getLon())*(myPosLon - toilets.get(i).getLon()))
                );
                if (distance<tempCloseIndex){
                    tempArrayIndex = i;
                }
            }
            if (tempArrayIndex != -1){
                toilets.get(tempArrayIndex).addMan(editText.getText().toString());

                Intent intent = new Intent(this, ListActivity.class);
                intent.putExtra(EXSTRA_ARRAY_INDEX, tempArrayIndex);
                startActivity(intent);

            }
        }
    }
    public void addKvinde(View view){
        //skal adde til en liste
    }
    public void showMap(View view){
        //skal vise map med toiletter
    }





}
