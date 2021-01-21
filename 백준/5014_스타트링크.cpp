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

#define Max 1000000+1
int F, S, G, U, D;
bool visit[Max];
int BFS()
{
	queue<pair<int, int>> q;
	q.push(make_pair(S, 0)); // CurrentPos, ButtonCount
	while (!q.empty())
	{
		int Pos = q.front().first;
		int Cnt = q.front().second;
		q.pop();
		if (Pos == G) return Cnt;
		if (Pos + U <= F && visit[Pos + U] == 0)
		{
			visit[Pos + U] = 1;
			q.push(make_pair(Pos + U, Cnt + 1));
		}
		if (Pos - D > 0 && visit[Pos - D] == 0)
		{
			visit[Pos - D] = 1;
			q.push(make_pair(Pos - D, Cnt + 1));
		}
	}
	return -1;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> F >> S >> G >> U >> D;
	int res = BFS();
	if (res == -1) cout << "use the stairs\n";
	else cout << res;


	return 0;
}