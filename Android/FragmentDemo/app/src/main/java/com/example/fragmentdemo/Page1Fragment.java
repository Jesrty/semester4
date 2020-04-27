package com.example.fragmentdemo;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import java.util.ArrayList;
import java.util.List;

public class Page1Fragment extends Fragment {

    private Button button;
    private ListView listView;
    private List<String> list = new ArrayList<>();
    MainActivity mainActivity;


    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        View view = inflater.inflate(R.layout.page1layout, container, false);

        button = view.findViewById(R.id.buttonP1Action);
        button.setOnClickListener(v -> {
            System.out.println("page 1 action");
        });
        return view;
    }


}
