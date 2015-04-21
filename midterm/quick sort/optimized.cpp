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

//SWAP 副程式用來交換兩個元素的位置
//INPUT 兩個需要交換位置的元素 
//用INLINE(行內函式) 有機會縮短時間 
inline void swap(int *a, int *b)
{
  int t=*a; *a=*b; *b=t;
}

//RANDOM 副程式用來製造隨機陣列
//INPUT 1.陣列名稱  2.隨機值的最大值 3.陣列元素個數 
void random(int arr[],int MaxValue,int number)
{
	int a;
	srand(time(NULL));
	for(int i=0;i<number;i++)
	{
		a=(10000*rand()+rand()%9999)%MaxValue+1;
		arr[i]=a;
	}
}

//WRITE 副程式用來記錄排序後的結果 並將結果存為一個TXT檔案 
//INPUT 1.要列印的陣列名稱  2.陣列元素個數 
void write(int arr[],int number)
{
	FILE *fp;
	fp=fopen("Result.txt","w");
	for(int i=0;i<number;i++)
	fprintf(fp,"[%d]=%d \n",i,arr[i]);	
	fclose(fp);
}

//SORT 副程式使用快速排序法來排序一個陣列
//此寫法不會造成無效步驟 所以很快!
//INPUT 1.要排序的陣列名稱  2.開始排序的位置  3.結束排序的位置 
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
    int size = 0; //data 的元素個數 
	int maximum = 0; //data的最大值
    printf("請輸入元素個數(整數)! \n");  
	scanf("%d",&size); //由使用者輸入個數  
    printf("請輸入元素最大值(整數)! \n");  
	scanf("%d",&maximum); //由使用者輸入最大值 
	//開始測試 Input 時間 
    LARGE_INTEGER startTime,endTime,fre;
    double times; //宣告實數用來存經過時間 
    QueryPerformanceFrequency(&fre); //取得CPU頻率
    QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
    //doing something
 	int *arr = (int*)malloc (size*sizeof(int)); //宣告data的陣列 使用動態配置 每一個元素用int型態的大小去存它 
	random(arr,maximum,size); //產生一個data個數的隨機陣列 
    //doing something
    QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
    times=((double)endTime.QuadPart-(double)startTime.QuadPart)/fre.QuadPart;
    cout <<"總共 INPUT 時間: "<< fixed << setprecision(20) << times << 's' << endl; //印出所花時間 
	//結束測試 Input 時間 

	//開始測試 Sort 時間 
    LARGE_INTEGER startTime2,endTime2,fre2;
    double times2; //宣告實數用來存經過時間 
    QueryPerformanceFrequency(&fre2); //取得CPU頻率
    QueryPerformanceCounter(&startTime2); //取得開機到現在經過幾個CPU Cycle
    //doing something
/*	sort(arr, arr + size); //最快速的sort */
	sort(arr,0,size); //快速排序陣列  
    //doing something
    QueryPerformanceCounter(&endTime2); //取得開機到程式執行完成經過幾個CPU Cycle
    times2=((double)endTime2.QuadPart-(double)startTime2.QuadPart)/fre2.QuadPart;
    cout <<"總共 SORT 時間: "<< fixed << setprecision(20) << times2 << 's' << endl; //印出所花時間 
	//結束測試 Sort 時間 

	//開始測試 Output 時間 
    LARGE_INTEGER startTime3,endTime3,fre3;
    double times3; //宣告實數用來存經過時間 
    QueryPerformanceFrequency(&fre3); //取得CPU頻率
    QueryPerformanceCounter(&startTime3); //取得開機到現在經過幾個CPU Cycle
    //doing something
	write(arr,size); //印出結果 
    //doing something
    QueryPerformanceCounter(&endTime3); //取得開機到程式執行完成經過幾個CPU Cycle
    times3=((double)endTime3.QuadPart-(double)startTime3.QuadPart)/fre3.QuadPart;
    cout <<"總共 OUTPUT 時間: "<< fixed << setprecision(20) << times3 << 's' << endl; //印出所花時間 
	//結束測試 Output 時間 
	free(arr); //釋放記憶體 
	
    system("pause");
    return 0;
    
}
