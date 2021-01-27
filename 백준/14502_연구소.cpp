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
#define Max 90 + 1

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int Map[Max][Max];
int CopyMap[Max][Max];
int N, M;
vector<pair<int, int>> Empty;

void DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 1 && xx <= N && yy >= 1 && yy <= M)
		{
			if (CopyMap[xx][yy] == 0)
			{
				CopyMap[xx][yy] = 2;
				DFS(xx, yy);
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
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> Map[i][j];
			CopyMap[i][j] = Map[i][j];
			if (Map[i][j] == 0)
			{
				Empty.push_back({ i,j });
			}
		}
	}
	
	int res = 0;
	for (int i = 0; i < Empty.size() - 2; i++)
	{
		for (int j = i+1; j < Empty.size() - 1; j++)
		{
			for (int k = j + 1; k < Empty.size(); k++)
			{
				pair<int, int > One = Empty[i];
				pair<int, int > Two = Empty[j];
				pair<int, int > Three = Empty[k];

				
				for (int i = 1; i <= N; i++)
				{
					for (int j = 1; j <= M; j++)
					{
						CopyMap[i][j] = Map[i][j];
					}
				}
				CopyMap[One.first][One.second] = 1;
				CopyMap[Two.first][Two.second] = 1;
				CopyMap[Three.first][Three.second] = 1;
				for (int i = 1; i <= N; i++)
				{
					for (int j = 1; j <= M; j++)
					{
						if (CopyMap[i][j] == 2)
						{
							DFS(i, j);
						}
					}
				}
				
				int cnt = 0;
				for (int i = 1; i <= N; i++)
				{
					for (int j = 1; j <= M; j++)
					{
						if (CopyMap[i][j] == 0)
						{
							++cnt;
						}
					}
				}
				res = max(res, cnt);
			}
		}
	}
	cout << res;

	
	return 0;

}

