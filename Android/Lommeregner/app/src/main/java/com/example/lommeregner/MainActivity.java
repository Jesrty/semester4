package com.example.lommeregner;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView result;
    private EditText number1, number2;
    private Button plus, minus, gange, dividere, clear;

    private double numb1, numb2;
    private double res;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        number1 = findViewById(R.id.editText);
        number2 = findViewById(R.id.editText2);

        result = findViewById(R.id.textView);

        plus = findViewById(R.id.button);
        minus = findViewById(R.id.button2);
        gange = findViewById(R.id.button3);
        dividere = findViewById(R.id.button4);
        clear = findViewById(R.id.button5);
    }

    public void plus(View view){
        numb1 = Double.parseDouble(number1.getText().toString());
        numb2 = Double.parseDouble(number2.getText().toString());
        res = numb1 + numb2;
        result.setText(String.valueOf(res));
    }
    public void minus(View view){
        numb1 = Double.parseDouble(number1.getText().toString());
        numb2 = Double.parseDouble(number2.getText().toString());
        res = numb1 - numb2;
        result.setText(String.valueOf(res));
    }
    public void gange(View view){
        numb1 = Double.parseDouble(number1.getText().toString());
        numb2 = Double.parseDouble(number2.getText().toString());
        res = numb1 * numb2;
        result.setText(String.valueOf(res));
    }
    public void dividere(View view){
        numb1 = Double.parseDouble(number1.getText().toString());
        numb2 = Double.parseDouble(number2.getText().toString());
        res = (numb1/numb2);
        result.setText(Double.toString(res));
    }

    public void clear(View view){
        number1.setText("");
        number2.setText("");
        String test = "Result";
        result.setText(test);
    }




}
