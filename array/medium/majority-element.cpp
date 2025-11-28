#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElementBrute(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(count == 0){
                ans = nums[i];
                count = 1;
            }
            else if(nums[i] == ans){
                count++;
            }
            else{
                count--;
            }
        }
        return ans;
    }
    int majorityElementBatter(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            hash[nums[i]]++;
        }
        for (auto it : hash)
        {
            if(it.second > n/2) return it.first;
        }
        return -1;
    }
    int majorityElementOptimal(vector<int> & nums){
        int n = nums.size();
        int cnt = 0;
        int el;
        for (int i = 0; i < n; i++)
        {
            if(cnt == 0){
                el = nums[i];
                cnt = 1;
            }else if(nums[i] == el){
                cnt++;
            }else{
                cnt--;
            }
        }
        int finalCount = 0;
        for (int i = 0; i < n; i++)
        {
            if(nums[i] == el){
                finalCount++;
            }
        }
        return finalCount > n/2 ? el : -1;
    }
};

int main(){
    vector<int> nums = {5,6,7,4,5,5,5,6,4,5,5,5,7,8,9,0,4,5,65,5,5};
    Solution obj;
    cout<<"Majority Element - Brute Approach: "<<obj.majorityElementBrute(nums)<<endl;
    cout << "Majority Element - Batter Approach: " << obj.majorityElementBatter(nums) << endl;
    cout << "Majority Element - Optimal Approach: " << obj.majorityElementOptimal(nums) << endl;

    return 0;
}