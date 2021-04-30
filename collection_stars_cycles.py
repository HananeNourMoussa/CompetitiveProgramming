from collections import defaultdict

#user defined function to break graph into its connected components
def connectedComponents (adj_list, verts):
    visited = []
    cc = []
    #set all vertices to unvisited
    for i in range (verts):
        visited.append(False)
    #now visit vertices one by one
    for v in range (1, verts+1):
        if visited [v-1] == False:
            temp = []
            cc.append (DFSUtil (temp, v, visited))
    #cc is an array of arrays, each element consists of the an array of vertices that make a connected component
    return cc
#DFS utility function used to break the graph into its connected components
def DFSUtil (temp, v, visited):
    visited[v-1] = True
    temp.append(v)
    for adj in adj_list[v]:
        if visited[adj-1] == False:
            temp = DFSUtil (temp, adj, visited)
    return temp
#predicate function that returns 1 if component is cycle, 0 otherwise
def isCycle (cc, adj_list):
    #checking if each vertex has degree 2
    for i in range (len (cc)):
        degree = len (adj_list[cc[i]])
        if degree != 2:
            #just return 0, it can't be a cycle
            return 0
    #will only reach here if in fact all vertices have degree 2
    #now we will see if we can make a closed cycle on these vertices
    numverts_seen = 0
    cycleclosed = False
    next_vert = adj_list.get(cc[0])[0] #getting first vertex adjacent to vertex cc[0] 
    numverts_seen = 1
    prev_vert = cc[0]
    current_vert = next_vert
    while cycleclosed == False:
        for adj in adj_list[current_vert]: #go to adjacency list of current_vert
            if adj != prev_vert: #make sure you haven't just been at this vertex
                next_vert = adj
                break
        numverts_seen += 1 
        prev_vert = current_vert
        current_vert = next_vert
        if current_vert == cc[0]:#back to starting point
            cycleclosed = True
    if numverts_seen == len(cc):
        return 1
    else:
        return 0
#predicate function that returns 1 if component is a star, 0 otherwise
def isStar (cc, adj_list):
    #the idea here is the same one we've seen in class
    #just make sure that one vertex has deg n-1 and the remaining have deg 1
    deg1 = 0
    degn_1 = 0
    for i in range (len(cc)):
        degree = len (adj_list[cc[i]])
        if degree == 1:
            deg1 += 1
        elif degree == (len(cc)-1):
            degn_1 += 1
    if deg1 == (len(cc)-1) and degn_1 == 1:
        return 1
    else:
        return 0
#driver function
if __name__ == "__main__":
    #processing the input
    verts = eval (input ("Enter number of vertices: "))
    edges = eval (input ("Enter number of edges: "))
    #adjacency list using dictionary
    adj_list = defaultdict (list)
    #getting the edges
    for i in range (edges):
        a,b = (input ("Enter edge (one-indexed): ")).split (" ")
        a = eval (a)
        b = eval (b)
        adj_list[a].append(b)
        adj_list[b].append(a)
    #decompose list into connected components using DFS
    cc = connectedComponents (adj_list,verts) #every element in cc is a list that contains the indices of a connected component of the graph
    #now let's examine each component of this graph
    num_cycles = 0
    num_stars = 0
    good = True
    cycles = []
    stars = []
    #let's process each component and see if it's a cycle or a star
    for i in range (len (cc)): 
        if isCycle (cc[i], adj_list):
            num_cycles += 1
            #keep track of this cycle, we'll want to print it later
            cycles.append(i)
        elif isStar (cc[i], adj_list):
            num_stars += 1
            #keep track of this star, we'll want to print it later
            stars.append(i)
        else:
            print ("Not a collection of stars and cycles! At least one component is neither a star nor a cycle.")
            good = False
            break; 
        
    if good == True:
        print(f"Graph is collection of {num_stars} stars and {num_cycles} cycles!")
        print ("The cycles are: ")
        for i in range (len(cycles)):
            print (cc[cycles[i]])
        print ("The stars are: ")
        for i in range (len(stars)):
            print (cc[stars[i]])
