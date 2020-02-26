package com.example.recyclerviewdemo.view;

import android.content.Intent;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.recyclerviewdemo.Main2Activity;
import com.example.recyclerviewdemo.R;
import com.example.recyclerviewdemo.Storage.NoteStorage;


public class ViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener{

    public TextView textView;
    public ImageView imageView;
    public Button button;
    public static final String rowKey = "ROW_KEY";
    public int rowNumber = -1;  //number, which corresponds to the item's position in the lsot

    public ViewHolder(@NonNull View itemView) {
        super(itemView);
        LinearLayout linearLayout = (LinearLayout) itemView;
        textView = linearLayout.findViewById(R.id.textView1);
        imageView = linearLayout.findViewById(R.id.imageView);

        button = linearLayout.findViewById(R.id.button2);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                NoteStorage.getNode(rowNumber).toogleLike();
                if (NoteStorage.getNode(rowNumber).getLiked()){
                    String like = "liked";
                    button.setText(like);
                    button.setBackgroundResource(R.color.green);
                }
                else {
                    String liked = "Like";
                    button.setText(liked);
                    button.setBackgroundResource(android.R.drawable.btn_default);
                }
            }
        });

        textView.setOnClickListener(this);

        setTextViewListener();

    }

    public void setTextViewListener(){
        textView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(v.getContext(), Main2Activity.class);
                intent.putExtra(rowKey, rowNumber);
                v.getContext().startActivity(intent);
            }
        });


    }






    public void setData(int row){
        rowNumber = row;
        textView.setText(NoteStorage.getNode(rowNumber).headline);
        imageView.setImageResource(getImageId());
    }

    private int getImageId(){
        switch (rowNumber){
            case 0: return R.drawable.image0;
            case 1: return R.drawable.image1;
            case 2: return R.drawable.image2;
            case 3: return R.drawable.image3;
            case 4: return R.drawable.image4;
            case 5: return R.drawable.image5;
            case 6: return R.drawable.image6;
            case 7: return R.drawable.image7;
            case 8: return R.drawable.image8;
            case 9: return R.drawable.image9;
        }
        return R.drawable.image0;


    }

    @Override
    public void onClick(View v) {
        TextView tv = (TextView) v;
        Log.i("all", "du har klikket right " + tv.getText());
        //lave en ny activity hvor man kan se og redier details eller noget
        //Intent intent = new Intent()
    }





}
