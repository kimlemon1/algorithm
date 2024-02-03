#include <iostream>
#include <vector>
#include <list>
using namespace std;

class undiGraph{
    vector<vector<int>> edge;
    int vnum;
    public:
        undiGraph(vector<vector<int>> e, int v_num)
        :vnum(v_num){
            // 벡터 크기 잡아야한다!
            edge.resize(vnum);
            // 우리 아는 딕셔너리 형태로 바꿈
            for (vector<int> set:e){
                int x = set[0];
                int y = set[1];

                edge[x].push_back(y);
                edge[y].push_back(x);
            }
        }

        void bfs();
        void dfs();
        
        void help_recur(int i, vector<int>& unvisited);

};


int main(){
    int vnum = 10;
    vector<vector<int>> e{{0,1},{1,4},{1,5},{2,3},{4,6},{5,6},{5,7},{6,9},{7,8}};
    undiGraph G(e, vnum);
    
    G.bfs();
    cout << endl;
    G.dfs();
    cout << endl;


    return 0;
}

void undiGraph::bfs(){
    vector<int> unvisited(vnum, 1);
    list<int> queue;
    for (int i=0;i <vnum; i++){
        if (unvisited[i]==1){
            unvisited[i] = 0;
            cout << i << "\t";
            queue.push_back(i);
            while (!queue.empty()){
                int cur = queue.front();
                queue.pop_front();
                vector<int> cur_edge = edge[cur];
                for (auto node:cur_edge){
                    if(unvisited[node] == 1){
                        unvisited[node] = 0;
                        queue.push_back(node);
                        cout << node << "\t";
                    }
                }
            }
        }
    }
}

void undiGraph::dfs(){
    vector<int> unvisited(vnum, 1);
    for (int i = 0; i < vnum; i++){
        help_recur(i, unvisited);
    }
}

void undiGraph::help_recur(int i, vector<int>& unvisited){
    if (unvisited[i] == 1){
        unvisited[i] = 0;
        // preoder print
        for (int node:edge[i]){
            help_recur(node, unvisited);
        }
        // postorder print
        cout << i << "\t";
    }
}