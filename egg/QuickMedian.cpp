#include <stdio.h>
#include <stdlib.h> //for rand(),srand()
#include <time.h> //for time(NULL)
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

//SWAP 副程式用來交換兩個元素的位置
//INPUT 兩個需要交換位置的元素指標 
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
		printf("arr[%d]=%d \n",i,a);
	}
	system("pause");
}

//SORT 副程式把beg位置的值排序，並回傳該位置
//INPUT 1.陣列名稱  2.起點位置 3.終點位置 
int sort(int arr[], int beg, int end)
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
	return l; //回傳 piv=beg 排序後的位置 
}

//MEDIAN 副程式計算並回傳中位數的值
//INPUT 1.陣列名稱  2.起點位置 3.終點位置 
int median(int arr[],int beg,int end)
{
	int median=(end-1)/2; //計算中位數該在哪個位置 
	int key=sort(arr,beg,end); //key用來判斷該值是否為中位數 
	while (key != median)
	{
		if(key < median) //如果key的位置比中位數小 從 key+1 到 end 位置找中位數 
		beg=key+1;
		else if (key > median) //如果key的位置比中位數大 從 beg 到 key 位置找中位數 
		end=key;
		key=sort(arr,beg,end);
	}
return arr[median]; //回傳中位數值 
}


int main()
{
    int size = 0; //data 的元素個數 
	int maximum = 0; //data的最大值
    printf("請輸入元素個數(奇數)! \n");  
	scanf("%d",&size); //由使用者輸入個數  
    printf("請輸入元素最大值(整數)! \n");  
	scanf("%d",&maximum); //由使用者輸入最大值 
 	int *arr = (int*)malloc (size*sizeof(int)); //宣告data的陣列 使用動態配置 每一個元素用int型態的大小去存它 
	random(arr,maximum,size); //產生一個data個數的隨機陣列 
	printf("median=%d \n",median(arr,0,size)); //尋找中位數 
	free(arr); //釋放記憶體 
    system("pause");
    return 0;
    
}
