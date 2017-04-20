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
void dijkstra(int source){
	priority_queue<pair<int,int> > q;
	for (int i=0;i<maxn;i++) d[i]=INF;
	d[source]=0;
	q.push(make_pair(0,source));
	while (!q.empty()){
		int now=q.top().second;
		vis[now]=1;q.pop();
		for (edge* it=head[now];it;it=it->next){
			if (d[now]+it->v<d[it->n]){
				d[it->n]=d[now]+it->v;
				q.push(make_pair(d[it->n],it->n));
			}
		}
		while((!q.empty())&&vis[q.top().second]) q.pop();
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
	dijkstra(1);
	for (int i=1;i<=n;i++) printf("%d\n",d[i]);
	return 0;
}
