#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream file("DET.txt",ios::app| ios::in | ios::out);
    float ex,total=0;
    if(file.is_open())
    {
        cout<<"Add Expense:";
        cin>>ex;
        file<<ex<<endl;
    }
    file.seekg(0);

    while(file>>ex)
    {
        cout<<ex<<endl;
        total += ex;
    }
    cout<<"Total expense:"<<total;
    file.close();

}

