#include <cstdio>
#include <algorithm>

using namespace std;

int x,r,c;

int main() {
	for (x=3;x<7;x++) {
		for (r=(x+1)/2;r<=x;r++) {
			for (c=max(r,x+1-r);c<=x;c++)
				if (r*c%x==0) printf("%d %d %d\n",x,r,c);
			printf("%d %d inf\n",x,r);
		}
	}
	return 0;
}
