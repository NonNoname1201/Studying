package com.example.lab1;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    int counter = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button clickMeButton = findViewById(R.id.clickMeButton);
        TextView helloTextView = findViewById(R.id.helloTextView);

        clickMeButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                helloTextView.setText(String.valueOf(counter));
                Toast.makeText(MainActivity.this, "Hello Android", Toast.LENGTH_LONG).show();
                counter++;
            }
        });
    }

}