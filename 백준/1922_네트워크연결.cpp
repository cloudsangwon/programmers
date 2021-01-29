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

int N, M;
int Unf[Max];
struct Edge {
	int v1, v2, cost;
	Edge(int a, int b, int c)
	{
		v1 = a;
		v2 = b;
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
	else return Find(Unf[V]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) Unf[a] = b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<Edge> Ed;
	for (int i = 1; i <= N; i++)
	{
		Unf[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Ed.push_back(Edge(a, b, c));
	}
	sort(Ed.begin(), Ed.end());
	int res = 0;
	for (int i = 0; i < Ed.size(); i++)
	{
		int Fa = Find(Ed[i].v1);
		int Fb = Find(Ed[i].v2);
		if (Fa != Fb)
		{
			res += Ed[i].cost;
			Union(Ed[i].v1, Ed[i].v2);
		}
	}
	cout << res;
	return 0;

}

