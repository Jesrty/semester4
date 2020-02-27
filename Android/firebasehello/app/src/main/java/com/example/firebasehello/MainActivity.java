package com.example.firebasehello;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;

import com.google.firebase.firestore.DocumentReference;
import com.google.firebase.firestore.DocumentSnapshot;
import com.google.firebase.firestore.EventListener;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.FirebaseFirestoreException;
import com.google.firebase.firestore.QuerySnapshot;

import org.w3c.dom.Document;

import java.util.HashMap;
import java.util.Map;

public class MainActivity extends AppCompatActivity {

    private final static String notes = "notes";
    FirebaseFirestore db = FirebaseFirestore.getInstance();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //addNewNote();
        startNoteListener();
        //deleteNote();
        //editNote();


    }

    private void editNote() {
        DocumentReference docRef = db.collection(notes).document("RN8qxR84ZdJTMJTB4wZK\n");
        Map<String, String> map = new HashMap<>();
        map.put("head", "changed head ");
        map.put("body", "changed body");
        docRef.set(map);
    }

    private void deleteNote() {
        DocumentReference docRef = db.collection(notes).document("hbZP4GkYxI61Cy3qtvfD");
        docRef.delete();
    }

    private void startNoteListener() {
        db.collection(notes).addSnapshotListener(new EventListener<QuerySnapshot>() {
            @Override
            public void onEvent(@Nullable QuerySnapshot values, @Nullable FirebaseFirestoreException e) {

                for (DocumentSnapshot snap : values.getDocuments()){
                    Log.i("all", "read from FB"  + snap.getId() + "" + snap.get("head").toString() + " " + snap.get("body").toString());
                }
            }
        });
    }

    private void addNewNote() {
        DocumentReference docRef = db.collection(notes).document();
        Map<String, String> map = new HashMap<>();
        map.put("head", "new headline 2");
        map.put("body", "new body 2");
        docRef.set(map);
    }
}
