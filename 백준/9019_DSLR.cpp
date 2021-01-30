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
#include<deque>
using namespace std;
#define Max 10000

bool visit[Max];
int Start, End;
int T;
string BFS(int a, int b)
{
	
	queue<pair<int,string>> q;
	q.push({ a,"" });
	visit[a] = 1;
	while (!q.empty())
	{
		int top = q.front().first;
		string word = q.front().second;
		
		q.pop();
		if (top == End)
		{
			return word;
		}
		
		int value = (top * 2) % 10000;
		if (!visit[value])
		{
			visit[value] = 1;
			q.push({ value,word + "D" });
		}
		value = top - 1;
		if (value < 0) value = 9999;
		if (!visit[value])
		{
			visit[value] = 1;
			q.push({ value,word + "S" });
		}

		value = (top % 1000) * 10 + top / 1000;
		if (!visit[value])
		{
			visit[value] = 1;
			q.push({ value,word + "L" });
		}
		value = (top / 10) + (top % 10) * 1000;
		
		
	
		if (!visit[value])
		{
			visit[value] = 1;
			q.push({ value,word + "R" });
		}
		
		
		
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		memset(visit, false, sizeof(visit));
		cin >> Start >> End;
		cout << BFS(Start, End) << "\n";
	}
	
	
	return 0;

}

