#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("data2.txt","w",stdout);
	printf("50000 500000\n");
	for (int i=1;i<=50000;i++)
		for (int j=1;j<=10;j++)
			printf("%d %d %d\n",i,rand()%50000+1,1);
	return 0;
}
