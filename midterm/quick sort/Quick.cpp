#include<iostream>
#include<cstdlib>

using namespace std;
void perm(char *ch,int a,int b);

    int n;
    int c=0;

int main()
{
    cout << "enter a number you want to perm : "<<endl;
    cin >> n;
    char list[n];
    cout << "and type "<< n << " alphat, for example 4 > a b c d." <<endl;
    for(int i=0;i<n;i++)
            cin >> list[i];
    
    perm(list,0,n-1);
    cout << c <<" type for " << n << " permutation"<<endl;
    system("pause");
    return 0;
}

void perm(char *ch,int a,int b)
{
     if(a==b)
     {
             for(int i=0;i<n;i++)
                     cout << ch[i];
             cout << endl;
             c++;
     }
     else
         for(int j=a;j<n;j++)
         {        
                  swap(ch[a],ch[j]);
                  perm(ch,a+1,b);
                  swap(ch[a],ch[j]);
         }
}

