#include<bits/stdc++.h>
using namespace std;

#define m 10
#define for(lo,hi) for(int i=lo;i<hi;i++)

int arr[m+10];
void print()
{
    for(0,m)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
int pivot(int a[],int x,int y)
{
    int temp=a[x];
    int i=x+1;
    int j=y;
    for(x,y+1)
    {
        while(a[i]<=temp)
            i++;
        while(a[j]>temp)
            j--;

        if(i<j){
            swap(a[i],a[j]);
            i++;
            j--;
            }
        else{
            swap(a[x],a[j]);
            return j;
        }
    }

}
void quicksort(int a[],int low,int high)
{

    int q;
    if(low<high)
    {
        q=pivot(a,low,high);
        quicksort(a,low,q-1);
        quicksort(a,q+1,high);
    }

}
int main()
{
    int low =0,high=m-1;
    for(low,high)
    {
        arr[i]=rand()%111;
    }
    print();
    cout<<endl;
    quicksort(arr,low,high);
    print();
    cout<<endl;
    return 0;
}
