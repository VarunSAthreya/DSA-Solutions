# [1323. Maximum 69 Number](https://leetcode.com/problems/maximum-69-number/)

**Level:** `Easy`.

**Topic:** `Math`, `Greedy`.

You are given a positive integer <code>num</code> consisting only of digits <code>6</code> and <code>9</code>.

Return <em>the maximum number you can get by changing <strong>at most</strong> one digit (</em><code>6</code><em> becomes </em><code>9</code><em>, and </em><code>9</code><em> becomes </em><code>6</code><em>)</em>.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> num = 9669
<strong>Output:</strong> 9969
<strong>Explanation:</strong>
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> num = 9996
<strong>Output:</strong> 9999
<strong>Explanation:</strong> Changing the last digit 6 to 9 results in the maximum number.
</pre>

<strong>Example 3:</strong>

<pre><strong>Input:</strong> num = 9999
<strong>Output:</strong> 9999
<strong>Explanation:</strong> It is better not to apply any change.
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= num &lt;= 10<sup>4</sup></code></li>
 <li><code>num</code>&nbsp;consists of only <code>6</code> and <code>9</code> digits.</li>
</ul>
