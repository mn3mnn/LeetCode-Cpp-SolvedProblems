class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
    /* 
    vector<int> res;
    for (int i=0; i < nums.size(); i++)
    {
        for (int j=0; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target && j != i) 
            {
                res.push_back(i);
                res.push_back(j);
                break;
            }
        }
        if(!res.empty())
        {
          break;  
        }
    }
    return res;
    */
        
   
        
    // another solution 
    //    O(n * lg(n))
         
        
    // store values and the indices in map
    unordered_map<int,int> mp;    
		
    // iterate through nums vector
    for(int i = 0; i < nums.size(); i++){
        
		if(mp.find(target-nums[i]) != mp.end()){
            
        // if mp contains the value (target - nums[i]), then  
        // return the indices
            return {i, mp[target-nums[i]]};
        }			
        
        mp[nums[i]] = i;
        
    }
        
    // else return an empty vector.    
    return {};
}
};
