class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
       
        int m = str1.size() ; 
        int n = str2.size();
        if(str1+str2 != str2+str1) return "";
         return str2.substr(0 , gcd(m , n));
        

    }
};