#include<iostream>


//��������һ����to��from֮��������
//double drand(double from, double to)
//{
//	double j;
//	j = from + (double)((to - from) * rand() / (RAND_MAX + 1.0));		
//	return j;
//}


//double Max_Vector(double *P, int len)
//{
//	double Max = P[0];
//	for (int i = 1; i < len; i++)
//	{
//		if (P[i] > Max)
//		{
//			Max = P[i];
//		}
//	}
//	return Max;
//}

//double Min_Vector(double *P, int len)
//{
//	double Min = P[0];
//	for (int i = 1; i < len; i++)
//	{
//		if (P[i] < Min)
//		{
//			Min = P[i];
//		}
//	}
//	return Min;
//}



//�������򣬰�����������
void quickSort(double s[], int index[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l], y = index[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����  
				j--;
			if (i < j)
			{
				s[i] = s[j];		//����ע�⣬Ӧ�����ȸ�ֵ�ˣ�������i++
				index[i++] = index[j];
			}

			while (i < j && s[i]< x) // ���������ҵ�һ�����ڵ���x����  
				i++;
			if (i < j)
			{
				s[j] = s[i]; index[j--] = index[i];
			}
				
		}

		s[i] = x; index[i] = y;
		quickSort(s, index, l, i - 1); // �ݹ����  
		quickSort(s, index, i + 1, r);
	}
}







