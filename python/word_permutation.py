# permutation promblem
import copy

def backtrack(cur_string, cur_set, ans_list):
    if len(cur_string)==0:
        cur_set = "".join(cur_set)
        ans_list.append(cur_set)
        return
    
    for i in range(len(cur_string)):
        new_string = cur_string[:i] + cur_string[i+1:]
        new_set = copy.deepcopy(cur_set)
        new_set.append(cur_string[i])
        
        backtrack(new_string, new_set, ans_list)
        
def insertion_sort(L):
    for i in range(1,len(L)):
        key = L[i]
        for j in range(i, 0, -1):
            if L[j] < L[j-1]:
                L[j], L[j-1] = L[j-1], L[j]
    return L

def str_perm(s:str):
    ans_list = []
    cur_string = s
    cur_set = []
    backtrack(cur_string, cur_set, ans_list)
    ans = insertion_sort(ans_list)
    return ans


s = "abc"
print(str_perm(s))
# s로 만들 수 있는 모든 조합 리스트 반환