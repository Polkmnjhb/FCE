#include <stdio.h>
#include <stdlib.h> //for rand(),srand()
#include <time.h> //for time(NULL)
//for test time 
#include <iostream>
#include <iomanip>
#include <windows.h>
//for test time
/* #include <algorithm> 最快速的sort */

using namespace std;

inline void swap(int *a, int *b)
{
  int t=*a; *a=*b; *b=t;
}

void random(int arr[],int MaxValue,int number)
{
	int a;
	srand(time(NULL));
	for(int i=0;i<number+1;i++)
	{
		a=10000*rand()%MaxValue+rand()%9999;
		arr[i]=a;
	}
}

void write(int arr2[],int max)
{
	FILE *fp;
	fp=fopen("Result.txt","w");
	for(int i=0;i<max;i++)
	fprintf(fp,"[%d]=%d \n",i,arr2[i]);	
	fclose(fp);
}
void sort(int arr[], int beg, int end)
{
  if (end > beg + 1)
  {
    int piv = arr[beg], l = beg + 1, r = end;
    while (l < r)
    {
      if (arr[l] <= piv)
        l++;
      else
        swap(&arr[l], &arr[--r]);
    }
    swap(&arr[--l], &arr[beg]);
    sort(arr, beg, l);
    sort(arr, r, end);
  }
}


int main()
{
	//開始測試時間 
    LARGE_INTEGER startTime,endTime,fre;
    double times;
    QueryPerformanceFrequency(&fre); //取得CPU頻率
    QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
    //doing something
    int size = 80000; //data 的數量 
	int *arr = (int*)malloc (sizeof(int)*size);
	random(arr,2147483647,size); //產生一個data數量的隨機陣列 
    //doing something
    QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
    times=((double)endTime.QuadPart-(double)startTime.QuadPart)/fre.QuadPart;
    cout << fixed << setprecision(20) << times << 's' << endl;
	//結束測試時間 

	//開始測試時間 
    LARGE_INTEGER startTime2,endTime2,fre2;
    double times2;
    QueryPerformanceFrequency(&fre2); //取得CPU頻率
    QueryPerformanceCounter(&startTime2); //取得開機到現在經過幾個CPU Cycle
    //doing something
/*	sort(arr, arr + size); //最快速的sort */
	sort(arr,0,size); //快速排序陣列  
    //doing something
    QueryPerformanceCounter(&endTime2); //取得開機到程式執行完成經過幾個CPU Cycle
    times2=((double)endTime2.QuadPart-(double)startTime2.QuadPart)/fre2.QuadPart;
    cout << fixed << setprecision(20) << times2 << 's' << endl;
	//結束測試時間 

	//開始測試時間 
    LARGE_INTEGER startTime3,endTime3,fre3;
    double times3;
    QueryPerformanceFrequency(&fre3); //取得CPU頻率
    QueryPerformanceCounter(&startTime3); //取得開機到現在經過幾個CPU Cycle
    //doing something
	write(arr,size); //印出結果 
    //doing something
    QueryPerformanceCounter(&endTime3); //取得開機到程式執行完成經過幾個CPU Cycle
    times3=((double)endTime3.QuadPart-(double)startTime3.QuadPart)/fre3.QuadPart;
    cout << fixed << setprecision(20) << times3 << 's' << endl;
	//結束測試時間 
	free(arr); //釋放記憶體 
    system("pause");
    return 0;
    
}
