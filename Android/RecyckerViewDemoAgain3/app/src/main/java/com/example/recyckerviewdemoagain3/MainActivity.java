package com.example.recyckerviewdemoagain3;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.widget.TextView;

import com.example.recyckerviewdemoagain3.adapter.MyAdapter;
import com.example.recyckerviewdemoagain3.storage.NoteStorage;

public class MainActivity extends AppCompatActivity {

    private RecyclerView recyclerView;
    private MyAdapter myAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        recyclerView = findViewById(R.id.RecyclerView1);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        myAdapter= new MyAdapter(new NoteStorage());
        recyclerView.setAdapter(myAdapter);
    }
}
