#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// ou are given an array of integers representing a stream of incoming numbers. Your task is to process these numbers and return a final list based on the following rules:
// 	1.	Maintain Insertion Order & Uniqueness:
// •	Process numbers one by one.
// •	If a number has not been seen before, add it to your final sequence.
// •	If a number has already been seen, ignore it.
// 	2.	Special Operations:
// •	If the number is -1, remove the most recently added unique number from your final sequence (if any exists).
// •	If the number is -2, remove the first added unique number from your final sequence (if any exists).
// 📥 Input Example
// nums = [10, 20, 10, 30, -1, 40, 20, -2, 50]
// 📤 Expected Output
// [30, 40, 50]
int main() {
    vector<int> vector={10, 20, 10, 30, -1, 40, 20, -2, 50};
    queue<int> set;
    for(auto it:vector){
        if(it==1){
            
        }
        set.push(it);
    }

    // for(auto sit:set)cout<<sit<<endl;
    






    return 0;
}