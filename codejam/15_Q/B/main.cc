#include <cstdio>

inline int max(int a,int b) {
	return a>b?a:b;
}
inline int min(int a,int b) {
	return a<b?a:b;
}

int a[1000];
int ans,n;

int need(int t) {
	int ans=0;
	for (int i=0;i<n;i++) {
		ans+=a[i]/t;
		if (a[i]!=0&&a[i]%t==0) ans--;
	}
	return ans;
}

int main() {
	int t,tt,i,maxp;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%d",&n);
		maxp=0;
		for (i=0;i<n;i++) {
			scanf("%d",&a[i]);
			maxp=max(maxp,a[i]);
		}
		if (maxp==0) ans=0;
		else ans=10000;
		for (i=1;i<=maxp;i++) {
			ans=min(ans,i+need(i));
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
