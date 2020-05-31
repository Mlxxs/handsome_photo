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
		t[u].cnt=t[u<<1].cnt+t[u<<1|1].cnt;//����size 
	}
	void rotate(int x){
		int f=t[x].ff;//father
		int z=t[f].ff;//grandfather
		int k=t[f].ch[1]==x;//x�Ǹ��׵��ĸ����� 
		t[z].ch[t[z].ch[1]==f]=x;//��x�滻Ϊ���׵�λ�� 
		t[x].ff=z;//x�ĸ������游 
		t[f].ch[k]=t[x].ch[k^1];//x��λ���滻Ϊx�ڸ���ԭ����λ��λ�Ķ��� 
		t[t[x].ch[k^1]].ff=f;//������ӵĸ����滻Ϊ���� 
		t[x].ch[k^1]=y;//���������x�ĵĺ���λ�滻Ϊ���� 
		t[f].ff=x;//���׵ĸ���Ϊx 
		pushup(f),pushup(x);//��������� 
	}
	void splay(int x,int goal){//splay 
		while(t[x].ff!=goal){//xû�б���ת��Ŀ��ڵ�ʱ 
			int f = t[x].ff,z=t[y].ff;//���׺��游 
			if(z!=goal)(t[z].ch[0]==y)^(t[f].ch[0]==x)?rotate(x):rotate(y);//����游���Ǹ��ڵ㣬�����һ�����ϣ�������תy�������������תx 
			rotate(x);//��תx���Ͼ������Ŀ��������Ϊ�˷�ֹ������ 
		}
		if(goal == 0)root = x;//���goal�Ǹ��ڵ㣬��ô��Ҫ���¸��ڵ���Ϣ�� 
	} 
	bool find(int x){//���Ҳ��� 
		int u = root;//��ǰ����λ�� 
		if(!u)return 0;//�����һ�ſ���������0 
		while(t[u].ch[x>t[u].val]&&x!=t[u].val)u=t[u].ch[x>t[u].val];//��û�в��ҵ�ʱ���������� 
		splay(x,root);
		return x==t[root].val; 
	} 
	void insert(int x){//������� 
		int u  = root,f = 0;//�Ӹ��ڵ㿪ʼ�ѣ����洢���׽ڵ� 
		while(u&&t[u].val!=x){//������������ 
			f=u;
			u=t[u].ch[x>t[u].val];
		} 
		if(t[u].cnt)t[u].cnt++;//����������ڣ���ô�����Ӽ� 
		else{//���򴴽��½ڵ� 
			u=++cnt;//����һ���½ڵ� 
			if(f)t[f].ch[x>t[f].val]=u;//������ڵ㲻�Ǹ�����ô�����ýڵ�Ķ��� 
			t[u].ch[0]=t[u].ch[1]=0;//�����ڵ㡣 
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
