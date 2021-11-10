#include<bits/stdc++.h>
using namespace std;
#define Max 10000
int a[Max],c=0,f=0;
void print()
{
    cout<<endl;
    for(int i=0;i<Max;i++)
    {
        cout<<a[i]<<"\t";
    }
}
void insertion()
{
    c=0;
    for(int i=0;i<Max;i++)
    {
        int temp=a[i];
        int j=i;
        while(j>0&&temp<a[j-1])
        {
            a[j]=a[j-1];
            j--;
            c++;
        }
        a[j]=temp;
    }
}
int main()
{
    cout<<"Random number: "<<endl;
    for(int i=0;i<Max;i++)
    {
        a[i]=rand()%10000;
    }
    print();
    cout<<endl;

    cout<<"sorted from random : "<<endl;
    insertion();
    print();

    cout<<endl;
    cout<<"operation: "<<c<<endl;

    insertion();
    cout<<"sorted from sort operation: "<<c<<endl;

    cout<<"reverse: ";

     for(int i=0;i<Max;i++)
    {

        int temp=a[i];
        int j=i;
        while(j>0&&temp>a[j-1])
        {
            a[j]=a[j-1];
            j--;
            f++;
        }
        a[j]=temp;
    }
    print();
    cout<<endl<<"operation: "<<f<<endl;
    cout<<endl;

}
