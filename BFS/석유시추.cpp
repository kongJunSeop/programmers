#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> land) {
	// 행, 열의 크기 구함
	int r = land.size(), c = land[0].size();
	// 4방향으로 이동
	int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
	// 각 열의 석유 양을 저장할 배열
	vector<int> col_oil(c, 0);
	// 방문 여부를 확인할 2차원 bool 형 배열
	vector<vector<bool>>visited(r, vector<bool>(c, false));
	// 2중 for문으로 0,0부터 끝까지 순회
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			// 만약 석유가 있고, 아직 방문하지 않은 땅을 만나면
			if (land[i][j] == 1 && !visited[i][j]) {
				// 대기열 역할을 할 queue 생성
				queue<pair<int, int>> q;
				// 큐에 좌표 삽입
				q.push({ i,j });
				// 방문여부 true 로 바꿈
				visited[i][j] = true;
				// 현재 위치한 석유의 size를 구할 정수형 변수 생성
				int size = 0;
				// 중복 방지를 위한 set cols 생성
				set<int> cols;
				// 대기열 q에 있던 값이 모두 사라질 때 까지 반복
				while (!q.empty()) {
					// x,y좌표 구함
					int x = q.front().first;
					int y = q.front().second;
					// x,y 를 구하고 삭제
					q.pop();
					// size 를 키워줌
					size++;
					// col 을 기준으로 값을 구하기 때문에 x값은 필요없음
					cols.insert(y);
					// 4방향으로 이동
					for (int d = 0; d < 4; d++) {
						// 새로운 x, y 값
						int nx = x + dx[d];
						int ny = y + dy[d];
						//  값이 범위를 벗어나지 않았는지 확인
						if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
							// 범위 안이라면 값이 1이고 아직 방문을 하지 않았는지 확인
							if (land[nx][ny] == 1 && !visited[nx][ny]) {
								// 좌표를 대기열에 삽입
								q.push({ nx,ny });
								// 방문 여부 갱신
								visited[nx][ny] = 1;
							}
						}
					}
				}
				// 열별로 석유량을 더해줌
				for (int col : cols)col_oil[col] += size;
			}
		}
	}
	// max_element는 주소를 반환하기 때문에 *로 받아줌
	return *max_element(col_oil.begin(), col_oil.end());
}
