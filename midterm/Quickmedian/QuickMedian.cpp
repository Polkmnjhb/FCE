#include <stdio.h>
#include <stdlib.h> //for rand(),srand()
#include <time.h> //for time(NULL)
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

//SWAP �Ƶ{���Ψӥ洫��Ӥ�������m
//INPUT ��ӻݭn�洫��m���������� 
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
		printf("arr[%d]=%d \n",i,a);
	}
	system("pause");
}

//SORT �Ƶ{����beg��m���ȱƧǡA�æ^�ǸӦ�m
//INPUT 1.�}�C�W��  2.�_�I��m 3.���I��m 
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
	return l; //�^�� piv=beg �Ƨǫ᪺��m 
}

//MEDIAN �Ƶ{���p��æ^�Ǥ���ƪ���
//INPUT 1.�}�C�W��  2.�_�I��m 3.���I��m 
int median(int arr[],int beg,int end)
{
	int median=(end-1)/2; //�p�⤤��ƸӦb���Ӧ�m 
	int key=sort(arr,beg,end); //key�ΨӧP�_�ӭȬO�_������� 
	while (key != median)
	{
		if(key < median) //�p�Gkey����m�񤤦�Ƥp �q key+1 �� end ��m�䤤��� 
		beg=key+1;
		else if (key > median) //�p�Gkey����m�񤤦�Ƥj �q beg �� key ��m�䤤��� 
		end=key;
		key=sort(arr,beg,end);
	}
return arr[median]; //�^�Ǥ���ƭ� 
}


int main()
{
    int size = 0; //data �������Ӽ� 
	int maximum = 0; //data���̤j��
    printf("�п�J�����Ӽ�(�_��)! \n");  
	scanf("%d",&size); //�ѨϥΪ̿�J�Ӽ�  
    printf("�п�J�����̤j��(���)! \n");  
	scanf("%d",&maximum); //�ѨϥΪ̿�J�̤j�� 
 	int *arr = (int*)malloc (size*sizeof(int)); //�ŧidata���}�C �ϥΰʺA�t�m �C�@�Ӥ�����int���A���j�p�h�s�� 
	random(arr,maximum,size); //���ͤ@��data�Ӽƪ��H���}�C 
	printf("median=%d \n",median(arr,0,size)); //�M�䤤��� 
	free(arr); //����O���� 
    system("pause");
    return 0;
    
}
