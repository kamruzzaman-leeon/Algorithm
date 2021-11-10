#include<bits/stdc++.h>
using namespace std;

void knapsack(int val[],int wt[],int w,int n)
{
    int k[n+1][w+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(i==0||j==0)
            {
                k[i][j]=0;
            }
            else if(wt[i-1]<=j)
            {
                k[i][j]=max(k[i-1][j],val[i-1]+k[i-1][j-wt[i-1]]);
            }
            else
            {
                k[i][j]=k[i-1][j];
            }

        }
    }
    int temp=k[n][w];
    cout<<"maximum benefit: "<<temp<<endl;
    for(int i=n; i>0&&temp>0; i--)
    {
        if(temp==k[i-1][w])
            continue;
        else
        {
            cout<<"weight : "<<wt[i-1]<<" value: "<<val[i-1]<<endl;
            temp=temp-val[i-1];
            w=w-wt[i-1];
        }
    }
}
int main()
{
    int n;
    cout<<"enter your element number: ";
    cin>>n;
    int wt[n],val[n],w;
    cout<<"enter your element value:";
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<": ";
        cin>>val[i];
    }
    cout<<"enter your element weight:";
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<": ";
        cin>>wt[i];
    }
    cout<<"enter your bag size:";
    cin>>w;
    knapsack(val,wt,w,n);

    return 0;
}
