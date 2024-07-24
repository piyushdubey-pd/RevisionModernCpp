#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[]={2,7,11,13};
    int target=9;

    vector<int> ans;
    unordered_set<int> temp;
    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        temp.insert(arr[i]);
    }
    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        if (temp.find(target - arr[i]) == temp.end()){
            continue;
        }
        else{
            ans.push_back(i);
        }
    }
    for (int i=0;i<ans.size();i++){
    cout << ans[i] <<endl;
    }
}