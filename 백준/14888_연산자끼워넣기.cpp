#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
#include<cmath>
using namespace std;

int N;
int Arr[101];
int Calc[5];
int iMax = -2147000000, iMin = 2147000000;
void DFS(int L,int num)
{
	if (L == N)
	{
		if (iMax < num) iMax = num;
		if (iMin > num) iMin = num;
		return;
	}
	else
	{
		if (Calc[1] > 0)
		{
			Calc[1]--;
			DFS(L + 1, num+Arr[L]);
			Calc[1]++;

		}
		if (Calc[2] > 0)
		{
			Calc[2]--;
			DFS(L + 1, num-Arr[L]);
			Calc[2]++;
		}
		if (Calc[3] > 0)
		{
			Calc[3]--;
			DFS(L + 1, num*Arr[L]);
			Calc[3]++;
		}
		if (Calc[4] > 0)
		{
			Calc[4]--;
			DFS(L + 1, num/Arr[L]);
			Calc[4]++;
		}
	}
	

}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i]; // 1 2 3 4 5 6 
	}
	for (int i = 1; i <= 4; i++)
	{
		cin >> Calc[i]; // 2 1 1 1 
	}
	DFS(1,Arr[0]);
	cout << iMax << "\n";
	cout << iMin << "\n";
	return 0;
}