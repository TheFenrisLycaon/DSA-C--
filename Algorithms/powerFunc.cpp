///Find a^b without using power function


#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b; ///2>>4

    int power =1;

    for(int i=1;i<=b;i++)  
    {
       power = power*a; 
    }
    cout<<power<<endl;
    return 0;
}
