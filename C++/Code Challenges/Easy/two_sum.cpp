#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/two-sum/
vector<int> twoSum(vector<int>& nums, int target);

int main(){
    vector<int> num {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(num,target);

    for(auto index: result)
        cout << index << " ";

    return 0;
}

vector<int> twoSum(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++){
        for(int j = (i + 1); j < nums.size(); j++){
            if(nums[i]+nums[j] == target){
                vector<int> results {i,j};
                return results;
            }
        }
    }
    return {};
}