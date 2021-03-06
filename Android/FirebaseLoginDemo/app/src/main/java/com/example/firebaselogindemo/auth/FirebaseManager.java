package com.example.firebaselogindemo.auth;

import android.app.Activity;

import androidx.annotation.NonNull;

import com.example.firebaselogindemo.MainActivity;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;

public class FirebaseManager {

    FirebaseAuth auth; //current user object
    private MainActivity mainActivity;

    public FirebaseManager(MainActivity activity) {
        auth = FirebaseAuth.getInstance();
        mainActivity = activity;
        setupAuthStateListener();

    }

    private void setupAuthStateListener(){
        auth.addIdTokenListener(new FirebaseAuth.IdTokenListener() {
            @Override
            public void onIdTokenChanged(@NonNull FirebaseAuth firebaseAuth) {
                if (firebaseAuth.getCurrentUser() == null){
                    System.out.println("Signed out from Firebase");
                    mainActivity.hideSecret();
                }
                else {
                    System.out.println("signed in  to Firebase");
                }
            }
        });
    }


    // sign in
    //will require email and password (min. 6 chars)

    public void signIn(String email, String pwd, final MainActivity activity){
        auth.signInWithEmailAndPassword(email, pwd).addOnCompleteListener(activity, new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                if (task.isSuccessful()) {
                    System.out.println("LOGIN success " + task.getResult().getUser().getEmail());
                    activity.showSecret(); // call the calling activity to show content.
                }
                else {
                    System.out.println("LOGIN failed " + task.getException());
                }
            }
        });
    }

    //singup
    public void signUp(String email, String pwd){
        auth.createUserWithEmailAndPassword(email, pwd).addOnCompleteListener(new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                if (task.isSuccessful()) {
                    System.out.println("SIGN UP success " + task.getResult().getUser().getEmail());
                }
                else {
                    System.out.println("SIGN UP failed " + task.getException());
                }
            }
        });
    }

    public void signOut(){
        auth.signOut();
    }

}
