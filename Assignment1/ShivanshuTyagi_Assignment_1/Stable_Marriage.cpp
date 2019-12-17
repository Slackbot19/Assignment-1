#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of couples : "<<endl;
    cin>>n;
    cout<<"Enter the preference of the couples in the specified format : "<<endl;
    int pref[2*n][n];
    for(int i=0;i<n*2;i++){
        for(int j=0;j<n;j++){
            cin>>pref[i][j];
        }
    }
    
    int Partner_of_W[n]; 
    bool Nalle_Launde[n]; 
    memset(Partner_of_W, -1, sizeof(Partner_of_W)); 
    memset(Nalle_Launde, false, sizeof(Nalle_Launde)); 
    int rem = n; 
    while (rem > 0) { 
        int m; 
        for (m = 0; m < n; m++) 
            if (Nalle_Launde[m] == false) 
                break; 
        for (int i = 0; i < n && Nalle_Launde[m] == false; i++){ 
            int w = pref[m][i];
            if (Partner_of_W[w-n] == -1){ 
                Partner_of_W[w-n] = m; 
                Nalle_Launde[m] = true; 
                rem--; 
            }
            else{
                int m1 = Partner_of_W[w-n];
                bool flag;
                for (int i = 0; i < n; i++){ 
                    if (pref[w][i] == m1) 
                        flag = true; 
                    if (pref[w][i] == m) 
                        flag = false; 
                    } 
                if (flag == false){ 
                    Partner_of_W[w-n] = m; 
                    Nalle_Launde[m] = true; 
                    Nalle_Launde[m1] = false; 
                } 
            }
        }
    }
    cout<<"The required pairing of couples is : "<<endl;
    cout <<"Woman       Man"<< endl; 
    for (int i = 0; i < n; i++) 
       cout << " " << i+n << "\t" << Partner_of_W[i] << endl; 
    return 0; 
} 