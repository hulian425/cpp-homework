#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <conio.h>
using namespace std;

const int N = 19;
int xx[4] = { -1, 0, 1, 0 };
int yy[4] = { 0, -1, 0, 1 };
class Pat {
public:
	Pat();
	~Pat();
	void Print_pat();
	void Move(int opt);
	void auto_move();
	void Gameover();
	void food();
	// 友元函数
	friend void start();
private:
	char m[N + 1][N + 1];
	char dir = 's';
	int hx = 4;
	int hy = 4;
	int wx = 3;
	int wy = 4;
};
Pat::Pat()
{
	for (int i = 0; i < N + 1; i++)
		for (int j = 0; j < N + 1; j++)
		{
			m[i][j] = ' ';
			if (i == 0 || i == N) m[i][j] = '#';
			else if (j == 0 || j == N) m[i][j] = '#';
		}
	m[4][4] = '*';
	m[3][4] = '*';

}
void Pat::Print_pat()
{
	for (int i = 0; i < N + 1; i++) {
		cout << "                                        ";
		for (int j = 0; j < N + 1; j++)
		{
			printf("%C%C", m[i][j], j == N ? '\n' : 0);
		}
	}
}

void Pat::food()
{
	for (;;) {
		int x = rand() % (N - 2) + 1;
		int y = rand() % (N - 2) + 1;
		if (m[x][y] == ' ')
		{
			m[x][y] = '@';
			break;
		}
	}
}
Pat::~Pat()
{
	
}
void Pat::auto_move()
{
	// 输入操作控制蛇头方向
	
	while (true)
	{
		bool IfEat = false;
		char c;
		
		// 非阻塞函数
		if (_kbhit()) {
			c = _getche();
			
			// 防误触
			if (c == 's' || c == 'w' || c == 'a' || c == 'd')
			{
				// 不能直接掉头
				if ((dir == 's' && c == 'w') || (dir == 'w' && c == 's') || (dir == 'a' && c == 'd') || (dir == 'd' && c == 'a'))
					;
				else
					dir = c;
			}
		}
		if (dir == 's')
		{
			hx = hx + 1;
		}
		else if (dir == 'w')
		{
			hx = hx - 1;
		}
		else if (dir == 'a')
		{
			hy -= 1;
		}
		else if (dir == 'd')
		{
			hy += 1;
		}

		// 假如吃到食物
		if (m[hx][hy] == '@')
		{
			IfEat = true;
			m[hx][hy] = ' ';
		}
		// 如果吃到了东西，重新更新食物，其他不做处理
		if (IfEat) {
			food();
			IfEat = false;
		}
		else {
			for (int i = 0; i < 4; i++)
			{
				int dx = wx + xx[i];
				int dy = wy + yy[i];
				if (m[dx][dy] == '*')
				{
					m[wx][wy] = ' ';
					wx = dx;
					wy = dy;
					break;
				}
			}
			
		}
		// 撞到墙或自己游戏结束
		if (m[hx][hy] == '#' || m[hx][hy] == '*')
		{
			Gameover();
			return;
		}
		else m[hx][hy] = '*';
		
		system("cls");
		Print_pat();
	}
}
void start()
{
	Pat x;
	cout << "						PUSH ENTER START GAME" << endl;
	getchar();
	x.Print_pat();
	x.food();
	x.auto_move();
}
void Pat::Gameover()
{
	cout << "						GAME OVER" << endl;
	cout << "						Do you want to leave?" << endl;
	cout << "						input Y to leave" << endl;
	char key;
	key = getchar();
	if (key == 'Y')
		;
	else start();
}

int main()
{
	start();
	
	return 0;
}


