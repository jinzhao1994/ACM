#include <cstdio>

char s[1002];
int sum,n,ans;

int main() {
	int t,i,tt;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%d",&n);
		scanf("%s",s);
		sum=0;
		ans=0;
		for (i=0;i<=n;i++) {
			if (sum<i) {
				ans+=i-sum;
				sum=i;
			}
			sum+=s[i]-'0';
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
