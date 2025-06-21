#include <iostrem>
#include <fstream>
#include <string> 
#include <vector>
using namesapce std;
class travel_book{
    public:
    string name;
    string id;
    long long int phn_no;
    int age;
    int seat_no;
    string destination;
    //email pending
    string Email;

    void input(){
        cout<<"Enter name :"<<endl;
        getline(cin,name);
    
    cout<<"Enter id:"<<endl;
    cin>>id;
    cin.ignore();
    cout<<"Enter Phone no:"<<endl;
    cin>>phn_no;
    while(phn_no[0]=='0' || phn_no.length()!=10){
        cout<<"Invalid"<<endl;
        cin>>phn_no;
    }
    cout<<"Enter Age:"<<endl;
    cin>>age;
    while(age<0){
        cout<<"Invalid"<<endl;
        cin>>age;
    }
    cout<<"Enter seat no:"<<endl;
    cin>>seat_no;
    cout<<"Enter Destination:"<<endl;
    getline(cin,destination);

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
                
            }

        }
    }

    void display(){
        cout<< "Name:"<<name;
        cout<< "Booking_id:"<<id;
        cout<< "Phone no:"<<phn_no;
        cout<< "Age:"<<age;
        cout<< "Seat no:"<<seat_no;
        cout<< "Destination:"<<destiantion;
    }   
    };
    int canceltravel_book(){
        string name;
        cout<<"Enter name"<<endl;
        getline(cin,name);
        int id;
        cout<<"enter id"<<endl;
        cin>>id;
        int n=0;
        for(int i=0;i<n;i++){
            if(travel_book[i].id==id){
                travel_book[i]==travel_book[n-1];
                n--;
                cout<<"Booking cancelled"<<endl;
                return 0;
            }
        }
        

    }
    int edittravel_book(){
        string name;
        cout<<"Enter name"<<endl;
        getline(cin,name);
        int id;
        cout<<"enter id"<<endl;
        cin>>id;
        cin.ignore();
        int n=0;
        for(int i=0;i<n;i++){
            if(travel_book[i].id==id){
                cout<<"Enter new name";
                cin>>travel_book[i].name;
                cout<<"Enter new destination";
                cin>>travel_book[i].destiantion;
                cout<<"Enter new seat no";
                cin>>travel_book[i].seat_no;
                cout<<"Booking updated"<<endl;
                return 0;
            }
        }        
    }
    // search and view pending
    int main(){
        int choice;
        while(true){
            cout<<"1.Add\n2.Cancel\n3.Edit\n4.Exit\n";
            cout<<"Enter choice"<<endl;
            cin>>choice;
            if(choice==1)  
            addtravel_book();
            else if(choice==2)
            canceltravel_book();
            else if(choice==3)
            edittravel_book();
            else if(choice==4)
            break;
            else
            cout<<"Invalid choice"<<endl;
        }
        return 0;
    }




}