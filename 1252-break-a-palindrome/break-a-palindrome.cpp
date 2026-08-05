class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n == 1) return "";
        bool ok = false;
        for(int i = 0; i < n; i++){
            if(n%2 == 0){
                if(palindrome[i] > 'a'){
                    palindrome[i] = 'a';
                    ok = true;
                    break;
                }
            }
            else{
                if(i != n/2 && palindrome[i] > 'a'){
                    palindrome[i] = 'a';
                    ok = true;
                    break;
                }
            }
        }
        if(!ok) palindrome.back() = 'b';
        return palindrome;
    }
};