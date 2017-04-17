#include<iostream>
#include<stdlib.h>
using namespace std;
int bottom_up_cut_rod(int p[],int n)
{
	int* r=(int*)malloc(sizeof(int)*(n+1));
	r[0]=0;
	int q;
	for(int j=1;j<=n;j++)
	{
		q=-255;
		for(int i=1;i<=j;i++)
		{
			if(q<=(p[i-1]+r[j-i])) q=p[i-1]+r[j-i];
			else q=q;
		}
		r[j]=q;
	}
	return r[n];
}
//bottom_up dynamic programming approach
int main()
{
	int p[]={1,5,8,9};
	int n=4;
	int optimal_solution;
	optimal_solution=bottom_up_cut_rod(p,n);
	cout<<"optimal solution:"<<optimal_solution<<endl;
	return 0;

}
