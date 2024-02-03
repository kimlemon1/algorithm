class directed_graph():
    def __init__(self, nodes, edges):
        self.v = nodes[:]
        self.e = {}
        for node in nodes:
            self.e[node] = []
        for (u,v) in edges:
            self.e[v].append(u) # 한방향

class weighted_graph():
    def __init__(self, nodes, edges): # nodes : 각 노트 들어간 리스트 / edges : (a, b, 1 형태)
        self.v = nodes[:]
        self.e = {}
        
        for node in nodes:
            self.e[node] = []
        for (u,v,w) in edges:
            self.e[v].append((u,w))
            self.e[u].append((v,w))