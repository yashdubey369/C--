#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    // Function add edges int adjacnecy list
    void addEdge(vector<int> adj[], int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Function to print adjlist
    void printadjlist(vector<int> adj[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "-> ";
            for (int &x : adj[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    // Traversal:
    // BFS:
    vector<int> bfs(int n, vector<int> adj[])
    {
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        vector<int> bfs;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for (auto &it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
    // DFS:
    void dfsgraph(int node, vector<int> &vis, vector<int> &ls, vector<int> adj[])
    {
        vis[node] = 1;
        ls.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfsgraph(it, vis, ls, adj);
            }
        }
    }
    vector<int> dfs(int n, vector<int> adj[])
    {
        vector<int> ls, vis(n + 1, 0);
        int start = 0;
        dfsgraph(start, vis, ls, adj);
        return ls;
    }
};
/////////////////////////////////////////////////////////Flood FilL Algorithm: Using DFS //////////////////////////////////////////////////////////
// To perform a flood fill, consider the starting pixel,
// plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel,
// plus any pixels connected 4-directionally to those pixels (also with the same color), and so on.
//  Replace the color of all of the aforementioned pixels with color.
void dfs(int n, int m, int sr, int sc, int iniColor, int newcolor, int delrow[], int delcol[], vector<vector<int>> &ans)
{
    ans[sr][sc] = newcolor;
    for (int i = 0; i < 4; i++)
    {
        int nrow = sr + delrow[i];
        int ncol = sc + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == iniColor && ans[nrow][ncol] != newcolor)
        {
            dfs(n, m, nrow, ncol, iniColor, newcolor, delrow, delcol, ans);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int iniColor = image[sr][sc];
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> ans = image;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    dfs(n, m, sr, sc, iniColor, color, delrow, delcol, ans);
    return ans;
}
/////////////////////////////////////////////////////////Flood Fill Algorithm: Using BFS////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////Is Graph Bipartite/////////////////////////////////////////////////////////////////////////////////////////
// Bipartite graph is the graph having only two color where every adjacent node have different color;
bool Bipartitebfs(int src, int n, vector<int> adj[], vector<int> &vis)
{

    queue<pair<pair<int, int>, int>> q;
    q.push({{src, -1}, 0});
    vis[src] = 0;
    while (!q.empty())
    {
        int node = q.front().first.first;
        int parent = q.front().first.second;
        int color = q.front().second;
        q.pop();
        for (auto adjnode : adj[node])
        {
            if (vis[adjnode] == -1)
            {
                if (color == 1)
                {
                    vis[adjnode] = 0;
                    q.push({{adjnode, node}, 0});
                }
                else
                {
                    vis[adjnode] = 1;
                    q.push({{adjnode, node}, 1});
                }
            }
            else if ((vis[adjnode] == 1 && color == 1 && adjnode != parent) || (vis[adjnode] == 0 && color == 0 && adjnode != parent))
                return false;
        }
    }
    return true;
}

bool isBipartite(int n, vector<int> adj[])
{
    // Code here
    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == -1)
        {
            if (!Bipartitebfs(i, n, adj, vis))
                return false;
        }
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// detect cycle in directed graph using DFS:
bool dfs(int node, int vis[], vector<int> adj[], int pathvis[], vector<int> &safenode)
{
    vis[node] = 1;
    pathvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, vis, adj, pathvis, safenode))
                return true;
        }
        else if (pathvis[it])
        {
            return true;
        }
    }
    safenode.push_back(node);
    pathvis[node] = 0;
    return false;
}
////////////////////////////////////////////////////////Toposort-Using DFS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dfstopo(int node, vector<int> adj[], int vis[], vector<int> &v)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfstopo(it, adj, vis, v);
    }
    v.push_back(node);
}
vector<int> topoSort(int n, vector<int> adj[])
{
    int vis[n] = {0};
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfstopo(i, adj, vis, v);
    }
    reverse(v.begin(), v.end());
    return v;
}
//////////////////////////////////////////////////////Toposort-Using BFS(KAHN'S ALGORITHM)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<int> topoSort(int n, vector<int> adj[])
{

    queue<int> q;
    vector<int> v;
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            v.push_back(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
                v.push_back(it);
            }
        }
    }

    return v;
}
// Driver Code
int main()
{
    // Given vertices
    graph g;
    // cout << "Undirected 0th-indexed graph--" << endl;
    // int n;
    // cout << "Enter the number of nodes: ";
    // cin >> n;
    // int m;
    // cout << "Enter th number of Edges: ";
    // cin >> m;
    // cout << "Enter the edges:" << endl;
    // int u, v;
    // vector<int> adj[n + 1];
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> u >> v;
    //     g.addEdge(adj, u, v);
    // }
    // cout << "Adjacency List:" << endl;
    // g.printadjlist(adj, n);
    // cout << "Traversal:" << endl;
    // cout << "   BFS: ";
    // vector<int> y = g.bfs(n, adj);
    // for (auto i : y)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "   DFS: ";
    // vector<int> d = g.dfs(n, adj);
    // for (auto i : d)
    // {
    //     cout << i << " ";
    // }

    return 0;
}
