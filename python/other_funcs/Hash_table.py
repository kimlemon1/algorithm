class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None
        
class HashTable:
    def __init__(self):
        self.capacity = 3
        self.buckets = [None] * self.capacity
        self.count = 0
        
    def Hash(self, key): # 나머지 반환
        return key % self.capacity # 나머지로 주소 계산
    
    def insert(self, key, value):
        alpha = self.count / self.capacity
        
        if alpha >= 1.5:
            self.rehash()
        
        index = self.Hash(key)
        node = self.buckets[index]
        if node is None:
            self.buckets[index] = Node(key, value)
        else:
            # prev = node
            while node is not None:
                prev = node
                node = node.next
            prev.next = Node(key, value)
        self.count += 1
    
    def retrieve(self, key):
        index = self.Hash(key)
        node = self.buckets[index]
        
        while node is not None and node.key != key: # 해당 인덱스로 가서 LL따라가며 key 값 찾기
            node = node.next
        if node is None: # 없는 경우
            return None
        else:
            return node.value
    
    def delete(self, key):
        index = self.Hash(key)
        node = self.buckets[index]
        
        # prev 값 기억시키기 위한 방법 : bst delete에서도 이거처럼 만들어 보자!!
        prev = None
        while node is not None and node.key != key:
            prev = node
            node = node.next
            
        if node is None: # 찾는 값 없다
            return None
        else: # 찾았다
            result = node.value
            self.count -= 1
            if prev is None: # 맨 처음에 있는 경우다
                self.buckets[index] = node.next
            else:
                prev.next = prev.next.next
            return result
        
    # insert 내부에서 alpha값을 넘는 경우 이미 들어간 모든 노드 재계산 + 재배치까지 한번에! 
    def rehash(self):
        self.capacity *= 2
        new_buckets = [None] * self.capacity
        
        for LL in self.buckets:
            while LL is not None:
                re_index = LL.key % self.capacity
                new_buckets[re_index] = Node(LL.key, LL.value)
                LL = LL.next
        self.buckets = new_buckets
        
    # 네이버 실시간 검색 순위 구하는 함수 (검색 순위 k위까지 저장)
    def k_most_frequent_queries(self, queries: list) -> list:
        
        Dic = {}
        # O(n(n+1)) : k 번째에 k만큼 훑어야 한다
        for key in queries:
            if key not in Dic.keys():
                Dic[key] = 1
            else:
                Dic[key] += 1
        '''        또 하나 방법 : set 이용해 dict 먼저 만들고 훑기, 훑기는 O(N)
        keys = set(queries)
        Dic = dict(zip(keys, [0]*len(keys)))
        for key in queries:
            Dic[key] += 1
        '''
                
        ans = []
        for i in range(5): # 몇위까지 출력할까, k
            max_key = list(Dic.keys())[0]
            max_val = list(Dic.values())[0]
            for key, value in Dic.items():
                if value > max_val:
                    max_key = key
                    max_val = value
            ans.append(max_key)
            del Dic[max_key]
        return ans
    
    def smallest_missing_pos_int(self, List):
        for item in List:
            self.insert(item, 0)
        start_num = 1
        end_num = 10
        while True:
            for i in range(start_num, end_num):
                if self.retrieve(i) != None:
                    
                    continue
                else:
                    return i
            start_num = end_num
            end_num = end_num * 2

        