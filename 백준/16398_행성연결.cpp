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
#define Max 1000 + 1

int N;
int Unf[Max];
struct Edge {
	int start, end, cost;
	Edge(int a, int b, int c)
	{
		start = a;
		end = b;
		cost = c;
	}
	bool operator<(Edge& b)
	{
		return cost < b.cost;
	}
};

int Find(int V)
{
	if (V == Unf[V]) return V;
	else return Unf[V]=Find(Unf[V]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b) Unf[a] = b;
}
int main()
{
	////ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		Unf[i] = i;
	}
	vector<Edge> Ed;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int cost;
			cin >> cost;
			if (j > i)
			{
				Ed.push_back(Edge(i, j, cost));
			}
			
		}
	}
	sort(Ed.begin(), Ed.end());
	
	long long res = 0;
	for (int i = 0; i < Ed.size() ; i++)
	{
		if (Find(Ed[i].start) != Find(Ed[i].end))
		{
			res += Ed[i].cost;
			Union(Ed[i].start, Ed[i].end);
		}
	}
	cout << res;
	return 0;

}

