class Solution {
public:
    int countVowelStrings(int n) {
        return ((n+1)*(n+2)*(n+3)*(n+4))/24;
        // this is n+4 C 4 ; jaise RMO questions mein krte the 
        // like a+e+i+o+u = n
    }
};