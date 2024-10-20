#include <iostream>

using namespace std;

class Node{
public:
    string Ename;
    string Eid;
    string Egender;
    double Esal;
    int Eyear;
    int Emonth;
    int Eday;

    bool isWorking;
    Node* next;

    Node(string name,string id,string gender,double sal,int day,int month,int year,bool work){
        Ename=name;
        Eid=id;
        Egender=gender;
        Esal=sal;
        Eyear=year;
        Emonth=month;
        Eday=day;
        isWorking=work;
        next= nullptr;
    }
};