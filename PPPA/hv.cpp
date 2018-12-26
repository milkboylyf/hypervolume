//求n行d列矩阵的hv
//已经标准化好了
//注意，这里会把原来的点都会改变掉的
//有待改进，参考点的选择：目前只是最大最小值，可改成最小分割点，解决排序方面的问题

#include "Utils.h"
#include "math.h"
#include "LinkList.h"
#include "global.h"
#include "Approximate.cpp"

//只用于测试，真正使用时可以删掉，test
//#include<iostream>
//using namespace std;


double hv(double ** p, int nrP,int dim, int Samp, int layer)
{
	if (nrP == 0)
	{
		return 0;
	}
	//if (nrP <= 2)


	if (layer >= numK)
	{
		return Approximate(p, nrP, dim, Samp);
	}


	if (nrP <= 2)
	{
		if (nrP == 2)
		{
			//double * Min = new double[dim];
			double Min = 1; double F = 1; double G = 1;
			for (int i = 0; i < dim;i++ )
			{
				Min *= min( p[0][i] , p[1][i] );
				F *= p[0][i]; G *= p[1][i];
			}
			return F + G - Min;
		}
		//else
		else if (nrP == 1)
		{
			double F = 1;
			for (int i = 0; i < dim; i++)
			{
				F *= p[0][i];
			}
			return F;
		}
	}
	else
	{

		double *tempP = new double[nrP];
		for (int i = 0; i < nrP; i++)
		{
			tempP[i] = 1;
			for (int j = 0; j < dim; j++)
			{
				tempP[i] *= p[i][j];
			}
		}
		int MIndex = Max_Index(tempP, nrP);  //cout << MIndex << endl;




		//double *RP = new double[dim];
		double *RP = p[MIndex];
		double F = 1;
		for (int i = 0; i < dim; i++)
		{
			F *= RP[i];
			//cout << RP[i] <<" ";
		}

		for (int i = 0; i < dim; i++)
		{
			LinkList<double *> Subp_ind;
			LinkList<double *> *Aa = &Subp_ind;
			//LinkList<double *> *Subp_ind = new LinkList<double *>;
			//LinkList<double *> *Aa = Subp_ind;
			int len = 0;
			//加入分割点并分割
			for (int j = 0; j < nrP; j++)
			{
				if (p[j][i] > RP[i])
				{
					p[j][i] = p[j][i] - RP[i];
					double *Subp = new double[dim];
					for (int k = 0; k < dim; k++)
					{
						Subp[k] = p[j][k];
					}
					p[j][i] = RP[i];
					Insert_ele(Aa,Subp);
					len++;
				}
			}
			if (len != 0)
			{
				//Aa = Subp_ind -> next;
				Aa = Subp_ind.next;
				double ** Sub_Region = new double*[len];
				for (int j = 0; j < len; j++, Aa = Aa->next)
				{
					Sub_Region[j] = Aa->data;
				}
				F += hv(Sub_Region, len, dim,Samp,layer+1);
				//delete[] Sub_Region;


				//释放内存
				Aa = &Subp_ind;
				for (int j = 0; j < len; j++)
				{
					LinkList<double *> *e = Aa->next;
					Aa->next = Aa->next->next;
					delete[] e->data;
					delete e;
				}
				delete[] Sub_Region, Aa;

			}
		}

		delete[] tempP, RP;

		return F;
	}

}




//选取参考点，最少分割法，但是没通过，因为排序的原因(相同点的排序比较麻烦)，和复杂度高的原因
//int *Num_DD = new int[nrP];
//int *index = new int[nrP];
//double *tempP = new double[nrP];
//
//
//
//for (int j = 0; j < nrP; j++)
//{
//	index[j] = j; tempP[j] = p[j][0];
//}
//
////test
//for (int j = 0; j < nrP; j++)
//{
//	cout << tempP[j] << endl;
//}
//
//
//quickSort(tempP, index, 0, nrP - 1);
//
//for (int j = 0; j < nrP; j++)
//{
//	Num_DD[index[j]] = nrP - 1 - j;
//}
//for (int i = 1; i < dim; i++)
//{
//	//快速排序
//	for (int j = 0; j < nrP; j++)
//	{
//		index[j] = j; tempP[j] = p[j][i];		//索引从0开始
//	}
//
//	//test
//	//for (int j = 0; j < nrP; j++)
//	//{
//	//	cout << tempP[j] << endl;
//	//}
//
//
//	quickSort(tempP, index, 0, nrP - 1);
//
//
//	//test
//	for (int j = 0; j < nrP; j++)
//	{
//		cout << tempP[j] << endl;
//	}
//
//
//
//
//	for (int j = 0; j < nrP; j++)
//	{
//		Num_DD[index[j]] += nrP - 1 - j;
//	}
//}
//
//
//int MIndex = Min_Index(Num_DD, nrP);
//
//
////test
//for (int j = 0; j < nrP; j++)
//{
//	cout << Num_DD[j] << endl;
//}

//测试子区域的点，test
//for (int i = 0; i < nrP; i++)
//{
//	for (int j = 0; j < dim; j++)
//	{
//		cout << p[i][j] << " ";
//	}
//	cout << endl;
//}
//cout << endl;

