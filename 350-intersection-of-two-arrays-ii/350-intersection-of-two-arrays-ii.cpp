
class Solution {
public:
    
    // search for element and delete it if founded
    bool binary_search(int key, vector<int>& vec){
        int l = 0, r = vec.size() - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if (vec[m] == key){
                // std::remove(vec.begin() + m, vec.begin() + m + 1, key);
                vec.erase(vec.begin() + m);
                return true;
            }
            else if (key < vec[m]){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return false;
    }

    

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int sz1 = nums1.size();
        int sz2 = nums2.size();

        vector<int> intersection;

        if (sz1 < sz2){
            // for each element in the shorter array apply binary search along the longer array
            for (int i = 0; i < sz1; ++i) {
                if (binary_search(nums1[i], nums2)){
                    intersection.push_back(nums1[i]);
                }
            }
        }
        else{
            for (int i = 0; i < sz2; ++i) {
                if (binary_search(nums2[i], nums1)){
                    intersection.push_back(nums2[i]);
                }
            }

        }

        return intersection;

    }

};