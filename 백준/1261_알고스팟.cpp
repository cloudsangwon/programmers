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
#include<stdio.h>
using namespace std;
#define Max 100 + 1

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int Map[Max][Max];
int dist[Max][Max];
bool visit[Max][Max];
int N, M;

void BFS(int a, int b)
{
	queue<pair<int, int>> q;
	q.push({ a,b });
	dist[a][b] = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || yy < 0 || xx >= M || yy >= N)continue;
			
			if (Map[xx][yy] == 1)
			{
				if (dist[xx][yy] > dist[x][y] + 1)
				{
					dist[xx][yy] = dist[x][y] + 1;
					q.push({ xx,yy });
				}
			}
			else if (Map[xx][yy] == 0)
			{
				if (dist[xx][yy] > dist[x][y])
				{
					dist[xx][yy] = dist[x][y];
					q.push({ xx,yy });
				}
			}
			
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int icnt = 0;
	for (int i = 0; i < M; i++)
	{
		string tmp; cin >> tmp;
		for (int j = 0; j < tmp.length(); j++)
		{

			cout << "i :" << i << " j :" << j << "\n";
			Map[i][j] = tmp[j] - '0';
			dist[i][j] = 2147000000;
		}
	}

	BFS(0, 0);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;

}

