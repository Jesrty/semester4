package com.example.list_to_gui;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.ScrollView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private EditText editText;
    private ListView listView;
    private List<String> myList = new ArrayList<>();
    private ArrayAdapter<String> adapter;
    private int postionHolder = -1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editText = findViewById(R.id.editText);
        listView = findViewById(R.id.listView);
        adapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, myList);
        listView.setAdapter(adapter);

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                editText.setText(myList.get(position));
                postionHolder = position;
            }
        });
    }

    public void addToList(View view){
        String inputString = editText.getText().toString();
        if(inputString.length() > 0){
            if(postionHolder == -1) {
                myList.add(inputString);
            }
            else {
                myList.set(postionHolder, inputString);
                postionHolder = -1;
            }
            adapter.notifyDataSetChanged();
            editText.getText().clear();
        }
    }







}
