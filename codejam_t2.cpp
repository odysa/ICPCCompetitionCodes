#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<fstream>
using namespace std;
int t;
inline void process()
{
	char c=getchar();
	for(int i=1;i<=2*t-1;++i)
	{
        c=getchar();
		if(c=='E') printf("S");
			else printf("E");
	}
	printf("\n");
	return;
}
int main()
{
	int k,n,num=1;
	scanf("%d",&k);
	while(num<=k)
	{
		++num;
		printf("Case #");
		printf("%d",num-1);
		printf(": ");
		scanf("%d",&t);
		process();
	}
	return 0;
}