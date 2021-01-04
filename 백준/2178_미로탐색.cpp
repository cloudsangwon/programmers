#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int arr[101][101];
int chk[101][101];
int N, M;
int Max = 2147000000;
int cnt = 1;
int ans = 0;
vector<string> str;
vector<int> V;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
void StringToInt(string a)
{
	int len = a.length();
	for (int i = 1; i <= len; i++)
	{
		char ch = a[i - 1];
		arr[cnt][i] = ch - 48;
	}
	++cnt;
}

int BFS()
{
	queue<pair<pair<int, int>, int > > q;
	q.push(make_pair(make_pair(1, 1), 1)); // x ÁÂÇ¥ y ÁÂÇ¥ 1ÀÇ °³¼ö
	chk[1][1] = 1;
	
	while (!q.empty())
	{
		int xx = q.front().first.first;
		int yy = q.front().first.second;
		int z = q.front().second;

		q.pop();

		if (xx == N && yy == M)
			return z;
		for (int i = 0; i < 4; i++)
		{
			int xpos = xx + dx[i];
			int ypos = yy + dy[i];
			if (xpos < 1 || xpos > N&& ypos < 1 || ypos > M)continue;
			if (chk[xpos][ypos] == 0 && arr[xpos][ypos]==1)
			{
				chk[xpos][ypos] = chk[xx][yy]+1;
				q.push(make_pair(make_pair(xpos, ypos), z + 1));
			}
		}
	}


}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string a; cin >> a;
		StringToInt(a);
	}
	/*
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	*/


	cout << BFS();

}

