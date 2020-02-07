package com.example.repetationdag15;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void toPage2(View view){
        Intent intent = new Intent(this, Main2Activity.class);
        startActivity(intent);
        ImageView imageView = findViewById(R.id.imageView);

    }

    public void toPage3(View view){
        Intent intent = new Intent(this, Main3Activity.class);
        startActivity(intent);
    }


}
