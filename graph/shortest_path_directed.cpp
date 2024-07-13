#include <bits/stdc++.h>

using namespace std;

int main()
{

    int num_vertices;
    int num_edges;

    cout << "Enter the Number of Vertices : ";
    cin >> num_vertices;

    cout << "Enter the Number of Edges : ";
    cin >> num_edges;

    unordered_map<int, vector<pair<int, int>>> adj_map;

    for (int i = 0; i < num_edges; i++)
    {

        int u, v, d;

        cin >> u >> v >> d;

        adj_map[u].push_back(make_pair(v, d));
    }

    int inDegree[num_vertices]{0};

    for (auto element : adj_map)
    {

        for (auto neigbour : element.second)
        {

            inDegree[neigbour.first]++;
        }
    }

    int top = 0;

    for (int i = 0; i < num_vertices; i++)
    {

        if (inDegree[i] == 0)
        {
            top = i;
            break;
        }
    }

    queue<int> q;

    vector<int> topSort{};

    q.push(top);

    while (!q.empty())
    {

        top = q.front();
        topSort.push_back(top);
        q.pop();
        for (auto neighbour : adj_map[top])
        {

            inDegree[neighbour.first]--;
        }

        for (int i = 0; i < num_vertices; i++)
        {
            if (inDegree[i] == 0)
            {

                q.push(i);
            }
        }
    }

    // Now we have the topological sort

    int distance[num_vertices]{INT_MAX};

    for (int i = 0; i < num_vertices; i++)
        distance[i] = INT_MAX;

    int source;
    cout << "Enter the Source : ";
    cin >> source;
    int destination;
    cout << "Enter the Destination : ";
    cin >> destination;

    distance[source] = 0;

    for (int i = 0; i < topSort.size(); i++)
    {

        if (distance[topSort[i]] == INT_MAX)
            continue;
        else
        {

            int value = distance[topSort[i]];

            for (auto neighbour : adj_map[topSort[i]])
            {

                if (distance[neighbour.first] > value + neighbour.second)
                {
                    distance[neighbour.first] = value + neighbour.second;
                }
            }
        }
    }

    // Now we have the Distance for the source to the Destinations

    return 0;
}