https://www.geeksforgeeks.org/paths-travel-nodes-using-edgeseven-bridges-konigsberg/
/*
Explaination:
1. Start from an odd degree vertex if any.
2. Check if the edge you are selcting is valid.
	conditions for validating for an edge u->v:
	1. if v is only adjacent node left to u, then we have to choose this.
	2. if u->v is bridge then we need must travel through this at the very last as we can never comeback.
	3. How to check bridge, dfs first with u->v edge and after removing this edge and if count1>count2
		it is a bridge.
3. make sure to remove the edges from adjacency while traversing, by replacing with -1;
4. Print path side by side.
*/
