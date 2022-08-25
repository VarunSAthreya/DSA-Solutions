# [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

**Level:** `Medium`.

**Topic:** `Hash Table`, `Two Pointer`, `String`, `Sliding Table`.

Given a string `s`, find the length of the **longest substring** without repeating characters.

**Example 1:**

```txt
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

**Example 2:**

```txt
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**

```txt
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

**Example 4:**

```txt
Input: s = ""
Output: 0
```

**Constraints:**

- <code>0 <= s.length <= 5 \* 10<sup>4</sup></code>
- `s` consists of English letters, digits, symbols and spaces.
