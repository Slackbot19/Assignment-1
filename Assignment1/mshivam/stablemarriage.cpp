#include <queue>
#include <iostream>
using namespace std;

int Ranking[1000][1000], ManPref[1000][1000], WomanPref[1000][1000], Next[1000], Current[1000];

int main()  {
    int N, i, j, m, w;
    queue <int> freeMen;    
        cin>>N;
        for (w=1;w<=N;w++) {
            for (j = 1; j <= N; j++)
                cin>>WomanPref[w][j];              
        }
        for (m=1; m<=N;m++) {
            for (j = 1; j <= N; j++){
                cin>>ManPref[m][j];
                ManPref[m][j]++;
            }
        }
        for (i = 1; i <= N; i++)
            for (j = 1; j <= N; j++)
                Ranking[i][WomanPref[i][j]] = j;
        for (i = 1; i <= N; i++) {
            freeMen.push(i);
            Next[i] = 1;
        }

        while (!freeMen.empty())    {
            m = freeMen.front();
            w = ManPref[m][Next[m]++];
            if (Current[w] == 0)   {
                Current[w] = m;
                freeMen.pop();
            } else if (Ranking[w][m] < Ranking[w][Current[w]])  {
                freeMen.pop();
                freeMen.push(Current[w]);
                Current[w] = m;
            }
        }
        cout<<"Women Men\n";
        for (w = 1; w <= N; w++)
            cout<<w+(N-1)<<"     "<<Current[w]-1<<"\n";
    return 0;
}