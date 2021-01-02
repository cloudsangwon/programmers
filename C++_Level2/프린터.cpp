#include <string>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<pair<int, int>> V;
	vector<pair<int, int>> V2;

	for (int i = 0; i < priorities.size(); i++)
	{
		V.push_back(make_pair(priorities[i], i));
	}
	bool flag = true;
	while (!V.empty())
	{
		int top = V[0].first;
		int second = V[0].second;
		V.erase(V.begin());
		flag = true;
		for (auto it = V.begin(); it != V.end(); it++)
		{
			if (top < it->first)
			{
				flag = false;
				break;
			}
		}
		if (flag == false)
		{
			V.push_back(make_pair(top, second));
		}
		else if (flag == true)
		{
			V2.push_back(make_pair(top, second));
		}

	}
	int cnt = 0;
	int idx = 0;
	for (auto it = V2.begin(); it != V2.end(); it++)
	{
		++cnt;
		if (location == it->second)
		{
			idx = cnt; break;
		}
	}
	answer = idx;
	return answer;
}
