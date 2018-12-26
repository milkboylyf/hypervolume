//��n��d�о����hv
//�Ѿ���׼������
//ע�⣬������ԭ���ĵ㶼��ı����
//�д��Ľ����ο����ѡ��Ŀǰֻ�������Сֵ���ɸĳ���С�ָ�㣬��������������

#include "Utils.h"
#include "math.h"
#include "LinkList.h"

bool dom(double* a, double* b, int dim);

double Approximate(double ** p, int nrP, int dim, int Samp, int numK)
{
	LinkList<double *> Subp_ind;
	LinkList<double *> *Aa = &Subp_ind;
	int len = 0;

	double * volume = new double[nrP];
	for (int i = 0; i < nrP; i++)
	{
		volume[i] = 1;
		for (int j = 0; j < dim; j++)
		{
			volume[i] *= p[i][j];
		}
	}
	double maxV = Max_Vector(volume, nrP);


	for (int i = 0; i < nrP; i++)
	{
		int tmplen = len;
		Aa = &Subp_ind;
		for (int j = 0; j < tmplen; j++)
		{
			//ɾ��������
			if (dom(p[i], Aa->next->data, dim))		//�������֧������㣬��ɾ������󻯣�
			{
				LinkList<double *> *e = Aa->next;
				Aa->next = Aa->next->next;
				delete[] e->data;
				delete e;
				len--;
			}
			else
			{
				Aa = Aa->next;
			}
		}
		//���������С
		//double SampSiz = Samp;		//��1
		//for (int j = 0; j < dim; j++)
		//{
		//	SampSiz *= p[i][j];
		//}

		//��2
		double SampSiz = ((double)Samp)*(volume[i] / maxV);


		//��Ӳ�����
		for (int j = 0; j < SampSiz; j++)
		{
			double *tmpInd = new double[dim];
			for (int k = 0; k < dim; k++)
			{
				tmpInd[k] = drand(0, p[i][k]);
			}
			Insert_ele(Aa, tmpInd);
			len++;
		}
	}

	Aa = &Subp_ind;
	for (int j = 0; j < len; j++)
	{
		LinkList<double *> *e = Aa->next;
		Aa->next = Aa->next->next;
		delete[] e->data;
		delete e;
	}
	//delete[] Aa;

	delete[] volume;

	return ((double)len) / ((double)Samp/ maxV);
	//return ((double)len) / ((double)Samp);
}


bool dom(double* a, double* b, int dim)
{
	bool dom = true;
	for (int i = 0; i < dim; i++)
	{
		if (a[i] < b[i])
		{
			dom = false;
		}
	}
	return dom;
}
