#include <bits/stdc++.h>

using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Create a adjacency list

    unordered_map<int, vector<pair<int, int>>> adj_map;

    for (int i = 0; i < m; i++)
    {

        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj_map[u].push_back(make_pair(v, w));
        adj_map[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1);
    vector<int> parent(n + 1);
    vector<bool> mst(n + 1);

    for (int i = 0; i <= n; i++)
        key[i] = INT_MAX;
    for (int i = 0; i <= n; i++)
        mst[i] = false;
    for (int i = 0; i <= n; i++)
        parent[i] = 0;

    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i <= n; i++)
    {

        int mini = INT_MAX;
        int u = -1;

        for (int j = 1; j <= n; j++)
        {

            if (key[j] < mini && !mst[j])
            {
                u = j;
                mini = key[j];
            }
        }

        mst[u] = true;

        for (auto neighbour : adj_map[u])
        {

            if (!mst[neighbour.first] && neighbour.second < key[neighbour.first])
            {

                key[neighbour.first] = neighbour.second;
                parent[neighbour.first] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> results;

    for (int i = 2; i <= n; i++)
    {

        results.push_back({{parent[i], i}, key[i]});
    }

    return results;
}
