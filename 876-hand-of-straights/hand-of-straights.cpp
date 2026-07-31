class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // A valid grouping is only possible if the total number of cards 
        // is perfectly divisible by the required group size.
        if (hand.size() % groupSize != 0) return false;
        
        // Use a map to store the frequency of each card.
        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }
        
        // Iterate through the sorted cards and their frequencies
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            // If the frequency is 0, this card was already fully used 
            // as part of previous consecutive groups, so we skip it.
            if (it->second > 0) {
                int start = it->first;   // The starting card for our consecutive groups
                int count = it->second;  // How many such groups we need to form right now
                
                // Attempt to build 'count' groups of size 'groupSize'
                for (int i = 0; i < groupSize; ++i) {
                    // Check if the next consecutive card (start + i) exists 
                    // and has enough frequency to satisfy the 'count' groups we are building.
                    if (freq.find(start + i) == freq.end() || freq[start + i] < count){
                        return false;
                    }
                    
                    // Deduct the used cards from the map so they aren't reused in future groups.
                    freq[start + i] -= count;
                }
            }
        }
        // If we successfully processed all cards without returning false, 
        // a valid grouping is possible.
        return true;
    }
};