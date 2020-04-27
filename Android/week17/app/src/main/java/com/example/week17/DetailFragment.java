package com.example.week17;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

public class DetailFragment extends Fragment {

    private TextView textView;
    Button btnBack;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.layout_detail, container, false);
        textView = v.findViewById(R.id.detailText);
        btnBack = v.findViewById(R.id.butBack);
        btnBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                getFragmentManager().beginTransaction().replace(R.id.fragmentCon, new ListFragment()).commit();
            }
        });

        Bundle data = getArguments();
        if (data != null){
            String text = data.getString("key");
            textView.setText("You clicked number: " + text);
        }
        return v;
    }
}
