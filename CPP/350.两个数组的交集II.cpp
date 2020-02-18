class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int size1 = int(nums1.size()), size2 = int(nums2.size());
        vector<int> res;
        if(size1 == 0 || size2 == 0)
            return res;
        map<int, int> m_map;
        for(int i = 0; i < size1; i++)
            m_map[nums1[i]]++;
        for(int i = 0; i < size2; i++)
        {
            if(m_map.count(nums2[i]) && m_map[nums2[i]] > 0)
            {
                m_map[nums2[i]]--;
                res.push_back(nums2[i]);
            }     
        }
        return res;
    }
};