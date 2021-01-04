#include <iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

int N;
int arr[26][26];
int chk[26][26];
int cnt = 0;
vector<int> V;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
void DFS(int x,int y)
{
	int xx, yy;
	for (int i = 0; i < 4; i++)
	{
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx < 1 || xx > N || yy < 1 || yy > N)continue;
		if (chk[xx][yy] == 0 && arr[xx][yy] == 1)
		{
			chk[xx][yy] = 1;
			++cnt;
			DFS(xx, yy);
		}
	}
}
int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf_s("%1d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (chk[i][j] == 0 && arr[i][j] == 1)
			{
				chk[i][j] = 1;
				++cnt;
				DFS(i, j);
				V.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(V.begin(), V.end());
	cout << V.size();
	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << "\n";
	}
	return 0;
}