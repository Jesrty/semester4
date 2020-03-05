package com.example.recyclerviewdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.EditText;
import android.widget.TextView;

import com.example.recyclerviewdemo.Model.Note;
import com.example.recyclerviewdemo.Storage.NoteStorage;
import com.example.recyclerviewdemo.view.ViewHolder;

public class Main2Activity extends AppCompatActivity {

    private TextView textView;
    private EditText editText;
    private int row = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        int row = getIntent().getIntExtra(ViewHolder.rowKey, 0 );
        textView = findViewById(R.id.textView);
        editText = findViewById(R.id.editText);
        textView.setText(NoteStorage.getNode(row).headline);
        editText.setText(NoteStorage.getNode(row).body);
    }

    @Override
    protected void onPause() {
        super.onPause();
        // her skal det være setNode og ikke getNode upsi upsi
        NoteStorage.getNode(row).headline = textView.getText().toString();
        NoteStorage.getNode(row).body = editText.getText().toString();
    }
}
