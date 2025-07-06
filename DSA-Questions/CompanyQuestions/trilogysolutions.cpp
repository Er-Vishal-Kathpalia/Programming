class Solution {
private:
    bool checkSum(const vector<string>& crypt, const vector<int>& mapping) {
        long long sum = 0;
        long long num = 0;
        
        // Check first word
        if (mapping[crypt[0][0] - 'A'] == 0 && crypt[0].length() > 1) return false;
        for (char c : crypt[0]) {
            sum = sum * 10 + mapping[c - 'A'];
        }
        
        // Check second word
        if (mapping[crypt[1][0] - 'A'] == 0 && crypt[1].length() > 1) return false;
        for (char c : crypt[1]) {
            num = num * 10 + mapping[c - 'A'];
        }
        sum += num;
        
        // Check third word
        if (mapping[crypt[2][0] - 'A'] == 0 && crypt[2].length() > 1) return false;
        num = 0;
        for (char c : crypt[2]) {
            num = num * 10 + mapping[c - 'A'];
        }
        
        return sum == num;
    }
    
    void countSolutions(const vector<string>& crypt, vector<int>& mapping, 
                       vector<bool>& used, vector<bool>& letters, int pos, int& count) {
        if (pos == 26) {
            if (checkSum(crypt, mapping)) {
                count++;
            }
            return;
        }
        
        if (!letters[pos]) {
            countSolutions(crypt, mapping, used, letters, pos + 1, count);
            return;
        }
        
        // Check if this letter is a first letter in any word
        bool isFirst = false;
        for (const string& word : crypt) {
            if (word[0] - 'A' == pos && word.length() > 1) {
                isFirst = true;
                break;
            }
        }
        
        int start = isFirst ? 1 : 0;
        for (int i = start; i <= 9; i++) {
            if (!used[i]) {
                used[i] = true;
                mapping[pos] = i;
                countSolutions(crypt, mapping, used, letters, pos + 1, count);
                used[i] = false;
            }
        }
    }

public:
    int solution(vector<string> crypt) {
        // Mark which letters are used
        vector<bool> letters(26, false);
        for (const string& word : crypt) {
            for (char c : word) {
                letters[c - 'A'] = true;
            }
        }
        
        vector<int> mapping(26, 0);
        vector<bool> used(10, false);
        int count = 0;
        
        countSolutions(crypt, mapping, used, letters, 0, count);
        return count;
    }
};