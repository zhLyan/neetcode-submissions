class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for (int num : nums) {
            count[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (auto& pair : count) {
            int num = pair.first;
            int freq = pair.second;

            buckets[freq].push_back(num);
        }

        vector<int> result;

        for (int freq = buckets.size() - 1; freq >= 0; --freq) {
            for (int num : buckets[freq]) {
                result.push_back(num);

                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
