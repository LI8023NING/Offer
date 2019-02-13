
vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int> vTemp;
    map<int, int> mapTemp;

    //使用哈希，下标和数字唯一对应
    for(int i = 0; i < nums.size(); i++) {
        mapTemp.insert(pair<int, int>(nums[i], i));
    }
    
    for(int i = 0; i < nums.size(); i++) {
        int findNum = target - nums[i];
        map<int, int>::iterator iter = mapTemp.find(findNum);
        if(iter != mapTemp.end() && iter->second != i)
        {
            vTemp.push_back(i);
            vTemp.push_back(iter->second);
            return vTemp;
        }
    }
    return vTemp;
}  