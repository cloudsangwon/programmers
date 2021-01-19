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

int cnt = 1;
int R, C;
char Map[21][21];
bool chk[26];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int res = 0;
void DFS(int x, int y, int check)
{
	
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 1 || xx > R || yy < 1 || yy > C)continue;
		int next = Map[xx][yy];
		if (chk[next - 'A'] == false)
		{
			chk[next - 'A'] = true;
			DFS(xx, yy, check + 1);
			chk[next - 'A'] = false;
		}
	}
	++check;
	if (res < check)
	{
		res = check;
	}
	//return res + 1;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> Map[i][j];
			
		}
	}
	chk[Map[1][1] - 'A'] = true;
	DFS(1, 1, 0);
	cout << res;
	return 0;
}