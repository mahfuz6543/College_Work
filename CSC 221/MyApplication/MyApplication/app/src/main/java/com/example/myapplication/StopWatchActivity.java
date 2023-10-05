package com.example.myapplication;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

public class StopWatchActivity extends AppCompatActivity
{
    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_stop_watch);
        getSupportFragmentManager().beginTransaction()
                .replace(androidx.appcompat.R.id.action_bar_container, new StopWatchFragment())
                .commit();
    }
}