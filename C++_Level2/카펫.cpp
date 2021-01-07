#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int total = brown + yellow;
	int val;
	for (int i = 3; ; i++)
	{
		if (!(total % i))
		{
			val = total / i;
		}
		if (((i - 2) * (val - 2)) == yellow)
		{
			
			answer.push_back(val);
			answer.push_back(i);
			break;
		}
	}
	return answer;
}
