#include<stdio.h>
void cal_elimination(double p[][20], double *constant_vector, int n);	 //消去
void cal_substitution(double p[][20], double *constant_vector, double *matrix_result, int n); //回代
void print_elimi(double p[][20], int n);				//输出变换后的系数矩阵
void print_const(double *constant_vector, int n);		//输出变换后的常向量矩阵
void print_result(double *matrix_result, int n);		//输出解
void main()
{
	double matrix_coeff[20][20]={0};		//系数矩阵
	double (*p)[20] = matrix_coeff;
	double constant_vector[20]={0};			//常向量
	double matrix_result[20]={0};
	printf("请输入解向量的数目：\n");
	int n;
	scanf("%d", &n);
	printf("请输入系数矩阵：\n");
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%lf", p[i] + j);
		}
	}
	printf("请输入%d个常向量：\n", n);
	for(i = 0; i < n; i++)
	{
		scanf("%lf", &constant_vector[i]);
	}
	p = matrix_coeff;
	cal_elimination(p, constant_vector, n);
	print_elimi(p, n);
	print_const(constant_vector, n);
	cal_substitution(p, constant_vector, matrix_result, n);
	print_result(matrix_result, n);
}
//void cal_elimination(int (*p)[20], int n)	//消去
void cal_elimination(double p[][20], double *constant_vector, int n)	//消去
{
	int i, j, t = 0, r = 0;
	double temp[20] = {0};
	double con_temp = 0;
	for(; r < n ; r++)
	{
		for(i = r; i < n - 1; i++)		//行坐标
		{
			double k1 = -(p[i + 1][r] / p[r][r]);	//计算每次要加的值，对于系数矩阵
			double k2 = k1 * constant_vector[r];	//计算每次加到常向量上的值
			for(j = 0; j < n; j++)
			{
				temp[j] = p[r][j] * k1;
			}
			t = i + 1;
			for(j = 0; j < n; j++)
			{
				p[t][j] += temp[j];
			}
			constant_vector[t] += k2;		//计算常向量上的值
		}
	}
}
void cal_substitution(double p[][20], double *constant_vector, double *matrix_result, int n)	//回代求解
{
	int i, j;
	matrix_result[n - 1] = constant_vector[n - 1] / p[n - 1][n - 1];
 	for(i = n - 2; i >= 0; i--)
	{
		double temp = 0;
		for(j = i + 1; j < n; j++)
		{
			temp += p[i][j] * matrix_result[j];
		}
		matrix_result[i] = (constant_vector[i] - temp) / p[i][i];
	}
}
void print_elimi(double p[][20], int n)
{
	printf("变换后的系数矩阵：\n");
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%5.1lf", p[i][j]);
		}
		printf("\n");
	}
}
void print_const(double *constant_vector, int n)
{
	printf("变换后的常向量矩阵：\n");
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%5.1f\n", *(constant_vector + i));
	}
	printf("\n");
}
void print_result(double *matrix_result, int n)
{
	int i;
	printf("解为：\n");
	for(i = 0; i < n; i++)
	{
		printf("x%d=%4.4f\n", i, *(matrix_result + i));
	}
	printf("\n");
}
