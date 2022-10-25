class Solution {
public:
    unordered_set<char> charset;

    bool invalid(string s) {
        unordered_set<char> prev;
        for (char ch : s) {
            if (charset.count(ch) || prev.count(ch)) return true;
            prev.insert(ch);
        }

        return false;
    }

    int backtracking(int i, vector<string>& arr) {
        if (i == arr.size()) return charset.size();

        int res = 0;

        if (!invalid(arr[i])) {
            for (char ch : arr[i]) charset.insert(ch);

            res = backtracking(i + 1, arr);

            for (char ch : arr[i]) charset.erase(ch);
        }

        return max(res, backtracking(i + 1, arr));
    }

    int maxLength(vector<string>& arr) {
        return backtracking(0, arr)	;
    }
};