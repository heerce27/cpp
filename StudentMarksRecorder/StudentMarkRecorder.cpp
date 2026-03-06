#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    ofstream fout("marks.txt", ios::app);
    string name;
    int marks,n;
    if(fout.is_open())
    {
        cout<<"Enter no of students:";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter name:";
            cin>>name;
            cout<<"Enter Marks:";
            cin>>marks;
            fout<<name<<" "<<marks<<endl;
        }
        fout.close();
    }
    ifstream fin("marks.txt");
    cout<<"\nStudents scoring more than 75 marks:\n";
    while(fin>>name>>marks)
    {
        if(marks>75)
            cout<<name<<" "<<marks<<endl;
    }
    fin.close();

}
