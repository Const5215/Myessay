#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int maxm=500005;
const int INF=2147483647;
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
bool vis[maxn];
void SPFA(int source){
	queue<int> q;
	for (int i=0;i<maxn;i++) d[i]=INF;
	d[source]=0;
	q.push(source);vis[source]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();vis[now]=0;
		for (edge* it=head[now];it;it=it->next){
			if (d[now]+it->v<d[it->n]){
				d[it->n]=d[now]+it->v;
				if (!vis[it->n]) {
					q.push(it->n);
					vis[it->n]=1;
				}
			}
		}
	}
}
int main(){
	freopen("in0.txt","r",stdin);
	freopen("out0.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int s,t,v;
		scanf("%d%d%d",&s,&t,&v);
		add_edge(s,t,v);
	}
	SPFA(1);
	for (int i=1;i<=n;i++) printf("%d\n",d[i]);
	return 0;
}

