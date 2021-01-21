#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
using namespace std;

int R, C;
char Map[501][501];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void)
{
	queue<pair<int, int>> wolf;
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 'W') wolf.push(make_pair(i, j));
		}
	}

	while (!wolf.empty())
	{
		int y = wolf.front().first;
		int x = wolf.front().second;
		wolf.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (xx < 1 || xx > C || yy < 1 || yy> R)continue;
			if (Map[yy][xx] == '.') Map[yy][xx] = 'D';
			else if (Map[yy][xx] == 'S')
			{
				cout << 0 << "\n"; return 0;
			}
		}
	}
	
	cout << 1 << "\n";
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cout << Map[i][j];
		}
		cout << "\n";
	}
	return 0;
}