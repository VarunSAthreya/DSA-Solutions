# [1704. Determine if String Halves Are Alike](https://leetcode.com/problems/determine-if-string-halves-are-alike/)

**Level:** `Easy`.

**Topic:** `Counting`, `String`.

You are given a string <code>s</code> of even length. Split this string into two halves of equal lengths, and let <code>a</code> be the first half and <code>b</code> be the second half.

Two strings are <strong>alike</strong> if they have the same number of vowels (<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, <code>'u'</code>, <code>'A'</code>, <code>'E'</code>, <code>'I'</code>, <code>'O'</code>, <code>'U'</code>). Notice that <code>s</code> contains uppercase and lowercase letters.

Return <code>true</code><em> if </em><code>a</code><em> and </em><code>b</code><em> are <strong>alike</strong></em>. Otherwise, return <code>false</code>.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> s = "book"
<strong>Output:</strong> true
<strong>Explanation:</strong> a = "b<u>o</u>" and b = "<u>o</u>k". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> s = "textbook"
<strong>Output:</strong> false
<strong>Explanation:</strong> a = "t<u>e</u>xt" and b = "b<u>oo</u>k". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>2 &lt;= s.length &lt;= 1000</code></li>
 <li><code>s.length</code> is even.</li>
 <li><code>s</code> consists of <strong>uppercase and lowercase</strong> letters.</li>
</ul>
