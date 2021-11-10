#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define m 50
#define inf 100000
vector<pii>G[m];///graph
vector<int>d(m,inf);///distance
vector<int>p(m,-1);///parent
void path(int i)
{
    if(p[i]==-1)
        return ;
    path(p[i]);
    cout<<"->"<<i;
}
void djikstra(int s)
{

    priority_queue< pii, vector<pii>,greater<pii> >q;
    q.push(pii(s,0));
    d[s]=0;
    while(!q.empty())
    {
        int u=q.top().second;///node
        int c=q.top().first;///node cost so far
        q.pop();
        if(d[u]<c)
            continue;
        for(auto x:G[u])
        {
            int v=x.first;///node
            int w=x.second;///edge weoght
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                q.push(pii(d[v],v));
                p[v]=u;
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
        G[v].push_back(make_pair(u,w));
    }
    int s;
    cout<<"source: ";
    cin>>s;
    djikstra(s);
    cout<<"source->node\tcost\t\tpath;"<<endl;
    for(int i=0; i<n; i++)
    {
        if(d[i]>=inf)
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
