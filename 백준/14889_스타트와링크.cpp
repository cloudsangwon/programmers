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
#define Max 100 + 1

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int Map[Max][Max];
bool visit[Max];
int N;
int chk[Max];
int res_x[Max];
int res_y[Max];
vector<pair<int, int>>V;
int res = 2147000000;
void DFS(int L, int pos)
{
	if (L == (N / 2))
	{
		int Start, Link;

		Start = 0, Link = 0;

		for (int i = 1; i <= N; i++)
		{
			//cout << visit[i] << " ";
		}
		//cout << "\n";
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				
				if (visit[i] == 1 && visit[j] == 1)
				{
					Start += Map[i][j];
				
				}
				else if (visit[i] == 0 && visit[j] == 0)
				{
					Link += Map[i][j];
					
				}
			}
		}
		 res = min(res, abs(Start - Link));
		///cout << "temp :" << res << "\n";
	}
	else
	{
		for (int i = pos; i < N; i++)
		{
			if (!visit[i])
			{
				visit[i] = true;
				DFS(L + 1,i+1);
				visit[i] = false;
				
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
			
		}
	}
	DFS(0,1);
	cout << res;
	return 0;

}

