#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
using namespace std;


class GNode{
public :
    string id;
    char color;
    GNode(string id, char color='W') : id(id), color(color) {}
};

vector<string> bfs(map<GNode*, vector<GNode*>> G, GNode* start){
    vector<GNode*> visited{start};
    list<GNode*> que;
    que.push_front(start);

    while (que.size() !=0){
        GNode* cur = que.back();
        que.pop_back();

        vector<GNode*> adj_vertex = G[cur];
        for (GNode* adj:adj_vertex){
            if (find(visited.begin(), visited.end(), adj)== visited.end()){
                visited.push_back(adj);
                que.push_front(adj);
            }
        }
    }
    vector<string> ans;
    for (GNode* node:visited){
        ans.push_back(node->id);
    }
    return ans;
}

vector<string> dfs(map<GNode*, vector<GNode*>> G, GNode* start){
    vector<GNode*> visited{};
    dfs_recur(G, visited, start);

}

void dfs_recur(map<GNode*, vector<GNode*>> G, vector<GNode*> visited, GNode* cur){
    if (find(visited.begin(), visited.end(), cur) == visited.end()){

        // preorder
        visited.push_back(cur);
        vector<GNode*> adj_vectors = G[cur];
        for (GNode* node: adj_vectors){
            dfs_recur(G, visited, node);
        }
        // postorder
        //visited.push_back(cur);
    }
}

// 시작점에서 방문 가능한 모든 지점
vector<string> all_reachable_node(map<GNode*, vector<GNode*>>& G){
    vector<GNode*> key_vec;
    for (auto it = G.begin(); it != G.end(); it++){
        key_vec.push_back(it->first);
    }

    vector<string> ans;

    for (GNode* start:key_vec){
        vector<string> path = bfs(G, start);
        if (path.size() == key_vec.size()){
            ans.push_back(start->id);
        }
    }
    return ans;
}



int main() {
    GNode *A = new GNode("A"), *B = new GNode("B"), *C = new GNode("C"), 
          *D = new GNode("D"), *E = new GNode("E"), *F = new GNode("F");

    map<GNode*, vector<GNode*>> G;
    G[A] = {C, D};
    G[B] = {A, E};
    G[C] = {B, D};
    G[D] = {F};
    G[E] = {F};
    G[F] = {};

    auto result = all_reachable_node(G);


    for (auto node : result) {
        cout << node << " ";
    }
    // Correct memory cleanup
    delete A; delete B; delete C; delete D; delete E; delete F;

    return 0;
}

