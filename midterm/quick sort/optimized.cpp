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

//SWAP �Ƶ{���Ψӥ洫��Ӥ�������m
//INPUT ��ӻݭn�洫��m������ 
//��INLINE(�椺�禡) �����|�Y�u�ɶ� 
inline void swap(int *a, int *b)
{
  int t=*a; *a=*b; *b=t;
}

//RANDOM �Ƶ{���Ψӻs�y�H���}�C
//INPUT 1.�}�C�W��  2.�H���Ȫ��̤j�� 3.�}�C�����Ӽ� 
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

//WRITE �Ƶ{���ΨӰO���Ƨǫ᪺���G �ñN���G�s���@��TXT�ɮ� 
//INPUT 1.�n�C�L���}�C�W��  2.�}�C�����Ӽ� 
void write(int arr[],int number)
{
	FILE *fp;
	fp=fopen("Result.txt","w");
	for(int i=0;i<number;i++)
	fprintf(fp,"[%d]=%d \n",i,arr[i]);	
	fclose(fp);
}

//SORT �Ƶ{���ϥΧֳt�ƧǪk�ӱƧǤ@�Ӱ}�C
//���g�k���|�y���L�ĨB�J �ҥH�ܧ�!
//INPUT 1.�n�ƧǪ��}�C�W��  2.�}�l�ƧǪ���m  3.�����ƧǪ���m 
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
    int size = 0; //data �������Ӽ� 
	int maximum = 0; //data���̤j��
    printf("�п�J�����Ӽ�(���)! \n");  
	scanf("%d",&size); //�ѨϥΪ̿�J�Ӽ�  
    printf("�п�J�����̤j��(���)! \n");  
	scanf("%d",&maximum); //�ѨϥΪ̿�J�̤j�� 
	//�}�l���� Input �ɶ� 
    LARGE_INTEGER startTime,endTime,fre;
    double times; //�ŧi��ƥΨӦs�g�L�ɶ� 
    QueryPerformanceFrequency(&fre); //���oCPU�W�v
    QueryPerformanceCounter(&startTime); //���o�}����{�b�g�L�X��CPU Cycle
    //doing something
 	int *arr = (int*)malloc (size*sizeof(int)); //�ŧidata���}�C �ϥΰʺA�t�m �C�@�Ӥ�����int���A���j�p�h�s�� 
	random(arr,maximum,size); //���ͤ@��data�Ӽƪ��H���}�C 
    //doing something
    QueryPerformanceCounter(&endTime); //���o�}����{�����槹���g�L�X��CPU Cycle
    times=((double)endTime.QuadPart-(double)startTime.QuadPart)/fre.QuadPart;
    cout <<"�`�@ INPUT �ɶ�: "<< fixed << setprecision(20) << times << 's' << endl; //�L�X�Ҫ�ɶ� 
	//�������� Input �ɶ� 

	//�}�l���� Sort �ɶ� 
    LARGE_INTEGER startTime2,endTime2,fre2;
    double times2; //�ŧi��ƥΨӦs�g�L�ɶ� 
    QueryPerformanceFrequency(&fre2); //���oCPU�W�v
    QueryPerformanceCounter(&startTime2); //���o�}����{�b�g�L�X��CPU Cycle
    //doing something
/*	sort(arr, arr + size); //�ֳ̧t��sort */
	sort(arr,0,size); //�ֳt�Ƨǰ}�C  
    //doing something
    QueryPerformanceCounter(&endTime2); //���o�}����{�����槹���g�L�X��CPU Cycle
    times2=((double)endTime2.QuadPart-(double)startTime2.QuadPart)/fre2.QuadPart;
    cout <<"�`�@ SORT �ɶ�: "<< fixed << setprecision(20) << times2 << 's' << endl; //�L�X�Ҫ�ɶ� 
	//�������� Sort �ɶ� 

	//�}�l���� Output �ɶ� 
    LARGE_INTEGER startTime3,endTime3,fre3;
    double times3; //�ŧi��ƥΨӦs�g�L�ɶ� 
    QueryPerformanceFrequency(&fre3); //���oCPU�W�v
    QueryPerformanceCounter(&startTime3); //���o�}����{�b�g�L�X��CPU Cycle
    //doing something
	write(arr,size); //�L�X���G 
    //doing something
    QueryPerformanceCounter(&endTime3); //���o�}����{�����槹���g�L�X��CPU Cycle
    times3=((double)endTime3.QuadPart-(double)startTime3.QuadPart)/fre3.QuadPart;
    cout <<"�`�@ OUTPUT �ɶ�: "<< fixed << setprecision(20) << times3 << 's' << endl; //�L�X�Ҫ�ɶ� 
	//�������� Output �ɶ� 
	free(arr); //����O���� 
	
    system("pause");
    return 0;
    
}
