#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;

const int Max = 101;
int chk[Max][Max];
int M, N,K, cnt = 0;
vector<int> answer;
int Map[Max][Max];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
void DFS(int x, int y)
{
	int xx, yy;
	for (int i = 0; i < 4; i++)
	{
		xx = x + dx[i];
		yy = y + dy[i];
		
		if (xx >= 0 && xx < M && yy >= 0 && yy < N)
		{
			if (chk[xx][yy] == 0 && Map[xx][yy] == 0)
			{
				//cout << "xx :" << xx << "yy:" << yy << "\n";
				chk[xx][yy] = 1;
				++cnt;
				DFS(xx, yy);
			}
		}
		
	}
}
int main(void)
{
	cin >> M >> N >> K;
	
	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
	
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int y = y1; y < y2; y++)
		{
			for (int x = x1; x < x2; x++)
			{
				Map[y][x] = 1;
			}
		}
	}


	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] == 0 && chk[i][j] == 0)
			{
				chk[i][j] = 1;
				++cnt;
				DFS(i, j); // M : 5  N : 7  y축이 5 x축이 7 
				//cout << "cnt :" << cnt << "\n";
				answer.push_back(cnt);
				cnt = 0;
			}

		}
		
	}
	cout << answer.size() << "\n";
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	
	return 0;
}