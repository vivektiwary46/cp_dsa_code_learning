//In this we will find the diameter of the tree using another method.

//Tree diameter :- it is the maximum number of edges present between two nodes in a tree.
//More than one diameter can exist in the tree, diameter are not always unique.

//Procedure :-
//1)Assume any node a as root
//2)Start dfs from a and find that node b, having max dist from a
//[ Using depth[child]=depth[node]+1 ]
//(This node b will be an endpoint of a diameter)
//3)Now, Start dfs from node b and find the node c,  which is at max distance (d) from b.
//This value of d is the diameter of the tree.

//solve it , the same has to be submitted in the below problem of cses.
//Question Link :- https://cses.fi/problemset/task/1131
