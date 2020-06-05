package com.example.exsamstoiletapp.storage;

import androidx.annotation.Nullable;

import com.example.exsamstoiletapp.MainActivity;
import com.example.exsamstoiletapp.model.Tiolet;
import com.google.firebase.firestore.DocumentSnapshot;
import com.google.firebase.firestore.EventListener;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.FirebaseFirestoreException;
import com.google.firebase.firestore.QuerySnapshot;

import java.util.ArrayList;

public class FirebaseRepo {

    private static FirebaseFirestore fb = FirebaseFirestore.getInstance();
    private static String colectionRef = "toilet";

    public static void loadList(){
        System.out.println("_-----------_______________");
        fb.collection(colectionRef).addSnapshotListener(new EventListener<QuerySnapshot>() {
            @Override
            public void onEvent(@Nullable QuerySnapshot queryDocumentSnapshots, @Nullable FirebaseFirestoreException e) {
                MainActivity.toilets.clear();
                for (DocumentSnapshot snapshot : queryDocumentSnapshots){
                    System.out.println("11111111111");
                    String name = snapshot.get("name").toString();
                    double lat = Double.valueOf(snapshot.get("lat").toString());
                    double lon = Double.valueOf(snapshot.get("lon").toString());
                    ArrayList<String> arrayList = (ArrayList) snapshot.get("toiletQList");

                    MainActivity.toilets.add(new Tiolet(name, lat, lon, arrayList));
                }
            }
        });
    }




}
