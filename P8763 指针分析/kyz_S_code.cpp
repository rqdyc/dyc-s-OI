#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[4];
struct s{
	ll x,y;
}a[201];
ll len=0;
bitset<27> dis[703],dis1[703];
void bellman_ford(){
	for(ll i=1;i<=len;i++){
		for(ll j=1;j<=702;j++)
			dis1[j]=dis[j];
		for(ll j=1;j<=len;j++){
			ll x=a[j].x,y=a[j].y;
//			printf("%lld %lld:\n",x,y);
			if(x<=26 && y<=26){
				dis[x]|=dis1[y];
//				printf("%c<-%c\n",(char)'A'+x-1,(char)'A'+y-1);
			}
			else if(x<=26){
				ll z=(y-1)%26+1;
				y=(y-1)/26;
				for(ll k=1;k<=26;k++)
					if(dis1[y][k]){
						dis[x]|=dis1[k*26+z];
//						printf("%c<-%c.%c\n",(char)'A'+x-1,(char)'a'+k-1,(char)'a'+z-1);
					}
			} else {
				ll z=(x-1)%26+1;
				x=(x-1)/26;
				for(ll k=1;k<=26;k++)
					if(dis1[x][k]){
						dis1[k*26+z]|=dis[y];
//						printf("%c.%c<-%c\n",(char)'a'+k-1,(char)'a'+z-1,(char)'A'+y-1);
					}
			}
		}
	}
}
int main(){
	freopen("Testdata001.in","r",stdin);
	freopen("kyz.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("\n%s",s+1);
		if(!s[2]){
			ll x=s[1]-'A'+1;
			scanf("%s%s",s+1,s+1);
			if(s[1]>='a' && s[1]<='z')
				dis[x][s[1]-'a'+1]=1;
			else{
				if(!s[2]){
					a[++len].x=x;
					a[len].y=s[1]-'A'+1;
				} else {
					a[++len].x=x;
					a[len].y=26*(s[1]-'A'+1)+s[3]-'a'+1;
				}
			}
		} else {
			ll x=26*(s[1]-'A'+1)+s[3]-'a'+1;
			scanf("%s%s",s+1,s+1);
			a[++len].x=x;
			a[len].y=s[1]-'A'+1;
		}
	}
	bellman_ford();
	for(ll i=1;i<=26;i++){
		printf("%c: ",(char)('A'+i-1));
		for(ll j=1;j<=26;j++)
			if(dis[i][j])
				printf("%c",(char)('a'+j-1));
		puts("");
	}
	return 0;
}