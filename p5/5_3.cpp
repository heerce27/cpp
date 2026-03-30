#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<limits>
using namespace std;
string toLower(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}
class Item
{
    string name;
    int qty;
    float price;
public:
    void add()
    {
        cout<<"Enter name:";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,name);
        cout<<"Enter qty:";
        cin>>qty;
        cout<<"Enter price:";
        cin>>price;
        if(qty < 0 || price < 0)
        {
            cout<<"Invalid input!\n";
            name="";
            return;
        }
    }
    void display()
    {
        cout<<"\n--------------\nName: "<<name<<"\nQty: "<<qty<<"\nPrice: "<<price<<endl;
    }
    string rN()
    {
        return name;
    }
    void wtf()
    {
        ofstream of("Item.txt", ios::app);
        if(of.is_open())
        {
            of<<name<<"\n"<<qty<<"\n"<<price<<endl;
            of.close();
        }
        else
            cout<<"Error opening file or file not found!\n";
    }
    void rff()
    {
        ifstream rf("Item.txt");
        if(rf.is_open())
        {
            while(getline(rf,name))
            {
                if(!(rf >> qty >> price))
                break;
                rf.ignore(numeric_limits<streamsize>::max(), '\n');
                display();
            }
            rf.close();
        }else
        cout<<"Error opening file or file not found!\n";
    }
    void search(string in)
    {
        ifstream fin("Item.txt");
        string n;
        int q;
        float p;
        int f=0;
        if(fin.is_open())
        {
            while(getline(fin,n))
            {
                if(!(fin >> q >> p))
                break;

                fin.ignore(numeric_limits<streamsize>::max(), '\n');

                if(toLower(n)==toLower(in))
                {
                cout<<"Item Found!\n";
                cout<<"----------------------\n";
                cout<<"Name: "<<n<<"\nQty: "<<q<<"\nPrice: "<<p<<endl;
                f=1;
                }
            } fin.close();
        }
        if(f==0)
            cout<<"Item not found!\n";
    }
};
int main()
{
    int ch;
    Item obj;
    string sn;
    do
    {
    cout<<"\n---------------\n1. Add Item\n2. View Items\n3. Search Item\n4. Exit\n";
    cout<<"Enter your choice:";
    cin>>ch;

    switch(ch)
    {
        case 1:
            obj.add();
             if(obj.rN() != "")
                obj.wtf();
            break;
        case 2:
            obj.rff();
            break;
        case 3:
            cout<<"Enter item name to search:";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,sn);
            obj.search(sn);
            break;
        case 4:
            cout<<"Exiting..\n";
            break;
        default:
            cout<<"Enter valid choice!\n";
            break;
    }
    }while(ch!=4);
    return 0;
}
