# [151. Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)

**Level:** `Medium`.

**Topic:** `Two Pointer`, `String`.

Given an input string <code>s</code>, reverse the order of the <strong>words</strong>.

A <strong>word</strong> is defined as a sequence of non-space characters. The <strong>words</strong> in <code>s</code> will be separated by at least one space.

Return <em>a string of the words in reverse order concatenated by a single space.</em>

<b>Note</b> that <code>s</code> may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> s = "the sky is blue"
<strong>Output:</strong> "blue is sky the"
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> s = "  hello world  "
<strong>Output:</strong> "world hello"
<strong>Explanation:</strong> Your reversed string should not contain leading or trailing spaces.
</pre>

<strong>Example 3:</strong>

<pre><strong>Input:</strong> s = "a good   example"
<strong>Output:</strong> "example good a"
<strong>Explanation:</strong> You need to reduce multiple spaces between two words to a single space in the reversed string.
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
 <li><code>s</code> contains English letters (upper-case and lower-case), digits, and spaces <code>' '</code>.</li>
 <li>There is <strong>at least one</strong> word in <code>s</code>.</li>
</ul>

<b>Follow-up:&nbsp;</b>If the string data type is mutable in your language, can&nbsp;you solve it&nbsp;<b>in-place</b>&nbsp;with&nbsp;<code>O(1)</code>&nbsp;extra space?
