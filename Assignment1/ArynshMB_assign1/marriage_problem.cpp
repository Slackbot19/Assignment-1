#include<iostream>
#include<math.h>
 using namespace std;

 int main()
 {
     int a,i,j,n,c,d,q,flag,b,k,e,flag1;
     c=0;
     q=0;
     flag=0;
     flag1=0;



 cout<<"enter the number of marriage pairs to be formed"<<endl;
 cin>>n;

 a=2*n;

 int arr[a][n];
int arr1[a][n];
int arr2[10];
 cout<<"enter preferences"<<endl;

 for(i=0;i<a;++i)

 { cout<<endl;

     for(j=0;j<n;++j)
     {
         cin>>arr[i][j];
     }

 }

 cout<<"the prefernces matrix is "<<endl;

  for(i=0;i<a;++i)
 { cout<<endl;

     for(j=0;j<n;++j)
     {
         cout<<arr[i][j];
     }

 }
 cout<<endl;

for(k=0;k<n;++k)
{
 for(j=0;j<n;++j)
 {

 for(i=0;i<n;++i)
 {   if(c!=0)
     {
         while(d<c)
     {
         if(arr2[d]==i)
         {
             flag=1;
             break;
         }


         ++d;
     }
     }

     if(flag!=1)
     {

     b=arr[i][k];
     if(c!=0)
     {
         while(e<c)
     {
         if(arr2[e]==b)
         {
             flag1=1;
             break;
         }


         ++e;
     }
     }

     if(flag1!=1)
     {
     if(arr[b][j]==i)
     {
         cout<<endl;
         cout<<b<<" "<<i<<endl;
         arr2[c]=i;
         arr2[++c]=b;
         c=c+1;
     }
     }
     }

  flag=0;
  d=0;
  flag1=0;
  e=0;

 }



 }
}


 }




