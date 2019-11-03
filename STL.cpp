#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main()
{
    s.insert(0);
    s.insert(-1);
    s.insert(0);
    s.insert(2);
    int k=s.lower_bound(-1);
    return 0;
}