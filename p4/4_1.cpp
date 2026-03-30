#include<iostream>
using namespace std;
class aray
{
    int *arr,size;
public:
    aray()
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
    void deletel(int pos)
    {

        if(pos < 0 || pos >= size)
        {
            cout << "Invalid position\n";
            return;
        }
        int *b = new int[size - 1];

        for(int i = 0, j = 0; i < size; i++)
        {
            if(i != pos)
                b[j++] = arr[i];
        }

        delete[] arr;
        arr = b;
        size--;
    }
    void display()
    {
        for(int i=0;i<size ;i++)
        {
            cout<<" "<<arr[i];
        }
    }
};
int main()
{
    int *ptr;
    int n,pos1,pos2,ele1;
    aray b;
   b.inserte(3);
   b.inserte(5);
   b.inserte(8);
   cout<<"Array:\n";
   b.display();
   b.deletel(1);
   cout<<"\nAfter deletation:\n";
   b.display();
    return 0;
}
