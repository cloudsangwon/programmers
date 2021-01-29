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
#define Max 300 + 1

int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1,  1, -2 , 2, -2, 2, -1,1 };


int Map[Max][Max];
int dis[Max][Max];
bool visit[Max][Max];
int StartX, StartY, EndX, EndY;
int Length;
int BFS(int x, int y)
{
	visit[x][y] = 1;
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(x, y), 0));

	while (!q.empty())
	{
		int nx = q.front().first.first;
		int ny = q.front().first.second;
		int move = q.front().second;
		q.pop();
		
		if (nx == EndX && ny == EndY)
		{
			return move;
		}
		for (int i = 0; i < 8; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			if (xx >= 0 && xx < Length && yy >= 0 && yy < Length)
			{
				if (!visit[xx][yy] && dis[xx][yy] == 0)
				{
					dis[xx][yy] = dis[x][y] + 1;
					visit[xx][yy] = 1;
					q.push(make_pair(make_pair(xx, yy), move + 1));
				}
			}
		}
	}
}
void Init()
{
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < Length; i++)
	{
		for (int j = 0; j < Length; j++)
		{
			dis[i][j] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	
	while (T--)
	{
		Init();
		cin >> Length;
		cin >> StartX >> StartY >> EndX >> EndY;
		int value = BFS(StartX, StartY);
		cout << value << "\n";


	}
	return 0;

}

