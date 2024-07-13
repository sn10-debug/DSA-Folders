#include <bits/stdc++.h>

using namespace std;
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    unordered_map<int, vector<int>> adj_matrix;

    for (int i = 0; i < m; i++)
    {

        adj_matrix[edges[i].first - 1].push_back(edges[i].second - 1);
        adj_matrix[edges[i].second - 1].push_back(edges[i].first - 1);
    }

    unordered_map<int, bool> visited_map;

    for (int i = 0; i < n; i++)
    {

        visited_map[i] = false;
    }

    unordered_map<int, int> parent;

    queue<int> q;

    q.push(s - 1);
    visited_map[s - 1] = true;
    parent[s - 1] = -1;

    while (!q.empty())
    {

        int top = q.front();

        q.pop();
        for (auto neighbour : adj_matrix[top])
        {
            if (!visited_map[neighbour])
            {

                q.push(neighbour);

                parent[neighbour] = top;
                visited_map[neighbour] = true;
            }
        }
    }

    vector<int> ans;

    int state = t - 1;

    ans.push_back(t - 1);

    while (state != s - 1)
    {

        ans.push_back(parent[state]);

        state = parent[state];
    }

    for (int i = 0; i < ans.size(); i++)
    {

        ans[i] = ans[i] + 1;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
