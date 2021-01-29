#include<iostream>
#include<vector>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<set>
#include<math.h>
#include<map>
#include<deque>

using namespace std;
#define Max 20000 + 1

int V, E, K;

struct Edge
{
	int E, cost;
	Edge(int a, int b)
	{
		E = a;
		cost = b;
	}
	bool operator<(const Edge& b)const
	{
		return cost > b.cost;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E >> K;
	vector<int> dist(V + 1, 2147000000);
	vector<pair<int, int>> Graph[Max];
	priority_queue<Edge> q;
	q.push(Edge(K, 0));

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Graph[a].push_back(make_pair(b, c));
	}
	dist[K] = 0;
	
	while (!q.empty())
	{
		Edge tmp = q.top();
		int now = tmp.E;
		int cost = tmp.cost;

		q.pop();

		for (int i = 0; i < Graph[now].size(); i++)
		{
			int next = Graph[now][i].first;
			int nextcost = cost + Graph[now][i].second;

			if (dist[next] > nextcost)
			{
				dist[next] = nextcost;
				q.push(Edge(next, nextcost));
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		
		if (dist[i] == 2147000000)
		{
			cout << "INF" << "\n";
		}
		else cout << dist[i] << "\n";
	}
	return 0;

}

