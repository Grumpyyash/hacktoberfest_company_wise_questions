#### Question 3

Alice and Bob want to renovate an old school in their city.
There are N classrooms in a school and the ith classroom has a capacity of A[i]
students. Bob is a builder and follows instructions of Alice.

Alice gives Q instructions of the following types:
 - 1 L: Move L classrooms left
 - 2 R: Move R classrooms right
 - 3 X Y: Remove the next classroom and add two new classrooms of capacity X, Y respectively, to the right of the current classroom

Note: the queries are always valid

Task:

Initially, Bob is in the 1st classroom. After performing all of Alice's instructions, print the classroom capacity from beginning to end.

Constraints:
```
3 <= N, Q <= 10^5
1 <= L, R <= 5
1 <= A[i], X, Y <= 10^9
```