class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cntZero_firstSegment = 0, cntOne = 0, cntZero_secondSegment = 0, maximumAddition = 0;
        for(auto i : s){
            if(i == '1') cntOne++;
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                if(!cntZero_firstSegment){
                    while(i < s.size() && s[i] == '0'){
                        cntZero_firstSegment++;
                        i++;
                    }
                    i--;
                }
                else if(!cntZero_secondSegment){
                    while(i < s.size() && s[i] == '0'){
                        cntZero_secondSegment++;
                        i++;
                    }
                    i--;
                }
                else{
                    int temp = cntZero_secondSegment+cntZero_firstSegment;
                    maximumAddition = max(maximumAddition,temp);
                    cntZero_firstSegment = cntZero_secondSegment;
                    cntZero_secondSegment = 0;
                    while(i < s.size() && s[i] == '0'){
                        cntZero_secondSegment++;
                        i++;
                    }
                    i--;
                }
            }
        }
        if(cntZero_secondSegment && cntZero_firstSegment){
            int temp = cntZero_secondSegment+cntZero_firstSegment;
            maximumAddition = max(maximumAddition,temp);
        }
        return cntOne+maximumAddition;
    }
};