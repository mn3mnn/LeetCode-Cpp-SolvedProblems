class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sz = m + n;
        vector<int> sorted(sz);

        int i = 0, j = 0, k = 0;
        while (k < sz && m > 0 && n > 0){
            if (nums1[i] > nums2[j]){
                sorted[k++] = nums2[j++];
                n--;
            }
            else{
                sorted[k++] = nums1[i++];
                m--;    
            }
        }

        while (m > 0){
            sorted[k++] = nums1[i++];
            m--;
        }
        while (n > 0){
            sorted[k++] = nums2[j++];
            n--;
        }

        std::copy(sorted.begin(), sorted.end(), nums1.begin());

    }

};