#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

void topSort(queue<int> &nums, unordered_map<int, vector<int>> adj_map, int inDegree[], unordered_map<int, bool> &visited, int num_nodes)
{

    if (nums.empty())
        return;

    for (auto x : adj_map[nums.front()])
    {
        inDegree[x - 1]--;
    }
    cout << nums.front() << " ";
    nums.pop();

    for (int i = 0; i < num_nodes; i++)
    {

        if (inDegree[i] == 0 && visited[i + 1] == false)
        {
            visited[i + 1] = true;
            nums.push(i + 1);
        }
    }

    topSort(nums, adj_map, inDegree, visited, num_nodes);
}
int main()
{

    queue<int> nums;
    int num_nodes;
    int num_edges;

    cout << "Enter the Number of Nodes : ";
    cin >> num_nodes;
    cout << "Enter the Number of Edges : ";
    cin >> num_edges;

    int inDegree[num_nodes]{};
    unordered_map<int, vector<int>> adj_map;
    unordered_map<int, bool> visited;

    for (int i = 1; i <= num_nodes; i++)
    {
        vector<int> x{};
        adj_map[i] = x;
        visited[i] = false;
    }

    cout << "Enter the vertices separated with space : " << endl;

    for (int i = 0; i < num_edges; i++)
    {
        int x;
        int y;
        cin >> x >> y;

        adj_map[x].push_back(y);
    }

    for (int i = 1; i <= num_nodes; i++)
    {

        for (auto x : adj_map[i])
        {
            inDegree[x - 1]++;
        }
    }

    visited[1] = true;
    nums.push(1);

    topSort(nums, adj_map, inDegree, visited, num_nodes);

    return 0;
}