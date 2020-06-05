package com.example.exsamstoiletapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;


import com.example.exsamstoiletapp.model.Tiolet;
import com.example.exsamstoiletapp.storage.FirebaseRepo;

import java.util.ArrayList;


public class MainActivity extends AppCompatActivity {

    public static ArrayList<Tiolet> toilets = new ArrayList<>();
    EditText editText;
    ListView listView;

    public static double testLon = 0;
    public static double testLat = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        editText = findViewById(R.id.editText);
        listView = findViewById(R.id.listView);

        FirebaseRepo.loadList();

        /*
        toilets.add(new Tiolet("Big ben", 55.665668, 12.3940884));
        toilets.add(new Tiolet("McD Glostrup", 55.6656939, 12.3787676));
        toilets.add(new Tiolet("McD KBH nørre voldgade", 55.6825559, 12.5675076));
        toilets.get(0).addToQ("Brian0");
        toilets.get(0).addToQ("Susanne0");
        toilets.get(1).addToQ("Brian1");
        toilets.get(1).addToQ("Susanne1");
        toilets.get(2).addToQ("Brian2");
        toilets.get(2).addToQ("Susanne2");
        */
        //123
        System.out.println("-----------------" + testLat + " " + testLon);
        //

        ArrayAdapter arrayAdapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, toilets.get(closedToilet()).getToiletQList());
        listView.setAdapter(arrayAdapter);


    }








    private Integer closedToilet(){
        double tempCloseDist = 999;
        int tempArrayIndex = -1;
        double distance;
        for (int i = 0; i<toilets.size(); i++){
            distance = Math.sqrt(
                                ((testLat - toilets.get(i).getLat())*(testLat - toilets.get(i).getLat()))+
                                ((testLon - toilets.get(i).getLon())*(testLon - toilets.get(i).getLon()))
            );
            if (distance<tempCloseDist){
                tempArrayIndex = i;
                tempCloseDist = distance;
            }
        }
        if (tempArrayIndex != -1){
            return tempArrayIndex;
        }
        else{
            return null;
        }
    }

    private boolean lockedEditText = false;
    public void tilslut(View view){
        if (!editText.getText().toString().equals("") && !toilets.get(closedToilet()).getToiletQList().contains(editText.getText().toString())){
            toilets.get(closedToilet()).addToQ(editText.getText().toString());

            editText.setEnabled(false);
            lockedEditText = true;
        }
    }

    public void forlad(View view){
        if (toilets.get(closedToilet()).getToiletQList().contains(editText.getText().toString()) && lockedEditText){
            toilets.get(closedToilet()).removeFromQ(editText.getText().toString());

            editText.setEnabled(true);
            lockedEditText = false;
        }
    }

    public void mapButton(View view){
        Intent intent = new Intent(this, MapsActivity.class);
        startActivity(intent);
    }






}
