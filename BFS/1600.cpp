#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int map[200][200];
int visit[200][200][31];

int K,W,H;

int dir_horse[8][2] = {-1,-2, -2,-11, -2,1, -1,2, 1,2, 2,1, 2,-1, 1,-2};
int dir[4][2] = {1,0,-1,0,0,1,0,-1};

void BFS()
{
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    visit[0][0][0] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Cnt = Q.front().second.first;
        int Ability = Q.front().second.second;
        Q.pop();
 
        if (x == H - 1 && y == W - 1)
        {
            cout << Cnt << endl;
            return;
        }
        if (Ability < K)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = x + dir_horse[i][0];
                int ny = y + dir_horse[i][1];
                if (nx >= 0 && ny >= 0 && nx < H && ny < W)
                {
                    if (map[nx][ny] == 0 && visit[nx][ny][Ability + 1] == false)
                    {
                        visit[nx][ny][Ability + 1] = true;
                        Q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Ability + 1)));
                    }
                }
            }
        }
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
 
            if (nx >= 0 && ny >= 0 && nx < H && ny < W)
            {
                if (map[nx][ny] == 0 && visit[nx][ny][Ability] == false)
                {
                    visit[nx][ny][Ability] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Ability)));
                }
            }
        }
    }
    cout << -1 << endl;
}

int main(){
    ios_base :: sync_with_stdio(false); 
	cin.tie( NULL); 
	cout.tie(NULL);

    freopen("test.txt","r",stdin);

    cin >> K >> W >> H;
    for(int i = 0; i < H; i++){
        for(int j = 0; j <W; j++){
            cin >> map[i][j];
        }
    }
   BFS();

}