#include<bits/stdc++>
#define N 100010
#define ls u<<1
#define rs u<<1|1
#define lz laz[u]
#define mi l+r>>1
#define len r-l+1
#define For(i,l,r) for(int i = l;i<=r;i++)
#define LL long long
using namespace std;
int lt[N*4];
int laz[N*4];
int pushup(int u){return lt[u]=lt[ls]+lt[rs];}
int pushdown(int u,int len){
	if(laz[u]){
		laz[ls]+=lz;
		laz[rs]+=lz;
		lt[ls]+=lz*(len-(len>>1));
		it[rs]+=lz*(len>>1);
		lz=0;
	}
}
int build(int u,int l,int r){
	if(l==r){return cin>>lt[u];}
	int mid = mi;
	build(ls,l,mid);
	build(rs,mid+1,r);
	return pushup(u);
}
void update(int L,int R,int c,int l,int r,int u){
	if(l>=L&&r<=r){
		laz[u]+=c;
		lt[u]+=c*len;
		return;
	}
	pushdown(u,len);
	int mid = mi;
	if(mid>=L)update(L,R,c,l,mid,ls);
	if(mid+1<=R)update(L,R,c,mid+1,r,rs);
	pushup(u);
}
LL query(int L,int R,int l,int r,int u){
	if(l>=L&&r<=r){return lt[u];}
	LL ans=0;
	pushdown(u,len);
	int mid = mi;
	if(mid>=L)ans+=query(L,R,l,mid,ls);
	if(mid+1<=R)ans+=query(L,R,mid+1,r,rs);
	return ans;
}
int main(){
	
}
