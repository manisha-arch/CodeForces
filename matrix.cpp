#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

  int a[5][5];
   for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
        cin>>a[i][j];
    }
   }
   for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
        if(a[i][j]==1){
            int moves=abs(i-2)+abs(j-2);
            cout<<moves<<endl;
            
        }
    }
}
    

    return 0;
}
