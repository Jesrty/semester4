package com.example.recyclerviewdemo.Storage;

import com.example.recyclerviewdemo.Model.Note;

import java.util.ArrayList;
import java.util.List;

public class NoteStorage {
    private static List<Note> list;
    static {
        list = new ArrayList<>();
        Note note = new Note("note 1", "body 1");
        list.add(note);
        list.add(note);
        list.add(note);
        list.add(note);
        list.add(note);
        list.add(note);
        list.add(note);
        list.add(note);
        list.add(note);
        list.add(note);

    }

    public static Note getNode(int index){
        return list.get(index);
    }

    public static int getlength(){
        return list.size();
    }

}
