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

int val;
stack<pair<int, int>> st;
int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N; cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> val;
		while (!st.empty())
		{
			if (st.top().second > val)
			{
				cout << st.top().first << " ";
				break;
			}
			st.pop();
		}

		if (st.empty())
		{
			cout << 0 << " ";
		}
		st.push(make_pair(i, val));
	}
	return 0;
}