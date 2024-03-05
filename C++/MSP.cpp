// Minimum Spanning Trees
// Weighted Graph가 주어졌을 때 모든 노드 연결하는 최단거리 찾기

// Spanning tree : undirected graph 중에서 모든 노드가 연결된 tree(acycle) (최소로 연결된 tree)
// level 표현 불가

// MST 용도 : 최단거리 찾기 
// weighted graph에서 사용 가능 
// 모든 edge의 weight가 다르면 최단거리는 하나, 같은게 있으면 보장 못함


// Greedy search 기반 방법 2가지

// 1. Prim's Algorithm
// min priority queue(complete binary tree) 사용 (LL 사용하면 내부 가장 짧은 edge 찾기 O(E)필요)
// 시작 node 잡기, 방문
// 모두 방문할 때까지 O(n)
    // 현재 방문한 node에서 이어지는 edge 모두 queue에 넣기 O(E)
    // queue에 있는 edge중 가장 짧은 거리 edge 선택 O(log(n))
    // queue에서 제거
    // 해당 edge너머 node 방문


// 2. Kruskal's Algorithm
// 전체 edge의 weight처음부터 기억
// 거리 짧은 edge부터 추가
    // acyclic 매번 확인

// 복잡도 : 내부 알고리즘 무엇을 쓰는가에 따라 달라진다

// 복잡도 계산 연습 매우 중요하다!

// Kruskal은 edge개수에 비례하는 복잡도 가진다, 왜냐하면 전체 edge를 저장해서 계산
// Prims는 전체 vertex개수가 중요

// 따라서 주어진 edge가 dense하면 prims가 적합, sparse하면 Kruskal이 적합하다