#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    string para;
    ofstream fout("Count.txt");
    if (fout.is_open())
    {
       int n;
       cout << "Enter number of lines: ";
       cin >> n;
       cin.ignore();

       for (int i = 0; i < n; i++)
      {
       getline(cin, para);
       fout << para << endl;
      } fout.close();
    }
    else
        cout<<"Error opening file!"<<endl;

    int wc=0,lc=0,cc=0;
    ifstream fin("Count.txt");
        if(fin.is_open())
        {
           while(getline(fin,para))
           {
                  lc++;
                   if (!para.empty())
                    wc = 1;
                    for (int i = 0; i < para.length(); i++)
                    {
                        if (para[i] == ' ')
                        wc++;
                    }

            cc++;
        }
            fin.close();
        } else
        cout<<"Error opening file!"<<endl;
    cout<<"Words count:"<<wc<<endl;
    cout<<"Line count:"<<lc<<endl;
    cout<<"Character count:"<<cc<<endl;
    return 0;
}
