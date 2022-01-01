class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        unordered_map<string, vector<int>> mp;
        vector<string> cp(string_list.begin(), string_list.end());
        int n = string_list.size();
        for(auto &it : cp)
            sort(it.begin(), it.end());
        
        for(int i =0;i<n;i++){
            mp[cp[i]].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it : mp){
            vector<string> st;
            for(int i : it.second){
                st.push_back(string_list[i]);
            }
            ans.push_back(st);
        }
        return ans;
    }
};