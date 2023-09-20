### 다익스트라(Dijkstra)   
* DP를 이용한 대표적인 최단경로 탐색 알고리즘 --> DP인 이뉴는 최단 거리는 여러 개의 최단 거리로 이루어져 있기 때문이다   
* 특정한 하나의 정점에서 다른 모든 정점으로 가는 최단 경로를 알려주며 이 때 음의 간선을 포함할 수 없다.

### Example   
![image](https://github.com/Hwangwoosam/BOJ/assets/61729954/24662df5-271a-40fc-a3d3-aefa0321039f)   
|||||||   
|---|---|---|---|---|---|   
| 0 | 2 | 5 | 1 |INF|INF|
| 2 | 0 | 3 | 2 |INF|INF|
| 5 | 3 | 0 | 3 | 1 | 5 |
| 1 | 2 | 3 | 0 | 1 |INF|
|INF|INF| 5 | 1 | 0 | 2 |
|INF|INF| 5 |INF| 2 | 0 |   

초기 표에서 Node 1에서 부터 최단 거리를 찾게 되면 노드 1의 거리표의 변화는 아래와 같이 변하게 된다.

|||||||   
|---|---|---|---|---|---|   
| 0 | 2 | 3 | 1 | 2 | 4 |   


### 시간복잡도 O(N^2)일 경우   
정점의 갯수가 많은데 간선은 적을 때 비효율적으로 작동할 가능성이 존재.   

```cpp
int a[][] = {
 {0,2,5,1,INF,INF},
 {2,0,3,2,INF,INF},
 {5,3,0,3,1,5},
 {INF,INF,1,1,0,2},
 {INF,INF,5,INF,2,0},
};

int num = 6
bool v[6];
int distance[6];

int getCloseVertex(){
  int min = INF;
  int idx = 0;
  for(int i = 0; i < num; i++){
    if(d[i] < min && !v[i]){
       min = d[i];
       idx = i;
    }
  }
  return idx;
}

void dijkstra(int start){
  for(int i = 0; i < num; i++){
    distance[i] = a[start][i];
  }
  v[start] = true;
  for(int i = 0; i < num -2; i++){
    int cur = getCloseVertex();
    v[cur] = true;
    for(int j = 0; j < num; j++){
      if(!v[j]){
        if(distance[cur] + a[cur][j] < distance[j]){
          distance[j] = distance[cur] + a[cur][j];
        }
      }
    }
  }
}
```   
### 시간복잡도 O(N*logN)일 경우 --> 힙 사용   

```cpp
void dijkstra(int start){
  distance[start] = 0;
  priority_queue<pair<int,int>> pq;
  pq.push({start,0});

  while(!pq.empty()){

    int cur = pq.top().first;
    int dist = -pq.top().second; // 값이 작은 것이 먼저 올 수 있도록 음수화
    pq.pop();

    if(distance[cur] < dist) continue;

    for(int i = 0; i < a[cur].size(); i++){
      int next = a[cur][i].first;
      int nextDistance = dist + a[cur][i].second;

      if(nextDistance < distance[next]){
        distance[next] = nextDistance;
        pq.push({next,-nextDistance));
      }

    }
  }
}
```
