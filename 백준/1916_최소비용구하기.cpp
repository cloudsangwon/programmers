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
#define Max 1000 + 1


int N, M;
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
	vector<pair<int, int>> Graph[Max];
	
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Graph[a].push_back(make_pair(b, c));
	}
	vector<int> dist(N + 1, 2147000000);
	int start, end;
	cin >> start >> end;
	dist[start] = 0;
	priority_queue<Edge> q;
	q.push(Edge(start, 0));
	
	while (!q.empty())
	{
		Edge temp = q.top();
		int now = temp.E;
		int cost = temp.cost;
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
	cout << dist[end];
	return 0;

}

