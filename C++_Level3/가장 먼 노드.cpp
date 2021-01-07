#include <string>
#include <vector>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;

vector<int> Map[20001];
vector<int> Ans(20001);
int chk[20001];
int dis[20001];
int cnt = 0;
void BFS(int node)
{
	chk[node] = 1;
	queue<int> q;
	q.push(node);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < Map[x].size(); i++)
		{
			if (chk[Map[x][i]] == 0)
			{
				chk[Map[x][i]] = 1;
				Ans[Map[x][i]] = Ans[x] + 1;
				q.push(Map[x][i]);
			}
			
		}
	}
}
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	for (int i = 0; i < edge.size(); i++)
	{
		int val = edge[i].front();
		for (int j = 1; j < edge[i].size(); j++)
		{
			Map[val].push_back(edge[i][j]);
			Map[edge[i][j]].push_back(val);
		}
		
	}
	BFS(1);
	sort(Ans.rbegin(), Ans.rend());
	int iMax = Ans[0];
	for (int i = 1; i < Ans.size(); i++)
	{
		if (iMax == Ans[i])
		{
			++cnt;
		}
	}
	answer = cnt + 1;
	return answer;
}
