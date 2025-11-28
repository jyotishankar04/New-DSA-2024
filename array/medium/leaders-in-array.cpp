#include<bits/stdc++.h>
using namespace std;

// ! The brute version needs some improvements because it is also returing the duplicate values


class LeadersInArray
{
    public:
        vector<int> leadersInArrayBrute(vector<int> nums);
        vector<int> leadersInArrayOptimal(vector<int> nums);

};

vector<int> LeadersInArray::leadersInArrayBrute(vector<int> nums){
    int n = nums.size();
    vector<int> leadersArray;
    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if(nums[j] > nums[i]){
                leader = false;
                break;
            }
        }
        if(leader){
            leadersArray.push_back(nums[i]);
        }
    }
    return leadersArray;
}
vector<int> LeadersInArray::leadersInArrayOptimal(vector<int> nums){
    vector<int> leadersArray;
    int max = INT_MIN;
    int n = nums.size();
    for (int i = n -1 ; i >= 0; i--)
    {
        if(nums[i] > max){
            max = nums[i];
            leadersArray.push_back(max);
        }
    }

    reverse(leadersArray.begin(),leadersArray.end());    
    return leadersArray;
}

int main(){
    vector<int> nums = {5,6,7,4,5,5,5,6,4,5,5,5,7,8,9,0,4,5,65,5,5};
    LeadersInArray obj;
    cout<<"Leader Elements: Brute -> ";
    for (auto it : obj.leadersInArrayBrute(nums))
    {
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Leader Elements: Optimal -> ";
    for (auto it : obj.leadersInArrayOptimal(nums))
    {
        cout<<it<<" ";
    }
    return 0;
}