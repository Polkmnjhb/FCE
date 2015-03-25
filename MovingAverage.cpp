#include <stdio.h> //標準的輸入輸出 
#include <math.h>  //數學系學到的函數 

void graduated_problem(int N)
{
	//變數宣告區
	int i,j,k; //i,j,k \in Z
	double a,b,c;  //a,b,c \in R
	double x[N],u[N]; //x,u is a vector;
	double A[N][N]; //A is a matrix;
	printf("graduated_problem(%d,%d) \n",N,K);
	// Moving average , example , K個平均
	/*
		u[0]=((x[0]+4*x[1]+6*x[2]+4*x[3]+x[4] )/ 16
		u[1]=((x[1]+4*x[2]+6*x[3]+4*x[4]+x[5] )/ 16
		...
		[1,4,6,4,1] -->FFT
		x --> FFT -->對應相乘 -->iFFT--> u
		
		思考u[0]-->u[1]
		u[1]=u[0]+(x[K]-x[0])/K
		思考u[1]-->u[2]
		u[2]=u[1]+(x[K+1]-x[1])/K
		...	General form
		u[i]=u[i-1]+(x[K+i-1]-x[i-1])/K
		... Given in program
		U[N-K] = (x[N-K]+...+x[N-1])		
	*/ 
	for(i=0;i<N;i++)
	{
		x[i]=cos(M_PI*i/N);
	}
	i = 0;
	u[i]=x[i];	 //step 0
	for(j=1;j<K;j++)
	{
		u[i]=u[i]+x[i+j];	
	}
	u[i]=u[i]/K;

	for(i=1;i<=N-K;i=i+1)
	{
		u[i]=u[i-1]+(x[K+i-1]-x[i-1])/K;
	}
	/*
	以上是university problem....
	(K-1)+2(N-1) 個加法 
	*/
}

void university_problem(int N,int K)
{
	//變數宣告區
	int i,j,k; //i,j,k \in Z
	double a,b,c;  //a,b,c \in R
	double x[N],u[N]; //x,u is a vector;
	double A[N][N]; //A is a matrix;
	printf("university_problem(%d,%d) \n",N,K);
	// Moving average , example , K個平均
	/*
		u[0]=(x[0]+x[1]+...+x[K-1])/K
		u[1]=(x[1]+x[2]+...+x[K])/K 
		u[2]=(x[2]+x[3]+...+x[K+1])/K 
		
		思考u[0]-->u[1]
		u[1]=u[0]+(x[K]-x[0])/K
		思考u[1]-->u[2]
		u[2]=u[1]+(x[K+1]-x[1])/K
		...	General form
		u[i]=u[i-1]+(x[K+i-1]-x[i-1])/K
		... Given in program
		U[N-K] = (x[N-K]+...+x[N-1])		
	*/ 
	for(i=0;i<N;i++)
	{
		x[i]=cos(M_PI*i/N);
	}
	i = 0;
	u[i]=x[i];	 //step 0
	for(j=1;j<K;j++)
	{
		u[i]=u[i]+x[i+j];	
	}
	u[i]=u[i]/K;

	for(i=1;i<=N-K;i=i+1)
	{
		u[i]=u[i-1]+(x[K+i-1]-x[i-1])/K;
	}
	/*
	以上是university problem....
	(K-1)+2(N-1) 個加法 
	*/
}


void youth_problem(int N,int K)
{
	//變數宣告區
	int i,j,k; //i,j,k \in Z
	double a,b,c;  //a,b,c \in R
	double x[N],u[N]; //x,u is a vector;
	double A[N][N]; //A is a matrix;
	printf("youth_problem(%d,%d) \n",N,K);
	for(i=0;i<N;i++)
	{
		x[i]=cos(M_PI*i/N);
	}
	for(i=0;i<=N-K;i=i+1)
	{
	/*
	step 0:u[i]=x[i];
	step 1:u[i]=x[i]+x[i+1]=u[i]+x[i+1]; 
	step 2:u[i]=x[i]+x[i+1]+x[i+2]=u[i]+x[i+2];
	...
	step j:u[i]=u[i]+x[i+j];
	*/
		u[i]=x[i];	 //step 0
		for(j=1;j<K;j++)
		{
			u[i]=u[i]+x[i+j];	
		}
		u[i]=u[i]/K;
	}
}


void children_problem(int N)
{
	//變數宣告區
	int i,j,k; //i,j,k \in Z
	double a,b,c;  //a,b,c \in R
	double x[N],u[N]; //x,u is a vector;
	double A[N][N]; //A is a matrix;
	
	/*Moving average , example , 七個平均
	u[0]=(x[0]+x[1]+x[2])/3 
	u[1]=(x[1]+x[2]+x[3])/3 
	u[2]=(x[2]+x[3]+x[4])/3 
	...
	u[i]=(x[i]+x[i+1]+x[i+2])/3
	...
	u[?]=(x[7]+x[8]+x[9])/3 
	*/
	for(i=0;i<N;i++)
	{
		x[i]=cos(M_PI*i/N);
		printf("Cx[%d]=%f\n",i,x[i]);
	}
	for(i=0;i<N-2;i++)	 
	{
		u[i]=(x[i]+x[i+1]+x[i+2])/3;
		printf("Cu[%d]=%f\n",i,u[i]);
	}
}

int main()
{
	//變數宣告區
	int i,j,k; //i,j,k \in Z
	double a,b,c;  //a,b,c \in R
	double x[10],u[10]; //x,u is a vector;
	double A[10][10]; //A is a matrix;
	
	/*Moving average , example , 七個平均
	u[0]=(x[0]+x[1]+x[2])/3 
	u[1]=(x[1]+x[2]+x[3])/3 
	u[2]=(x[2]+x[3]+x[4])/3 
	...
	u[i]=(x[i]+x[i+1]+x[i+2])/3
	...
	u[?]=(x[7]+x[8]+x[9])/3 
	*/
	for(i=0;i<10;i++)
	{
		x[i]=cos(i/10.0*M_PI);
		printf("x[%d]=%f\n",i,x[i]);
	}
	for(i=0;i<8;i++)	 
	{
		u[i]=(x[i]+x[i+1]+x[i+2])/3;
		printf("u[%d]=%f\n",i,u[i]);
	}
	
	children_problem(100);
	youth_problem(10,5);
	university_problem(50,10);
	return 0;
}

