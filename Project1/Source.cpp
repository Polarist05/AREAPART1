#include<stdio.h>
#include<string>
#include<iostream>
#include<queue>
struct Pos
{
	int x, y;
	Pos(int x, int y) :x(x), y(y) {}
};
bool bHorizontalEdge[100][100] = {}, bVerticleEdge[100][100] = {}, havePast[100][100] = {};
int sizeY, sizeX, lastPosY, lastPosX, ans;
int main() {
	std::cin >> sizeY >> sizeX >> lastPosY >> lastPosX;
	lastPosY--; lastPosX--;
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t j = 0; j < sizeX; j++)
		{
			char c;
			std::cin >> c;
			if (c == 'B') {
				bVerticleEdge[i][j + 1] = true;
				bHorizontalEdge[i + 1][j] = true;
			}
			if (c == 'R') {
				bVerticleEdge[i][j + 1] = true;
			}
			if (c == 'D') {
				bHorizontalEdge[i + 1][j] = true;
			}
		}
	}
	std::queue<Pos> currentQueue, nextQueue;
	havePast[0][0] = true;
	currentQueue.push(Pos(0, 0));
	ans = 0;
	while (ans < sizeX * sizeY) {
		while (!currentQueue.empty()) {
			Pos position = currentQueue.front();
			if (position.x == lastPosX && position.y == lastPosY) {
				printf("%d", ans);
				return 0;
			}
			if (position.y - 1 >= 0 && !havePast[position.y - 1][position.x] && bHorizontalEdge[position.y][position.x]) {
				havePast[position.y - 1][position.x] = true;
				nextQueue.push(Pos(position.x, position.y - 1));
			}
			if (position.y + 1 < sizeY && !havePast[position.y + 1][position.x] && bHorizontalEdge[position.y + 1][position.x]) {
				havePast[position.y + 1][position.x] = true;
				nextQueue.push(Pos(position.x, position.y + 1));
			}
			if (position.x - 1 >= 0 && !havePast[position.y][position.x - 1] && bVerticleEdge[position.y][position.x]) {
				havePast[position.y][position.x - 1] = true;
				nextQueue.push(Pos(position.x - 1, position.y));
			}
			if (position.x + 1 < sizeX && !havePast[position.y][position.x + 1] && bVerticleEdge[position.y][position.x + 1]) {
				havePast[position.y][position.x + 1] = true;
				nextQueue.push(Pos(position.x + 1, position.y));
			}
			currentQueue.pop();
		}
		currentQueue = nextQueue;
		while (!nextQueue.empty())
			nextQueue.pop();
		ans++;
	}
	printf("Null");
}
/*
4 4 2 2
B R D D
D R B D
R R R D
N N N N
*/