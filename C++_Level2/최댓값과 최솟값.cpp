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
			// �����̰ų�, - ��ȣ ������ �ӽ� string ���� tmp�� ���Ѵ�.
			tmp += s[i];
		}
		if (i == len - 1)
		{
			// �ݺ��� i�� len-1 ���̶��,
			// ������ ���� ������ �̶� �ѹ� �� tmp ���� �־��ش�.
			V.push_back(stoi(tmp));
		}
		if (s[i] == ' ')
		{
			// ������ ���� ��, ����� tmp ���� int������ �ٲٰ�
			// ���Ϳ� �����Ѵ�.
			// �׸��� �ٽ� tmp�� �ʱ�ȭ�Ѵ�.
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
