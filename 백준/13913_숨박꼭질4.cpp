#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000 + 1;
int cnt;
int iMin;
bool visited[MAX];
int chk[MAX];

vector<int> path;
int parent[MAX];
int BFS(int N, int K)
{
	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));
	visited[N] = true;
	while (!q.empty())
	{
		int Pos = q.front().first;
		int curSec = q.front().second;
		q.pop();
	
		if (Pos == K)
		{
			int idx = Pos;

			while (idx != N)
			{
				path.push_back(idx);
				idx = parent[idx];
			}
			path.push_back(N);

			return curSec;
		}
		

		
		if (Pos + 1 < MAX && !visited[Pos + 1])
		{
			visited[Pos + 1] = 1;
			parent[Pos + 1] = Pos;
			q.push(make_pair(Pos + 1, curSec + 1));
			
		}
		if (Pos - 1 >= 0 && !visited[Pos - 1])
		{
			visited[Pos - 1] = 1;
			parent[Pos - 1] = Pos;
			q.push(make_pair(Pos - 1, curSec + 1));
		}
		if (Pos * 2 < MAX && !visited[Pos * 2])
		{
			visited[Pos * 2] = 1;
			parent[Pos * 2] = Pos;
			q.push(make_pair(Pos * 2, curSec + 1));
		}
	}
	return iMin;
}



int main(void)

{
	int N, K;
	cin >> N >> K;
	cout << BFS(N, K) << "\n";
	for (int i = path.size() - 1; i >= 0; i--)
	{
		cout << path[i] << " ";
	}
	cout << "\n";
	return 0;
}

