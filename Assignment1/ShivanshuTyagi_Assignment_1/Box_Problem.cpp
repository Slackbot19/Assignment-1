#include <bits/stdc++.h>
using namespace std;

typedef struct a{
    int h;
    int w;
    int d;
    int BArea;
} box;

void sort(box* a,int n){
    for(int i=0;i<3*n;i++)
	{		
		for(int j=i+1;j<3*n;j++)
		{
			if(a[i].BArea>a[j].BArea)
			{
				box temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

int main(){
    int n;
    cout<<"Enter the number of boxes"<<endl;
    cin>>n; 
    
    cout<<"Enter the dimention of boxes as a 3 X N grid"<<endl;
    box boxes_t[n];
    for(int i=0;i<n;i++){
        cin>>boxes_t[i].h>>boxes_t[i].w>>boxes_t[i].d;
        boxes_t[i].BArea = boxes_t[i].w * boxes_t[i].d;
    }
    
    box boxes[3*n];
    for(int i=0;i<n;i++){
        boxes[i*3].h = boxes_t[i].h;
        boxes[i*3].w = (boxes_t[i].w<boxes_t[i].d) ? boxes_t[i].w:boxes_t[i].d;
        boxes[i*3].d = (boxes_t[i].w>boxes_t[i].d) ? boxes_t[i].w:boxes_t[i].d;
        boxes[i*3].BArea = boxes[i*3].d * boxes[i*3].w;
        
        boxes[i*3+1].h = boxes_t[i].w;
        boxes[i*3+1].w = (boxes_t[i].h<boxes_t[i].d) ? boxes_t[i].h:boxes_t[i].d;
        boxes[i*3+1].d = (boxes_t[i].h>boxes_t[i].d) ? boxes_t[i].h:boxes_t[i].d;
        boxes[i*3+1].BArea = boxes[i*3+1].d * boxes[i*3+1].w;
        
        boxes[i*3+2].h = boxes_t[i].d;
        boxes[i*3+2].w = (boxes_t[i].w<boxes_t[i].h) ? boxes_t[i].w:boxes_t[i].h;
        boxes[i*3+2].d = (boxes_t[i].w>boxes_t[i].h) ? boxes_t[i].w:boxes_t[i].h;
        boxes[i*3+2].BArea = boxes[i*3+2].d * boxes[i*3+2].w;
        
    }
    
    sort(boxes,n);
    
    int P_W=boxes[3*n-1].w;
    int P_D=boxes[3*n-1].d;
    int sum=boxes[3*n-1].h;
    for(int i=3*n-2;i>=0;i--){
        if(boxes[i].w<P_W && boxes[i].d<P_D){
            sum+=boxes[i].h;
            P_W = boxes[i].w;
            P_D = boxes[i].d;
        }
    }

    cout<<"The required Height of the Stack of Boxes is : ";
    cout<<sum;
}