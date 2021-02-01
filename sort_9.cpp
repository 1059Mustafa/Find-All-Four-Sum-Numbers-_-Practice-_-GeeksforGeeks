vector<vector<int> > fourSum(vector<int> &nums, int target) 
{
    sort(nums.begin(),nums.end());
      
      vector<vector<int>> ans;
      
      for(int i=0;i<nums.size();i++)
      {
          if(i>0 && nums[i]==nums[i-1]) continue;
          
          int target_3=target-nums[i];
          
          for(int j=i+1;j<nums.size();j++)
          {
              if(j>i+1 && nums[j]==nums[j-1]) continue;
              
              int target_2=target_3 - nums[j];
              int left=j+1;
              int right=nums.size()-1;
              
              while(left < right)
              {
                  int sum=nums[left]+nums[right];
                  
                  if(target_2 > sum) left++;
                  
                  else if( target_2 < sum ) right--;
                  
                  else
                  {
                      vector<int> quadruplet(4);
                      quadruplet[0]=nums[i];
                      quadruplet[1]=nums[j];
                      quadruplet[2]=nums[left];
                      quadruplet[3]=nums[right];
                      
                      ans.push_back(quadruplet);
                      
                      while(left < right && nums[left]==quadruplet[2] ) left++;
                      while(left < right && nums[right]==quadruplet[3] ) right--;
                      
                  }
                  
              }
          }
      }
      return ans;
    
}
