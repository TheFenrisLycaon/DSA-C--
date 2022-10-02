#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char pass[20], ePass[20];
    int numOne, numTwo, sum;
    cout<<"Create a Password: ";
    cin>>pass;
    cout<<"\nEnter Two Numbers to Add: ";
    cin>>numOne>>numTwo;
    cout<<"\nEnter the Password to See the Result: ";
    cin>>ePass;
    if(!strcmp(pass, ePass))
    {
        sum = numOne + numTwo;
        cout<<endl<<numOne<<" + "<<numTwo<<" = "<<sum;
    }
    else
        cout<<"\nSorry! You've entered a Wrong Password!";
    cout<<endl;
    return 0;
}
