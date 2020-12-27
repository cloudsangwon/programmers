#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

// pos 변수를 사용해서, 공백이 생기면 pos를 0으로 초기화하고
// 공백이 아니면 하나씩 늘린다.
string solution(string s) {
	string answer = "";
	int pos = 0;
	int len = s.length(), idx = 0;
	for (int i = 0; i < len; i++)
	{
		idx = i;
		char a = s[i];
		if (a == ' ')
		{
			pos = 0;
			answer += ' ';
		}
		else
		{
			if (pos % 2 == 0)
			{
				s[i] = toupper(s[i]);
				answer += s[i];
			}
			else
			{
				s[i] = tolower(s[i]);
				answer += s[i];
			}
			++pos;
		}
	}
	return answer;
}
