#include<iostream>
using namespace std;
/*class Array
{
    int *arr,size;
public:
    Array()
    {
        arr=NULL;
        size=0;
    }
    void inserte(int ele)
    {
        int *b = new int[size + 1];
        for(int i = 0; i < size; i++)
            b[i] = arr[i];

        b[size] = ele;

        delete[] arr;
        arr = b;
        size++;
    }
    void mergearry(int n,int m,Array *a,Array *b)
    {
        int *c=new int[n+m];
        while(i<n && j<m)
    {
        if(a[i]<=b[j])
        {
            c[k++]=a[i++];
        } else

        c[k++]=b[j++];
    }
    while(k<n)
        c[k++]=a[i++];
    while(j<m)
        c[k++]=b[j++];
    }
    void display()
    {

    }
};
*/
int main()
{
    int n,m;
    cout<<"Enter size of 1st array:";
    cin>>n;
    cout<<"Enter size of 2nd array:";
    cin>>m;
    int *a=new int[n];
    int *b=new int[m];
    int *c=new int[n+m];
    cout<<"Enter elements of 1st array:";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter elements of 2nd array:";
    for(int i=0;i<m;i++)
        cin>>b[i];
    int i=0,j=0,k=0;



  /*  while(i<n && j<m)
    {
        if(a[i]<=b[j])
        {
            c[k++]=a[i++];
        } else

        c[k++]=b[j++];
    }*/
    int *d=new int[n+m];

    while(k<n)
        c[k++]=a[i++];
    while(j<m)
        c[k++]=b[j++];

     for(int i=0;i<n+m-1;i++)
    {
        for(int j=0;j<n+m-i-1;j++)
        {
            if(c[j] > c[j+1])
            {
                int temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
    }
    cout<<"\nMerged Array:\n";
    for(int x=0; x<(n+m);x++)
        cout<<c[x]<<" ";
}
