# [Longest Duplicate Substring](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3365/)

#### Given a string ``` S ```, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

#### Return any duplicated substring that has the longest possible length.  (If ``` S ``` does not have a duplicated substring, the answer is ``` "" ``` .)

 

#### Example 1:
```
Input: "banana"
Output: "ana"
```
#### Example 2:
```
Input: "abcd"
Output: ""
```

#### Note:

1. ``` 2 <= S.length <= 10^5 ```
2. ``` S ``` consists of lowercase English letters.

#### Hide Hint #1  
Binary search for the length of the answer. (If there's an answer of length 10, then there are answers of length 9, 8, 7, ...)
#### Hide Hint #2  
To check whether an answer of length K exists, we can use Rabin-Karp 's algorithm.
