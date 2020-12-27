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
			// 숫자이거나, - 부호 있으면 임시 string 변수 tmp에 더한다.
			tmp += s[i];
		}
		if (i == len - 1)
		{
			// 반복문 i가 len-1 값이라면,
			// 공백이 없기 때문에 이때 한번 더 tmp 값을 넣어준다.
			V.push_back(stoi(tmp));
		}
		if (s[i] == ' ')
		{
			// 공백을 만날 떄, 저장된 tmp 값을 int형으로 바꾸고
			// 벡터에 저장한다.
			// 그리고 다시 tmp를 초기화한다.
			V.push_back(stoi(tmp));
			tmp = "";
		}
		
	}
	
	sort(V.begin(), V.end());
	answer += to_string(V[0]);
	answer += " ";
	answer += to_string(V[V.size() - 1]);
	return answer;
}
