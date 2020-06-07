package com.example.toiletapp_v2.storage;

import android.widget.ArrayAdapter;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.toiletapp_v2.Main2Activity;
import com.example.toiletapp_v2.MainActivity;
import com.example.toiletapp_v2.model.Tiolet;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.firestore.CollectionReference;
import com.google.firebase.firestore.DocumentReference;
import com.google.firebase.firestore.DocumentSnapshot;
import com.google.firebase.firestore.EventListener;
import com.google.firebase.firestore.FieldValue;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.FirebaseFirestoreException;
import com.google.firebase.firestore.Query;
import com.google.firebase.firestore.QuerySnapshot;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FirebaseRepo {
    private static FirebaseFirestore fb = FirebaseFirestore.getInstance();
    private static final String colectionRef = "toilet";
    public static CollectionReference collectionReference = fb.collection(colectionRef);

    public static void addToFirebaseQ(){
        if (MainActivity.tempArrayIndex == 0) {
            collectionReference.document("7V9jYaoDzz1iIBVMxpqc").update("toiletQList", MainActivity.toilets.get(MainActivity.tempArrayIndex).getToiletQList());
        }
        else if (MainActivity.tempArrayIndex == 1) {
            collectionReference.document("92pGNewuxLZMR3fErSwS").update("toiletQList", MainActivity.toilets.get(MainActivity.tempArrayIndex).getToiletQList());
        }
        else if (MainActivity.tempArrayIndex == 2) {
            collectionReference.document("JL8PgdoyboWuCwrFvDpn").update("toiletQList", MainActivity.toilets.get(MainActivity.tempArrayIndex).getToiletQList());
        }

        /*  adds a hole new document witch i don't want to do
        MainActivity.toilets.get(MainActivity.tempArrayIndex).getToiletQList();
        Tiolet tiolet = new Tiolet(MainActivity.toilets.get(MainActivity.tempArrayIndex).getName(),
                                   MainActivity.toilets.get(MainActivity.tempArrayIndex).getLat(),
                                   MainActivity.toilets.get(MainActivity.tempArrayIndex).getLon(),
                                   MainActivity.toilets.get(MainActivity.tempArrayIndex).getToiletQList());
        collectionReference.add(tiolet);
         */
    }

    public static void loadList(){
        fb.collection(colectionRef).addSnapshotListener(new EventListener<QuerySnapshot>() {
            @Override
            public void onEvent(@Nullable QuerySnapshot queryDocumentSnapshots, @Nullable FirebaseFirestoreException e) {
                MainActivity.toilets.clear();
                for (DocumentSnapshot snapshot : queryDocumentSnapshots.getDocuments()){
                    String name = snapshot.get("name").toString();
                    double lat = Double.valueOf(snapshot.get("lat").toString());
                    double lon = Double.valueOf(snapshot.get("lon").toString());
                    ArrayList<String> arrayList = (ArrayList) snapshot.get("toiletQList");

                    MainActivity.toilets.add(new Tiolet(name, lat, lon, arrayList));
                }
                Main2Activity.adapterNotify();
            }
        });
    }




    public static void removeFromFirebaseQ(String name){
        if (MainActivity.tempArrayIndex == 0) {
            collectionReference.document("7V9jYaoDzz1iIBVMxpqc").update("toiletQList", FieldValue.arrayRemove(name));
        }
        else if (MainActivity.tempArrayIndex == 1) {
            collectionReference.document("92pGNewuxLZMR3fErSwS").update("toiletQList", FieldValue.arrayRemove(name));
        }
        else if (MainActivity.tempArrayIndex == 2) {
            collectionReference.document("JL8PgdoyboWuCwrFvDpn").update("toiletQList", FieldValue.arrayRemove(name));
        }
    }





}
