#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
// �迭�� ������ �ٲ�� �ȵǹǷ�, ���� ���� ���� �ε����� ã��
// �ش� �ε����� �����ϰ� �����Ѵ�.
vector<int> solution(vector<int> arr) {
	vector<int> answer;
	int max = 2147000000;
	int idx = 0;
	vector<int> tmp;
	int len = arr.size();
	if (len == 1)
	{
		answer.push_back(-1);
		return answer;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (max > arr[i])
			{
				max = arr[i];
				idx = i;
			}
		}
		for (int i = 0; i < len; i++)
		{
			if (idx != i)
			{
				answer.push_back(arr[i]);
			}
		}

	}
	return answer;
}
