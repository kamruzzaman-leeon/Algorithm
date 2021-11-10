#include<bits/stdc++.h>
#define m 7
using namespace std;
int arr[m+10];

void print()
{
    for(int i=0; i<m; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void Merge(int low,int high,int mid)
{
//    cout<<"merge into "<<low<<" "<<mid<<" "<<high<<endl;
    int t=1;
    int l[high-low];
    for(int i=low; i<=mid; i++)
    {
        l[t++]=arr[i];
    }
    l[t]=INT_MAX;
    t=1;
    int R[high-low];
    for(int i=mid+1; i<=high; i++)
    {
        R[t++]=arr[i];
    }
    R[t]=INT_MAX;
    int i=1,j=1;
    for(int k=low; k<=high; k++)
    {
        if(l[i]<R[j])
            arr[k]=l[i++];
        else
            arr[k]=R[j++];
    }
}

void Mergesort(int low,int high)
{
    int mid=(low+high)/2;
//    cout<<"out "<<low<<" "<<high<<endl;
    if(low < high)
    {
//        cout<<"in "<<low<<" "<<high<<endl;
        Mergesort(low,mid);
//        cout<<"       1st"<<endl;
        Mergesort(mid+1,high);
//        cout<<"       2nd"<<endl;
        Merge(low,high,mid);
//        cout<<"Merge"<<endl;
    }

}
int main()
{
    for(int i=0; i<m; i++)
    {
        arr[i]=rand();
    }

    print();
    cout<<endl;
    int low=0,high=m-1;
    Mergesort(low,high);
    print();
    return 0;
}
