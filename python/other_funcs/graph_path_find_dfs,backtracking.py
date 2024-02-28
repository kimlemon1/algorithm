class GNode:
    def __init__(self,id):
        self.id = id

    def __str__(self):
        return self.id
    
a, b, c,d = GNode('a'),GNode('b'),GNode('c'),GNode('d')
G = dict()
G[a], G[b],G[c],G[d] = [b,c],[d],[],[c]

def paths(G, start, end):
    #cur_path = [start.id]
    cur_path = [start]
    ans_list = []
    visited = []
    #dfs(G, start, end, cur_path, ans_list, visited)
    find_path(G, cur_path, end, ans_list)
    return ans_list


# def dfs(G, cur, end, cur_path, ans_list, visited):
#     if cur.id not in visited:
#         visited.append(cur.id)
#         if cur.id == end.id:
#             ans_list.append(cur_path)
#             return
#         next_vertexes = G[cur]
#         for vertex in next_vertexes:
#             next_path = cur_path.copy()
#             next_path.append(vertex.id)
#             dfs(G,vertex, end, next_path, ans_list, visited)
#             # 이게 중요하다! 그냥 dfs하면 안됨back tracking과 섞어서 생각
#             visited.remove(vertex.id)

def find_path(G, cur_path,end_id, ans_list):
    if (cur_path[-1] == end_id):
        ans_list.append([cur_path[i].id for i in range(len(cur_path))])
    
    for next_vertex in G[cur_path[-1]]:
        if next_vertex not in cur_path:
            new_path = cur_path + [next_vertex]
            find_path(G, new_path, end_id, ans_list)


print(paths(G, a, c))