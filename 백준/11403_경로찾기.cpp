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

using namespace std;
#define Max 100 + 1

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool visit[Max][Max];
int Map[Max][Max];

int N;


void DFS(int x, int y)
{
	visit[x][y] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (Map[y][i] && !visit[x][i])
		{
			DFS(x, i);
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
		}
	}

	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Map[i][j]) DFS(i, j);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;

}

