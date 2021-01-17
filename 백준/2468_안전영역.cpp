#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int Max = 101;
bool ch[Max][Max];
int Map[Max][Max];
int N, cnt = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int>answer;
vector<int> res;

void DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 1 || xx > N || yy < 1 || yy > N)continue;
		if (ch[xx][yy] == 0 && Map[xx][yy] != 0)
		{
			ch[xx][yy] = 1;
			++cnt;
			DFS(xx, yy);
		}
	}
}
void Calc(int x)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Map[i][j] <= x)
			{
				Map[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (ch[i][j] == 0 && Map[i][j] != 0)
			{
				++cnt;
				ch[i][j] = 1;
				DFS(i, j);
				answer.push_back(cnt);
				cnt = 0;
			}
		}
	}
	res.push_back(answer.size());
	while (!answer.empty())answer.pop_back();
	cnt = 0;
	
}
int main(void)
{
	cin >> N;
	
	int iMax = 2;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int val; cin >> val;
			Map[i][j] = val;
			if (val > iMax)
			{
				iMax = val;
			}
		}
	}
	int a = 0;
	while (a <= iMax)
	{
		Calc(a);
		memset(ch, false, sizeof(ch));
		++a;
	}
	int tmax = 0;
	int idx = 0;

	sort(res.rbegin(), res.rend());
	cout << res[0];
	
	return 0;
}