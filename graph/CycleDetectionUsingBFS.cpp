#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;
typedef vector<long long> vll;
#define pb push_back
#define ho(a) a.begin(), a.end()
ll aj = LLONG_MAX;
ll mod = 1e9 + 7;
bool cmp(pr a, pr b)
{
    return a.second < b.second;
}
ll binpow3(ll a, ll b)
{
    ll res = 1;
    a = a % mod;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b = b >> 1;
    }
    return res;
}
bool CheckForCycle(ll s,ll v,vector<ll>adj[],vector<ll>&visited)
{
    queue<pair<ll,ll>>q;
    visited[s]=1;
    q.push({s,-1});
    while(!q.empty())
    {
        ll node=q.front().first;
        ll par=q.front().second;
        q.pop();
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                visited[it]=true;
                q.push({it,node});
            }
            else{
                if(par!=it)
                {
                    return true;
                }
            }
        }
        
    }
    return false;
}
bool IsCycle(ll v,vll adj[])
{
     vll vis(v+1,0);
     for(int i=1;i<=v;i++)
     {
        if(!vis[i])
        {
            if(CheckForCycle(i,v,adj,vis))
            {
                return true;
            }
        }
     }
     return false;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool tell = IsCycle(n, adj);
    if(tell)
    {
        cout<<"YES\n";

    }
    else{
        cout<<"NO\n";
    }

    return 0;
}