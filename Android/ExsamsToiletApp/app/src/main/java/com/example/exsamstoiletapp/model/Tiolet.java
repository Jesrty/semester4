package com.example.exsamstoiletapp.model;

import java.util.ArrayList;
import java.util.List;

public class Tiolet {

    private String name;
    private double lat;
    private double lon;
    private ArrayList<String> toiletQList = new ArrayList<>();

    public ArrayList getToiletQList() {
        return toiletQList;
    }


    public void addToQ(String name){
        toiletQList.add(name);
    }
    public void removeFromQ(String name){
        toiletQList.remove(name);
    }

    public Tiolet(String name, double lat, double lon, ArrayList<String> toiletQList) {
        this.name = name;
        this.lat = lat;
        this.lon = lon;
        this.toiletQList = toiletQList;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getLat() {
        return lat;
    }

    public void setLat(double lat) {
        this.lat = lat;
    }

    public double getLon() {
        return lon;
    }

    public void setLon(double lon) {
        this.lon = lon;
    }
}
