//https://leetcode.com/problems/anagrams/
class Solution {
public:
 string getCode(string s){
        sort(s.begin(),s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > results;
        int size=strs.size();
        if(size==0)
            return results;
        if(size==1){
             results.push_back(strs);
             return results;
        }
        
        map<string,vector<string> > head;
        
        for(int i=0;i<size;++i){
            head[getCode(strs[i])].push_back(strs[i]);
        }
        
map<string,vector<string> >::iterator itor=head.begin(),end=head.end();
        for(;itor!=end;++itor){
            results.push_back(itor->second);
        }
        return results;  
    }
};
