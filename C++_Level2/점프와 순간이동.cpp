#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int solution(int n)
{
	int cnt = 0;
	while (n > 0)
	{
		if (n % 2)
		{
			++cnt;
		}
		n = n / 2;
	}
	return cnt;
}

int main(void)
{
	solution(6);
	return 0; 
}