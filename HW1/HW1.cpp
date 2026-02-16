#include <iostream> //library for input and output 
#include <string> //for string 
#include <iomanip> //for formatting
using namespace std; //meant to prevent name conflicts 

//Homework Question 1
int time_s; //input 
int hour, minute, second; //output
float re_h, re_m;//remainder hour and minutes 
//Homework Question 2
float hours_worked; //input
int dependents; //input
float rate, overtime_rate = 1.5f; //overtime rate
float gross_pay; //output
float ss_tax; //social security tax 
float fed_tax;   //federal tax
float state_tax; //state tax 
float bethlehem_tax; //bethlehem city tax 
float union_fees; //union fees
float health_fees; //health fees
//Homework Question 3
float balance; //loan amount also the same as the balance 
float principal; //principal
float interest_rate; //interest rate
float monthly_payment  = 50.0f; //monthly payment
float total_interest; //total interest
float total_paid; //total paid

int main() {
    //Homework Question 1
    cout << "Enter time in seconds" << endl; //print output, endl starts a new line 
    cin >> time_s; //time input 
  
    //hour, minute, second calculation
    hour = time_s / 3600; //calculates the hours 
    minute = (time_s % 3600) / 60; //calculates the reaminging minutes 
    second = (time_s % 3600) % 60; //calculated the remaining seconds 
    
    cout << "The time is: " << hour << " hours, " << minute << " minutes, and " << second << " seconds." << endl;
    
    cout.setf(ios::fixed); //sets the float to fixed
    cout.setf(ios::showpoint); //shows the decimal point
    cout.precision(4); //sets the precision to 4 decimal places
    re_h = (time_s / 3600.0f); //calculates the time in hours with decimal
    re_m = (time_s / 60.0f); //calculates the time in minutes with decimal
    
    cout << "The time in hours is: " << re_h << " hours." << "The time in minutes is: " << re_m << " minutes." << endl;
    
    //Homework Question 2
    cout << "Enter the number of hours worked: " << endl; //print output;
    cin >> hours_worked; //hours worked input
    cout << "Enter the number of dependents: " << endl; //print output;
    cin >> dependents ; //dependents input 

    //gross pay based on hours worked 
    if (hours_worked <= 40){
        rate = 36.75f;
        gross_pay = hours_worked * rate;
        cout.setf(ios::fixed); //sets the float to fixed
        cout.setf(ios::showpoint); //shows the decimal point
        cout.precision(2); //sets the precision to 2 decimal places
        cout << "Gross pay is: $" << gross_pay << endl;
    }
    else { 
        rate = 36.75f;
        gross_pay = (40 * rate) + ((hours_worked - 40) * rate * overtime_rate);
        cout.setf(ios::fixed); //sets the float to fixed
        cout.setf(ios::showpoint); //shows the decimal point
        cout.precision(2); //sets the precision to 2 decimal places
        cout << "Gross pay is: $" << gross_pay << endl;
    }
    //dependents and tax calculation
    if (dependents >= 2) {
        ss_tax = gross_pay * 6  / 100; //6% social security tax 
        fed_tax = gross_pay * 15/ 100; //14% federal tax 
        state_tax = gross_pay * 4/100; //4% state tax
        bethlehem_tax = gross_pay * 1/ 100; //1% bethlehem city tax
        union_fees = 20;//$20 for union fees 
        health_fees = 40;//$40 for health fees 
        float net_pay = gross_pay - (ss_tax + fed_tax + state_tax + bethlehem_tax + union_fees + health_fees);
        cout.setf(ios::fixed); //sets the float to fixed
        cout.setf(ios::showpoint); //shows the decimal point
        cout.precision(2); //sets the precision to 2 decimal places
        cout << "Social Security Tax: $" << ss_tax << endl;
        cout << "Federal Income Tax: $" << fed_tax << endl;
        cout << "State Tax: $" << state_tax << endl;
        cout << "Bethlehem Local Tax: $" << bethlehem_tax << endl;
        cout << "Union Dues: $" << union_fees << endl;
        cout << "Health Insuarance: $" << health_fees << endl;
        cout << "Net pay is: $" << net_pay << endl;

    }
    else {
        ss_tax = gross_pay * 6  / 100; //6% social security tax 
        fed_tax = gross_pay * 15/ 100; //14% federal tax 
        state_tax = gross_pay * 4/100; //4% state tax
        bethlehem_tax = gross_pay * 1/ 100; //1% bethlehem city tax
        union_fees = 20;//$20 for union fees
        float net_pay = gross_pay - (ss_tax + fed_tax + state_tax + bethlehem_tax + union_fees);
        cout.setf(ios::fixed); //sets the float to fixed
        cout.setf(ios::showpoint); //shows the decimal point
        cout.precision(2); //sets the precision to 2 decimal places
        cout << "Social Security Tax: $" << ss_tax << endl;
        cout << "Federal Income Tax: $" << fed_tax << endl;
        cout << "State Tax: $" << state_tax << endl;
        cout << "Bethlehem Local Tax: $" << bethlehem_tax << endl;
        cout << "Union Dues: $" << union_fees << endl;
        cout << "Health Insuarance: $" << health_fees << endl;
        cout << "Net pay is: $" << net_pay << endl;
    }

    //Homework Question 3
    //loan calculator while loop 
    cout << "Enter Loan Amount: " << endl; //print loan amount 
    cin >> balance; //initial balance 
    cout << "Enter Interest Rate: " << endl; //print interest rate 
    cin >> interest_rate; //interest rate input 
    total_paid = 0.0f; //total paid starts at 0 
    total_interest = 0.0f; //total interest starts at 0
    int month = 0; //month counter starts at 0 
    //table 
    cout << fixed << right << setw(10) << "Month #" << setw(15) << "Interest" << setw(15) << "Principal" << setw(15) << "Balance" << setw(15) << "Total Interest" << setw(15) << "Total Paid" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    while (balance > 0) {
        month++; //add one month to each loop 
        float monthly_interest = (interest_rate / 100.0f) / 12.0f * balance; // monthly interest calculation
        total_interest += monthly_interest; //adds money to the monthly interest
        balance -= (monthly_payment - monthly_interest); //subtracts the monthly payment minus interest from balance 
        total_paid += monthly_payment; //adds money to the total paid
        principal = monthly_payment - monthly_interest; //principal is the payment minus interest
        if (balance < 0) {
            monthly_payment += balance; // the last payment if balance is less than 0
            principal = monthly_payment - monthly_interest; //recalculates principal for last payment
            balance = 0; //sets balance to 0
        }
        else {
            balance = balance; //keeps balance the same if not last payment
        }
        cout << fixed << right << setw(10) << month << setw(15) << monthly_interest << setw(15) << principal << setw(15) << balance << setw(15) << total_interest << setw(15) << total_paid << endl;
    }
    return 0;
}
    



   
