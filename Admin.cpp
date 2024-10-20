#include "Node.cpp"
#include <algorithm>
#include <cctype>
class Admin_mode{
public:
    Node* head= nullptr;

    const int MAX_VALID_YR = 2024;
    const int MIN_VALID_YR = 1900;
    /*-------------------To lower--------------*/
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(),
                       [](unsigned char c) { return tolower(c); });
        return str;
    }
    /*-------------------Validate Number--------------*/

    bool isNumber(string s)
    {
        for (int i = 0; i < s.length(); i++)
            if (isdigit(s[i]) == false&&s[i]!='.')
                return false;

        return true;
    }

    /*--------------------Validate Date--------------------*/

    bool isLeap(int year)
    {
        return (((year % 4 == 0) &&
                 (year % 100 != 0)) ||
                (year % 400 == 0));
    }
    bool isValidDate(int d, int m, int y)
    {
        if (y > MAX_VALID_YR ||
            y < MIN_VALID_YR)
            return false;
        if (m < 1 || m > 12)
            return false;
        if (d < 1 || d > 31)
            return false;

        if (m == 2)
        {
            if (isLeap(y))
                return (d <= 29);
            else
                return (d <= 28);
        }
        if (m == 4 || m == 6 ||
            m == 9 || m == 11)
            return (d <= 30);

        return true;
    }

    /*----------------------Validate unique ID ---------*/

    bool is_unique(string id){
        Node* temp=head;
        while(temp){
            if(temp->Eid==id){
                return false;
            }
            temp=temp->next;
        }
        return true;
    }

    /*-------------------------ADD OPP--------------------*/

    void Add(){

        string name,id,gender;
        cout<<"Employee Name:";
        getline(cin>>ws,name);
        cout<<"Employee id(unique):";
        cin>>id;
        while(true){
            if(is_unique(id)){
                break;
            }else{
                cout<<"\n!!!!!!!!!!!!! THIS ID IS ALREADY EXIST !!!!!!!!!!!!!\n\n";
                cout<<"Employee id(unique):";
                cin>>id;
            }
        }

        while(true){
            int gen;
            cout<<"Gender: male   (1)\n"
                <<"        female (2)\n"
                <<"Enter the choice ( 1 / 2 ):";
            cin>>gen;
            if(gen==1){
                gender="male";
                break;
            }else if(gen==2){
                gender="female";
                break;
            }else{
                cout<<"\n!!!!!!!!!!!!!!!!!INVALID INPUT!!!!!!!!!!!!!!!!!\n\n";
            }
        }


        string slry,dd,mm,yyyy;
        double emp_slry=0;
        int day=0,mon=0,year=0;
        cout<<"employee salary:$";
        cin>>slry;
        while(!isNumber(slry)){
            cout<<"\n!!!!!!!!!!!!!!!!!INVALID INPUT!!!!!!!!!!!!!!!!!\n\n";
            cout<<"employee salary:$";
            cin>>slry;
        }
        emp_slry= stod(slry);
        cout<<"date(dd mm yyyy):";
        cin>>dd>>mm>>yyyy;
        while(!isNumber(dd)||!isNumber(mm)||!isNumber(yyyy)){
            cout<<"\n!!!!!!!!!!!!!!!!!INVALID INPUT!!!!!!!!!!!!!!!!!\n\n";
            cout<<"date(dd mm yyyy):";
            cin>>dd>>mm>>yyyy;
        }
        day= stoi(dd),mon= stoi(mm),year= stoi(yyyy);
        while(!isValidDate(day,mon,year)) {
            cout << "\n!!!!!!!!!!!!!!!!!INVALID DATE!!!!!!!!!!!!!!!!!\n\n";
            cout << "date(dd mm yyyy):";
            cin >> dd >> mm >> yyyy;
            day = stoi(dd), mon = stoi(mm), year = stoi(yyyy);
        }


        bool w=false;
        int stat;
        cout<<"Status:Working    (1)\n"
            <<"       Not Working(2)\n"
            <<"Enter the choice ( 1 / 2 ):";
            cin>>stat;
                while(true){
                    if(stat==1){
                        w= true;
                        break;
                    }else if(stat==2){
                        w= false;
                        break;
                    }else{
                        cout<<"\n!!!!!!!!!!!!!!!!!INVALID INPUT!!!!!!!!!!!!!!!!!\n\n";
                        cout<<"Status:Working    (1)\n"
                            <<"       Not Working(2)\n"
                            <<"Enter the choice ( 1 / 2 ):";
                        cin>>stat;
                    }
            }

        Node* NEmployee=new Node(name, id , gender,emp_slry,day,mon,year,w);
        if(!head){
            head=NEmployee;
        }else{
            Node* temp=head;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=NEmployee;
        }

        cout << "\nEmployee added successfully.\n";
    }

/*---------Display working and non-working OPP----*/

    void printDetails(Node* emp){
        cout << "Name: " << emp->Ename << endl;
        cout << "Employee ID: " << emp->Eid << endl;
        cout << "Gender: "<<emp->Egender<<endl;
        cout << "Salary: " << emp->Esal << endl;
        cout << "Date of Joining: " << emp->Eday<<"/"<<emp->Emonth<<"/"<<emp->Eyear << endl;
        cout << "Status: " << (emp->isWorking ? "Working\n" : "Non-working\n") << endl;
    }
    void displayWorking(bool working) {
        if(!head){
            cout<<"\nNo Such Records Yet.\n";
            return;
        }
        Node *temp = head;
        if(working){
            cout << "\nWorking Employees List:\n";
        }else{
            cout << "\nNON-Working Employees List:\n";
        }

        while (temp) {
            if (temp->isWorking == working) {
                printDetails(temp);
                cout << endl;
            }
            temp = temp->next;
        }
    }

/*-------------------------Delete OPP--------------------*/

    void Delete(){
        if(!head){
            cout<<"\nNo Such Records To Be Deleted Yet.\n";
            return;
        }
        string key;
        cout<<"Enter the ID:";
        cin>>key;
        Node* temp=head;
        Node* pre= nullptr;
        if(temp!= nullptr&&temp->Eid==key){
            head=temp->next;
            delete temp;
            cout<<"\nDeleted successfully.\n\n";
            return;
        }

        while(temp!= nullptr&&temp->Eid!=key){
            pre=temp;
            temp=temp->next;
        }
        if(temp== nullptr){
            cout<<"\nNo Such record with this id.\n";
            return;
        }
        pre->next=temp->next;
        delete temp;
        cout<<"Deleted successfully.\n\n";
    }

/*-------------------------Search OPP--------------------*/

    void Search(){
        bool f=false;
        Node* temp=head;
        if(!head){
            cout<<"\nNo Such Records To Be Searched Yet.\n";
            return;
        }
        string key;
        cout<<"Enter the ID/Name:";
        cin.ignore();
        getline(cin>>ws,key);
        while(temp){
            if(temp->Eid==key||toLowerCase(temp->Ename)==toLowerCase(key)){
                cout<<endl;
                printDetails(temp);
                cout<<endl;
                f=true;
            }
            temp=temp->next;
        }
        if(!f){
            cout<<"\nThe Employee is not Founded\n";
        }
        cout << "\nPress Enter to continue...";

    }

/*-------------------------Update OPP--------------------*/

    void Update(){
        if(!head){
            cout<<"\nNo Such Records To Be Updated Yet.\n\n";
            return;
        }
        bool f= false;
        Node* temp=head;
        string key;
        cout<<"Enter the ID:";
        cin>>key;
        while(temp){
            if(temp->Eid==key){
                cout<<endl;
                printDetails(temp);
                cout<<endl;
                cout<<"Employee ID(can't be changed):"<<temp->Eid<<endl;
                cout<<"Employee Name:";
                getline(cin>>ws,temp->Ename);
                cout<<"Gender(can't be changed):"<<temp->Egender<<endl;
                string slry,dd,mm,yyyy;
                cout<<"employee salary:$";
                cin>>slry;
                while(!isNumber(slry)){
                    cout<<"\n!!!!!!!!!!!!!!!!!INVALID INPUT!!!!!!!!!!!!!!!!!\n\n";
                    cout<<"employee salary:$";
                    cin>>slry;
                }
                temp->Esal= stod(slry);
                cout<<"date(dd mm yyyy):";
                cin>>dd>>mm>>yyyy;
                while(!isNumber(dd)||!isNumber(mm)||!isNumber(yyyy)){
                    cout<<"\n!!!!!!!!!!!!!!!!!INVALID INPUT!!!!!!!!!!!!!!!!!\n\n";
                    cout<<"date(dd mm yyyy):";
                    cin>>dd>>mm>>yyyy;
                }
                temp->Eday= stoi(dd),temp->Emonth= stoi(mm),temp->Eyear= stoi(yyyy);
                while(!isValidDate(temp->Eday,temp->Emonth,temp->Eyear)) {
                    cout << "\n!!!!!!!!!!!!!!!!!INVALID DATE!!!!!!!!!!!!!!!!!\n\n";
                    cout << "date(dd mm yyyy):";
                    cin >> dd >> mm >> yyyy;
                    temp->Eday= stoi(dd),temp->Emonth= stoi(mm),temp->Eyear= stoi(yyyy);
                }

                int stat;
                cout<<"Status:Working    (1)\n"
                    <<"       Not Working(2)\n"
                    <<"Enter the choice ( 1 / 2 ):";
                cin>>stat;
                while(true){
                    if(stat==1){
                        temp->isWorking= true;
                        break;
                    }else if(stat==2){
                        temp->isWorking= false;
                        break;
                    }else{
                        cout<<"\n!!!!!!!!!!!!!!!!!INVALID INPUT!!!!!!!!!!!!!!!!!\n\n";
                        cout<<"Status:Working    (1)\n"
                            <<"       Not Working(2)\n"
                            <<"Enter the choice ( 1 / 2 ):";
                        cin>>stat;
                    }
                }
                cout<<"\nUpdated Successfully.\n\n";
                return;
            }
            temp=temp->next;
        }
        cout<<"\nNo Such record with this id.\n";

    }

/*-------------------------Admin Mode--------------------*/
    void Admin(){
        while(true){
            int OP;

            cout<<"\nAdd new employee                      (1)\n"
                <<"Update existing employee(by ID/Name)  (2)\n"
                <<"Delete existing employee(by ID)       (3)\n"
                <<"Search for the details of an employee (4)\n"
                <<"Display the Working employees         (5)\n"
                <<"Display the Non-Working employees     (6)\n"
                <<"To Quit the admin mode                (7)\n"
                <<"Exit                                  (8)\n\n"
                <<"Enter the choice:";
            cin>>OP;
            switch (OP) {
                case 1:cout<<"\n";Add();
                    break;
                case 2:cout<<"\n";Update();
                    break;
                case 3:cout<<"\n";Delete();
                    break;
                case 4:cout<<"\n";Search();
                    break;
                case 5:cout<<"\n";displayWorking(true);
                    break;
                case 6:cout<<"\n";displayWorking(false);
                    break;
                case 7:cout<<"\n";
                    return;
                case 8:exit(0);
                default:
                    cout<<"\n!!!!!!!!!!!!!!!!!INVALID INPUT!!!!!!!!!!!!!!!!!\n\n";
            }
            cin.clear();
            cin.ignore();
        }
    }
};