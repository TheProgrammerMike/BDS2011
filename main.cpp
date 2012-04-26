//DENTASOFT BILLING V. 1.1.0.2 -Created by: Michael Bekesz, July 2011. For Brodway Dental Studios Inc.

#include "main.h"

using namespace std;
void CreateNewFile(); //establishes primary *.txt for billing
void WelcomeScr();  //Main Menu
void AnotherEntry(); //Repeat control function
void Total(); //Enables total feature, allows for multi text input and calculation of numeric values.
int mode=1, x, cycle=0, BillNum;
bool Repeat=true;
double date, charge, sum=0, unpaid;
string Month, Doctor, Date, Pat, Pat2, Amount, Year;
int main()
{
        while(mode>0)
        {
                if(mode==1)
                {
                        WelcomeScr();
                }
                if(mode==0)
                {
                        exit(1);
                }
                if(mode==2)
                {
                        CreateNewFile();
                }
        }
        return 0;
}
void CreateNewFile()
{

        ofstream Bill("C:\\Dentasoft Billing\\New Created Dentasoft Bill.txt");
        for(x=0;x<=13;x++)
        {
                Bill<<endl;
        }
        x=0;
        cout<<"Please enter the name of the doctor."<<endl;
        cin>>Doctor;
       system("cls");

        Bill<<"Dr. "<<Doctor;
        cout<<"Please enter the Month of the Bill. (E.g. January)"<<endl;
        cin>>Month;
        system("cls");
        cout<<"Please enter the Year of the Bill. (E.g. 2003)"<<endl;
        cin>>Year;
system("cls");

        Bill<<setw(55)<<Month<<", "<<Year<<endl;
        while(Repeat==true)
        {
                if (cycle==0)
                {
                        cout<<"It is now time to begin the billing process."<<endl;
                        system("cls");
                        Bill<<endl<<"Date"<<setw(20)<<"Bill Number"<<setw(20)<<"Patient"<<setw(20)<<"Amount ($)"<<endl<<endl;
                        cycle++;
                }
                if (cycle>=1)
                {
                        system("cls");
                        cout<<"Please enter the date of line #"<<cycle<<". E.g. MM/DD"<<endl;
                        cin>>Date;
                        cout<<"Please enter the bill number."<<endl;
                        cin>>BillNum;
                        cout<<"Please enter the patient's name."<<endl;
                        //cin>>Pat>>Pat2;
                        cin>>Pat;
						cout<<"Please enter an amount."<<endl;
						double checkcharge=0;
                     //   cin>>checkcharge;
						charge=CheckInputNumber(checkcharge);
                        cout<<"Is this ok?"<<endl<<"Date: "<<Date<<endl<<"Bill#: "<<BillNum<<endl<<"Patient: "<<Pat<<endl<<"Amount: "<<charge<<endl<<"(1-True, 0-False)"<<endl;
                        cin>>x;
                        if (x==1)
                        {
                           Bill<<Date<<setw(20)<<BillNum<<setw(20)<<Pat<<setw(20)<<charge<<endl;
                           sum+=charge;
                           AnotherEntry();
                           cycle++;
                        }
                }
        }
        cout<<"Is there an unpaid balance? (Press 1=yes, 0=no)"<<endl;
        cin>>x;
        system("cls");
        if (x==1)
        {
                cout<<"Please enter the unpaid amount."<<endl;
                cin>>unpaid;
                system("cls");
                Bill<<endl<<setw(65)<<"Sub-total $ "<<sum<<endl;
                Bill<<setw(65)<<"Unpaid balance $ "<<unpaid<<endl;
                sum+=unpaid;
                Bill<<setw(65)<<"Total $ "<<sum;
        }
        if (x==0)
        {
                Bill<<endl<<setw(65)<<"Total $ "<<sum;
        }
        cout<<"Bill composition complete!"<<endl;
        system("cls");
        mode=1;
        return;             
}
void WelcomeScr()
{
        cout<<"Welcome to the Main Menu"<<endl<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"2. To create a new file"<<endl;
        cin>>mode;
        system("cls");
        return;                 
}
void AnotherEntry()
{
        cout<<"Would you like to input another entry? (Press 1=true, 0=false)"<<endl;
        cin>>x;
        if (x==0)
        {
                Repeat=false;
        }
        if (x==1)
        {
                Repeat=true;
        }
        return;
}
void Total()
{
        int A=0, B=0;
        char a,b,c;
        ofstream Totals("C:\\Users\\Michael Bekesz\\Desktop\\Broadway Dental Studios\\Dentalsoft Billing\\Totals.txt",ios::app);
        Totals<<Doctor<<setw(40)<<sum<<endl;
        cout<<"Calculate and print total? (1=true, 0=false)";
        cin>>A;
        if(A==1)
        {

                A=0;
                while(Totals<<A)
                {
                        Totals<<A;
                        B+=A;
                }
                Totals<<"Total gross income: $ "<<B;
        }
        return;
}

