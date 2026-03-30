#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main()
{
    string para;
    cout<<"Enter paragraph:";
    getline(cin,para);
    for(int i=0; i<para.length(); i++)
    {
        para[i]=tolower(para[i]);
    }
    string words[500];
    int wc=0;
    int f[500];
    string temp="";
    for(int i=0 ; i<=para.length(); i++)
    {
        if(para[i]!=' ' && para[i]!='\0')
        {
            temp+=para[i];
        }
        else
        {
            if(temp!="")
            {
                int found=0;
                for(int j=0; j<wc; j++)
                {
                    if(words[j]==temp)
                    {
                        f[j]++;
                        found=1;
                        break;
                    }
                }
                if(found==0)
                    {
                        words[wc]=temp;
                        f[wc]=1;
                        wc++;
                    }
                     temp="";
            }
        }
    }
    cout<<"\nWords count\n";
    for(int i=0;i<wc;i++)
    {
        cout<<words[i]<<" : "<<f[i]<<endl;
    }
    return 0;
}
