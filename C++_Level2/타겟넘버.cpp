#include <string>
#include <vector>
#include<iostream>
using namespace std;

int a[21];
int cnt = 0;
int isize;
int M;
void DFS(int L, int sum)
{
	if (L == isize + 1)
	{
		if (sum == M)
		{
			++cnt;
		}
	}
	else
	{
		DFS(L + 1, sum + a[L]);
		DFS(L + 1, sum - a[L]);
	}
}
int solution(vector<int> numbers, int target) {
	int answer = 0;
	M = target;
	isize = numbers.size();
	for (int i = 1; i <= isize; i++)
	{
		a[i] = numbers[i - 1];
	}
	DFS(1, 0);
	cout << "cnt :" << cnt;
	return answer;
}

int main(void)
{
	vector<int> numbers = { 1,1,1,1,1 };
	int target = 3;
	solution(numbers, target);
	return 0;
}