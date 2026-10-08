class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        int ans=0;
        stack<int> st;
        for(int i=0; i<=n; i++) {
            int curr;
            if(i==heights.size()) {
                curr=0;
            }
            else {
                curr=heights[i];
            }
            while(!st.empty() && heights[st.top()] > curr ) {
                int h= heights[st.top()];
                st.pop();

                int w;
                if(st.empty()) {
                    w=i;
                }
                else {
                    w= i - st.top() -1;
                }
                ans= max(ans, h*w);
            }
            st.push(i);
        }
        return ans;
    }
};