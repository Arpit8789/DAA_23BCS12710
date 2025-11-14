#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount; 
    int count = 0, sum = 0;

    prefixSumCount[0] = 1; 

    for (int num : nums) {
        sum += num; 

        
        if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            count += prefixSumCount[sum - k];
        }

        
        prefixSumCount[sum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, -2, 5}; 
    int k = 5;

    cout << "Number of subarrays with sum " << k << " is: " << subarraySum(nums, k) << endl;
    return 0;
}