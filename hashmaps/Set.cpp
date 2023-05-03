#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>a;
        set<int>b;
        for(int i=0;i<nums1.size();i++){
            a.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            b.insert(nums2[i]);
        }
        vector<vector<int>>answer{{},{}};
        for(auto i:a){
            if(b.count(i)==0){
                answer[0].push_back(i);
            }
        }
        for(auto i:b){
            if(a.count(i)==0){
                answer[1].push_back(i);
            }
        }
        return answer;
    }
};