#include <cstdio>
#include <algorithm>

using namespace std;

const int N=203;
const int M=700;
const int MAXINT=1<<20;

struct NetWorkFlow {
	struct Node {
		int fe,h,cur,v;
	};
	struct Edge {
		int t,ne,f;
	};
	Node a[N];
	Edge b[M*2];
	int d[M];
	int s,t,n,p;
	void clear(int nn,int ss,int tt) {
		n=nn;s=ss;t=tt;
		for (int i=1;i<=n;i++) {
			a[i].fe=-1;
			a[i].v=0;
		}
		p=0;
	}
	void putedge(int x,int y,int f) {
		b[p].t=y;
		b[p].f=f;
		b[p].ne=a[x].fe;
		a[x].fe=p++;
		b[p].t=x;
		b[p].f=0;
		b[p].ne=a[y].fe;
		a[y].fe=p++;
	}
	bool bfs() {
		int i,p,q,j;
		for (i=1;i<=n;i++) a[i].h=0;
		a[s].h=1;
		p=q=0;
		d[q++]=s;
		while (p<q) {
			i=d[p];
			for (j=a[i].fe;j!=-1;j=b[j].ne) {
				if (a[b[j].t].h==0&&b[j].f>0) {
					a[b[j].t].h=a[i].h+1;
					if (b[j].t==t) return true;
					d[q++]=b[j].t;
				}
			}
			p++;
		}
		return false;
	}
	int dfs(int i,int v) {
		if (i==t) {
			a[t].v+=v;
			return v;
		}
		int ans=0;
		for (int &j=a[i].cur;j!=-1;j=b[j].ne) {
			if (b[j].f>0&&a[b[j].t].h>a[i].h) {
				int tmp=dfs(b[j].t,min(b[j].f,v));
				v-=tmp;
				b[j].f-=tmp;
				b[j^1].f+=tmp;
				ans+=tmp;
				if (v==0) return ans;
			}
		}
		a[i].v+=ans;
		return ans;
	}
	int flow() {
		int i;
		a[s].v=MAXINT;
		while (bfs()) {
			for (i=1;i<=n;i++) a[i].cur=a[i].fe;
			dfs(s,MAXINT);
		}
		return a[t].v;
	}
};

NetWorkFlow c;
int n,m,suma,sumb,s,t;
int ans[101][101];

int main() {
	int i,j,x,y;
	scanf("%d%d",&n,&m);
	s=n+n+1;
	t=n+n+2;
	c.clear(n+n+2,s,t);
	for (i=1;i<=n;i++) {
		scanf("%d",&x);
		c.putedge(s,i,x);
		c.putedge(i,i+n,x);
		suma+=x;
	}
	for (i=1;i<=n;i++) {
		scanf("%d",&x);
		c.putedge(i+n,t,x);
		sumb+=x;
	}
	for (i=0;i<m;i++) {
		scanf("%d%d",&x,&y);
		c.putedge(x,y+n,MAXINT);
		c.putedge(y,x+n,MAXINT);
	}
	if (suma!=sumb||c.flow()!=sumb) printf("NO\n");
	else {
		printf("YES\n");
		for (i=1;i<=n;i++) {
			for (j=c.a[i].fe;j!=-1;j=c.b[j].ne) {
				if (c.b[j].t<=n+n) {
					ans[i][c.b[j].t-n]=c.b[j^1].f;
				}
			}
		}
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++)
				printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}
