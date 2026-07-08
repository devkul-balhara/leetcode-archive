class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.size();
        const int mod = 1e9+7;
        
        vector<long long> pow10(m + 1, 1);
        for(int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i-1] * 10) % mod;
        }

        vector<long long> pref;
        vector<int> last_index;
        vector<int> sod;
        vector<int> nod;
        
        long long curr = 0;
        int sum = 0;
        int digits = 0;

        for(int i = 0; i < m; i++){
            if(s[i] != '0'){
                curr = (curr * 10 + (s[i]-'0')) % mod; 
                sum += s[i]-'0';
                digits++;
                
                pref.push_back(curr);
                sod.push_back(sum);
                nod.push_back(digits);
                last_index.push_back(i); 
            }
        }

        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int st = queries[i][0], end = queries[i][1];
            int st_idx = lower_bound(last_index.begin(), last_index.end(), st) - last_index.begin();
            int end_idx = upper_bound(last_index.begin(), last_index.end(), end) - last_index.begin()-1;
            if(st_idx > end_idx || st_idx >= last_index.size()) {
                ans.push_back(0);
                continue;
            }
            long long e_ele = pref[end_idx];
            int e_sum = sod[end_idx];
            int e_digits = nod[end_idx];

            long long s_ele = (st_idx > 0) ? pref[st_idx-1] : 0;
            int s_sum = (st_idx > 0) ? sod[st_idx-1] : 0;
            int s_digits = (st_idx > 0) ? nod[st_idx-1] : 0;

            int current_sum = e_sum - s_sum;
            int digit_diff = e_digits - s_digits;
            long long prefix_to_remove = (s_ele * pow10[digit_diff]) % mod;
            long long no = (e_ele - prefix_to_remove + mod) % mod;
            ans.push_back((no * current_sum) % mod);
        }
        return ans;
    }
};