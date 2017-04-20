#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int maxm=500005;
const int INF=0x3f3f3f3f;
struct edge{
	int n,v;
	edge* next;
}mem[maxm],*head[maxn];
int cnt;
void add_edge(int s,int t,int v){
	mem[++cnt].next=head[s];
	mem[cnt].n=t;
	mem[cnt].v=v;
	head[s]=mem+cnt;
}

int n,m;
int d[maxn];
void bellman_ford(int source){
	for (int i=0;i<maxn;i++) d[i]=INF;
	d[source]=0;
	bool f=1;
	while(f){
		f=0;
		for (int i=1;i<=n;i++){
			for (edge *it=head[i];it;it=it->next){
				if (d[i]+it->v<d[it->n]){
					d[it->n]=d[i]+it->v;
					f=1;
				}
			}
		}
	}
}
int main(){
	freopen("data0.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int s,t,v;
		scanf("%d%d%d",&s,&t,&v);
		add_edge(s,t,v);
	}
	bellman_ford(1);
	for (int i=1;i<=n;i++) printf("%d\n",d[i]);
	return 0;
}


