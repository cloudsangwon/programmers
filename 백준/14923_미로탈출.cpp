#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
using namespace std;

int Y, X;
int startx, starty, endx, endy;
const int Max = 1001;
int Map[Max][Max];
int dis[Max][Max][2];
bool ch[Max][Max];
int cnt = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
vector<int> res;

queue<pair<pair<int,int>,int>> q;
int BFS(int x, int y)
{
	q.push(make_pair(make_pair(x, y), 0));
	//dis[x][y][0] = 1;
	while (!q.empty())
	{
		int firstx = q.front().first.first;
		int firsty = q.front().first.second;
		int z = q.front().second;
		q.pop();
		if (firstx == endx && firsty == endy)
		{
			return dis[firstx][firsty][z];
		}
		for (int i = 0; i < 4; i++)
		{
			int xx = firstx + dx[i];
			int yy = firsty + dy[i];
			if (xx <1 || xx > Y || yy < 1 || yy > X)continue;
			if (Map[xx][yy] == 0)
			{
				if (dis[xx][yy][z] == 0)
				{
					dis[xx][yy][z] = dis[firstx][firsty][z] + 1;
					q.push(make_pair(make_pair(xx, yy), z));
				}
			}
			if (Map[xx][yy] == 1)
			{
				if (z == 0)
				{
					if (dis[xx][yy][z] == 0)
					{
						dis[xx][yy][1] = dis[firstx][firsty][z] + 1;
						q.push(make_pair(make_pair(xx, yy), 1));
					}
				}
			}
		}
	}
	return 0;
}
int main(void)
{
	//memset(ch, false, sizeof(ch));
	cin >> Y >> X;
	cin >> startx >> starty;
	cin >> endx >> endy;
	for (int i = 1; i <= Y; i++)
	{
		for (int j = 1; j <= X; j++)
		{
			cin >> Map[i][j];
		}
	}
	int value = BFS(startx, starty);
	if (value == 0) cout << -1;
	else cout << value;
	return 0;
}