#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

void dfs(unordered_map<int, vector<int>> &adj_map,
         unordered_map<int, bool> &visited,
         stack<int> &order)
{

    cout << order.top() << " ";
    if (order.empty())
        return;

    for (auto x : adj_map[order.top()])
    {
        if (visited[x])
            continue;
        visited[x] = true;
        order.push(x);
        dfs(adj_map,
            visited,
            order);
    }
    order.pop();
    return;
}

int main()
{

    int n;
    cout << "Enter the Number of Node : " << endl;
    cin >> n;
    int num_edges;
    cout << "Enter the Number of Edges : " << endl;
    cin >> num_edges;

    unordered_map<int, vector<int>> adj_map;
    unordered_map<int, bool> visited{};
    stack<int> order;

    for (int i = 1; i <= n; i++)
    {
        vector<int> x{};
        adj_map[i] = x;
        visited[i] = false;
    }

    cout << "Enter the vertex of the edges separated with space : " << endl;

    for (int i = 0; i < num_edges; i++)
    {

        int x;
        int y;
        cin >> x >> y;
        adj_map[x].push_back(y);
    }
    order.push(1);
    visited[1] = true;
    dfs(adj_map, visited, order);
    return 0;
}