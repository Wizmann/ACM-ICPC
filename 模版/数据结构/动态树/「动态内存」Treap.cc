#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

template<typename T> class Treap
{
private:
    struct TreapNode
    {
        TreapNode *left,*right;
        T value;
        int fix,size;
        TreapNode()
        {
            size=0;
        }
    };
    TreapNode *root,*null;
    /*
    void Right_Rotate(TreapNode *&a);              //右旋              done
    void Left_Rotate(TreapNode *&a);               //左旋              done
    void Insert(TreapNode *&a,T k);                //插入              done
    void Delete(TreapNode *&a,T k);                //删除              done
    void Msize(TreapNode *&a);                     //维护节点的大小    done
    T Rank(TreapNode *&a,int k);                   //取第k小元素       done
    int Get_Rank(TreapNode *&a,int num,T k);       //取x的排名         done
    */
    
public:
	/*
    Treap<T>();                                     //构造函数          done
    void Insert(T x);                               //插入              done
    void Delete(T x);                               //删除              done
    int Size();                                     //返回树的大小      done
    T Max();                                        //取最大值          done
    T Min();                                        //取最小值          done
    T Rank(int k);                                  //取第k小元素       done
    int Get_Rank(T x);                              //取x的排名，如果不存在返回-1，done
    //当树为空的时候，Max,Min,Rank函数会出错
    */
    /*******************************************************************/
    Treap(){}
    
    void init()
	{
		srand(0);
		null=new TreapNode;
		root=null;
	}
	
	void Right_Rotate(TreapNode *&a)
	{
		TreapNode *b=a->left;
		a->left=b->right;
		b->right=a;
		Msize(a);
		Msize(b);
		a=b;
	}

	void Left_Rotate(TreapNode *&a)
	{
		TreapNode *b=a->right;
		a->right=b->left;
		b->left=a;
		Msize(a);
		Msize(b);
		a=b;
	}

	void Insert(TreapNode *&a,T k)
	{
		if(a==null)
		{
			a=new TreapNode;
			a->value=k;
			a->fix=rand();
			a->size=1;
			a->left=a->right=null;
		}
		else if(k<=a->value)
		{
			Insert(a->left,k);
			a->size++;
			if(a->left->fix<a->fix)Right_Rotate(a);
		}
		else
		{
			Insert(a->right,k);
			a->size++;
			if(a->right->fix<a->fix)Left_Rotate(a);
		}
	}
	void Insert(T x)
	{
		Insert(root,x);
	}


	void Msize(TreapNode*& a)
	{
		a->size = 1+(a->left->size)+(a->right->size);
	}
	
	void Delete(TreapNode*& a,T k)
	{
		if(a->value==k)
		{
			if(a->right==null || a->left==null)
			{
				TreapNode *t=a;
				if(a->right==null)a=a->left;
				else a=a->right;
				
				delete t;//note
			}
			else
			{
				if(a->left->fix<a->right->fix)
				{
					TreapNode *tmp=a->left;
					Right_Rotate(a);
					Delete(a->right,k);
					Msize(tmp);
				}
				else
				{
					TreapNode *tmp=a->right;
					Left_Rotate(a);
					Delete(a->left,k);
					Msize(tmp);
				}
			}
		}
		else if(k<a->value) Delete(a->left,k),Msize(a);
		else Delete(a->right,k),Msize(a);
	}

	void Delete(T x)
	{
		Delete(root,x);
	}

	T Max()
	{
		TreapNode *tmp=root;
		while(tmp->right!=null)tmp=tmp->right;
		return tmp->value;
	}

	T Min()
	{
		TreapNode *tmp=root;
		while(tmp->left!=null) tmp=tmp->left;
		return tmp->value;
	}

	int Size()
	{
		return root->size;
	}

	T Rank(TreapNode*& a, int k)
	{
		if(a->left->size+1==k)return a->value;
		else if(a->left->size>=k)return Rank(a->left,k);
		else return Rank(a->right,k-a->left->size-1);
	}

	T Rank(int k)
	{
		return Rank(root,k);
	}

	int Get_Rank(TreapNode*& a, int num, T k)
	{
		if(a==null)return -1;
		else if(a->value==k) return num+a->left->size+1;
		else if(k<a->value) return Get_Rank(a->left,num,k);
		else return Get_Rank(a->right,num+a->left->size+1,k);
	}

	int Get_Rank(T x)
	{
		return Get_Rank(root,0,x);
	}
};


Treap< pair<int,int> > tp;//Tristian Prettyman

int main()
{
	int cmd,a,b;
	while(scanf("%d",&cmd)!=EOF && cmd)
	{
		if(cmd==1)
		{
			scanf("%d%d",&a,&b);
			tp.Insert(make_pair(b,a));
		}
		else if(cmd==2)
		{
			if(tp.Size()==0) puts("0");
			else
			{
				printf("%d\n",tp.Max().second);
				tp.Delete(tp.Max());
			}
		}
		else if(cmd==3)
		{
			if(tp.Size()==0) puts("0");
			else
			{
				printf("%d\n",tp.Min().second);
				tp.Delete(tp.Min());
			}
		}
	}
	return 0;
}
