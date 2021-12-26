#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[9] = {0};
int getn[9] = {0};
int check[9] = {0};
int help[9] = {0};

void fun(int cnt){
    if(cnt == m){
        for(int i =0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int start=0;
    int same = 0; 
    for(int i=start; i<n; i++){
        if(!check[i] && same != getn[i]){ // at the sort arr, past last == now last -> 중복
            check[i] = true;
            help[cnt] = i;
            arr[cnt] = getn[i];
            same = getn[i];
            fun(cnt +1);
            check[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> getn[i];
    }
    sort(getn, getn+n);
    fun(0);
    return 0;
}