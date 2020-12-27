#include <string>
#include<math.h>
using namespace std;
int solution(int n) {
	int answer = 0;
	string tmp = "";
	while (n > 0)
	{
		// 3진법으로 표현해야하므로, 자연수 n을 3으로 
		// 나눈 나머지의 값에 따라 처리한다.
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
