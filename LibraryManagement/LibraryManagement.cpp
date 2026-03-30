#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Book
{
    string title;
    int id;
    string aname;
public:
    void input()
    {
       cout<<"Enter Id:";
       cin>>id;
       cout<<"Enter Book Title:";
       cin.ignore();
       getline(cin,title);
      // cin.ignore();
       cout<<"Enter Author's name:";
       getline(cin,aname);
    }
    void Display()
    {
        cout<<"Book Id:"<<id<<"\nTitle:"<<title<<"\nAuthor's Name:"<<aname<<endl;
    }
    int getid()
    {
        return id;
    }
    void wtf()
    {
        ofstream of("LibraryManagemet.txt",ios::app);
        if(of.is_open())
        {
            of<<id<<"\n"<<title<<"\n"<<aname<<endl;
            of.close();
        }
        else
            cout<<"Error opening file!\n";
    }
    void rff()
    {
        ifstream fin("LibraryManagemet.txt");
        if(fin.is_open())
        {
            while(fin>>id)
            {
                fin.ignore();
                getline(fin,title);
                getline(fin,aname);
                Display();
            }
            fin.close();
        }
        else
            cout<<"Error opening file!";
    }
};
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    Book *b=new Book[n];
    for(int i=0;i<n;i++)
    {
        b[i].input();
        b[i].wtf();
    }
    cout<<"\nBooks Record\n";
    //for(int i=0;i<n;i++)
        b[0].rff();
    int bid,found=0;
    cout<<"Enter book id to search:";
    cin>>bid;
    for(int i=0;i<n;i++)
    {
        if(b[i].getid()==bid)
        {
            b[i].Display();
            found =1;
            break;
        }
    }
    if(found==0)
        cout<<"Book not found!";
    delete[] b;
    return 0;
}
