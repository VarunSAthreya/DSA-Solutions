# [609. Find Duplicate File in System](https://leetcode.com/problems/find-duplicate-file-in-system/)

**Level:** `Medium`.

**Topic:** `Hashing`, `String`, `Array`.

Given a list <code>paths</code> of directory info, including the directory path, and all the files with contents in this directory, return <em>all the duplicate files in the file system in terms of their paths</em>. You may return the answer in <strong>any order</strong>.

A group of duplicate files consists of at least two files that have the same content.

A single directory info string in the input list has the following format:

<ul>
 <li><code>"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"</code></li>
</ul>

It means there are <code>n</code> files <code>(f1.txt, f2.txt ... fn.txt)</code> with content <code>(f1_content, f2_content ... fn_content)</code> respectively in the directory "<code>root/d1/d2/.../dm"</code>. Note that <code>n &gt;= 1</code> and <code>m &gt;= 0</code>. If <code>m = 0</code>, it means the directory is just the root directory.

The output is a list of groups of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

<ul>
 <li><code>"directory_path/file_name.txt"</code></li>
</ul>

<strong>Example 1:</strong>
<pre><strong>Input:</strong> paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
<strong>Output:</strong> [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
</pre><strong>Example 2:</strong>
<pre><strong>Input:</strong> paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"]
<strong>Output:</strong> [["root/a/2.txt","root/c/d/4.txt"],["root/a/1.txt","root/c/3.txt"]]
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= paths.length &lt;= 2 *10<sup>4</sup></code></li>
 <li><code>1 &lt;= paths[i].length &lt;= 3000</code></li>
<li><code>1 &lt;= sum(paths[i].length) &lt;= 5* 10<sup>5</sup></code></li>
 <li><code>paths[i]</code> consist of English letters, digits, <code>'/'</code>, <code>'.'</code>, <code>'('</code>, <code>')'</code>, and <code>' '</code>.</li>
 <li>You may assume no files or directories share the same name in the same directory.</li>
 <li>You may assume each given directory info represents a unique directory. A single blank space separates the directory path and file info.</li>
</ul>

<strong>Follow up:</strong>

<ul>
 <li>Imagine you are given a real file system, how will you search files? DFS or BFS?</li>
 <li>If the file content is very large (GB level), how will you modify your solution?</li>
 <li>If you can only read the file by 1kb each time, how will you modify your solution?</li>
 <li>What is the time complexity of your modified solution? What is the most time-consuming part and memory-consuming part of it? How to optimize?</li>
 <li>How to make sure the duplicated files you find are not false positive?</li>
</ul>

### Follow Up Solution

**1. Imagine you are given a real file system, how will you search files? DFS or BFS ?**
In general, BFS will use more memory then DFS. However BFS can take advantage of the locality of files in inside directories, and therefore will probably be faster

**2. If the file content is very large (GB level), how will you modify your solution?**
In a real life solution we will not hash the entire file content, since it's not practical. Instead we will first map all the files according to size. Files with different sizes are guaranteed to be different. We will than hash a small part of the files with equal sizes (using SHA256 for example). Only if the SHA256 is the same, we will compare the files byte by byte

**3. If you can only read the file by 1kb each time, how will you modify your solution?**
This won't change the solution. We can create the hash from the 1kb chunks, and then read the entire file if a full byte by byte comparison is required.

**What is the time complexity of your modified solution? What is the most time consuming part and memory consuming part of it? How to optimize?**
Time complexity is O(n^2 * k) since in worse case we might need to compare every file to all others. k is the file size

**How to make sure the duplicated files you find are not false positive?**
We will use several filters to compare: File size, Hash and byte by byte comparisons.
