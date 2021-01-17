#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;

int N;
vector<int> Map;
vector<int> Comp;
int cnt = 0;
int answer = 0;
void Divide(int x)
{
	int temp = x; 
	int tmp = x;
	int chk = 0;
	while (x > 0)
	{
		int temp = x % 10;
		int value = pow(10, chk) * temp;
		Comp.push_back(value);
		tmp = tmp / 10;  
		x = tmp;
		++chk;
	}
	sort(Comp.begin(), Comp.end());
	int idx = 0;
	for (auto it = Comp.begin(); it != Comp.end(); it++)
	{
		if (*it == 0)
		{
			++idx;
		}
	}
	if (idx != 0)
	{
		Comp.erase(Comp.begin(), Comp.begin() + idx);
	}
	sort(Comp.rbegin(), Comp.rend());
	sort(Map.rbegin(), Map.rend()); 
	int pos1 = 0, pos2 = 0;
	x = temp;
	while (x > 0)
	{
		if (x / Map[pos1] > 0)
		{
			int a = x / Map[pos1];
			x = x - (Map[pos1] * a);
			answer += a;
			
			++pos1;
			
			--chk;
		}
		else
		{
			++pos1;
		}

	}
	cout << answer;
}
int main(void)
{

	int K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int val; cin >> val;
		if (val <= K)
		{
			Map.push_back(val);
		}
		else continue;
	}
	
	
	Divide(K);
	return 0;
}