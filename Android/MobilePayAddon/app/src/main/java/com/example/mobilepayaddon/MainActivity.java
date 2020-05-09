package com.example.mobilepayaddon;

import androidx.appcompat.app.AppCompatActivity;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.SeekBar;

public class MainActivity extends AppCompatActivity implements SensorEventListener {

    private SensorManager sm;
    private Sensor gyroSensor;
    private SeekBar seekBar;
    private ImageView starView;
    private float seekbarMax = 100;
    private float seekbarCurrent = 10;
    private float aplifier = 3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        seekBar = findViewById(R.id.seekBar);
        starView = findViewById(R.id.imageView);
        seekBar.setMax((int) seekbarMax);
        sm = (SensorManager) getSystemService(SENSOR_SERVICE);
        gyroSensor = sm.getDefaultSensor(Sensor.TYPE_GAME_ROTATION_VECTOR);     //no magnetic field

    }

    public void startPaymentPressed(View view){
        startMotionSensor();
    }

    private void startMotionSensor(){
        sm.registerListener(this, gyroSensor, SensorManager.SENSOR_DELAY_NORMAL);
    }


    @Override
    public void onSensorChanged(SensorEvent event) {
        float y = event.values[1]; // x=0, y = 1 & z = 2
        if (y > 0.01){
            seekbarCurrent = seekbarMax * y * aplifier;    //y is < 1
            seekBar.setProgress((int) seekbarCurrent);
            if (seekbarCurrent > seekbarMax){
                starView.setVisibility(View.VISIBLE);   //show the img/star
                sm.unregisterListener(this);    //stop listening
            }
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }

    @Override
    protected void onPause() {
        super.onPause();
        sm.unregisterListener(this);    //this will stop listening, when app is paused
    }
}
