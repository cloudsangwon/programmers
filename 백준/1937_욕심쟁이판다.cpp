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
#define Max 500 + 1

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int Map[Max][Max];
int DP[Max][Max];
bool visit[Max][Max];
int N;
int iMax = -2147000000;
int res = -2147000000;
int BFS(int a, int b)
{
	if (DP[a][b] != 0) return DP[a][b];
	DP[a][b] = 1;
	for (int i = 0; i < 4; i++)
	{
		int xx = a + dx[i];
		int yy = b + dy[i];

		if (xx >= 0 && yy >= 0 && xx <= N && yy <= N)
		{
			if (Map[a][b] < Map[xx][yy])
			{
				DP[a][b] = max(DP[a][b], BFS(xx, yy) + 1);
			}
		}
	}
	return DP[a][b];

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
			//int value = BFS(i, j);
			iMax = max(iMax, BFS(i, j));
		}
	}

	cout << iMax << "\n";
	return 0;

}

