package com.example.pickme;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button button1 = findViewById(R.id.button1);
        Button button2 = findViewById(R.id.button2);
        Button button3 = findViewById(R.id.button3);

        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                customerLogin();
            }
        });
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                customerLogin();
            }
        });
        button3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                customerLogin();
            }
        });
    }
    public void customerLogin() {
        Intent intent = new Intent(this, customerLogin.class);
        startActivity(intent);
    }
    public void businessOwnerLogin(){
        Intent intent = new Intent(this, customerLogin.class);
        startActivity(intent);
    }
    public void administratorLogin() {
        Intent intent = new Intent(this, customerLogin.class);
        startActivity(intent);
    }
}