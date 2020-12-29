#include <string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	string tmp = "";
	vector<string> V1, V2;
	for (int i = 0; i < str1.length(); i++)
	{
		str1[i] = tolower(str1[i]);
	}for (int i = 0; i < str2.length(); i++)
	{
		str2[i] = tolower(str2[i]);
	}
	for (int i = 0; i < str1.length() - 1; i++)
	{
		char str = str1[i];
		char str2 = str1[i + 1];
		if ((str >= 97 && str <= 122) && (str2 >= 97 && str2 <= 122))
		{
			tmp = str1.substr(i, 2);
			V1.push_back(tmp);
		}
	}
	for (int i = 0; i < str2.length() - 1; i++)
	{
		char str = str2[i];
		char str3 = str2[i + 1];
		if ((str >= 97 && str <= 122) && (str3 >= 97 && str3 <= 122))
		{
			tmp = str2.substr(i, 2);
			V2.push_back(tmp);
		}
	}
	if (V1.size() == 0 && V2.size() == 0)  return 65536;
	int total = V1.size() + V2.size();
	int cnt = 0;
	for (auto it = V1.begin(); it != V1.end(); it++)
	{
		auto itt = find(V2.begin(), V2.end(), *it);
		if (itt != V2.end())
		{
			V2.erase(itt);
			++cnt;
		}
	}
	if (cnt == 0) return 0;
	total = total - cnt;
	double val = (double)cnt / total;
	answer = (int)(val * 65536);
	return answer;
}
