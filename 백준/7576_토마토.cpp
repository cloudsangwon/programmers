#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int M, N;
const int Max = 1001;
int tomato[Max][Max];
int dis[Max][Max];
queue<pair<int, int>> q;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool flag = true;
int main(void)
{
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int val; cin >> val;
			tomato[i][j] = val;
			if (tomato[i][j] == 1)
			{
				q.push(make_pair(i, j));
			}
			else
			{
				flag = false;
			}
		}
	}
	if (flag)
	{
		cout << 0;
		return 0;
	}
	while (!q.empty())
	{
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x1 + dx[i];
			int yy = y1 + dy[i];
			if (xx < 1 || xx > N || yy < 1 || yy > M)continue;
			
			if (tomato[xx][yy] == 0)
			{
				tomato[xx][yy] = 1;
				q.push(make_pair(xx, yy));
				dis[xx][yy] = dis[x1][y1] + 1;
			}
		}
	}
	
	int f = 1;
	int res = -2147000000;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (tomato[i][j] == 0) f = 0;
		}
	}
	if (f == 1)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (dis[i][j] > res)
				{
					res = dis[i][j];
				}
			}
		}
		cout << res;
	}
	else
	{
		cout << -1;
	}
	return 0;
}