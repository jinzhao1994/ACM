#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int oriMatrix[4][4]={
	{1,2,3,4},
	{2,-1,4,-3},
	{3,-4,-1,2},
	{4,3,-2,-1}};
int tran[8][8];

void initMatrix() {
	for (int i=0;i<8;i++) {
		for (int j=0;j<8;j++) {
			int ri=i,rj=j;
			bool flag=true;
			if (i>=4) {
				ri-=4;
				flag=!flag;
			}
			if (j>=4) {
				rj-=4;
				flag=!flag;
			}
			int ans=oriMatrix[ri][rj];
			if (!flag) ans=-ans;
			if (ans<0) ans=-ans+3;
			else ans--;
			tran[i][j]=ans;
		}
	}
}

bool dp[2][4][8];
int s[10000];
int l,n;
long long x;

int main() {
	int t,tt,i,j,k;
	initMatrix();
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%d%lld",&l,&x);
		for (i=0;i<l;i++) {
			char c;
			scanf(" %c",&c);
			if (c=='i') s[i]=1;
			else if (c=='j') s[i]=2;
			else if (c=='k') s[i]=3;
		}
		memset(dp[1],0,sizeof(dp[1]));
		dp[1][0][0]=true;
		if (x>12) x=12+x%4;
		n=l*x;
		cerr << "n = " << n << endl;
		for (i=0;i<n;i++) {
			int a=i&1,b=a^1,c=s[i%l];
			memset(dp[a],0,sizeof(dp[1]));
			for (j=0;j<4;j++)
				for (k=0;k<8;k++)
					if (dp[b][j][k])
						dp[a][j][tran[k][c]]=true;
			if (dp[a][0][1]) dp[a][1][0]=true;
			if (dp[a][1][2]) dp[a][2][0]=true;
			if (dp[a][2][3]) dp[a][3][0]=true;
		}
		if (dp[(n-1)&1][3][0]) printf("Case #%d: YES\n",tt);
		else printf("Case #%d: NO\n",tt);
		cerr << "Case #" << tt << " completed" << endl;
	}
	return 0;
}
