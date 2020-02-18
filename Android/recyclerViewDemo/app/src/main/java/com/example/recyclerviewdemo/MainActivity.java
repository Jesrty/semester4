package com.example.recyclerviewdemo;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.EditText;

import com.example.recyclerviewdemo.ad.MyRecycleViewAdapter;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private RecyclerView recyclerView;
    private RecyclerView.LayoutManager layoutManager;
    private EditText editText;
    private ArrayList<String> list;
    private MyRecycleViewAdapter myRecycleViewAdapter;
    private int postionHolder = -1;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        editText = findViewById(R.id.editText1);
        recyclerView = findViewById(R.id.recyclerView1);
        layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        myRecycleViewAdapter = new MyRecycleViewAdapter(getList());
        recyclerView.setAdapter(myRecycleViewAdapter);


    }

    private ArrayList<String> getList(){
        list = new ArrayList<>();
        list.add("the qutck brown fox");
        list.add("jumped over the lairy dog");
        list.add("again and again");
        list.add("again and again");
        list.add("again and again");
        return list;
    }

    public void addToList(View view){
        String headLine = editText.getText().toString();
        if (headLine.length() > 0){
            list.add(headLine);
            myRecycleViewAdapter.notifyDataSetChanged();
            editText.getText().clear();
        }
    }
}
