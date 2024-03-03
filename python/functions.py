def check_palindrome(word:str):
    start = 0
    end = len(word)-1
    while(start < end):
        if (word[start] != word[end]):
            return False
        
        start += 1
        end -= 1
    return True


def substring(s, t):
    len_s = len(s)
    len_t = len(t)
    flag = 0
    if (len(t)==0) or (len_t > len_s):
        return flag
    for i in range(len_s):
        if s[i] == t[0]:
            if (len(s[i:]) >= len(t)):
                for j in range(len_t):
                    if s[i+j] != t[j]:
                        flag = 0
                        break
                    else:
                        flag = 1
                        continue
                if flag:
                    break
            else:
                flag = 0
    return flag


def insertion_sort(L):
    for i in range(1,len(L)):
        key = L[i]
        for j in range(i, 0, -1):
            if L[j] < L[j-1]:
                L[j], L[j-1] = L[j-1], L[j]
    return L

def selection_sort(L):
    for i in range(len(L)):
        min = i
        for j in range(i, len(L)):
            if L[min] > L[j]:
                min = j
        L[i], L[min] = L[min], L[i]
    return L

def merge_sort(L):
    if len(L) > 1:
        mid = len(L) // 2
        sorted_left = merge_sort(L[:mid])
        sorted_right = merge_sort(L[mid:])
        merge = []
        while len(sorted_left) and len(sorted_right):
            if sorted_left[0] > sorted_right[0]:
                merge.append(sorted_right.pop(0))
            else:
                merge.append(sorted_left.pop(0))
        if len(sorted_left) == 0:
            merge += sorted_right
        else:
            merge += sorted_left
        
        return merge
    else:
        return L
    
def counting_sort(list): # 양의 정수만 있는 리스트, max를 알 때 가능
    count = [0] * (max(list) + 1)
    output = [0] * (len(list))
    
    for i in range(len(list)):
        count[list[i]] += 1
    for j in range(len(count)-1):
        count[j + 1] = count[j] + count[j +1]
    
    for k in range(len(list)-1, -1 ,-1):
        count[list[k]] -= 1
        idx = count[list[k]]
        output[idx] = list[k]
    return output

def bfs(G:dict,s:GNode):
    queue = [s]
    visited = [s]

    while (len(queue)!=0):
        cur = queue[0]
        queue.pop(0)
        adj_vertices = G[cur]
        for vertex in adj_vertices:
            if vertex not in visited:
                vertex.distance = cur.distance + 1
                visited.append(vertex)
                queue.append(vertex)
    return visited


# string split
s = "I have pizza"
ans = s.split(' ')   # list [I, have, pizza]
# list to string
new_string = ' '.join(ans) # "I have pizza"
