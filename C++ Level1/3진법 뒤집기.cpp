#include <string>
#include<math.h>
using namespace std;
int solution(int n) {
	int answer = 0;
	string tmp = "";
	while (n > 0)
	{
		// 3�������� ǥ���ؾ��ϹǷ�, �ڿ��� n�� 3���� 
		// ���� �������� ���� ���� ó���Ѵ�.
		int x = n % 3; 
		if (x == 0) tmp += to_string(0);
		else tmp += to_string(x);
		n = n / 3;
	}
	int len = tmp.length();
	for (int i = 0; i < len; i++)
	{
		int val = pow(3, len - i - 1);
		answer += (tmp[i] - 48) * val;
	}
	return answer;
}
