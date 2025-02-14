#include <iostream>
#include <vector>
#include <unordered_set> // ✅ Required for unordered_set

using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            std::unordered_set<int> mySet; 
    
            for(int i = 0; i < nums.size(); i++) {
                if(mySet.find(nums[i]) == mySet.end()) {
                    mySet.insert(nums[i]); 
                }
                else {
                    mySet.erase(nums[i]); 
                }
            }
            return *mySet.begin();
        }
    };