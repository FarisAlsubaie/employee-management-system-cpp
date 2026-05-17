package com.example.pickme;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class createAnAccount extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_create_account);

        Button goStudentCred = findViewById(R.id.continueCustomerButton);
        goStudentCred.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mainPage();
            }
        });
    }
    public void mainPage(){
        Intent intent = new Intent(this, customerBusinessInfo.class);
        startActivity(intent);
    }
}