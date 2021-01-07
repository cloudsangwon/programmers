#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
const int Max = 1001;

bool chk[Max];
vector<int> Map[Max];
int cnt = 0;

void DFS(int node)
{
	chk[node] = 1;

	for (int i = 0; i < Map[node].size(); i++)
	{
		int next = Map[node][i];
		if (!chk[next])
		{
			DFS(next);
		}
	}
}
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		Map[a].push_back(b);
		Map[b].push_back(a);
	}
	
	for (int i = 1; i <= N; i++)
	{
		if (!chk[i])
		{
			++cnt;
			DFS(i);
		}
	}
	cout << cnt;
	return 0; 
}