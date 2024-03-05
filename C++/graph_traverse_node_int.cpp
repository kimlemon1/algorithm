#include <iostream>
#include <list>
#include <vector>

using namespace std;

// 우선 파이썬으로 구현 해보자 
// 그다음 사용되는 vector, list같은 constructor 이해 
// 직접 만들고 tree같은 것들도 만들자 
// 동적할당도 배워보자 

/*  Let's implement our class undi_graph that provides 
    (1) BFS, (2) DFS preorder, and (3) DFS postorder    */

// Define undi_graph
class undi_graph{
    int vNum;
    vector<vector<int>> neighbors; // 파이썬 dict처럼 각 vertex에 연결된 모든 vertex정리

    public:
        undi_graph(const int &num, const vector<vector<int>> &edges);

        void visit(const int& vertex);

        void bfs(void);

        void dfs(const int& mode);

        void dfs_help(const int& mode, const int& v, vector<bool>& visited);
};

int main(void) {
    // Graph construction using 10 vertices
    int myVNum = 10;
    vector<vector<int>> myEdges{
        {0,1}, {1,4}, {1,5}, {2,3}, {4,6}, {5,6}, {5,7}, {6,9}, {7,8}
    };
    undi_graph myGraph(myVNum, myEdges); // myGraph : instance!!

    cout << "[BFS] ";           // Breadth First Search
    myGraph.bfs();
    cout << endl;

    cout << "[DFS preorder] ";  // Depth First Search - Preorder
    myGraph.dfs(0);
    cout << endl;

    cout << "[DFS postorder] "; // Depth First Search - Postorder
    myGraph.dfs(1);
    cout << endl;

    return 0;
}

undi_graph::undi_graph(const int &num, const vector<vector<int>> &edges)
    : neighbors(num, vector<int>(0)) // vector(0) : empty vector
{
    vNum = num;

    for (int i =0; i < edges.size(); i++){ // vector에서 크기 반환 메소드 : size
    // 벡터 : 파이썬 리스트처럼 내부 리스트 크기가 달라도 된다!
        neighbors[edges[i][0]].push_back(edges[i][1]); // vector 크기 정의 안해도 처음부터 인덱싱이 가능하다? 안된다!! initialization list 사용!
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
}

void undi_graph::visit(const int& vertex){
    std::cout << vertex << " ";
}

void undi_graph::bfs(void){
    // tree search 와 차이점 : 이미 방문 했는지 여부 기억 필요 + 끊어진 vertex도 방문 필요

    // 방문 여부 확인 용 
    vector<bool> visited(this->vNum, false);
    list<int> q;
    // 모든 곳 돌기 위한 for
    for (int v= 0;v <vNum; v++){
        q.push_back(v);
        int currV;

        while (!q.empty()){
            currV = q.front();
            q.pop_front();

            if (!visited[currV]){
                visited[currV] = true;
                visit(currV);

                for (const auto& n: neighbors[currV]){ // for each 문에서도 함수처럼 &로 받고 const 사용할 수 있다!
                    q.push_back(n);
                }
            }
        }
    }
}


void undi_graph::dfs(const int& mode){
    vector<bool> visited(vNum, false);

    // tree 와 차이 : for loop
    for (int v = 0; v<vNum; v++){
        dfs_help(mode, v, visited);
    }
}

void undi_graph::dfs_help(const int& mode, const int& v, vector<bool>& visited){
    if (!visited[v]){
        visited[v] = true;
        if (mode == 0){
            visit(v);
        }
        for (const int& n : neighbors[v]){
            dfs_help(mode, n, visited);
        }

        if (mode == 1){
            visit(v);
        }
    }

}
