#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int isize = prices.size();
	int cnt = 0;
	for (int i = 0; i < isize - 1; i++)
	{
		cnt = 0;
		for (int j = i + 1; j < isize - 1; j++)
		{
			if (prices[i] > prices[j])
			{
				break;
			}
			if (prices[i] <= prices[j])
			{
				++cnt;
			}
		}
		answer.push_back(cnt);
	}
	for (int i = 0; i < answer.size(); i++)
	{
		answer[i] += 1;
	}
	answer.push_back(0);
	return answer;
}
