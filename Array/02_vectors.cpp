#include <iostream>
#include <vector>
using namespace std;


    int maink() {
    vector<int> practiceVector={1,2,3,4,5};
    
    practiceVector.push_back(5);
    for(int val:practiceVector)cout<<val<<" ";
    cout<<endl;
    practiceVector.pop_back();
    for(int val:practiceVector)cout<<val<<" ";
    cout<<endl;
    cout<<practiceVector.front();
    cout<<endl;
    cout<<practiceVector.back();
    cout<<endl;
    cout<<practiceVector.at(2);

    // for(int val:practiceVector)cout<<val<<" ";
    
    return 0;
}