package com.example.imagedemowhithrefactor;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;

import com.example.imagedemowhithrefactor.controller.ImageController;

import java.io.FileNotFoundException;
import java.io.InputStream;

public class MainActivity extends AppCompatActivity {

    public ImageView imageView;
    private ImageController ic;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        imageView = findViewById(R.id.imageView);

        ic = new ImageController(this);
        isStoragePermissionGranted();
    }



    public void photoRollBtnPressed(View view){
        Intent intent = new Intent(Intent.ACTION_PICK);
        intent.setType("image/*");
        startActivityForResult(intent, 0); //0 means photo roll, 1 means camera
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        System.out.println("test1");
        if(resultCode != -1) return; //-1 indicates ok
        ic.handleImageReturn(requestCode, data, this);
        System.out.println("test2 " + data + " - " + requestCode);

    }

    private boolean isStoragePermissionGranted(){
        if (Build.VERSION.SDK_INT >= 23){
            if ((this.checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED)){
                System.out.println("Permission Granted");
                return true;
            }else{
                System.out.println("Permission revoked");
                ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE}, 1);
                return false;
            }
        }else{
            System.out.println("Permission is granted");
            return true;
        }

    }

    public void cameraBtnPressed(View view){
        System.out.println("test3");
        Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        startActivityForResult(intent, 1);
        System.out.println("test4");
    }

}
