#include <bits/stdc++.h>
#include <set>

using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{

    unordered_map<int, vector<pair<int, int>>> adj_map;

    for (int i = 0; i < edges; i++)
    {

        int u = vec[i][0];
        int v = vec[i][1];
        int d = vec[i][2];

        adj_map[u].push_back(make_pair(v, d));
        adj_map[v].push_back(make_pair(u, d));
    }

    set<pair<int, int>> st;

    vector<int> distance(vertices);

    for (int i = 0; i < vertices; i++)
        distance[i] = INT_MAX;

    distance[source] = 0;

    st.insert(make_pair(0, source));

    while (!st.empty())
    {

        pair<int, int> p = *(st.begin());
        st.erase(st.begin());
        int value = p.first;
        int nodeValue = p.second;
        for (auto neighbour : adj_map[p.second])
        {
            if (distance[neighbour.first] > value + neighbour.second)
            {

                auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));

                if (record != st.end())
                    st.erase(record);

                distance[neighbour.first] = value + neighbour.second;

                st.insert(make_pair(distance[neighbour.first], neighbour.first));
            }
        }
    }

    return distance;
}
