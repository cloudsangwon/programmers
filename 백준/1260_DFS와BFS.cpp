#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int N, M, V;
int adj[1001][1001];
bool visit[1001];
queue<int> q;

void DFS(int x)
{
	cout << x << " ";
	for (int i = 1; i<=N; i++)
	{
		
		if (adj[x][i] && !visit[i])
		{
			visit[i] = 1;
			DFS(i);
		}
		
	}
}
void BFS(int x)
{
	q.push(x);
	visit[x] = 1;
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		cout << p << " ";
		for (int i = 1; i <= N; i++)
		{
			if (adj[p][i] && !visit[i])
			{
				visit[i] = 1;
				q.push(i);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		adj[start][end] = 1;
		adj[end][start] = 1;
	}
	visit[V] = 1;
	DFS(V);
	cout << "\n";
	memset(visit, false, sizeof(visit));
	BFS(V);
	cout << "\n";
	return 0;
}

