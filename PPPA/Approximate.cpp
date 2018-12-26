//求n行d列矩阵的hv
//已经标准化好了
//注意，这里会把原来的点都会改变掉的
//有待改进，参考点的选择：目前只是最大最小值，可改成最小分割点，解决排序方面的问题

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
			//删除采样点
			if (dom(p[i], Aa->next->data, dim))		//如果个体支配采样点，则删除（最大化）
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
		//计算采样大小
		//double SampSiz = Samp;		//法1
		//for (int j = 0; j < dim; j++)
		//{
		//	SampSiz *= p[i][j];
		//}

		//法2
		double SampSiz = ((double)Samp)*(volume[i] / maxV);


		//添加采样点
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
