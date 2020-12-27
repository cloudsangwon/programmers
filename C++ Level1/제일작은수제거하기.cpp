#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
// 배열의 순서가 바뀌면 안되므로, 제일 작은 값의 인덱스를 찾아
// 해당 인덱스를 제외하고 복사한다.
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
