#include <bits/stdc++.h>
#define maxn (int)1e3+10 //max size for the board
using namespace std;

int n,visitados=0;
int visited[maxn][maxn], grid[maxn][maxn], ok[maxn][maxn],A[8]={1,-1,0,0,0,0,-1,1};

int valido(int x, int y){return x>=1&&y>=1&&y<=n&&x<=n;}

int dfs(int x,int y){
  visited[x][y]=1;
  visitados++;
    pair<int,int>min={0,0};
    int minimo = maxn;
    for(int i=0;i<4;i++){
      if(minimo>grid[x+A[i]][y+A[i+4]]&&!visited[x+A[i]][y+A[i+4]]&&valido(x+A[i],y+A[i+4])){
        minimo = grid[x+A[i]][y+A[i+4]];
        min={x+A[i],y+A[i+4]};
      }
    }
    if(min.first==0&&min.second==0){
      if(visitados==n*n)return 1;
      return 0;
    }
    if(dfs(min.first,min.second))return 1;
    return 0;
}

int main(int argc, char const *argv[]) {

    cin>>n; //size of the board

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        cin>>grid[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            visitados=0;
            memset(visited,0,sizeof(visited));
            if(dfs(i,j)){ //checks if the current square is green (which corresponds to 1) or red (which corresponds to 0)
                ok[i][j]=1;
            }
            cout<<ok[i][j]<<" ";
            }
            cout<<endl;
    }
    return 0;
  }