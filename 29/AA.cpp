#include <iostream>

using namespace std;

int main(){
    //freopen("input.txt", "rt", stdin);
    int N;
    scanf("%d", &N);
    int count = 0;
    for(int i = 1; i < N+1; i++){
        int current = i;
        int leftover = current;
        int result = current;
        while(1){
            leftover = result % 10;
            result = result / 10;
            if(leftover == 3){
                count++;
            }
            else if(result == 0){
                break;
            }
        }
    }
    cout << count;
}