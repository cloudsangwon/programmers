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
#include<stdio.h>
using namespace std;
#define Max 100 + 1

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//int Map[Max][Max];
bool visit[Max][Max];
int N;
char Map[Max][Max];
char dis[Max][Max];
int Rcnt = 0, Gcnt = 0, Bcnt = 0;
vector<int> Rv, Gv, Bv;
void RDFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 1 && xx <= N && yy >= 1 && yy <= N)
		{
			if (Map[xx][yy] == 'R' && !visit[xx][yy])
			{
				visit[xx][yy] = 1;
				++Rcnt;
				RDFS(xx, yy);
			}
		}
	}
}
void BDFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 1 && xx <= N && yy >= 1 && yy <= N)
		{
			if (Map[xx][yy] == 'B' && !visit[xx][yy])
			{
				visit[xx][yy] = 1;
				++Bcnt;
				BDFS(xx, yy);
			}
		}
	}
}
void RD(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 1 && xx <= N && yy >= 1 && yy <= N)
		{
			if (dis[xx][yy] == 'R' && !visit[xx][yy])
			{
				dis[xx][yy] = 1;
				++Rcnt;
				RD(xx, yy);
			}
		}
	}
}
void BD(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 1 && xx <= N && yy >= 1 && yy <= N)
		{
			if (dis[xx][yy] == 'B' && !visit[xx][yy])
			{
				dis[xx][yy] = 1;
				++Bcnt;
				BD(xx, yy);
			}
		}
	}
}
void GDFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 1 && xx <= N && yy >= 1 && yy <= N)
		{
			if (Map[xx][yy] == 'G' && !visit[xx][yy])
			{
				visit[xx][yy] = 1;
				++Gcnt;
				GDFS(xx, yy);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
			dis[i][j] = Map[i][j];
			if (dis[i][j] == 'G')
			{
				dis[i][j] = 'R';
			}
			//scanf_s("%1c", &Map[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Map[i][j] == 'R' && !visit[i][j])
			{
				++Rcnt;
				RDFS(i, j);
				Rv.push_back(Rcnt);
				Rcnt = 0;
			}
		}
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Map[i][j] == 'B' && !visit[i][j])
			{
				++Bcnt;
				BDFS(i, j);
				Bv.push_back(Bcnt);
				Bcnt = 0;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Map[i][j] == 'G' && !visit[i][j])
			{
				++Gcnt;
				GDFS(i, j);
				Gv.push_back(Gcnt);
				Gcnt = 0;
			}
		}
	}
	int total = Rv.size() + Bv.size() + Gv.size();
	
	while (!Rv.empty()) Rv.pop_back();
	while (!Bv.empty()) Bv.pop_back();
	Rcnt = 0;
	Bcnt = 0;
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dis[i][j] == 'R' && !visit[i][j])
			{
				++Rcnt;
				RD(i, j);
				Rv.push_back(Rcnt);
				Rcnt = 0;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dis[i][j] == 'B' && !visit[i][j])
			{
				++Bcnt;
				BD(i, j);
				Bv.push_back(Bcnt);
				Bcnt = 0;
			}
		}
	}



	int sum = Rv.size() + Bv.size();
	cout << total << " " << sum << "\n";
	return 0;

}

