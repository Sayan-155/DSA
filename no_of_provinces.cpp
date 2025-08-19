#include<bits/stdc++.h>
using namespace std;

// function to make undirected graph
void add_edge_undir(vector<vector<int>> & adj , int u , int v)
{
    adj[u].push_back(v); 
}

vector<int> bfs(vector<vector<int>> adj)
{
    int n = adj.size();
    
    queue<int> qu;
    vector<int> res;

    int start = 0 ;
    vector<bool> visited(n , false);

    visited[start] = true;
    qu.push(start);

    while(! qu.empty())
    {
        int curr = qu.front();
        qu.pop();
        res.push_back(curr);

        for(int x: adj[curr])
        {
            if(! visited[x])
            {
                visited[x] = true;
                qu.push(x);
            }
        }
    }
    return res;
}

vector<int> dfs(vector<vector<int>> adj , int start = 0)
{
    int n= adj.size();
    vector<bool> visited(n , false);
    vector<int> res(n);

    visited[start] = true;

    stack<int> st;
    st.push(start);

    while(! st.empty())
    {
        int curr = st.top();
        st.pop();
        res.push_back(curr);

        for(int x: adj[curr])
        {
            if(! visited[x])
            {
                visited[x] = true;
                st.push(x);
            }
        }
    }
    return res;
}

int num_provinces(vector<vector<int>> &adj)
{
    int n = adj.size();
    int provinces = 0 ;

    vector<bool> visited(n , false);

    for(int i= 0 ; i<n ; i++)
    {
        if(! visited[i])
        {
            dfs(adj , i);
            provinces ++;
        }
    }
    return provinces;
}