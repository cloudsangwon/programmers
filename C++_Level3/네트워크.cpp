#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;


vector<int> Map[201];
int chk[201];
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
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	int isize = computers.size();
	int jsize = computers[0].size();

	for (int i = 0; i < isize; i++)
	{
		for (int j = 0; j < jsize; j++)
		{
			
			if (i != j)
			{

				if (computers[i][j] == 1)
				{
		
					Map[i].push_back(j);
					Map[j].push_back(i);

				}
			}
			
		}
	}
	
	for (int i = 0; i < isize; i++)
	{
		if (!chk[i])
		{
			++cnt;
			DFS(i);
		}
	}
	answer = cnt;
	return answer;
}
int main(void)
{
	vector<vector<int>> computers = {
		{1,1,0},
		{1,1,0},
		{0,0,1}
	};
	
	/*vector<vector<int>> computers = {
		{1,1,0},
		{1,1,1},
		{0,1,1}
	};*/
	int n = 3;
	solution(n, computers);
	
	return 0;
}