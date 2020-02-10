package com.example.week7jesperravn;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    EditText editText;
    View v;
    private String msg = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editText = findViewById(R.id.editText);

        v = this.getWindow().getDecorView();

    }

    public void saveText(View view){
        msg = msg + "\n" + editText.getText().toString();
        editText.setText("");
        //Log.i("all", "saved " + msg);
    }

    public void clearSave(View view){
        msg = "";
        editText.setText("");
    }

    public void viewText(View view){
        msg = msg + "\n" + editText.getText().toString();
        editText.setText("");
        Intent intent = new Intent(this, Main2Activity.class);
        intent.putExtra("put_string", msg);
        startActivity(intent);
    }

    public void redColor(View view){
        v.setBackgroundResource(R.color.red);
    }

    public void whiteColor(View view){
        v.setBackgroundResource(R.color.white);
    }

}
