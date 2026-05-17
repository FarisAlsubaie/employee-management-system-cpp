package com.example.pickme;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.textfield.TextInputLayout;

public class customerBusinessInfo extends AppCompatActivity {

    //Variables
    TextInputLayout businessName, businessLocation, businessIndustry, businessEmployeeCount;
    Button businessList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_business_info);

        //This hooks all elements
        businessName = findViewById(R.id.companyName);
        businessLocation = findViewById(R.id.companyLocation);
        businessIndustry = findViewById(R.id.companyIndustry);
        businessEmployeeCount = findViewById(R.id.companyEmployeeCount);
        businessList = findViewById(R.id.companyList);

        businessList.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                //if any is not valid and returns false, the errors will be shown
                if (!validateBusinessName() || !validateBusinessLocation() || !validateBusinessIndustry() || !validateBusinessEmployeeCount()) {
                    return;
                }

                //Get all the values
                String name = businessName.getEditText().getText().toString();
                String location = businessLocation.getEditText().getText().toString();
                String industry = businessIndustry.getEditText().getText().toString();
                String employeeCount = businessEmployeeCount.getEditText().getText().toString();

                businessList();
            }
        });

    }
    public void businessList(){
        Intent intent = new Intent(this, customerBusinessList.class);
        startActivity(intent);
    }

    private Boolean validateBusinessName() {
        String val = businessName.getEditText().getText().toString();

        if (val.isEmpty()) {
            businessLocation.setError("Field can not be empty");
            return false;
        }
        else {
            businessLocation.setError(null);
            return true;
        }
    }


    private Boolean validateBusinessLocation() {
        String val = businessLocation.getEditText().getText().toString();

        if (val.isEmpty()) {
            businessLocation.setError("Field can not be empty");
            return false;
        }
        else {
            businessLocation.setError(null);
            return true;
        }
    }

    private Boolean validateBusinessIndustry() {
        String val = businessIndustry.getEditText().getText().toString();

        if (val.isEmpty()) {
            businessIndustry.setError("Field cannot be empty");
            return false;
        }
        else {
            businessIndustry.setError(null);
            return true;
        }
    }

    private Boolean validateBusinessEmployeeCount() {
        String val = businessEmployeeCount.getEditText().getText().toString();

        if (val.isEmpty()) {
            businessEmployeeCount.setError("Field cannot be empty");
            return false;
        }
        else {
            businessEmployeeCount.setError(null);
            return true;
        }
    }
}