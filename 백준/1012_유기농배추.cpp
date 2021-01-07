#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int T, M, N, K;
const int Max = 51;
int Map[Max][Max];
bool chk[Max][Max];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> answer;
int cnt = 0;
void DFS(int x, int y)
{
	int xx, yy;
	for (int i = 0; i < 4; i++)
	{
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx < 0 || xx > M || yy < 0 || yy > N) continue;
		if (chk[xx][yy] == 0 && Map[xx][yy] == 1)
		{
			chk[xx][yy] = 1;
			++cnt;
			DFS(xx, yy);
		}
	}
}
int main(void)
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++)
		{
			int a, b;
			cin >> a >> b;
			Map[a][b] = 1;
		}
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (chk[i][j] == 0 && Map[i][j] == 1)
				{
					chk[i][j] = 1;
					++cnt;
					DFS(i, j);
					answer.push_back(cnt);
					cnt = 0;
				}
			}

		}
		cout << answer.size() << "\n";
		memset(chk, false, sizeof(chk));
		cnt = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				Map[i][j] = 0;
			}
		}
		while (!answer.empty())
		{
			answer.pop_back();
		}
	}

	
	
	
	return 0;
}