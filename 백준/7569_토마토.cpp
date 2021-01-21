#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
#include<cmath>
using namespace std;

#define Max 101
int dx[6] = { -1,0,1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0};
int dz[6] = { 0,0,0,0,1,-1 };
int M, N, H; // (X,Y)  M : Y , N : X  , H : 높이
int Map[Max][Max][Max];
int dis[Max][Max][Max];
bool visit[Max][Max][Max];
queue<pair<int,pair<int,int>>> q; //  x y z 
int cnt = 0;
void Input()
{
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> Map[i][j][k];
				if (Map[i][j][k] == 1)
				{
					++cnt;
					visit[i][j][k] = 1;
					q.push(make_pair(i,make_pair(j, k))); 
					// i : z축
					// j : x축
					// k : y축
				}
			}
		}
	}
}
void BFS()
{
	while (!q.empty())
	{
		int height = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int hh = height + dz[i];
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (hh >= 0 && hh < H && xx >= 0 && xx < N && yy >= 0 && yy < M)
			{
				if (Map[hh][xx][yy] == -1 )continue;
				else if (Map[hh][xx][yy] == 0)
				{
					if (visit[hh][xx][yy] == 0)
					{
						Map[hh][xx][yy] = Map[height][x][y] + 1;
						visit[hh][xx][yy] = 1;
						dis[hh][xx][yy] = dis[height][x][y] + 1;
						q.push(make_pair(hh, make_pair(xx, yy)));
					}
				}
			}
		}
	}
}
void Calc()
{
	int count = 0;
	int res = 0;
	bool flag = true;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (Map[i][j][k] == 0)
				{
					cout << -1 << "\n"; exit(0);
				}
				res = max(res, Map[i][j][k]);
			}
		}
	}
	cout << res-1;
	
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	Input();
	BFS();
	Calc();
	return 0;
}