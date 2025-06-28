#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <cctype>
using namespace std;
class travel_book{
    public:
    string name;
    string id;
    string phn;
    int age;
    int seat_no;
    string destination;
    //email pending
    string Email;

    void input(){                           // add entries
        cin.ignore(); // use of ingnore
        cout<<"Enter name :"<<endl;
        getline(cin,name);
    
    cout<<"Enter id:"<<endl;
    cin>>id;
    cin.ignore();
    cout<<"Enter Phone no:"<<endl;
    cin>>phn;
    while(phn[0]=='0' || phn.length() !=10){
        cout<<"Invalid"<<endl;
        cin>>phn;
    }


    cout<<"Enter Age:"<<endl;
    cin>>age;
    while(age<=0){
        cout<<"Invalid"<<endl;
        cin>>age;
    }


    cout<<"Enter seat no:"<<endl;
    cin>>seat_no;
    cout<<"Enter Destination:"<<endl;
    cin.ignore();
    getline(cin,destination);
    }


    bool isValidEmail(string email){
        if(!isalpha(email[0]))
        return false;
        for(int i=0;i<email.length();i++){
            char ch=email[i];
            if(ch==' ')
            return false;
        if(!isalnum(ch) && ch!='@' && ch!='.' && ch!='_')
        return false;
            if(ch=='@'){
              return false;  
            }
        }
    };


    void display() {
        cout<< "Name:"<<name;
        cout<< "Booking_id:"<<id;
        cout<< "Phone no:"<<phn;
        cout<< "Age:"<<age;
        cout<< "Seat no:"<<seat_no;
        cout<< "Destination:"<<destination;
        cout<<"Email:"<<Email;
    }
        

    void saveToFile(ofstream &file) {
        file <<name<<endl<< id <<endl<< phn <<endl<< age <<endl
             << seat_no <<endl<< destination <<endl<< Email <<endl;
    }

    bool loadFromFile(ifstream &file) {
        getline(file, name);
        getline(file, id);
        getline(file, phn);
        file >> age;
        file >> seat_no;
        file.ignore();
        getline(file, destination);
        getline(file, Email);
        return !file.eof();
    }
};
    vector<travel_book> booking;

    void loadBookings() {
    ifstream infile("bookings.txt");
    travel_book t;
    while (t.loadFromFile(infile)) {
        booking.push_back(t);
    }
    infile.close();
}

void saveBookings() {
    ofstream outfile("bookings.txt");
    for (travel_book &t : booking) {
        t.saveToFile(outfile);
    }
    outfile.close();
}

void addtravel_book() {
    travel_book t;
    t.input();
    booking.push_back(t);
    cout << "Booking added successfully"<<endl;
}


void canceltravel_book() {               // cancel entries
    cin.ignore();
    string id;
    cout << "Enter booking ID to cancel: ";
    getline(cin, id);

    for (size_t i =0; i < booking.size(); i++) {
        if (booking[i].id == id) {
            booking.erase(booking.begin() + i);
            cout << "Booking cancelled"<<endl;
            return;
        }
    }
    
}

    int edittravel_book(){         //edit entries 
        string name;
        cout<<"Enter name"<<endl;
        getline(cin,name);
        int id;
        cout<<"enter id"<<endl;
        cin>>id;
        cin.ignore();
        int n=0;
        for(int i=0;i<n;i++){
            if(booking[i].id==id){
                cout<<"Enter new name";
                cin>>booking[i].name;
                cout<<"Enter new destination";
                cin>>booking[i].destination;
                cout<<"Enter new seat no";
                cin>>booking[i].seat_no;
                cout<<"Booking updated"<<endl;
                return 0;
            }
        }        
    }


    void viewtravel_book(){         //view entries
        int n=0;
        if(n==0){
            cout<<"Nothing found";
            return;
        }
        for(int i=0;i<n;i++){
            cout<<"Name:"<<booking[i].name;
            cout<<"Booking id"<<booking[i].id;
            cout<<"Destination"<<booking[i].destination;
            cout<<"Seat no"<<booking[i].seat_no;
            cout<<"Phone no"<<booking[i].phn;
        }
    }


    void searchtravel_book(){         //search entries
        string a;
        cin>>a;
        int n=0;
        bool found=false;
       for(int i=0;i<n;i++){
        if(booking[i].name==a || booking[i].destination==a){
            cout<<"Name:"<<booking[i].name;
            cout<<"Booking id"<<booking[i].id;
            cout<<"Destination"<<booking[i].destination;
            cout<<"Seat no"<<booking[i].seat_no;
            cout<<"Phone no"<<booking[i].phn;
            found= true;
        }
    }
    if(!found){
        cout<<"Nothing found";
    }
    }
    

    int main(){
        int choice;
        while(true){
            cout<<"1.Add Booking"<<endl;
            cout<<"2.Cancel Booking"<<endl;
            cout<<"3.Edit Booking"<<endl;
            cout<<"4.View Booking"<<endl;
            cout<<"5.Search Booking"<<endl;
            cout<<"6.Exit Booking"<<endl;

            cout<<"Enter choice"<<endl;
            cin>>choice;
            switch (choice) {
            case 1:
                addtravel_book();
                break;
            case 2:
                canceltravel_book();
                break;
           case 3:
                edittravel_book();
                break;
            case 4:
                viewtravel_book();
                break;
            case 5:
               searchtravel_book();
               break;
            case 6:
                cout << "Exit"<<endl;
                return 0;
            default:
                cout << "Invalid choice."<<endl;
        }
            
        }
    };


