bool isPalindrome(string word)
{
    int i = 0;
    int j = word.size() - 1;
    while (i < j)
    {
        if (word[i] != word[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string> &words)
{
    vector<vector<int>> result;
    unordered_map<string, int> wordMap;
    for (int i = 0; i < words.size(); i++)
    {
        wordMap[words[i]] = i;
    }
    for (int i = 0; i < words.size(); i++)
    {
        string word = words[i];
        string reversedWord = word;
        reverse(reversedWord.begin(), reversedWord.end());
        if (wordMap.find(reversedWord) != wordMap.end() && wordMap[reversedWord] != i)
        {
            result.push_back({i, wordMap[reversedWord]});
        }
        if (isPalindrome(word))
        {
            string emptyString = "";
            if (wordMap.find(emptyString) != wordMap.end() && wordMap[emptyString] != i)
            {
                result.push_back({i, wordMap[emptyString]});
                result.push_back({wordMap[emptyString], i});
            }
        }
        for (int j = 1; j < word.size(); j++)
        {
            string left = word.substr(0, j);
            string right = word.substr(j);
            string reversedLeft = left;
            string reversedRight = right;
            reverse(reversedLeft.begin(), reversedLeft.end());
            reverse(reversedRight.begin(), reversedRight.end());
            if (isPalindrome(left) && wordMap.find(reversedRight) != wordMap.end())
            {
                result.push_back({wordMap[reversedRight], i});
            }
            if (isPalindrome(right) && wordMap.find(reversedLeft) != wordMap.end())
            {
                result.push_back({i, wordMap[reversedLeft]});
            }
        }
    }
    return result;
}
