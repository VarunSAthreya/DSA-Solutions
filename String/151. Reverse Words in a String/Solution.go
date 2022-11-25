func reverseWords(s string) string {
	s = strings.TrimSpace(s)
	wordList := strings.Fields(s)
	for i, j := 0, len(wordList)-1; i < j; i, j = i+1, j-1 {
		wordList[i], wordList[j] = wordList[j], wordList[i]
	}

	return strings.Join(wordList, " ")
}
