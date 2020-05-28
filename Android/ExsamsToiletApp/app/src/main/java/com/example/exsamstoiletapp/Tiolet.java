package com.example.exsamstoiletapp;

import java.util.ArrayList;
import java.util.List;

public class Tiolet {

    private String name;
    private double lat;
    private double lon;
    private List<String> toiletQList = new ArrayList<>();

    public List<String> getToiletQList() {
        return toiletQList;
    }



    public void addMan(String name){
        toiletQList.add(name);
    }
    public void removeMan(String name){
        toiletQList.remove(name);
    }


    public Tiolet(String name, double lat, double lon) {
        this.name = name;
        this.lat = lat;
        this.lon = lon;
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
