# Assignment 2 - Graphs and Operator Overloading

In the previous assignment, you implemented the `Graph.cpp` class that allows graph representation using an adjacency matrix. In this assignment, you will extend the class and add support for arithmetic operators on graphs.
As mentioned, the graphs are represented using an adjacency matrix, so all operators need to be valid for matrices (as you learned in the Linear Algebra course).

You will need to add the following operators:

- Six arithmetic operators: addition (+), addition assignment (+=), unary plus (+), and the three corresponding subtraction operators (-). As mentioned, addition/subtraction of two matrices is defined only for matrices of the same size nXn. Attempting to add/subtract two matrices that do not meet this condition will result in an error being thrown.
- Six comparison operators: greater than, greater than or equal to, less than, less than or equal to, equal, not equal. For this assignment, the graph comparison rules are as follows:

  1. Graphs G1 and G2 are considered equal if they are of the same size and contain the same edges (with identical edge weights) or if G1 is not greater than G2 and G2 is not greater than G1.
  2. Graph G2 is greater than graph G1 if graph G1 is properly contained within graph G2. If neither graph is properly contained within the other and the graphs are not equal, then graph G2 is greater than graph G1 if the number of edges in G2 is greater than the number of edges in G1. If the number of edges is still the same, then graph G2 is greater than graph G1 if the matrix representing G2 has a higher order than that of G1.

- Increment (++) and decrement (--) operators before and after the number. This operation will increase or decrease all the weights of the edges in the graph by 1.
- Scalar multiplication (`int`) - multiplies the weight of all the edges.
- Graph multiplication - we define the multiplication operation between graph G1 and graph G2 by multiplying the adjacency matrices representing the two graphs. The result should be a matrix representing a graph. Attempting to multiply graphs of different sizes should throw an error.
- Output operator - logical printing of the graph (the printing format is at your discretion).

Additionally, you should include the `Algorithms.cpp` file from the previous assignment and see how the functions you defined previously change now. Besides the assignment files, you are required to submit a README file that describes the implementation and the division you performed in the code (a kind of user guide). You must write your ID number and email at the beginning of each file. Failure to comply with the instructions will result in a grade reduction.
Good luck!