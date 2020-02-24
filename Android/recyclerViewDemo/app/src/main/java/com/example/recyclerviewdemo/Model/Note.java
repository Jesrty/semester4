package com.example.recyclerviewdemo.Model;

import java.io.Serializable;

public class Note implements Serializable {

    static final long serialVersionUID = 42;
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
