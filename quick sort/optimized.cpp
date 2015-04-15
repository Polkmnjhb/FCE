#include <stdio.h>
#include <stdlib.h> //for rand(),srand()
#include <time.h> //for time(NULL)
//for test time 
#include <iostream>
#include <iomanip>
#include <windows.h>
//for test time
/* #include <algorithm> �ֳ̧t��sort */

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
	//�}�l���ծɶ� 
    LARGE_INTEGER startTime,endTime,fre;
    double times;
    QueryPerformanceFrequency(&fre); //���oCPU�W�v
    QueryPerformanceCounter(&startTime); //���o�}����{�b�g�L�X��CPU Cycle
    //doing something
    int size = 80000; //data ���ƶq 
	int *arr = (int*)malloc (sizeof(int)*size);
	random(arr,2147483647,size); //���ͤ@��data�ƶq���H���}�C 
    //doing something
    QueryPerformanceCounter(&endTime); //���o�}����{�����槹���g�L�X��CPU Cycle
    times=((double)endTime.QuadPart-(double)startTime.QuadPart)/fre.QuadPart;
    cout << fixed << setprecision(20) << times << 's' << endl;
	//�������ծɶ� 

	//�}�l���ծɶ� 
    LARGE_INTEGER startTime2,endTime2,fre2;
    double times2;
    QueryPerformanceFrequency(&fre2); //���oCPU�W�v
    QueryPerformanceCounter(&startTime2); //���o�}����{�b�g�L�X��CPU Cycle
    //doing something
/*	sort(arr, arr + size); //�ֳ̧t��sort */
	sort(arr,0,size); //�ֳt�Ƨǰ}�C  
    //doing something
    QueryPerformanceCounter(&endTime2); //���o�}����{�����槹���g�L�X��CPU Cycle
    times2=((double)endTime2.QuadPart-(double)startTime2.QuadPart)/fre2.QuadPart;
    cout << fixed << setprecision(20) << times2 << 's' << endl;
	//�������ծɶ� 

	//�}�l���ծɶ� 
    LARGE_INTEGER startTime3,endTime3,fre3;
    double times3;
    QueryPerformanceFrequency(&fre3); //���oCPU�W�v
    QueryPerformanceCounter(&startTime3); //���o�}����{�b�g�L�X��CPU Cycle
    //doing something
	write(arr,size); //�L�X���G 
    //doing something
    QueryPerformanceCounter(&endTime3); //���o�}����{�����槹���g�L�X��CPU Cycle
    times3=((double)endTime3.QuadPart-(double)startTime3.QuadPart)/fre3.QuadPart;
    cout << fixed << setprecision(20) << times3 << 's' << endl;
	//�������ծɶ� 
	free(arr); //����O���� 
    system("pause");
    return 0;
    
}
