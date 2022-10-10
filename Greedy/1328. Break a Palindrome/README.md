# [1328. Break a Palindrome](https://leetcode.com/problems/break-a-palindrome/description/)

**Level:** `Medium`.

**Topic:** `String`, `Greedy`.

Given a palindromic string of lowercase English letters <code>palindrome</code>, replace <strong>exactly one</strong> character with any lowercase English letter so that the resulting string is <strong>not</strong> a palindrome and that it is the <strong>lexicographically smallest</strong> one possible.

Return <em>the resulting string. If there is no way to replace a character to make it not a palindrome, return an <strong>empty string</strong>.</em>

A string <code>a</code> is lexicographically smaller than a string <code>b</code> (of the same length) if in the first position where <code>a</code> and <code>b</code> differ, <code>a</code> has a character strictly smaller than the corresponding character in <code>b</code>. For example, <code>"abcc"</code> is lexicographically smaller than <code>"abcd"</code> because the first position they differ is at the fourth character, and <code>'c'</code> is smaller than <code>'d'</code>.

<strong >Example 1:</strong>

<pre><strong>Input:</strong> palindrome = "abccba"
<strong>Output:</strong> "aaccba"
<strong>Explanation:</strong> There are many ways to make "abccba" not a palindrome, such as "<u>z</u>bccba", "a<u>a</u>ccba", and "ab<u>a</u>cba".
Of all the ways, "aaccba" is the lexicographically smallest.
</pre>

<strong >Example 2:</strong>

<pre><strong>Input:</strong> palindrome = "a"
<strong>Output:</strong> ""
<strong>Explanation:</strong> There is no way to replace a single character to make "a" not a palindrome, so return an empty string.
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= palindrome.length &lt;= 1000</code></li>
 <li><code>palindrome</code> consists of only lowercase English letters.</li>
</ul>
