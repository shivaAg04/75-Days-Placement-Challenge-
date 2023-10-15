bool areIsomorphic(string &str1, string &str2)
{
    if(str2.size()!= str1.size()) return false;
    map<char , char>mp1;
    map<char , char>mp;
    for(int i = 0  ; i < str1.size() ; i++){
        if(mp.find(str1[i])== mp.end() &&mp1.find(str2[i])==mp1.end() ){
              mp[str1[i]] = str2[i];
              mp1[str2[i]] = str1[i];
       

        }else{
              if(mp1[str2[i]]!= str1[i]) return false;
              if(mp[str1[i]]!= str2[i]) return false;}
          

    }
     return true;
}