
class Guest_mode{

public:
    /*-------------------To lower-------------------------*/
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(),
                  [](unsigned char c) { return tolower(c); });
        return str;
    }
    /*-------------------Validate Number-------------------*/

    bool isNumber(string s)
    {
        for (int i = 0; i < s.length(); i++)
            if (isdigit(s[i]) == false&&s[i]!='.')
                return false;

        return true;
    }

    /*-------------------------Display OPP--------------------*/

    void printDetails(Node* emp){
        cout << "Name: " << emp->Ename << endl;
        cout << "Employee ID: " << emp->Eid << endl;
        cout << "Gender: "<<emp->Egender<<endl;
        cout << "Salary: " << emp->Esal << endl;
        cout << "Date of Joining: " << emp->Eday<<"/"<<emp->Emonth<<"/"<<emp->Eyear << endl;
        cout << "Status: " << (emp->isWorking ? "Working\n" : "Non-working\n") << endl;
    }
    void displayWorking(Admin_mode AD) {

        Node *temp = AD.head;
        if(!temp){
            cout<<"\nNo Such Records Yet.\n";
            return;
        }


        while (temp) {
                printDetails(temp);
                cout << endl;
            temp = temp->next;
        }
    }

    /*-------------------------Search OPP--------------------*/

    void Search(Admin_mode AD){
        bool f=false;
        Node* temp=AD.head;
        if(!temp){
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

    /*-------------------------Sort Based on name--------------------*/

    void NSorted(Admin_mode AD){
        Node* temp=AD.head,*index= nullptr;
        Node* cont;
        if(!temp){
            cout<<"\nNo Such Employees To Be Sorted Yet.\n\n";
            return;
        }
        while(temp){
            index=temp->next;
            while(index){
                if(temp->Ename > index->Ename){
                    swap(temp->Ename, index->Ename);
                    swap(temp->Eid, index->Eid);
                    swap(temp->Esal, index->Esal);
                    swap(temp->Eday, index->Eday);
                    swap(temp->Emonth, index->Emonth);
                    swap(temp->Eyear,index->Eyear);
                    swap(temp->Egender,index->Egender);
                    swap(temp->isWorking,index->isWorking);

                }
                index = index->next;
            }
            temp=temp->next;
        }
        cout<<endl;
        cout<<"\nSorted Based on Name:\n";
        displayWorking(AD);
    }

    /*-------------------------Sort Based on ID--------------------*/

    void IDSorted(Admin_mode AD){
        Node* temp=AD.head,*index= nullptr;
        Node* cont;
        if(!temp){
            cout<<"\nNo Such Employees To Be Sorted Yet.\n\n";
            return;
        }
        while(temp){
            index=temp->next;
            while(index){
                if(temp->Eid > index->Eid){
                    swap(temp->Ename, index->Ename);
                    swap(temp->Eid, index->Eid);
                    swap(temp->Esal, index->Esal);
                    swap(temp->Eday, index->Eday);
                    swap(temp->Emonth, index->Emonth);
                    swap(temp->Eyear,index->Eyear);
                    swap(temp->Egender,index->Egender);
                    swap(temp->isWorking,index->isWorking);
                }
                index = index->next;
            }
            temp=temp->next;
        }
        cout<<"\nSorted Based on ID:\n";
        displayWorking(AD);
    }

    /*--------------------Salary between Given Range------------*/

    void SalaryRange(Admin_mode AD){
        Node* temp=AD.head;
        if(!temp){
            cout<<"\nNo Such Salaries To Be Sorted Yet.\n\n";
            return;
        }
        string l,r;
        cout<<"Enter the range(from to):";
        cin>>l>>r;
        while(!isNumber(l)|| !isNumber(r)){
            cout<<"\n!!!!!!!!!!!!!!!!!INVALID INPUT!!!!!!!!!!!!!!!!!\n";
            cout<<"Enter the range(from to):";
            cin>>l>>r;
        }
        double l1=stod(l),r1= stod(r);
        int ans=0;
        while(temp){
            if(temp->Esal >=l1&&temp->Esal<=r1){
                ans++;
                cout<<endl;
                printDetails(temp);
                cout<<endl;
            }
            temp=temp->next;
        }
        if(ans!=0){
            cout<<"\nThe Number of Salaries in that given range is:"<<ans<<endl;
        }else{
            cout<<"\nNo Salaries in that given range\n\n";
        }

    }

    /*-------------------------Guest mode--------------------*/
    void DisplayGuest(Admin_mode AD){
        while(true) {
            int OP;
            cout << "\nDisplay Employees sorted based on Name     (1)\n"
                 << "Display Employees sorted based on ID       (2)\n"
                 << "Display salary between given range         (3)\n"
                 << "To Quit Guest mode                         (4)\n"
                 << "Exit                                       (5)\n"
                 << "Enter the choice:";
            cin >> OP;
            switch (OP) {
                case 1:
                    NSorted(AD);
                    break;
                case 2:
                    IDSorted(AD);
                    break;
                case 3:
                    SalaryRange(AD);
                    break;
                case 4:
                    cout << "\n";
                    return;
                case 5:
                    exit(0);

                default:
                    cout << "!!!!! Invalid Input !!!!!\n\n";
            }
            cin.clear();
            cin.ignore();
        }
    }
    void Guest(Admin_mode AD){
        while(true){
            int OP;
            cout<<"\nSearch for the details of an employee    (1)\n"
                <<"Generate a report for existing employees (2)\n"
                <<"To Quit the Guest mode                   (3)\n"
                <<"Exit                                     (4)\n"
                <<"Enter the choice:";
            cin>>OP;
            switch (OP) {
                case 1:Search(AD);
                    break;
                case 2:DisplayGuest(AD);
                    break;
                case 3:return;
                case 4:exit(0);

                default:
                    cout<<"\n!!!!!!!!!!!!!!!!!INVALID INPUT!!!!!!!!!!!!!!!!!\n\n";
            }
            cin.clear();
            cin.ignore();
        }
    }

};