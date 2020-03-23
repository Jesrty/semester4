package com.example.imagedemowhithrefactor.controller;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.MediaScannerConnection;
import android.net.Uri;
import android.os.Environment;
import android.provider.MediaStore;
import android.util.Log;

import androidx.annotation.Nullable;

import com.example.imagedemowhithrefactor.MainActivity;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.UUID;

public class ImageController {

    private MainActivity mainActivity;

    public ImageController(MainActivity mainActivity) {
        this.mainActivity = mainActivity;
    }

    public void handleImageReturn(int requestCode, @Nullable Intent data, Context context) {
        if (requestCode == 0){
            Uri uri = data.getData();
            try {
                InputStream is = mainActivity.getContentResolver().openInputStream(uri);
                Bitmap bitmap = BitmapFactory.decodeStream(is);
                mainActivity.imageView.setImageBitmap(bitmap);

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        if (requestCode == 1){
            Bitmap bitmap = (Bitmap) data.getExtras().get("data");

            String root = Environment.getExternalStorageDirectory().toString();
            File file = new File(root, "/saved_images");
            if (!file.exists()){
                file.mkdirs();
            }

            String name = "Image-" + UUID.randomUUID().toString() + ".jpg";
            File f = new File(file, name);

            try {
                f.createNewFile();
                FileOutputStream fos = new FileOutputStream(f);
                bitmap.compress(Bitmap.CompressFormat.JPEG, 90, fos);
                fos.flush();
                fos.close();
            } catch (Exception e) {
                e.printStackTrace();
            }

            MediaScannerConnection.scanFile(context, new String[]{f.toString()}, new String[]{f.getName()}, null);

            mainActivity.imageView.setImageBitmap(bitmap);

        }
    }

}
