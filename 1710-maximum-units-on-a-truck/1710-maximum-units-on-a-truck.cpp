class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });
        int sum=0;
        int i=0;
        while(truckSize > 0 && i < boxTypes.size()) {
            if(boxTypes[i][0] <= truckSize) {
                sum += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
                i++;
            }
            else {
                sum += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
        }
        return sum;
    }
};