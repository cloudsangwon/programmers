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
#define Max 1000000 + 1

typedef long long ll;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int Map[Max];
bool visit[Max];
int A, B;

int BFS()
{
	visit[A] = 1;
	queue<pair<int, int>> q;
	q.push({ A,0 });
	
	while (!q.empty())
	{
		int top = q.front().first;
		int cnt = q.front().second;

		if (top == B)
		{
			return cnt;
		}
		visit[top] = 1;
		q.pop();
		int multi = top * 2;// 2¹è °öÇÑ °ª
		string temp = "";
		temp += to_string(top);
		temp += "1";
		ll value = stoi(temp);
		if (value < Max && !visit[value])
		{
			q.push({ value,cnt + 1 });
		}
		if (multi < Max && !visit[multi])
		{
			q.push({ top * 2,cnt + 1 });
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;
	int value = BFS();
	if (value == -1)
	{
		cout << "-1\n";
	}
	else cout << value + 1 << "\n";
	return 0;

}

