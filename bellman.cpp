#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define m 50

vector<pii>G[m];///graph
vector<int>d(m,INT_MAX);///distance
vector<int>p(m,-1);///parent
void path(int i)
{
    if(p[i]==-1)
        return ;
    path(p[i]);
    cout<<"->"<<i;
}
void bellman(int s,int n)
{
    d[s]=0;
    int u,v,w;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n; j++)
        {
            u=j;
            for(auto x:G[u])
            {
                u=j;
                v=x.first;///node
                w=x.second;///edge weoght
                if(d[u]!=INT_MAX&&d[u]+w<d[v])
                {
                    d[v]=d[u]+w;
                p[v]=u;
                }
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(auto x:G[u])
        {
            v=x.first;
            w=x.second;
            if(d[v]>d[u]+w)
            {
                cout<<"negative cycle";
                break;
            }
        }
    }

}
int main()
{
    int n,e,u,v,w;
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
//        G[v].push_back(make_pair(u,w));
    }
    int s;
    cout<<"source: ";
    cin>>s;
    bellman(s,n);
    cout<<"source->node\tcost\t\tpath;"<<endl;
    for(int i=0; i<n; i++)
    {
        if(d[i]>=INT_MAX)
            cout<<"not reachable!"<<endl;
        else
        {
            cout<<s<<"->"<<i<<"\t\t"<<d[i]<<"\t\t"<<s;
        path(i);
            cout<<endl;
        }
    }


    return 0;
}
