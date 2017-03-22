#include<iostream>
using namespace std;

void max_crossing_subarray(int a[],int low,int mid,int high)
{
	
	int left_sum=-255;//define infinitesimal
	int right_sum=-255;///define infinitesimax
	int max_left,max_right; 
	int sum1=0;
	int sum2=0;
	for(int i=mid;i>=low;i--){
		sum1=sum1+a[i];
		if(sum1>left_sum) 
		{
			left_sum=sum1;
			max_left=i+1;
		}
	}
	for(int j=mid+1;j<high;j++){
		sum2=sum2+a[j];
		if(sum2>right_sum){
			right_sum=sum2;
			max_right=j;
		}
	}
	cout <<"max_left:"<<max_left<<" max_right:"<<max_right<<" sum:"<<left_sum+right_sum<<endl;
}
int main()
{
	int A[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	max_crossing_subarray(A,0,7,16);
 	return 0;
}

