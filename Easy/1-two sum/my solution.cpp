#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
//version 1  暴力搜索  96ms
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> indices;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }   
    }
};
//version 2 hash
static int lambda_0 = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int remainder = target - nums[i];
            
            if (mp.find(remainder) != mp.end()) {
                return vector<int>{i, mp.at(remainder)};
            }
            
            mp[nums[i]] = i;
        }
    }
};