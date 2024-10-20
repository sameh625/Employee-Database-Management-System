#include<iostream>
#include "Admin.cpp"
#include "Guest.cpp"
using namespace std;

int main(){
    Admin_mode AD;
    Guest_mode GU;
    cout<<"\n-----------------------Employee Management System-----------------------\n";
    int Mode;
    while(true){
        cout<<"\nAdmin mode           (1)\n"
            <<"Guest mode           (2)\n"
            <<"Exit                 (3)\n"
            <<"Enter the choice:";
        cin>>Mode;
        switch (Mode) {
            case 1:AD.Admin();
                break;
            case 2:GU.Guest(AD);
                break;
            case 3:exit(0);
            default:
                cout<<"\n!!!!!!!!!!!!!!!!!INVALID INPUT!!!!!!!!!!!!!!!!!\n\n";
        }
        cin.clear();
        cin.ignore();
    }

}