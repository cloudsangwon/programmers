#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

string solution(string s) {
	string answer = "";
	vector<int> V;
	string tmp = "";
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
	
		if (s[i] - 48 >= 0 && s[i] - 48 <= 9 || s[i]=='-')
		{
			
			tmp += s[i];
		}
		if (i == len - 1)
		{
			V.push_back(stoi(tmp));
		}
		if (s[i] == ' ')
		{
			V.push_back(stoi(tmp));
			tmp = "";
		}
		
	}
	
	sort(V.begin(), V.end());
	answer += to_string(V[0]);
	answer += " ";
	answer += to_string(V[V.size() - 1]);
//	cout << "answer :" << answer << "\n";
	return answer;
}

int main(void)
{

	string s; getline(cin, s);
	solution(s);
	/*
	string answer = "";
	vector<int> V;
	string tmp = "";
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		char a = s[i];
		if (s[i] - 48 >= 0 && s[i] - 48 <= 9)
		{
			tmp += s[i];
			V.push_back(stoi(tmp));
			tmp = "";
		}
		else
		{
			tmp += s[i];
		}
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << " ";
	}*/
	return 0;
}