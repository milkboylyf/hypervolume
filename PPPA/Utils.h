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


//void Sort(double *, int *, int);		//����������0��ʼ������������������ĳ���,�ڶ���������������
void quickSort(double[], int [] , int , int);		//����������ţ���Ҫ������һ��˳������index


//��������
template <typename T>
void quickSort(T s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l];// , y = index[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����  
				j--;
			if (i < j)
			{
				s[i++] = s[j];		//����ע�⣬Ӧ�����ȸ�ֵ�ˣ�������i++
				//index[i++] = index[j];
			}

			while (i < j && s[i]< x) // ���������ҵ�һ�����ڵ���x����  
				i++;
			if (i < j)
			{
				s[j--] = s[i]; //index[j--] = index[i];
			}
		}

		s[i] = x; //index[i] = y;
		quickSort(s, l, i - 1); // �ݹ����  
		quickSort(s, i + 1, r);
	}
}



//�޸ĵĲ���Ԫ�غ���������һ��Ԫ�أ�Ȼ�󷵻�p�������������һ��Ԫ�صĵ�ַ
//�÷���LinkList<double *> * p = &RP;Ҳ����������һ����������Ȼ��ȡ���ĵ�ַ��ֵ��p
//�����p�ı䣬�����Ա��ı�
//ע��~~������ʹ�øú���ʱ��Ҫȷ��ģ���Ƿ����������ͣ����ģ��������Ļ�����ô���������Ҳֻ�Ǹ�ָ�룬��ʱ�������������Ӱ��ԭ����
//��õ��������ǣ�����֮ǰnewһ�����飬����һ����Щֵ�ȣ���ʹ�øú������ο�hv.cpp�����82~87��
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