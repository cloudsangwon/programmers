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

#define Max 51
int R, C;
char Map[Max][Max];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int WaterMap[Max][Max];
int GoMap[Max][Max];
queue<pair<int, int>> Water, Go;


void WaterBFS()
{
	while (!Water.empty())
	{
		int x = Water.front().first;
		int y = Water.front().second;
		Water.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 1 || xx > R || yy < 1 || yy > C)continue;
			if (Map[xx][yy] == '.' && WaterMap[xx][yy]==0)
			{
				WaterMap[xx][yy] = WaterMap[x][y] + 1;
				Water.push(make_pair(xx, yy));
			}
		}
	}
}
void GoBFS()
{
	while (!Go.empty())
	{
		int x = Go.front().first;
		int y = Go.front().second;
		Go.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 1 || xx> R || yy < 1 || yy > C)continue;
			if (GoMap[xx][yy] == 0 && ( Map[xx][yy] == '.' || Map[xx][yy]=='D'))
			{
			
				if (WaterMap[xx][yy] == 0)
				{
					GoMap[xx][yy] = GoMap[x][y] + 1;
					Go.push(make_pair(xx, yy));
				}
				else
				{
					if (WaterMap[xx][yy] > GoMap[x][y] + 1)
					{
						GoMap[xx][yy] = GoMap[x][y] + 1;
						Go.push(make_pair(xx, yy));
					}
				}
				
			}
			
		}
	}
}
int main(void)
{
	pair<int, int> End;
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 'S')
			{
				Go.push(make_pair(i, j));
			}
			else if (Map[i][j] == '*')
			{
				Water.push(make_pair(i, j));
			}
			else if (Map[i][j] == 'D')
			{
				End.first = i;
				End.second = j;
			}
		}
	}
	WaterBFS();

	GoBFS();

	if (GoMap[End.first][End.second] != 0)
	{
		cout << GoMap[End.first][End.second];
	}
	else cout << "KAKTUS";
	return 0;
}