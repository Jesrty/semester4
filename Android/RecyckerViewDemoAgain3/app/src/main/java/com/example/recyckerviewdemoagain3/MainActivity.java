package com.example.recyckerviewdemoagain3;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.widget.AbsListView;
import android.widget.TextView;

import com.example.recyckerviewdemoagain3.adapter.MyAdapter;
import com.example.recyckerviewdemoagain3.storage.NoteStorage;

public class MainActivity extends AppCompatActivity {

    private RecyclerView recyclerView;
    private MyAdapter myAdapter;
    private boolean isLastItemReached;
    private boolean isScrolling;
    private LinearLayoutManager layoutManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        NoteStorage.init(this);
        recyclerView = findViewById(R.id.RecyclerView1);
        layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        myAdapter= new MyAdapter(new NoteStorage());
        recyclerView.setAdapter(myAdapter);
        setUpScrollListener();
    }
    public void notifyAdapter(){
        myAdapter.notifyDataSetChanged();
    }

    public void setIsLastItemReahed(boolean b){
        isLastItemReached = b;
    }


    private void setUpScrollListener(){
        RecyclerView.OnScrollListener scrollListener = new RecyclerView.OnScrollListener() {
            @Override
            public void onScrollStateChanged(@NonNull RecyclerView recyclerView, int newState) {
                super.onScrollStateChanged(recyclerView, newState);
                if (newState == AbsListView.OnScrollListener.SCROLL_STATE_TOUCH_SCROLL){
                    isScrolling = true; //use this later to prevent multiple calls to firebase
                }
            }

            @Override
            public void onScrolled(@NonNull RecyclerView recyclerView, int dx, int dy) {
                super.onScrolled(recyclerView, dx, dy);
                int firstVisibleItemPosition = layoutManager.findFirstVisibleItemPosition();
                int visibleItemCount = layoutManager.getChildCount(); // get how many items are visible
                int totalItemCount = layoutManager.getItemCount(); // how many items are available in the adaptor

                if (isScrolling && (firstVisibleItemPosition + visibleItemCount == totalItemCount) && !isLastItemReached){
                    isScrolling = false; // to prevent exstra calls to firebase
                    NoteStorage.getNextNotes(); // this will load the next 5 item from firebase, starting after the last one
                }


            }
        };
        recyclerView.addOnScrollListener(scrollListener);
    }


}
