#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<fstream>
#define maxn 1000000002
using namespace std;
int a[300];
int cnt=0,k,n,num,bl;
int main()
{
	scanf("%d",&k);
	num=1;
	while(k<=num)
	{
		scanf("%d",&n);
		cnt=0;
		++num;
		printf("Case #");
		printf("%d",num-1);
		printf(": ");
		while(n)
		{
			a[++cnt]=n%10;
			n/=10;
		}
		bl=0;
		for(int i=cnt;i>=1;--i)
		{
			if(a[i]==4) bl=1;
			if(bl)
			{
				if(a[i]==4) printf("2");
				else printf("0");
			}
		}
		printf(" ");
		for(int i=cnt;i>=1;--i)
		{
			if(a[i]==4) printf("2");
			else printf("%d",a[i]);
		}
		if(k<=num) printf("\n");
	}
}