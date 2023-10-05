package com.example.myapplication;

import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.os.SystemClock;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Chronometer;
import androidx.fragment.app.Fragment;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import java.util.Locale;

public class StopWatchFragment extends Fragment{
    private long timeStop=0;
    private Chronometer stopWatchChronometer;
    private FloatingActionButton pauseButton;
    private FloatingActionButton playButton;
    private FloatingActionButton refreshButton;

    public StopWatchFragment(){
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.activity_stop_watch, container, false);
        requireActivity().setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
        stopWatchChronometer= rootView.findViewById(R.id.cStopWatch);
        stopWatchChronometer.setOnChronometerTickListener(chronometer -> {
            long time= SystemClock.elapsedRealtime()-chronometer.getBase();
            int hours=(int)(time/3600000);
            int minutes=(int)(time-hours*3600000)/60000;
            int seconds=(int)(time-hours*3600000-minutes*60000)/1000;
            String timeToDisplay=String.format(Locale.getDefault(),
                    "%02d:%02d:%02d",
                    hours,minutes,seconds);
            chronometer.setText(timeToDisplay);
        });
        pauseButton= rootView.findViewById(R.id.pauseStopWatch);
        playButton= rootView.findViewById(R.id.playStopWatch);
        refreshButton= rootView.findViewById(R.id.refreshStopWatch);
        stopWatchChronometer.setBase(SystemClock.elapsedRealtime());
        onRefreshClicked();
        pauseButton.setOnClickListener(v -> onPauseClicked());
        playButton.setOnClickListener(v -> onPlayClicked());
        refreshButton.setOnClickListener(v -> onRefreshClicked());
        return rootView;
    }

    private void onPauseClicked(){
        timeStop=stopWatchChronometer.getBase()-SystemClock.elapsedRealtime();
        stopWatchChronometer.stop();
        playButton.setVisibility(View.VISIBLE);
        pauseButton.setVisibility(View.GONE);
        refreshButton.setVisibility(View.VISIBLE);
    }

    private void onPlayClicked(){
        stopWatchChronometer.setBase(SystemClock.elapsedRealtime() +timeStop);
        stopWatchChronometer.start();
        playButton.setVisibility(View.GONE);
        pauseButton.setVisibility(View.VISIBLE);
        refreshButton.setVisibility(View.VISIBLE);
    }

    private void onRefreshClicked(){
        stopWatchChronometer.stop();
        timeStop=0;
        stopWatchChronometer.setText(R.string.default_start_time);
        playButton.setVisibility(View.VISIBLE);
        pauseButton.setVisibility(View.GONE);
        refreshButton.setVisibility(View.GONE);
    }
}