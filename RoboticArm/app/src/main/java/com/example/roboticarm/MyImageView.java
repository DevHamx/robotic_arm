package com.example.roboticarm;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.util.Log;
import android.view.View;

import androidx.appcompat.widget.AppCompatImageView;

import java.util.ArrayList;
import java.util.List;

public class MyImageView extends AppCompatImageView
{
    Canvas canvas;
    ArrayList<int[]> lines = new ArrayList<int[]>();


    public MyImageView(Context context) {
        super(context);
       // setFocusable(true);
        invalidate();
    }

    public MyImageView(Context context, AttributeSet attrs)
    {
        super(context,attrs);
       // setFocusable(true);
        invalidate();
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        this.canvas=canvas;
        Paint p = new Paint(Paint.ANTI_ALIAS_FLAG);
        p.setColor(Color.RED);
        for (int i=0;i<lines.size();i++){
            Log.d("ondraw", lines.get(i)[1]+"");
            canvas.drawLine(lines.get(i)[0], lines.get(i)[1], 100, 100, p);
        }
    }

}
