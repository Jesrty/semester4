package com.example.mobilepayaddon;

import androidx.appcompat.app.AppCompatActivity;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.widget.TextView;

public class ShackActivity extends AppCompatActivity implements SensorEventListener {

    private TextView textView;
    private SensorManager sm;
    private Sensor accSensor;
    private static final int SHAKE_THRESHOLD = 45;
    private long lastUpdate = 0; //to keep track of amount of time between sensor data
    private float lastX, lastY, lastZ;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_shack);
        textView = findViewById(R.id.textView3);
        sm = (SensorManager) getSystemService(SENSOR_SERVICE);
        accSensor = sm.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        sm.registerListener(this, accSensor, SensorManager.SENSOR_DELAY_NORMAL);
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        float x = event.values[0];
        long currentTime = System.currentTimeMillis();
        long deeltaTime = currentTime - lastUpdate;
        if(deeltaTime > 300){
            float speed = Math.abs(x-lastX)/deeltaTime*10000;
            lastUpdate = currentTime;
            if (speed > SHAKE_THRESHOLD){
                textView.setText("Stop shaking!!!");
            }
            lastX = x;
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }
}
