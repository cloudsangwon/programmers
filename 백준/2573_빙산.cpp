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


#define Max 301
int N, M;
int Map[Max][Max];
bool visit[Max][Max];
vector<int> answer;
int Year = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int icount = 0;
int cnt = 0;
queue<pair<int, int>>q;
vector<pair<pair<int, int>, int>> V;
void BFS(int x,int y)
{

	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int fir = q.front().first;
		int sec = q.front().second;
		int cnt = 0;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = fir + dx[i];
			int yy = sec + dy[i];
			if (xx < 1 || xx >N || yy<1 || yy>M)continue;
			if (Map[xx][yy] == 0) ++cnt;
		}
		V.push_back(make_pair(make_pair(fir, sec), cnt));
	}
}

void Input()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (Map[i][j] != 0)
			{
				BFS(i, j);
			}
		}
	}
}
void Calc()
{
	for (auto it = V.begin(); it != V.end(); it++)
	{
		int x = it->first.first;
		int y = it->first.second;
		int z = it->second;
		Map[x][y] -= z;
		if (Map[x][y] < 0) Map[x][y] = 0;
	}
	while (!V.empty()) V.pop_back();
}
void DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 1 || xx > N || yy < 1 || yy >M)continue;
		if (Map[xx][yy] != 0 && visit[xx][yy] == 0)
		{
			visit[xx][yy] = 1;
			++icount;
			DFS(xx, yy);
		}
	}
}


int main(void)
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> Map[i][j];
		}
	}

	while (1)
	{
		++Year;
		while (!answer.empty()) answer.pop_back();
		Input();
		Calc();
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (Map[i][j] != 0 && visit[i][j]==0)
				{
					visit[i][j] = 1;
					++icount;
					DFS(i, j);

					answer.push_back(icount);
					icount = 0;
				}
			}
		}
		
		if (answer.size() >= 2)
		{
			cout << Year << "\n"; exit(0);
		}
		else if (answer.size() == 0)
		{
			cout << 0 << "\n"; exit(0);
		}
		memset(visit, false, sizeof(visit));
	}

	

	return 0;
}