package com.example.pickme;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class customerLogin extends AppCompatActivity {

    String customerUsername;
    String customerPassword;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);


        Button customerLoginButton = findViewById(R.id.customerLoginButton);
        Button customerCreateAccountButton = findViewById(R.id.customerCreateAccountButton);

        customerCreateAccountButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                customerCreateAccount();
            }
        });
        customerLoginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //studentEmail= customerUsernameInput.getText().toString();
                //studentPassword = customerPasswordInput.getText().toString();
                //showToast(customerUsername);
                //showToast(customerPassword);
                mainPage();
            }
        });
    }
    public void customerCreateAccount(){
        Intent intent = new Intent(this, createAnAccount.class);
        startActivity(intent);
    }
    public void mainPage(){
        Intent intent = new Intent(this, mainPage.class);
        startActivity(intent);
    }
    private void showToast(String text){
        Toast.makeText(customerLogin.this, text, Toast.LENGTH_SHORT).show();
    }
}