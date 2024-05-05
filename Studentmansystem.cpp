// student management system in c++

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>

using namespace std;
class student
{
private:
    string name, roll_no, course, address, email_id, contact_no;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};
void student::menu()
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t----------------------------------" << endl;
    cout << "\t\t\t |  STUDENT MANAGEMENT SYSTEM  |" << endl;
    cout << "\t\t\t----------------------------------" << endl;
    cout << "\t\t\t 1.  Enter new Record  : " << endl;
    cout << "\t\t\t 2.  Display Record  : " << endl;
    cout << "\t\t\t 3.  Modify Record  : " << endl;
    cout << "\t\t\t 4.  Search Record  : " << endl;
    cout << "\t\t\t 5.  Delete Record  : " << endl;
    cout << "\t\t\t 6.  EXIT  : " << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choice:";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t Add Another Student Record(Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid Choice....PleaseTry Again..";
    }
    getch();
    goto menustart;
}
void student::insert()   // add student details
{
    system("cls");
    fstream file;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------------------------------Add Student Details-----------------------------------------------------------------" << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_no;
    cout << "\t\t\tEnter Course: ";
    cin >> course;
    cout << "\t\t\tEnter Email Id: ";
    cin >> email_id;
    cout << "\t\t\tEnter Contact No.: ";
    cin >> contact_no;
    cout << "\t\t\tEnter Address: ";
    cin >> address;
    file.open("studentrecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();
}
void student::display()
{
    system("cls");
    fstream file;
    int total=0;
     cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------";
     cout << "--------------------------------------------------------Student Record Table-----------------------------------------------------------------" << endl;
    file.open("studentrecord.txt", ios::in);
    if(!file)
    {
        cout<<"\n\t\t\tNo Data Is Present.....";
        file.close();
    }
    else
    {
        file >> name >> roll_no >>course >> email_id >> contact_no >>address;
        while (!file.eof())
        {
            cout<<"\n\n\t\t\t Student No. : " <<total++ <<endl;
            cout<<"\t\t\t Student Name : " << name <<endl;
            cout<<"\t\t\t Student Roll No. : " << roll_no <<endl;
            cout<<"\t\t\t Student email Id : " << course <<endl;
            cout<<"\t\t\t Student Course : " << email_id <<endl;
            cout<<"\t\t\t Student Address : " << address <<endl;
            file >> name >> roll_no >>course >> email_id >> contact_no >>address;
        }
        if (total == 0)
        {
            cout<<"\n\t\t\tNo Data Is Present.....";
        }
    }
    file.close();
}
void student::modify()
{
    system("cls");
    fstream file, file1;
    int found=0;
    string rollno;
    cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------";
    cout << "--------------------------------------------------------Student Modify Details---------------------------------------------------------------------" << endl;
    file.open("studentrecord.txt", ios::in);
    if(!file)
    {
        cout<<"\n\t\t\t No Data Is Present....";
        // file.close();
    }
    else
    {
        cout<<"\n Enter Roll No. of student which you want to Modify:";
        cin>>rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >>course >> email_id >> contact_no >>address;
        while(!file.eof())
        {
            if(rollno != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                cout << "\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "\t\t\tEnter Course: ";
                cin >> course;
                cout << "\t\t\tEnter Email Id: ";
                cin >> email_id;
                cout << "\t\t\tEnter Contact No.: ";
                cin >> contact_no;
                cout << "\t\t\tEnter Address: ";
                cin >> address;
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
        file >> name >> roll_no >>course >> email_id >> contact_no >>address;
        if (found==0)
        {
            cout<<"\n\t\t\t Student Roll No. Not Found...";
        }
        }
        file1.close();
        file.close();
        remove("studentrecord.txt");
        rename("Record.txt","studentrecord.txt");

    }
 

}
void student::search()    // Search data of Student..............
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentrecord.txt", ios::in);
    if(!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------";
        cout << "--------------------------------------------------------Student Search Data------------------------------------------------------------------------" << endl;
        cout<<"\n\t\t\t No Data Is Present....";
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------";
        cout << "--------------------------------------------------------Student Search Data------------------------------------------------------------------------" << endl;
        cout<<"\n Enter Roll No. of Student Which You Want to Search: ";
        cin>>rollno;
        file >> name >> roll_no >>course >> email_id >> contact_no >>address;
        while(!file.eof())
        {
            if(rollno == roll_no)
            {
            cout<<"\t\t\t Student Name : " << name <<endl;
            cout<<"\t\t\t Student Roll No. : " << roll_no <<endl;
            cout<<"\t\t\t Student email Id : " << course <<endl;
            cout<<"\t\t\t Student Course : " << email_id <<endl;
            cout<<"\t\t\t Student Address : " << address <<endl;
            found++;
            }
        file >> name >> roll_no >>course >> email_id >> contact_no >>address;
        }
        if(found == 0)
        {
            cout<<"\n\t\t\t Student Roll No. Not Found...";
        }
        file.close();
    }
}

void student::deleted()
{
    system("cls");
    fstream file,file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------";
    cout << "--------------------------------------------------------Delete Student Details-----------------------------------------------------------------" << endl;
    file.open("studentrecord.txt", ios::in);
    if(!file)
    {
        cout<<"\n\t\t\t No Data Is Present....";
    }
    else
    {
        cout<<"\n Enter Roll No. of Student which you want to Delete Data:";
        cin>>rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >>course >> email_id >> contact_no >>address;
        while(!file.eof())
        {
            if(rollno != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else{
                found++;
                cout<<"\n\t\t\t Successfully Data has been deleted";
            }
            file >> name >> roll_no >>course >> email_id >> contact_no >>address;
        }
        if(found == 0)
        {
            cout<<"\n\t\t\t Student Roll No. not found...";
        }
        file1.close();
        file.close();
        remove("studentrecord.txt");
        rename("Record.txt","studentrecord.txt");

    }
    
}
main()
{
    student project;
    project.menu();
    return 0;
}