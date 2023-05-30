/* 
70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
 */



/* Trick to write recurrence relation in any sort of DP question 
1. Try to represent problems in terms of index.
2. Do all possible stuff on that index, according to the problem statement.
3. If question says -
    a. Count all the ways then find -> Sum of all stuffs 
    b. Find minimum/maximum -> take minimum/maximum of all stuffs
 */

