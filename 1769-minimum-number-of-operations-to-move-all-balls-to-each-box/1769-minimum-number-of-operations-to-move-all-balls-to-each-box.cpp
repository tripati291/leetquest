class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer;
        int n= boxes.size();
        for(int j=0; j<n; j++) {
            int sum=0;
            for(int i=0; i<n; i++) {
                if(boxes[i]== '1') {
                    sum += abs(i - j);
                }
                else continue;
            }
            answer.push_back(sum);
        }
        return answer;
    }
};