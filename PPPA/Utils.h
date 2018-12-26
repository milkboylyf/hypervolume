#pragma once
#ifndef UTILS
#define UTILS
#define max(a,b)  (a>b)?a:b
#define min(a,b)  (a<b)?a:b
#define min3(a,b,c)  (a<b)? ((a<c)?a:c) : ((b<c)?b:c)

#include "LinkList.h"


double drand(double from, double to)
{
	double j;
	j = from + (double)((to - from) * rand() / (RAND_MAX + 1.0));
	return j;
}

//int Max_Index(double *P, int len);
//int Max_Index(int *P, int len);

double Max_Vector(double *P, int len)
{
	double Max = P[0];
	for (int i = 1; i < len; i++)
	{
		if (P[i] > Max)
		{
			Max = P[i];
		}
	}
	return Max;
}

double Min_Vector(double *P, int len)
{
	double Min = P[0];
	for (int i = 1; i < len; i++)
	{
		if (P[i] < Min)
		{
			Min = P[i];
		}
	}
	return Min;
}



template <typename T>
int Min_Index(T *P, int len)
{
	int MinI = 0;
	for (int i = 1; i < len; i++)
	{
		if (P[i] < P[MinI])
		{
			MinI = i;
		}
	}
	return MinI;
}

template <typename T>
int Max_Index(T *P, int len)
{
	int MaxI = 0;
	for (int i = 1; i < len; i++)
	{
		if (P[i] > P[MaxI])
		{
			MaxI = i;
		}
	}
	return MaxI;
}


//void Sort(double *, int *, int);		//排序索引从0开始，第三个参数是数组的长度,第二个参数声明即可
void quickSort(double[], int [] , int , int);		//包含排序序号，但要事先做一个顺序序列index


//快速排序
template <typename T>
void quickSort(T s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l];// , y = index[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数  
				j--;
			if (i < j)
			{
				s[i++] = s[j];		//这里注意，应该是先赋值了，再运行i++
				//index[i++] = index[j];
			}

			while (i < j && s[i]< x) // 从左向右找第一个大于等于x的数  
				i++;
			if (i < j)
			{
				s[j--] = s[i]; //index[j--] = index[i];
			}
		}

		s[i] = x; //index[i] = y;
		quickSort(s, l, i - 1); // 递归调用  
		quickSort(s, i + 1, r);
	}
}



//修改的插入元素函数：插入一个元素，然后返回p是这个链表的最后一个元素的地址
//用法：LinkList<double *> * p = &RP;也就是先声明一个线性链表，然后取它的地址赋值给p
//这个，p改变，但线性表不改变
//注意~~！！！使用该函数时：要确定模板是否是引用类型，如果模板是数组的话，那么插入的数据也只是个指针，这时操作线性链表会影响原数据
//最好的做法就是：插入之前new一个数组，复制一次那些值先，再使用该函数，参考hv.cpp里面的82~87行
template <typename ElemType>
Status Insert_ele(LinkList<ElemType> *(&p), ElemType Col_ele)
{
	LinkList<ElemType> *s = new LinkList<ElemType>;
	s->data = Col_ele;
	s->next = p->next;
	p->next = s;
	p = s;
	return TRUE;
}


#endif