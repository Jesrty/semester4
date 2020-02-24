package com.example.recyclerviewdemo.Storage;

import com.example.recyclerviewdemo.Model.Note;

import java.nio.file.FileStore;
import java.util.ArrayList;
import java.util.List;

public class NoteStorage {
    private static FileStorage fileStorage;
    private static List<Note> list;
    private static final String filename = "data.dat";
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

    public static void setFileStorage(FileStorage fs){
        fileStorage = fs;
    }

    public static void saveNotesToFile(){
        fileStorage.saveToFile(list, filename);
    }

    public static void readNotesFromFile(){
        Object object = fileStorage.readObject(filename);
        if (object != null){
            list = (List<Note>) object;
        }
    }


    public static Note getNode(int index){
        return list.get(index);
    }

    public static int getlength(){
        return list.size();
    }

}
