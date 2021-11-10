#include<bits/stdc++.h>
using namespace std;

void mcm(int p[],int n)
{
    int i,j,k,l;
    int mini,m[n][n];
    for(i=1;i<n;i++)
    {
        m[i][i]=0;
    }
    for(l=2;l<n;l++)
    {
        for(i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(k=i;k<j;k++)
            {
                mini=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(mini<m[i][j])
                {
                    m[i][j]=mini;
                    cout<<m[i][j]<<" ";
                }
            }
        }cout<<endl;
    }
    cout<<"minimuim cost : "<<m[1][n-1]<<endl;
}
int main()
{
    int n;
    cout<<"enter your martix dimension element size in 1d :";
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    mcm(p,n);
    return 0;

}
