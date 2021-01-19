#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
using namespace std;

int L, C;
const int Max = 16;
vector<char> Map;
//char Map[Max];
int chk[Max];
char dis[Max];
vector<string> answer;
bool flag = true;
bool f = false;
int cnt = 0;
void DFS(int s,int Level)
{
	if (Level==L)
	{
		flag = true;
		f = false;
		cnt = 0;
		string temp = "";
		for (int i = 0; i < L; i++)
		{
			char first = Map[chk[i]];
			int numf = first - 97;
			if (first != 'a' && first != 'e' && first != 'i' && first != 'o' && first != 'u')
			{
				
				++cnt;
			}
			if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u')
			{
				f = true;
			}
			for (int j = i + 1; j < L; j++)
			{
				char second = Map[chk[j]];
				int numff = second - 97;
				
				
				if (numf > numff )
				{
					flag = false;
				}
				break;
			}
		}
		if (!f) flag = false;
		if (cnt < 2) flag = false;
		if (flag)
		{
			for (int i = 0; i < L; i++)
			{
				
				temp += Map[chk[i]];
			}
			answer.push_back(temp);
		}
	}
	else
	{
		for (int i = s; i < C; i++)
		{
			chk[Level] = i;
			DFS(i + 1, Level + 1);
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> L >> C; 
	for (int i = 1; i <= C; i++)
	{
		char a; cin >> a;
		Map.push_back(a);
	}
	sort(Map.begin(), Map.end());
	DFS(0,0);
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}
	
	return 0;
}