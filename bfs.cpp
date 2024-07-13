#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
class Graph
{
public:
    T nodes;
    unordered_map<T, vector<T>> adj_list;
    Graph(T nodes, unordered_map<T, vector<T>> &adj_list)
    {
        this->nodes = nodes;
        this->adj_list = adj_list;
    }

private:
    void bfs_init(T node, unordered_map<T, bool> &verified)
    {

        T top = node;
        queue<T> s;
        verified[top] = true;
        s.push(node);
        while (!s.empty())
        {

            top = s.front();
            cout << top << " " << endl;
            for (auto c : adj_list[top])
            {
                if (verified[c])
                    continue;
                else
                {
                    verified[c] = true;
                    s.push(c);
                }
            }

            s.pop();
        }
    }

public:
    void bfs()
    {
        unordered_map<T, bool> verified;
        for (T i = 0; i < this->nodes; i++)
        {
            if (!verified[i])
                bfs_init(i, verified);
        }
    }

    void display_adj_list()
    {

        for (T i = 0; i < nodes; i++)
        {
            cout << i << " -> ";
            for (T c : adj_list[i])
                cout << c << ",";
            cout << endl;
        }
    }
};

int main()
{

    int nodes;
    unordered_map<int, vector<int>> adj_list;

    cout << "Enter the Number of Nodes : ";
    cin >> nodes;

    int num_edges;
    cout << "Enter the Number of Edges : ";
    cin >> num_edges;

    for (int i = 0; i < nodes; i++)
    {
        vector<int> x{};
        adj_list[i] = x;
    }

    for (int i = 0; i < num_edges; i++)
    {
        int u, v;
        cout << "Enter the edge separated with space : ";
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    Graph<int> graph_1{nodes, adj_list};
    graph_1.display_adj_list();
    graph_1.bfs();
    return 0;
}