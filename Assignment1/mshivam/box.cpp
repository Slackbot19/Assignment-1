#include <bits/stdc++.h>
using namespace std;


struct box
{
   int h,w,d;
};


int comparision(const void *a, const void *b)
{
   return ((*(box *)b).d*(*(box *)b).w) - ((*(box *)a).d*(*(box *)a).w) ; 
}

int maxHeight(box a[],int n)
{
   box orientation[3*n];
   int index=0,maximum;
   for(int i=0;i<n;++i)
   {
      orientation[index++]=a[i];
    
      orientation[index].h=a[i].d;   
      orientation[index].d=max(a[i].h,a[i].w);
      orientation[index++].w=min(a[i].h,a[i].w);
      
      orientation[index].h=a[i].w;   
      orientation[index].d=max(a[i].h,a[i].d);
      orientation[index++].w=min(a[i].h,a[i].d);
   }   
   n*=3;
   qsort(orientation,n,sizeof(box),comparision);
   
   int hmax[n];
   
   for(int i=0;i<n;++i)
      hmax[i]=orientation[i].h;
      
   for(int i=1;i<n;++i)   
      for(int j=0;j<i;++j)
         if((orientation[i].w<orientation[j].w && orientation[i].d<orientation[j].d 
            || orientation[j].d>orientation[i].w && orientation[j].w>orientation[i].d) 
            &&hmax[i]<hmax[j]+orientation[i].h ) 
               hmax[i]=hmax[j]+orientation[i].h;
   maximum=hmax[0];
   for(int i=1;i<n;++i)
      if(maximum<hmax[i])
         maximum=hmax[i];
   return maximum;   
}

   
int main()
{
    int N;
    cin>>N;
    box stack[N];
    for(int i = 0;i<N;i++)
    {
       cin>>stack[i].w>>stack[i].d>>stack[i].h;
    }
    cout << "Maximum height =" << maxHeight(stack, N);
    return 0;
}