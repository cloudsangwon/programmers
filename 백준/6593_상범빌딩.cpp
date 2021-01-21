#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
using namespace std;

int dx[6] = { -1,0,1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
#define MAX 30
int L, R, C;
char Map[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
pair<pair<int, int>, int> Start, End;



int BFS(int floor, int x, int y)
{
	visit[floor][x][y] = 1;
	queue<pair<pair<int, int>, pair<int, int>>> q; // floor, x, y , cnt
	q.push(make_pair(make_pair(floor, x), make_pair(y, 0)));
	while (!q.empty())
	{
		int f = q.front().first.first; 
		int x = q.front().first.second;
		int y = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (f == End.first.first && x == End.first.second && y == End.second) return cnt;
		for (int i = 0; i < 6; i++)
		{
			int ff = f + dz[i];
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (ff >= 0 && ff < C && xx >= 0 && xx < R && yy >= 0 && yy < C)
			{
				if (Map[ff][xx][yy] == '#')continue;
				if (Map[ff][xx][yy] == '.' || Map[ff][xx][yy] == 'E')
				{
					if (visit[ff][xx][yy] == 0)
					{
						visit[ff][xx][yy] = 1;
						q.push(make_pair(make_pair(ff, xx), make_pair(yy, cnt + 1)));
					}
				}
			}
		}
	}
	return -1;
}
void Input()
{
	cin >> L >> R >> C;
	if (L == 0 && R == 0 && C == 0) exit(0);
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < R; j++)
		{
			for (int k = 0; k < C; k++)
			{
				cin >> Map[i][j][k];
				if (Map[i][j][k] == 'S')
				{
					Start.first.first = i; // floor
					Start.first.second = j; // x axis
					Start.second = k; // y axis
				}
				else if (Map[i][j][k] == 'E')
				{
					End.first.first = i; // floor
					End.first.second = j; // x axis
					End.second = k; // y axis
				}


			}
		}
	}
}
int main(void)
{
	while (1)
	{
		memset(visit, false, sizeof(visit));
		Input();
		int answer = BFS(Start.first.first, Start.first.second, Start.second);
		if (answer == -1)cout << "Trapped!" << "\n";
		else cout << "Escaped in " << answer << " minute(s)." << "\n";
	}
	
	return 0;
}