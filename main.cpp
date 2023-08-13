// Unit 4: Screen Output
// Created by Henry Tran

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Customer.h"
#include "BinarySearchTree.h"
#include "HashNode.h"
#include "HashTable.h"

using namespace std;

int key_to_index(const Customer &key, int size);
void searchManager(const BinarySearchTree<Customer> &list);
void displayManager(const BinarySearchTree<Customer> &list);
void buildList(const string& inputFileName,  BinarySearchTree<Customer> &list);
//void deleteHashManager(HashTable<Customer> hash);

void deleteManager( BinarySearchTree<Customer> &list);
void menuManager(const string& inputFileName,  BinarySearchTree<Customer> &list);
void insertManager(BinarySearchTree<Customer> &list);
void inputManager(const string& inputFileName, string &filename, BinarySearchTree<Customer> &list);
void displayName();

int main()
{

       HashTable<Customer> hash;
    string inputFileName = "customers.txt";
    BinarySearchTree<Customer> list;
    buildList(inputFileName, list);
    menuManager(inputFileName, list );

   // searchManager(list);
    //displayManager(list);
//    deleteManager(list);

    return 0;
}



void menuManager(const string& inputFileName,  BinarySearchTree<Customer> &list)
{
    HashTable<Customer> hash;
    string ff = "newStudents.txt";//file to add its contents
    string targetCode = "";
    Customer aCustomer;


    cout << "\n Menu\n";
    cout <<   "=======\n";
    //loop
    while(toupper(targetCode[0]) != 'Q')
    {
        cout << "\nEnter to select (or Q to stop) : \n";

    //show menu
    cout << " " << setw(4) <<"showMenu(H)"<<endl;

    //hidden option

    cin >> targetCode;
    if(toupper(targetCode[0]) == 'H')
    {
  //  cout << " " << setw(4) <<"showAuthors (hidden)"<<endl;
    cout << " " << setw(4) <<"search(S)"<<endl;
    cout << " " << setw(4) <<"insert(I)"<<endl;
    cout << " " << setw(4) <<"delete(D)"<<endl;
    cout << " " << setw(4) <<"deletehash(C)"<<endl;
    cout << " " << setw(4) <<"read from one file and add to another file(F)"<<endl;
    cout << " " << setw(4) <<"display team(A)"<<endl;
    cout << " " << setw(4) <<"...etc"<<endl;

    cout << "\nEnter anything else to return to front (or Q to stop) : \n";
    cout<<"input: "; cin >> targetCode;
    cout <<   "=======\n";

    if(toupper(targetCode[0]) == 'S')
      //  search by id
       searchManager(list);

    else if(toupper(targetCode[0]) == 'P')
        //print data with table
        cout<<"A";

    else if(toupper(targetCode[0]) == 'T')
            cout<<"B";
    //else if(toupper(targetCode[0]) == 'C')
     //       deleteHashManager(hash);
        else if(toupper(targetCode[0]) == 'I')
          insertManager(list);//insert a new record

    else if(toupper(targetCode[0]) == 'F')
        inputManager(inputFileName, ff,list);
            //add data from an input file to the original file
            //ios::app
   else if(toupper(targetCode[0]) == 'D')
            deleteManager(list);
    else if(toupper(targetCode[0]) == 'M')
            displayManager(list);
     else if(toupper(targetCode[0]) == 'A')
        displayName();
        //display name of team members


    cout << "\nEnter anything else to return to front (or Q to stop) : \n";
    cin >> targetCode; //so the whole process doesnt end unexpected
    }



    }

}

//not finished
/*
void deleteHashManager(HashTable<Customer> hash)
{
    string name;
     cout << "Test delete" << endl;
    cout << "Enter name or Q to quit: ";
    cin >> name;
    while ( name != "Q" )
    {
        Customer itemOut, found, key(name, 0);
        if (hash.remove(itemOut, key,
                        key_to_index))
            cout << endl << itemOut.getName() << " " << itemOut.getOrderID() << " - deleted!" << endl;

        cout << "Load Factor: " << hash.getLoadFactor() << endl;

        cout << "Enter name or Q to quit: ";
        cin >> name;
    }
}
*/

void displayName()
{
    cout<<"Displaying team members: "<<endl;
    cout << " " << setw(27) <<"Minoo Hong"<<endl;
    cout << " " << setw(27) <<"Rodjaron Monteagudo"<<endl;
    cout << " " << setw(27) <<"Johanna Phan"<<endl;
    cout << " " << setw(27) <<"Henry Tran"<<endl;

}


void displayManager(const BinarySearchTree<Customer> &list)
{
    Customer aCustomer;
    cout << left;
    cout << " " << setw(4) << aCustomer.getOrderID() << "  ";
    cout << " " << setw(2) << aCustomer.getName() << "  ";
    cout << " " << setw(27)<< aCustomer.getAddress() << "  ";
    cout << right;
    cout << " " << setw(7) << aCustomer.getPhoneNumber() << " ";
    cout << " " << setw(7) << aCustomer.getDate() << " ";
    cout << left << endl;
}
/*
 Search manager: search the list until the user enters Q to quit searching
 Input Parameter: list
 */


 void insertManager( BinarySearchTree<Customer> &list)
 {
    string inputFileName = "customers.txt";
     string answer;
     cout << "\n Insert\n";
    cout <<   "=======\n";
     cout << "Insert [Y/N]?";
     cin >> answer;
if (answer == "Y" || answer == "y")
    {

        string targetCode = "";
        Customer aCustomer;

        while(toupper(targetCode[0]) != 'Q')
    {
        cout << "\nEnter a customer code code (or Q to stop Insert) : \n";

             string Order_id;
                string name;
                string address;
                string phoneNumber;
                string date;
                cin >> targetCode;

        if(toupper(targetCode[0]) != 'Q')
        {


            Customer hold;
            Order_id = targetCode;
            hold.setOrderID(Order_id);


            if(!list.search(hold, aCustomer)) //reject duplicate
            {


           cout<<"name: ";
           cin>>name;

           //cin.ignore();
           cout<<"address: ";
           cin>>address;

           cout<<"phonenumber: ";
           cin>>phoneNumber;

            cout<<"date: ";
            cin>>date;

           Customer bCustomer(Order_id, name, address, phoneNumber,date);
           list.insert(bCustomer);
            bCustomer.vDisplay();

            //write to file
            cout<<"Write to file?"<<endl;
            string answer1;
            cin>>answer1;
        if (answer1 == "Y" || answer == "y")
            {
                fstream fout(inputFileName,ios::app);
                fout<<Order_id<<" ";
                fout<<name;
                fout<<"; "<<address<<"; "<<phoneNumber<<"; "<<date<<"\n";

            }





            }
            else
                cout << "Customer \"" << targetCode << "\" was found in this list, duplicate" << endl;
        }

    }

    }
    cout << "___________________END INSERT SECTION _____\n";
 }


 void deleteManager( BinarySearchTree<Customer> &list)
 {
     string answer;
     cout << "\n Delete\n";
    cout <<   "=======\n";
     cout << "Delete [Y/N]?";
     cin >> answer;
if (answer == "Y" || answer == "y")
    {

        string targetCode = "";
        Customer aCustomer;

        while(toupper(targetCode[0]) != 'Q')
    {
        cout << "\nEnter a customer code code (or Q to stop deleting) : \n";
        cin >> targetCode;

        if(toupper(targetCode[0]) != 'Q')
        {


            Customer hold;
            hold.setOrderID(targetCode);

            if(list.search(hold, aCustomer))
            {

            list.deleteNode(aCustomer);
                aCustomer.vDisplay();
            }
            else
                cout << "Customer \"" << targetCode << "\" was not found in this list." << endl;
        }
    }

    }
    cout << "___________________END DELETE SECTION _____\n";
 }

void searchManager(const BinarySearchTree<Customer> &list)
{
    string targetCode = "";
    Customer aCustomer;

    cout << "\n Search\n";
    cout <<   "=======\n";

    while(toupper(targetCode[0]) != 'Q')
    {
        cout << "\nEnter a customer code (or Q to stop searching) : \n";
        cin >> targetCode;

        if(toupper(targetCode[0]) != 'Q')
        {

            // Create an empty object, put the target string inside,
            // and pass this target object to the searchList function.
            Customer hold;
            hold.setOrderID(targetCode);

            if(list.search(hold, aCustomer))
                aCustomer.vDisplay();
            else
                cout << "Customer \"" << targetCode << "\" was not found in this list." << endl;
        }
    }
    cout << "___________________END SEARCH SECTION _____\n";
}

void buildList(const string& filename,  BinarySearchTree<Customer> &list /*, hash*/)
{

    ifstream fin(filename);
    if(!fin)
    {
        cout << "Error opening the input file: \""<< filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    int i = 0;
    while(getline(fin, line))
    {
        string Order_id;
        string name;
        string address;
        string phoneNumber;
        string date;

       stringstream temp(line); // create temp with data from line
       temp>>Order_id; // read from temp
       temp.ignore();
       getline(temp,name, ';');
       temp.ignore();
       getline(temp,address, ';');
        temp>>phoneNumber;
        temp>>date;




       // create a College object and initialize it with data from file
       Customer aCustomer(Order_id, name, address, phoneNumber,date);
       list.insert(aCustomer);


         // HashTable<Customer> hash;
      //  Customer list[i] = {{Order_id, name, address, phoneNumber, date}};
       // i++;

        //hash.insert(aCustomer, key_to_index);
       //insertHash
    }


}

 void inputManager(const string& inputFileName, string& filename, BinarySearchTree<Customer> &list)
{
    ofstream fout(inputFileName,ios::app);//write to this
        if(!fout)
    {
        cout << "Error opening the input file: \""<< inputFileName << "\"" << endl;
        exit(EXIT_FAILURE);
    }


    ifstream fin(filename);
        if(!fin)
    {
        cout << "Error opening the input file: \""<< filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    string line, ln;
    while(getline(fin, line))//cant catch duplicates though
    {

        fin>>line;

        fout<<"\n"<<line;//start with new line

        string Order_id;

        string name;
        string address;
        string phoneNumber;
        string date;

       stringstream temp(line); // create temp with data from line
       temp>>Order_id; // read from temp
       temp.ignore();
       getline(temp,name, ';');
       temp.ignore();
       getline(temp,address, ';');
        temp>>phoneNumber;
        temp>>date;
        Customer aCustomer(Order_id, name, address, phoneNumber,date);
       list.insert(aCustomer);

    }

fout.close();


}
int key_to_index(const Customer &key, int size)
{
    string k = key.getName();
    int sum = 0;
    for (int i = 0; k[i]; i++)
        sum += k[i];
    return sum % size;
};
