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

#define Max 1000001

int main(void)
{
	ios_base::sync_with_stdio(false);
	string str, bomb; cin >> str >> bomb;
	char res[Max];
	int idx = 0;
	int len1 = str.length();
	int len2 = bomb.length();
	for (int i = 0; i < len1; i++)
	{
		res[idx++] = str[i];
		int BombSize = len2;
		if (str[i] == bomb[--BombSize])
		{
			bool chk = true;
			int Size = idx - len2; 
			for (int j = idx - 1; j >= Size; j--)
			{
				if (res[j] == bomb[BombSize--])
				{
					chk = true;
				}
				else
				{
					chk = false; break;
				}
			}
			if (chk) idx -= len2;
		}
	}
	if (idx == 0) cout << "FRULA\n"; 
	else
	{
		for (int i = 0; i < idx; i++)
		{
			cout << res[i];
		}
		cout << "\n";
	}
	return 0; 
}