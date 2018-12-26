#ifndef LINKLIST_H
#define LINKLIST_H


#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

template <typename ElemType>
struct LinkList {
	ElemType data;
	LinkList * next;

};		//�����������LNode����ô����һ����������������LinkList����ô����һ����ַָ��


//�����Ա�L�л�ȡ��i��Ԫ�أ����Ԫ����e

//Status Init_L(LinkList &L);								//��ʼ��һ����������
//Status GetElem_L(LinkList L,int i,ElemType &e);			//��ȡԪ��
//Status ListInsert_L(LinkList &L,int i,ElemType e);		//����Ԫ�أ�ע�⣬����ͻ�ȡ��λ��ָ����ʵ��λ�ã���matlab��Ӧ�������Ǵ�0��ʼ
template <typename ElemType>
Status Init_L(LinkList<ElemType> &L)			//���п���
{
	LinkList<ElemType> *s = new LinkList<ElemType>;
	L = *s;
	if (!(&L)) exit(OVERFLOW);
	return OK;
}
template <typename ElemType>
Status GetElem_L(LinkList<ElemType> L, int i, ElemType &e)
{
	//LinkList<ElemType> * p = (&L)->next;
	LinkList<ElemType> * p = L.next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}
template <typename ElemType>
Status ListInsert_L(LinkList<ElemType> &L, int i, ElemType e)
{
	//LNode * p = L;
	LinkList<ElemType> * p = &L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return ERROR;
	//LinkList s = ( LinkList )malloc(sizeof(LNode) );
	LinkList<ElemType> *s = new LinkList<ElemType>;

	s->data = e; s->next = p->next;
	p->next = s;
	return OK;
}

//ɾ��ĳindexԪ�أ����ظ�Ԫ��,�˴��ķ��ص�Ԫ��e��Ҫ�����ڹ��������������ͷ�Ԫ��e�Ŀռ��
template <typename ElemType>
Status ListDelete_L(LinkList<ElemType> &L, int i, ElemType &e)		
{
	LinkList<ElemType> * p = &L; 
	LinkList<ElemType> * q;

	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return ERROR;

	q = p->next;
	e = q->data;
	p->next = q->next;
	delete q;		//ע�⣬�˴�delete q�����ԭ�������������ָ�붼delete����

	return OK;
}

#endif
