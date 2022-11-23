# [224. Basic Calculator](https://leetcode.com/problems/basic-calculator/)

**Level:** `Hard`.

**Topic:** `Stack`, `Math`, `Stack`, `Recursion`.

Given a string <code>s</code> representing a valid expression, implement a basic calculator to evaluate it, and return <em>the result of the evaluation</em>.

<strong>Note:</strong> You are <strong>not</strong> allowed to use any built-in function which evaluates strings as mathematical expressions, such as <code>eval()</code>.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> s = "1 + 1"
<strong>Output:</strong> 2
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> s = " 2-1 + 2 "
<strong>Output:</strong> 3
</pre>

<strong>Example 3:</strong>

<pre><strong>Input:</strong> s = "(1+(4+5+2)-3)+(6+8)"
<strong>Output:</strong> 23
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
 <li><code>s</code> consists of digits, <code>'+'</code>, <code>'-'</code>, <code>'('</code>, <code>')'</code>, and <code>' '</code>.</li>
 <li><code>s</code> represents a valid expression.</li>
 <li><code>'+'</code> is <strong>not</strong> used as a unary operation (i.e., <code>"+1"</code> and <code>"+(2 + 3)"</code> is invalid).</li>
 <li><code>'-'</code> could be used as a unary operation (i.e., <code>"-1"</code> and <code>"-(2 + 3)"</code> is valid).</li>
 <li>There will be no two consecutive operators in the input.</li>
 <li>Every number and running calculation will fit in a signed 32-bit integer.</li>
</ul>
