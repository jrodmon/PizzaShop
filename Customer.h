
// Specification file for the Customer class
// Written By: Henry Tran

#ifndef Customer_h
#define Customer_h

#include <string>

using std::ostream;
using std::string;

class Customer
{
    private:
        string Order_id;
        string name;
        string address;
        string phoneNumber;
        string date;

    public:
        //constructors
        Customer();
        Customer(string, string, string, string, string);

        //setters
        void setOrderID(string ID){ Order_id = ID;}
        void setName(string nm){ name = nm;}
        void setAddress(string ad){ address = ad;}
        void setPhoneNumber(string pn){ phoneNumber = pn;}
        void setDate(string dt){ date = dt;}

        //getters
        string getOrderID() const {return Order_id;}
        string getName() const {return name;}
        string getAddress() const {return address;}
        string getPhoneNumber() const {return phoneNumber;}
        string getDate() const {return date;}

        void hDisplay() const;
        void vDisplay() const;

        // overloaded operators

         bool operator==(const Customer& C)
         {
             return (Order_id == C.getOrderID());
         }
         bool operator>(const Customer& C)
         {
             return (Order_id > C.getOrderID());
         }
         bool operator<(const Customer& C)
         {
             return (Order_id < C.getOrderID());
         }
        // Friends
        friend ostream &operator << (ostream &, const Customer &);
};

#endif /* Customer_h */
