#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;
typedef vector<long long> vll;
#define pb push_back
#define ho(a) a.begin(), a.end()
ll aj = LLONG_MAX;
ll mod = 1e9 + 7;
void dfs(int node,vll &vis ,vector<ll> adj[],vll &storeDfs)
{
    storeDfs.push_back(node);
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj,storeDfs);
        }
    }
}
vector<ll> dfsOfGraph(int node,vector<ll> adj[])
{
    vll storeDfs;
    vll vis(node+1,0);
    for(int i=1;i<=node;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,adj,storeDfs);
        }
    }
    return storeDfs;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vll dfs=dfsOfGraph(n,adj);
    for(int i=0;i<dfs.size();i++)
    {
        cout<<dfs[i]<<" ";
    }

    return 0;
}