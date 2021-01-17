#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
using namespace std;

int Map[6][6];
int chk[6][6];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
set<int> S;
vector<string> answer;
string temp = "";
void DFS(int x, int y, int cnt,string sum)
{
	if (cnt == 5)
	{
		cout << "sum :" << sum << "\n";
		int value = stoi(sum);
		sum = "";
		cout << "value :" << value << "\n";
		S.insert(value);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 1 || xx > 5 || yy < 1 || yy > 5)continue;
		sum = "";
		DFS(xx, yy, cnt + 1, sum += to_string(Map[xx][yy]));
		
		
	}
}
int main(void)
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			DFS(i, j, 0, to_string(Map[i][j]));
		}
		cout << "\n";
	}
	
	cout << S.size();
	return 0;
}