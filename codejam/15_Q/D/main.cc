#include <cstdio>
#include <algorithm>

using namespace std;

int x,r,c;

bool canwin() {
	if (r*c%x!=0) return true;
	if (x>r+c-1) return true;
	if (x>=r+r-1+2) return true;
	if (x>=7) return true;
	if (x==4&&r==2) return true;
	if (x==5&&r==3&&c==5) return true;
	if (x==6&&r==3) return true;
	return false;
}

int main() {
	int t,tt;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%d%d%d",&x,&r,&c);
		if (r>c) swap(r,c);
		if (canwin()) printf("Case #%d: RICHARD\n",tt);
		else printf("Case #%d: GABRIEL\n",tt);
	}
	return 0;
}
