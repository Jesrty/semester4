package com.example.toiletapp_v2;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.ListView;

import com.example.toiletapp_v2.model.Tiolet;
import com.example.toiletapp_v2.storage.FirebaseRepo;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    public static ArrayList<Tiolet> toilets = new ArrayList<>();
    EditText editText;
    ListView listView;

    //123
    LocationManager locationManager;
    LocationListener locationListener;
    //

    public static int tempArrayIndex = -1;
    public static double testLon = 0;
    public static double testLat = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editText = findViewById(R.id.editText);
        listView = findViewById(R.id.listView);

        FirebaseRepo.loadList();

        //123
        locationManager = (LocationManager) this.getSystemService(Context.LOCATION_SERVICE);
        locationListener = new LocationListener() {
            @Override
            public void onLocationChanged(Location location) {
                testLon = location.getLongitude();
                testLat = location.getLatitude();
            }

            @Override
            public void onStatusChanged(String provider, int status, Bundle extras) {

            }

            @Override
            public void onProviderEnabled(String provider) {

            }

            @Override
            public void onProviderDisabled(String provider) {

            }
        };
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED)
        {
            ActivityCompat.requestPermissions(this, new String[] {Manifest.permission.ACCESS_FINE_LOCATION}, 1);
        } else {
            locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 0, 0, locationListener);
        }

        //
    }

    //123
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);

        if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
            if(ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
                locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 0, 0, locationListener);
            }
        }
    }
    //



    private Integer closedToilet(){
        double tempCloseDist = 999;
        double distance;
        for (int i = 0; i<toilets.size(); i++){
            distance = Math.sqrt(
                    ((testLat - toilets.get(i).getLat())*(testLat - toilets.get(i).getLat()))+
                    ((testLon - toilets.get(i).getLon())*(testLon - toilets.get(i).getLon()))
            );
            if (distance<tempCloseDist){
                tempArrayIndex = i;
                tempCloseDist = distance;
            }
        }
        if (tempArrayIndex != -1){
            return tempArrayIndex;
        }
        else{
            return null;
        }
    }

    private boolean lockedEditText = false;
    public void tilslut(View view){
        if (!editText.getText().toString().equals("") && !toilets.get(closedToilet()).getToiletQList().contains(editText.getText().toString())){

            toilets.get(closedToilet()).addToQ(editText.getText().toString());
            FirebaseRepo.addToFirebaseQ();

            editText.setEnabled(false);
            lockedEditText = true;

            Intent intent = new Intent(this, Main2Activity.class);
            intent.putExtra("indexValue", tempArrayIndex);
            startActivity(intent);
        }
    }

    public void forlad(View view){
        if (toilets.get(closedToilet()).getToiletQList().contains(editText.getText().toString()) && lockedEditText){
            //toilets.get(closedToilet()).removeFromQ(editText.getText().toString());

            FirebaseRepo.removeFromFirebaseQ(editText.getText().toString());

            editText.setEnabled(true);
            lockedEditText = false;
        }
    }

    public void mapButton(View view){
        Intent intent = new Intent(this, MapsActivity.class);
        startActivity(intent);
    }
}
