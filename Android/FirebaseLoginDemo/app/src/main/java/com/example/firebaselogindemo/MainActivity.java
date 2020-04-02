package com.example.firebaselogindemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

import com.example.firebaselogindemo.auth.FirebaseManager;

public class MainActivity extends AppCompatActivity {

    private EditText emailText;
    private EditText passwordText;

    private FirebaseManager firebaseManager;

    private EditText secretText;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        firebaseManager = new FirebaseManager(this);

        emailText = findViewById(R.id.emailText);
        passwordText = findViewById(R.id.passwordText);
        secretText = findViewById(R.id.secretText);

    }

    public void showSecret(){
        secretText.setVisibility(View.VISIBLE);
    }

    public void hideSecret(){
        secretText.setVisibility(View.INVISIBLE);
    }

    public void signIn(View view){
        String email = emailText.getText().toString();
        String password = passwordText.getText().toString();
        if (email.length() > 0 && password.length() > 0) {
            firebaseManager.signIn(email, password, this);
        }
    }

    public void signUp(View view){
        String email = emailText.getText().toString();
        String password = passwordText.getText().toString();
        if (email.length() > 0 && password.length() > 0) {
            firebaseManager.signUp(email, password);
        }
    }

    public void signOut(View view){
        firebaseManager.signOut();
    }

    //keep this activity as slim as possible. put code in separate classes
}
