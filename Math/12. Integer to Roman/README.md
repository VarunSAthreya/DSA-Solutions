# [12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/)

**Level:** `Medium`.

**Topic:** `Hashing`, `String`, `Math`.

Roman numerals are represented by seven different symbols: <code>I</code>, <code>V</code>, <code>X</code>, <code>L</code>, <code>C</code>, <code>D</code> and <code>M</code>.

<pre><strong>Symbol</strong>       <strong>Value</strong>
I             1
V             5
X             10
L             50
C             100
D             500
M             1000</pre>

For example, <code>2</code> is written as <code>II</code> in Roman numeral, just two one's added together. <code>12</code> is written as <code>XII</code>, which is simply <code>X + II</code>. The number <code>27</code> is written as <code>XXVII</code>, which is <code>XX + V + II</code>.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not <code>IIII</code>. Instead, the number four is written as <code>IV</code>. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as <code>IX</code>. There are six instances where subtraction is used:

<ul>
 <li><code>I</code> can be placed before <code>V</code> (5) and <code>X</code> (10) to make 4 and 9. </li>
 <li><code>X</code> can be placed before <code>L</code> (50) and <code>C</code> (100) to make 40 and 90. </li>
 <li><code>C</code> can be placed before <code>D</code> (500) and <code>M</code> (1000) to make 400 and 900.</li>
</ul>

Given an integer, convert it to a roman numeral.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> num = 3
<strong>Output:</strong> "III"
<strong>Explanation:</strong> 3 is represented as 3 ones.
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> num = 58
<strong>Output:</strong> "LVIII"
<strong>Explanation:</strong> L = 50, V = 5, III = 3.
</pre>

<strong>Example 3:</strong>

<pre><strong>Input:</strong> num = 1994
<strong>Output:</strong> "MCMXCIV"
<strong>Explanation:</strong> M = 1000, CM = 900, XC = 90 and IV = 4.
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= num &lt;= 3999</code></li>
</ul>
