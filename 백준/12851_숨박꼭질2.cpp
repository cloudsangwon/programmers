#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000 + 1;
int cnt;
int iMin;
bool visited[MAX];

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



		visited[Pos] = true;

		if (iMin && iMin == curSec && Pos == K) cnt++;
		if (!iMin && Pos == K)
		{
			iMin = curSec;
			cnt++;
		}

		if (Pos + 1 < MAX && !visited[Pos + 1])
		{
			q.push(make_pair(Pos + 1, curSec + 1));
		}
		if (Pos - 1 >= 0 && !visited[Pos - 1])
		{
			q.push(make_pair(Pos - 1, curSec + 1));
		}

		if (Pos * 2 < MAX && !visited[Pos * 2])
		{
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
	cout << cnt << endl;
	return 0;
}

