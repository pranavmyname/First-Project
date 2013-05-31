#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    long int x,y,z;
    char a='y';
    while(a=='y')
    {
    cout<<"Enter two numb ";
    cin>>x>>y;
    z=x+y;
    cout<<"Sum = ";
    cout<<z;
    cout<<"\nDo you want to continue just tell me(y/n)";
    cin>>a;
    }
    return 0;
}
