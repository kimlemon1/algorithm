#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 4
// 미로 matrix형태, 출발점 2개 이상 BFS
int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize);

int main(){
    char maze[ROW][COL] = {{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    char *mazeptr[ROW];
    for (int i =0; i < ROW; i++){
        mazeptr[i] = maze[i];
    }
    int mazesize = ROW;
    int mazecolsize;
    int ensize = 2;
    int start[2] = {1,2};

    int ans = nearestExit(mazeptr, mazesize, &mazecolsize, start, ensize);
    printf("%d\n", ans);
}

int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize) {
    // 이미 mazeColSize 줬다!
    //*mazeColSize = sizeof(maze[0])/sizeof(maze[0][0]);
    
    int ans = -1;
    int **dist = (int**)malloc(sizeof(int*)*mazeSize);
    for (int i =0; i < mazeSize; i++){
        dist[i] = (int*)malloc(sizeof(int)*(*mazeColSize));
        for (int j =0; j < *mazeColSize; j++){
            dist[i][j] = -1;
        }
    }
    int x0 = entrance[0];
    int y0 = entrance[1];
    dist[x0][y0] = 0;

    int **queue = (int**)malloc(sizeof(int*)*(mazeSize*(*mazeColSize)));

    // queue각 행을 첨부터 초기화 하지 말고 값을 넣을 때 초기화 하자!!
    // for (int i = 0; i<mazeSize*(*mazeColSize);i++){
    //     queue[i] = (int*)malloc(sizeof(int)*entranceSize);
    // }
    int q_s =0, q_e = 0;
    queue[q_e] = (int*)malloc(sizeof(int)*entranceSize);
    queue[q_e][0] = x0;
    queue[q_e][1] = y0;
    q_e++;

    int dxdy[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int end_flag = 0;

    while(q_s < q_e){
        int *cur = queue[q_s++];
        
        int x = cur[0];
        int y = cur[1];
        free(cur);

        for (int i = 0; i < 4; i++){
            
            int dx = dxdy[i][0];
            int dy = dxdy[i][1];

            int new_x = x + dx;
            int new_y = y + dy;
            if (new_x >=0 && new_x < mazeSize && new_y >=0 && new_y < *mazeColSize){
                char newpoint = maze[new_x][new_y];
                if (newpoint == '.' && dist[new_x][new_y] == -1){
                    
                    queue[q_e] = (int*)malloc(sizeof(int)*entranceSize);
                    queue[q_e][0] = new_x;
                    queue[q_e][1] = new_y;
                    q_e++;
                    dist[new_x][new_y] = dist[x][y]+1;

                    if (new_x == 0 || new_x == mazeSize-1 || new_y == 0 || new_y == *mazeColSize-1){
                        ans = dist[new_x][new_y]; 
                        end_flag = 1;
                    }
                }
            }
            if (end_flag == 1) break;
        }
        if (end_flag==1) break;
    }

    // 2차원은 free도 배열 하나씩 해야 한다!
    for (int i =q_s; i < q_e; i++){
        free(queue[i]);
    }
    free(queue);

    for (int i = 0; i < mazeSize; i++){
        free(dist[i]);
    }
    free(dist);

    return ans;
}