package com.example.myapplication;

import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.NumberPicker;
import android.widget.TextView;
import androidx.fragment.app.Fragment;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import java.util.Locale;


public class TimerFragment extends Fragment {
    private boolean wasRunning;
    private int tHours;
    private int tMinutes;
    private int tSeconds;
    private long secondsLeft;
    private boolean sDefault;
    private FloatingActionButton playButton;
    private FloatingActionButton pauseButton;
    private FloatingActionButton refreshButton;
    private TextView textTimer;
    private LinearLayout timerLayout;
    private CountDownTimer countDownTimer;

    public TimerFragment() {
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.activity_timer, container, false);
        requireActivity().setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
        sDefault = false;

        NumberPicker hoursNumberPicker=rootView.findViewById(R.id.hours);
        NumberPicker minutesNumberPicker=rootView.findViewById(R.id.minutes);
        NumberPicker secondsNumberPicker=rootView.findViewById(R.id.seconds);

        timerLayout= rootView.findViewById(R.id.timer);
        textTimer= rootView.findViewById(R.id.cTimer);

        hoursNumberPicker.setMinValue(0);
        hoursNumberPicker.setMaxValue(23);
        hoursNumberPicker.setFormatter(i -> String.format(Locale.getDefault(),"%02d", i));
        hoursNumberPicker.setOnValueChangedListener((picker, oldVal, newVal) -> tHours = newVal);

        minutesNumberPicker.setMinValue(0);
        minutesNumberPicker.setMaxValue(59);
        minutesNumberPicker.setFormatter(i -> String.format(Locale.getDefault(),"%02d", i));
        minutesNumberPicker.setOnValueChangedListener((picker, oldVal, newVal) -> {
            sDefault = true;
            tMinutes = newVal;
        });

        secondsNumberPicker.setMinValue(0);
        secondsNumberPicker.setMaxValue(59);
        secondsNumberPicker.setFormatter(i -> String.format(Locale.getDefault(),"%02d", i));
        secondsNumberPicker.setOnValueChangedListener((picker, oldVal, newVal) -> tSeconds = newVal);

        pauseButton = rootView.findViewById(R.id.pauseTimer);
        playButton = rootView.findViewById(R.id.playTimer);
        refreshButton = rootView.findViewById(R.id.refreshTimer);

        onRefreshClicked();

        pauseButton.setOnClickListener(v -> onStopClicked());

        playButton.setOnClickListener(v -> onPlayClicked());

        refreshButton.setOnClickListener(v -> onRefreshClicked());
        updateText();
        return rootView;
    }

    @Override
    public void onStop(){
        super.onStop();
    }

    private void onStopClicked(){
        countDownTimer.cancel();
        wasRunning = true;
        pauseButton.setVisibility(View.GONE);
        playButton.setVisibility(View.VISIBLE);
        refreshButton.setVisibility(View.VISIBLE);
    }

    private void onPlayClicked(){
        if(!wasRunning){
            if(!sDefault)
                tMinutes=0;
            secondsLeft=(tHours*3600+tMinutes*60+tSeconds)*1000;
        }
        if(secondsLeft>0){
            countDownTimer=new CountDownTimer(secondsLeft,1000){
                @Override
                public void onTick(long timeFinished){
                    secondsLeft=timeFinished;
                    updateText();
                }
                @Override
                public void onFinish(){
                    wasRunning=false;
                    onRefreshClicked();
                }
            }.start();
            wasRunning=false;
            playButton.setVisibility(View.GONE);
            pauseButton.setVisibility(View.VISIBLE);
            refreshButton.setVisibility(View.INVISIBLE);
            timerLayout.setVisibility(View.GONE);
            textTimer.setVisibility(View.VISIBLE);
        }
    }

    private void onRefreshClicked(){
        wasRunning=false;
        secondsLeft=0;
        playButton.setVisibility(View.VISIBLE);
        pauseButton.setVisibility(View.GONE);
        refreshButton.setVisibility(View.GONE);
        timerLayout.setVisibility(View.VISIBLE);
        textTimer.setVisibility(View.GONE);
    }

    private void updateText(){
        int hours=(int)(secondsLeft/1000)/3600;
        int minutes=(int)((secondsLeft/1000)%3600)/60;
        int seconds=(int)(secondsLeft/1000)%60;
        String time=String.format(Locale.getDefault(),"%02d:%02d:%02d",hours,minutes,seconds);
        textTimer.setText(time);
    }
}