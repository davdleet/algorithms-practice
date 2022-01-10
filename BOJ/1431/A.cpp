#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool custom_sort(string a, string b){
    if(a.size() != b.size()){
        return a.size() < b.size();
    }
    else{
        int sum_a = 0;
        int sum_b = 0;
        for(int i = 0 ; i < a.size(); i++){
            if(isdigit(a[i])){
                sum_a += a[i] - '0';
            }
        }
        for(int i = 0 ; i < b.size(); i++){
            if(isdigit(b[i])){
                sum_b += b[i] - '0';
            }
        }
        if(sum_a != sum_b){

            return sum_a < sum_b;
        }
        else{
           return a < b;
        }
    }
}

int main(){
    //freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie();
    int N;
    cin >> N;
    vector <string> arr;
    for(int i = 0 ; i < N; i++){
        string temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), custom_sort);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }
}