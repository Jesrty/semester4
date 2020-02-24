package com.example.recyclerviewdemo.Model;

public class Note {
    public String headline;
    public String body;
    private  boolean liked = false;

    public Note(String headline, String body) {
        this.headline = headline;
        this.body = body;
    }

    public void toogleLike(){
        liked = !liked;
    }
    public boolean getLiked(){
        return liked;
    }
}
