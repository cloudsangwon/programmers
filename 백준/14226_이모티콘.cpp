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
#define Max 2000 + 1

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int Map[Max][Max];
bool visit[Max][Max];

int S;
queue<pair<pair<int, int>, int>> q; // 화면,클립보드,시간

int BFS()
{
	while (!q.empty())
	{
		int display = q.front().first.first;
		int clip = q.front().first.second;
		int Time = q.front().second;
		q.pop();

		if (display == S)
		{
			return Time;
		}
		if (display > 0 && display < Max)
		{
			if (visit[display][display] == 0)
			{
				visit[display][display] = 1;
				q.push(make_pair(make_pair(display, display), Time + 1));
			}

			if (visit[display - 1][clip] == 0)
			{
				visit[display - 1][clip] = 1;
				q.push(make_pair(make_pair(display - 1, clip), Time + 1));
			}
		}


		if (clip > 0 && display + clip < Max)
		{
			if (visit[display + clip][clip] == 0)
			{
				visit[display + clip][clip] = 1;
				q.push(make_pair(make_pair(display + clip, clip), Time + 1));
			}

		}


	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	q.push(make_pair(make_pair(1, 0), 0));
	cin >> S;
	visit[1][0] = 1;

	int value = BFS();
	cout << value;
	return 0;

}

