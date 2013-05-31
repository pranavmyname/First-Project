#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>

#include<stdlib.h>
using namespace std;
struct data
{
    string noun1,noun2,noun3,nounp,adjective,name,place,entry[7];
};
void putquestion()
{
    cout<<"This is your question\n";
    ifstream afile;
    afile.open("1.txt");
    char a;
    while(afile)
    {
        afile.get(a);
        cout<<a;
    }
    cout<<endl;
    afile.close();
}
void copyfile(data info)
{
    ofstream temp;
    ifstream afile;
    int i=0;
    afile.open("1.txt");
    afile.seekg(0L,ios::beg);
    char a;
    temp.open("temp.txt");
    while(afile)
    {
        afile.get(a);
        if (a=='#')
        {
            //cout<<"\nFound"<<endl;
            temp<<info.entry[i];
            i++;
        }
        else
        {
            temp.put(a);
        }
    }
}
//int check()
//{
//    int flag=1,ctr=0;
//    int i=0;
//    string a="100.txt";
//
//    ifstream text;
//    while(flag==1)
//    {
//        cout<<"a= "<<a<<endl;
//        text.open(a.c_str());
//        if(!text)
//        {
//            cout<<"File not found"<<endl;
//            flag=0;
//        }
//        else
//        {
//            cout<<"File found"<<endl;
//            a[0]+=1;
//            i++;
//            text.close();
//        }
//    }
//    return (i);
//}
void create()
{
    ofstream text;
    data info;
    cout<<"Enter a noun ";
    cin>>info.entry[0];
    cout<<"Enter another noun ";
    cin>>info.entry[2];
    cout<<"Enter yet another noun ";
    cin>>info.entry[3];
    cout<<"Enter a plural noun ";
    cin>>info.entry[1];
    cout<<"Enter an adjective ";
    cin>>info.entry[5];
    cout<<"Enter a name ";
    cin>>info.entry[6];
    cout<<"Enter the name of place ";
    cin>>info.entry[4];
    copyfile(info);
}
void showans()
{
    cout<<"This is your answer\n";
    ifstream temp;
    char a;
    temp.open("temp.txt");
    while(temp)
    {
        temp.get(a);
        cout<<a;
    }
    cout<<endl;
}
int main()
{
    char a,b;
    putquestion();
    create();
    cout<<endl;
    showans();
    cout<<"Do you want to save your answer file y/n ";
    cin>>a;
    switch(a)
    {
        case 'y':
        {
            ifstream temp;
            char fname[20];
            cout<<"Enter your file name ";
            cin>>fname;
            strcat(fname,".txt");
            temp.open("temp.txt");
            ofstream nfile;
            nfile.open(fname);
            while(temp)
            {
                temp.get(b);
                nfile.put(b);
            }
            cout<<"\nFile Saved "<<endl;
            break;
        }
        case 'n':
            break;
    }
    return 0;
}
