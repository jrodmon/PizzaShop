
#include <iostream>
#include <iomanip>
#include <string>

#include "Customer.h"

using namespace std;
        string Order_id;
        string name;
        string address;
        string phoneNumber;
        string date;
//**************************************************
// Constructor
//**************************************************
Customer::Customer()
{
    Order_id = "";
    address = "";
    name = "";
    phoneNumber = "";
    date = "";
}

//**************************************************
// Overloaded Constructor
//**************************************************
Customer::Customer(string id, string nm, string add, string phone, string dat)
{
    Order_id = id;
    name = nm;
    address = add;
    phoneNumber = phone;
    date = dat;
}



// overloaded operators

 //friend function
 ostream& operator <<(ostream& output, const Customer &C)
 {
        cout << left;
    cout << " " << setw(4) << C.Order_id << "  ";
    cout << " " << setw(2) << C.name << "  ";
    cout << " " << setw(27)<< C.address << "  ";
    cout << right;
    cout << " " << setw(7) << C.phoneNumber << " ";
    cout << " " << setw(7) << C.date << " ";
    cout << left << endl;


 }

 void Customer::vDisplay() const
 {
     cout << "           Address: " << address << endl;

     cout << "              Name: " << name << endl;
     cout << "       phoneNumber: "<<phoneNumber<<endl;
     cout << "              date: "<<date<<endl;
 }

