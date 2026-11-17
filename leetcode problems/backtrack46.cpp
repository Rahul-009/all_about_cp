// problem - Permutations

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> perm;
    vector<bool> used;

    void backtrack(vector<int>& nums) {

        if (perm.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            used[i] = true;
            perm.push_back(nums[i]);

            backtrack(nums);

            perm.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        used.resize(nums.size(), false);

        backtrack(nums);

        return ans;
    }
};




// another method | without using extra space

void getPerms(vector<int> & nums, int idx, vector<vector<int>> &ans){
    for(int i = idx; i<nums.size(); i++){
        swap(nums[idx], nums[i]);
        getPerms(nums, idx+1, ans);
        swap(nums[idx], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> ans;
    getPerms(nums, 0, ans)
}