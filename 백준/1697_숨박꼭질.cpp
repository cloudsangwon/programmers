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

using namespace std;
#define Max 100000 + 1

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int N, K;
bool visit[Max];
int BFS()
{
	queue<pair<int,int>> q;
	q.push({ N,0 });
	visit[N] = 1;
	while (!q.empty())
	{
		int Pos = q.front().first; //5
		int Sec = q.front().second;
		visit[Pos] = 1;
		q.pop();
		if (Pos == K)
		{
			return Sec;
		}
		if (Pos + 1 <= Max && !visit[Pos + 1])
		{
			q.push({ Pos + 1,Sec + 1 });
		}
		if (Pos - 1 >= 0 && Pos - 1 <= Max && !visit[Pos - 1])
		{
			q.push({ Pos - 1,Sec + 1 });
		}
		if (Pos * 2 <= Max && !visit[Pos * 2])
		{
			q.push({ Pos * 2,Sec + 1 });
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	
	int value = BFS();
	cout << value << "\n";
	return 0;

}

