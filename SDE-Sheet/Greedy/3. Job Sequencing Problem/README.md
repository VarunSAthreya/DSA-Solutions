# [Job Sequencing Problem](https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#)

**Level:** `Medium`.

**Topics:** `Greedy`, `Dynamic Programming`.

Given a set of **N** jobs where each **job<sub>i</sub>** has a deadline and profit associated with it. Each job takes **1** unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the **maximum profit**.

**Note:** Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

**Example 1:**

```txt
Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
```

**Example 2:**

```txt
Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).
```

**Your Task :**
You don't need to read input or print anything. Your task is to complete the function **JobScheduling()**which takes an integer **N** and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.

**Expected Time Complexity: O(NlogN)**
**Expected Auxilliary Space: O(N)**

**Constraints:**

- 1 <= N <= 10<sup>5</sup>
- 1 <= Deadline <= 100
- 1 <= Profit <= 500
