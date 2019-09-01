#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 10001;
int N, Q, maxb;
vector<int> pic[maxn];
vector<int> bird[maxn];
int tree[maxn];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int K;
		cin >> K;
		int b;
		for (int j = 0; j < K; j++)
		{
			cin >> b;
			pic[i].push_back(b);
			bird[b].push_back(i);
			maxb = maxb < b ? b : maxb;
		}
	}
	fill(tree, tree + maxn, maxn + 1);
	for (int i = 0; i <= maxb; i++)
	{
		sort(bird[i].begin(), bird[i].end());
		for (int j = 1; j < bird[i].size(); j++)
		{
			int s = bird[i][0];
			int u = bird[i][j];
			pic[s].insert(pic[s].end(), pic[u].begin(), pic[u].end());
			pic[u].clear();
		}
	}
	int t = 0;
	for (int i = 0; i < N; i++)
	{
		bool use = false;
		for (int j = 0; j < pic[i].size(); j++)
		{
			if (tree[pic[i][j]] > i)
			{
				use = true;
				tree[pic[i][j]] = i;
			}
		}
		if (use)
		{
			t++;
		}
	}
	printf("%d %d\n", t, maxb);
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int a, b;
		cin >> a >> b;
		if (tree[a] == tree[b])
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
