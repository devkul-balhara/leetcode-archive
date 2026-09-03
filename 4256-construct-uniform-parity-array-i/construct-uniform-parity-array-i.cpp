class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool odd = false, even = false;
        for(auto i : nums1){
            if(i&1) odd = true;
            else even = true;
        }
        // odd
        bool ok1 = true;
        for(auto i : nums1){
            if(i%2 == 0){
                if(!odd){
                    ok1 = false;
                    break;
                }
            }
        }
        // even
        bool ok2 = true;
        for(auto i : nums1){
            if(i&1){
                if(!even){
                    ok2 = false;
                    break;
                }
            }
        }
        return ok1 || ok2;
    }
};