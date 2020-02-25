package com.example.recyclerviewdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.EditText;
import android.widget.TextView;

import com.example.recyclerviewdemo.Model.Note;
import com.example.recyclerviewdemo.Storage.NoteStorage;

public class Main2Activity extends AppCompatActivity {

    private TextView textView;
    private EditText editText;
    private int row = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        int row = getIntent().getIntExtra(Viewholder.rowkey, 0 );
        textView = findViewById(R.id.textView);
        editText = findViewById(R.id.editText);
        textView.setText(NoteStorage.);
    }

    @Override
    protected void onPause() {
        super.onPause();
        NoteStorage.getNode(row).headline = textView.getText().toString();
        NoteStorage.getNode(row).body = editText.getText().toString();
    }
}
