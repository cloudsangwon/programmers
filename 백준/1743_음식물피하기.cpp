#include <iostream>
#include <queue>
#include<algorithm>
#include<vector>
using namespace std;

const int Max = 100 + 1;
int Map[Max][Max];
bool visit[Max][Max];

int N, M, K;
vector<int> answer;
int cnt = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void DFS(int x, int y)
{
	int xx, yy;
	for (int i = 0; i < 4; i++)
	{
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx >= 1 && xx <= N && yy >= 1 && yy <= M)
		{
			if (Map[xx][yy] == 1 && !visit[xx][yy])
			{
				visit[xx][yy] = 1;
				++cnt;
				DFS(xx, yy);
			}
		}
	}
}
int main(void)
{
	cin >> N >> M >> K;
	
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		Map[x][y] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (Map[i][j] == 1 && !visit[i][j])
			{
				visit[i][j] = 1;
				++cnt;
				DFS(i, j);
				answer.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(answer.rbegin(), answer.rend());
	cout << answer[0];
	return 0;
}

