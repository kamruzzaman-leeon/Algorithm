#include<bits/stdc++.h>
using namespace std;
#define n 4
#define m 5
//int a[n][m]={{2,4,2,5,2},{2,8,2,10,3},{4,2,2,10,3},{3,8,7,8,3},{15,4,3,10,9},{5,2,8,7,3}};
int a[n][m]={{2,8,9,5,8},{4,4,6,2,3},{5,7,5,6,1},{3,2,5,4,8}};
int x[n][m]={{0},{0},{0},{3,2,5,4,8}};
//int x[n][m]={{0},{0},{0},{0},{0},{5,2,8,7,3}};
int print(int c[n][m])
{

    for(int i =0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<setw(n)<<c[i][j];
        cout<<endl;
    }
    cout<<endl;
}
int rock()
{



    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            if(j==0)
            {
                x[i][j]= min(x[i+1][j],x[i+1][j+1])+a[i][j];
            }
            else if(j==m-1)
            {
                x[i][j]= min(x[i+1][j],x[i+1][j-1])+a[i][j];
            }
            else
                x[i][j]= min(x[i+1][j-1],min(x[i+1][j],x[i+1][j+1]))+a[i][j];
        }
    }
}
int main()
{
    print(a);
    cout<<endl;
    print(x);
    cout<<endl;
    rock();
    cout<<endl;
    print(x);
    int p=INT_MAX;
    for(int i=0;i<m;i++)
    {
        if(p>=x[0][i])
        {
            p=x[0][i];
        }
    }
    cout<<endl<<p<<endl;
    return 0;
}
