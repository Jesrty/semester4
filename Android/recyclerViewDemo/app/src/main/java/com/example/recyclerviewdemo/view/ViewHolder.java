package com.example.recyclerviewdemo.view;

import android.content.Intent;
import android.util.Log;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.recyclerviewdemo.R;

import java.time.Instant;

public class ViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener{

    public TextView textView;

    public ViewHolder(@NonNull View itemView) {
        super(itemView);
        LinearLayout linearLayout = (LinearLayout) itemView;
        textView = linearLayout.findViewById(R.id.textView1);
        textView.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        TextView tv = (TextView) v;
        Log.i("all", "du har klikket right " + tv.getText());
        //lave en ny activity hvor man kan se og redier details eller noget
        //Intent intent = new Intent()
    }
}
