class undi_graph():
    def __init__(self, V:list, E:list):
        self.V = V[:]
        self.neighbors = {}
        
        for v in V:
            self.neighbors[v] = []
        for (x,y) in E:
            self.neighbors[x].append(y)
            self.neighbors[y].append(x)
            
    def bfs(self):
        unvisited = self.V.copy()
        stack = []
        while len(unvisited) !=0:
            now = unvisited[0]
            stack.append(now)
            print(now)
            del unvisited[0] # stack에 들어갈 때 방문해야함, stack에서 나갈 때 방문하면 다른 곳에서 재방문 문제
            
            while len(stack)!=0:
                cur = stack[0]
                stack.pop(0)
                for vertex in self.neighbors[cur]:
                    if vertex in unvisited:
                        stack.append(vertex)
                        print(vertex)
                        unvisited.remove(vertex)
            
    def dfs(self):
        unvisited = self.V.copy()
        queue = []
        while len(unvisited)!=0:
            queue.append(unvisited[0])
            print(unvisited[0])
            
            del unvisited[0]
            
            while (len(queue)!=0):
                cur = queue[-1]
                queue.pop()
                for val in self.neighbors[cur]:
                    if val in unvisited:
                        queue.append(val)
                        unvisited.remove(val)
                        print(val)
    def dfs_recur(self):
        unvisited = self.V.copy()
        
        self.dfs_recur_help(unvisited,unvisited[0])
        
        
    def dfs_recur_help(self, unvisited, v):
        if v in unvisited:
            unvisited.remove(v)
            for vertex in self.neighbors[v]:
                self.dfs_recur_help(unvisited, vertex)
            print(v)
            

v = ['a','b','c']
e = [('a','b'),('b','c')]
graph = undi_graph(v,e)
print(graph.neighbors)
graph.bfs()
print("\n")
graph.dfs()
print("\n")
graph.dfs_recur()
            