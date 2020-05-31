#include<bits/stdc++.h>
#define For(i,l,r) for(int i = l;i<=r;i++)
#define LL long long
#define N 100000
using namespace std;
struct tree{
	int ch[2];
	int ff;
	int val; 
	int cnt;
};
struct st{
	tree t[N];
	int root = 0;
	int cnt=0;
	void pushup(u){
		t[u].cnt=t[u<<1].cnt+t[u<<1|1].cnt;//更新size 
	}
	void rotate(int x){
		int f=t[x].ff;//father
		int z=t[f].ff;//grandfather
		int k=t[f].ch[1]==x;//x是父亲的哪个儿子 
		t[z].ch[t[z].ch[1]==f]=x;//将x替换为父亲的位置 
		t[x].ff=z;//x的父亲是祖父 
		t[f].ch[k]=t[x].ch[k^1];//x的位置替换为x在父亲原孩子位等位的儿子 
		t[t[x].ch[k^1]].ff=f;//这个孩子的父亲替换为父亲 
		t[x].ch[k^1]=y;//这个孩子在x的的孩子位替换为父亲 
		t[f].ff=x;//父亲的父亲为x 
		pushup(f),pushup(x);//结束后更新 
	}
	void splay(int x,int goal){//splay 
		while(t[x].ff!=goal){//x没有被旋转到目标节点时 
			int f = t[x].ff,z=t[y].ff;//父亲和祖父 
			if(z!=goal)(t[z].ch[0]==y)^(t[f].ch[0]==x)?rotate(x):rotate(y);//如果祖父不是根节点，如果在一条链上，就先旋转y，如果不是先旋转x 
			rotate(x);//旋转x，毕竟这才是目标上面是为了防止出现链 
		}
		if(goal == 0)root = x;//如果goal是根节点，那么需要更新根节点信息。 
	} 
	bool find(int x){//查找操作 
		int u = root;//当前搜索位置 
		if(!u)return 0;//如果是一颗空树，返回0 
		while(t[u].ch[x>t[u].val]&&x!=t[u].val)u=t[u].ch[x>t[u].val];//当没有查找到时，继续查找 
		splay(x,root);
		return x==t[root].val; 
	} 
	void insert(int x){//插入操作 
		int u  = root,f = 0;//从根节点开始搜，并存储父亲节点 
		while(u&&t[u].val!=x){//类似搜索操作 
			f=u;
			u=t[u].ch[x>t[u].val];
		} 
		if(t[u].cnt)t[u].cnt++;//如果这个点存在，那么计数加加 
		else{//否则创建新节点 
			u=++cnt;//创建一个新节点 
			if(f)t[f].ch[x>t[f].val]=u;//如果父节点不是根，那么创建该节点的儿子 
			t[u].ch[0]=t[u].ch[1]=0;//创建节点。 
			t[u].ff=f;
			t[u].val=x;
			t[u].cnt=1;
			t[u].size=1;	
		}
		splay(u,root);
	} 
	int nest(int x,int ope){
		find(x);
		int u = root;
		if(t[u].val>x&&ope)return u;
		if(t[u].val<x&&!ope)return u;
		u=t[u].ch[ope];
		while(t[u].ch[ope^1])u=t[u].ch[ope^1];
		return u;
	}
};
//https://www.cnblogs.com/cjyyb/p/7499020.html
//https://www.cnblogs.com/zwfymqz/p/7896036.html     https://www.cnblogs.com/zwfymqz/p/7898210.html
//https://www.cnblogs.com/yzhang-rp-inf/p/9957906.html 
