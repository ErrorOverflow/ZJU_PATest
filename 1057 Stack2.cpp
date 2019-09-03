#include <iostream>
#include <stack>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;

int mid = 0;
multiset<int> upper;
multiset<int, greater<int>> lower;

void adjust(int *mid)
{
    if (upper.size() > lower.size())
    {
        lower.insert(*upper.begin());
        upper.erase(upper.begin());
    }
    else if (lower.size() > upper.size() + 1)
    {
        upper.insert(*lower.begin());
        lower.erase(lower.begin());
    }
    *mid = *lower.begin();
}

int main()
{
    stack<int> st1;
    int n;
    scanf("%d", &n);
    char ch[11];
    int stem;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", ch);
        if ((ch[1] == 'o' && st1.size() == 0) || (ch[1] == 'e' && st1.size() == 0))
        {
            printf("Invalid\n");
            continue;
        }
        else if (ch[1] == 'u')
        {
            scanf("%d", &stem);
            st1.push(stem);
            if (stem > mid)
            {
                upper.insert(stem);
            }
            else
                lower.insert(stem);
            adjust(&mid);
        }
        else if (ch[1] == 'o')
        {
            int key = st1.top();
            printf("%d\n", st1.top());
            st1.pop();
            if (key > *lower.begin())
                upper.erase(upper.find(key));
            else
                lower.erase(lower.find(key));

            if (st1.empty())
                mid = 0;
            else
                adjust(&mid);
        }
        else if (ch[1] == 'e')
        {
            printf("%d\n", mid);
        }
    }
    return 0;
}
