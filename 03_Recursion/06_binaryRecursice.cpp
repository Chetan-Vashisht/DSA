// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;
// int binarySearch(vector<int>v,int s,int st,int end,int target){
//     int mid =st+end/2;
//     if (mid == target) return;
//     if(target<mid) binarySearch(v,s,st,mid-1,target);
//     else binarySearch(v,s,mid+1,end,target);
// }

// int main() {
//     vector<int>v ={1,2,3,4,5,6,7,9};
//     int s=v.size();
//     int target=3;
//     auto st=v.begin();
//     auto e=v.end();
//     cout<<binarySearch(v,s,v.begin(),)


// Leetcode
class Solution {
public:
    int binarySearch(vector<int>& arr, int size, int start, int end, int target) {
        if (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == target)
                return mid;
            if (target < arr[mid])
                return binarySearch(
                    arr, size, start, mid - 1,target) ;
            else return binarySearch(arr, size, mid +1, end,target);
        }
        return -1;
    }
    int search(vector<int>& arr, int target) {
        return binarySearch(arr, arr.size(), 0, arr.size()-1, target);
    }
};
    






//     return 0;
// }