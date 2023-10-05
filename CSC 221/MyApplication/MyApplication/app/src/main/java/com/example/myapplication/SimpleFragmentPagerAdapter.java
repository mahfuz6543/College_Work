package com.example.myapplication;

import android.content.Context;

import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentPagerAdapter;

public class SimpleFragmentPagerAdapter extends FragmentPagerAdapter{
    private Context tContext;

    public SimpleFragmentPagerAdapter(Context context,FragmentManager fragmentManager){
        super(fragmentManager);
        tContext = context;
    }

    @Override
    public Fragment getItem(int position){
        if (position == 0){
            return new StopWatchFragment();
        }
        else{
            return new TimerFragment();
        }
    }

    @Nullable
    @Override
    public CharSequence getPageTitle(int position){
        if (position==0){
            return tContext.getString(R.string.stopwatch);
        }
        else{
            return tContext.getString(R.string.timer);
        }
    }

    @Override
    public int getCount(){
        return 2;
    }
}
