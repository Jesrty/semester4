package com.example.string_to_file;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class MainActivity extends AppCompatActivity {
    private TextView textView;
    private final String file = "text.dat";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = findViewById(R.id.textView);
        saveToFile("hello there", "text.dat");
        Object obj = readObject(file);
        String text = (String)obj;
        textView.setText(text);
    }

    private void saveToFile(Object obj, String fileName){
        try {
            FileOutputStream fos = new FileOutputStream(getFileObject(fileName));
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(obj);

            Log.i("all", "OK writing");
        }
        catch (Exception e) {
            Log.i("all", "error writing " + e.getMessage());
        }
    }

    private File getFileObject(String fileName){
        File path = getFilesDir();
        return new File(path, fileName);
    }

    private Object readObject(String fileName){
        Object obj = null;
        try{
            FileInputStream fis = new FileInputStream(getFileObject(fileName));
            ObjectInputStream ois = new ObjectInputStream(fis);
            obj = ois.readObject();
            ois.close();
        }
        catch (Exception e){
            Log.i("all", "error reading " + e.getMessage());
        }
        return obj;
    }
}
