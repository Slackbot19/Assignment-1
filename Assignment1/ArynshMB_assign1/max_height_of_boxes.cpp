#include<iostream>
 using namespace std;

 int main()
 {   int i=0;
     int j=0;
     int n;
     int s,t;
     int d,x;

 int inp[100][100];
 	 int out[100][100];
     cout<<"enter how many different dimensions will you give?"<<endl;
     cin>>n;
 	cout<<"enter the dimensions"<<endl;


    int b=n*6;
   int m=0;

 	for(j=0;j<n;++j)
 	{
 		for(i=0;i<3;++i)
 		{
 			cin>>inp[j][i];

 		}

       out[m][0]=inp[j][0];
      
       out[m][1]=inp[j][1];
       s=out[m][1];
       out[m][2]=inp[j][2];
       t=out[m][2];
       out[m][3]=s*t;
       
       
       

       
       m=m+1;
       out[m][0]=inp[j][0];
       out[m][1]=inp[j][2];
       s=out[m][1];
       out[m][2]=inp[j][1];
       t=out[m][2];
       out[m][3]=s*t;

 	
         m=m+1;
        out[m][0]=inp[j][1];
       out[m][1]=inp[j][0];
       s=out[m][1];
       out[m][2]=inp[j][2];
       t=out[m][2];
       out[m][3]=s*t;
       

  
       m=m+1;
       out[m][0]=inp[j][1];
       out[m][1]=inp[j][2];
       s=out[m][1];
       out[m][2]=inp[j][0];
       t=out[m][2];
       out[m][3]=s*t;
 
        m=m+1;
        out[m][0]=inp[j][2];
       out[m][1]=inp[j][0];
       s=out[m][1];
       out[m][2]=inp[j][1];
       t=out[m][2];
       out[m][3]=s*t;
       
       m=m+1;
       out[m][0]=inp[j][2];
       out[m][1]=inp[j][1];
       s=out[m][1];
       out[m][2]=inp[j][0];
       t=out[m][2];
       out[m][3]=s*t;

       m=m+1;
 	}

    int fin[100][100];
    int temp1[4];
    int swap[4];
    int area;
    
    int q=0;

 	for(int j=0;j<b;j++)
 	{

 		if(out[j][1]<out[j][2])
 		{   
 			fin[q][0]=out[j][0];
            fin[q][1]=out[j][1];
            fin[q][2]=out[j][2];
            fin[q][3]=out[j][3];
            q=q+1;
            
 		}
 	}
 	
 	d=q;
 
 	 for(i=0;i<q;++i)
 	 { 
 	     area=fin[i][3];
 	     
 	     for(int j=i;j<q;++j)
 	     {

 	          if(fin[j][3]>=area)
 		        {   
 			      area=fin[j][3];
 			      x=j;
 		         }
 	       }
 	       
 	        swap[0]=fin[i][0];
            swap[1]=fin[i][1];
            swap[2]=fin[i][2];
            swap[3]=fin[i][3];
 			
 			
            fin[i][0]=fin[x][0];
            fin[i][1]=fin[x][1];
            fin[i][2]=fin[x][2];
            fin[i][3]=fin[x][3];
            
            fin[x][0]=swap[0];
            fin[x][1]=swap[1];
            fin[x][2]=swap[2];
            fin[x][3]=swap[3];
 	 }
  
   int sum; 
   int height=0;
   int f=0;
   
 for(i=0;i<d;++i)
 { sum=fin[i][0];
  	 for(j=1+i;j<d;j++)
 	 {
 	     if(fin[j][1]<fin[f][1] && fin[j][2]<fin[f][2])
 	     { sum=sum+fin[j][0];
 	         f=j;
 	     }
 	 }
 	 
 	 if(sum>height)
 	 {height=sum;}
 }	
 
    cout<<endl;
    cout<<endl;
    if(height==0)
    {cout<<"no height possible"<<endl;
    }
    
    else
    cout<<" max height is : "<<height<<endl;
 	
 	
 
 	
 }





