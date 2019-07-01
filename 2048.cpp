#include<graphics.h>
#include<iostream>
#include<ctype.h>
#include<stdlib.h>
#include<ctime>
#include<vector>
#include<windows.h>

using namespace std;

#define ROW 4
#define COL 4

class Game
{
public:
	Game()
	{
		memset(_arr, 0, ROW * COL * sizeof(int));
	}

	~Game(){}

	void draw()
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				PIMAGE img;
				img = newimage();
				switch (_arr[i][j])
				{
				case 0:
				{
						  getimage(img, "0.jpg");
						  putimage(j * 180, i * 180, img);
						  break;
				}
				case 2:
				{
						  getimage(img, "2.gif");
						  putimage(j * 180, i * 180, img);
						  break;
				}
				case 4:
				{
						  getimage(img, "4.gif");
						  putimage(j * 180, i * 180, img);
						  break;
				}
				case 8:
				{
						  getimage(img, "8.gif");
						  putimage(j * 180, i * 180, img);
						  break;
				}
				case 16:
				{
						   getimage(img, "16.gif");
						   putimage(j * 180, i * 180, img);
						   break;
				}
				case 32:
				{
						   getimage(img, "32.gif");
						   putimage(j * 180, i * 180, img);
						   break;
				}
				case 64:
				{
						   getimage(img, "64.gif");
						   putimage(j * 180, i * 180, img);
						   break;
				}
				case 128:
				{
							getimage(img, "128.gif");
							putimage(j * 180, i * 180, img);
							break;
				}
				case 256:
				{
							getimage(img, "256.gif");
							putimage(j * 180, i * 180, img);
							break;
				}
				case 512:
				{
							getimage(img, "512.gif");
							putimage(j * 180, i * 180, img);
							break;
				}
				case 1024:
				{
							 getimage(img, "1024.gif");
							 putimage(j * 180, i * 180, img);
							 break;
				}
				case 2048:
				{
							 getimage(img, "2048.gif");
							 putimage(j * 180, i * 180, img);
							 break;
				}
				}
			}
		}
	}

	int Getkey(int k)		//获取键盘的键值
	{
		k = getch();
		return k;
	}

	vector<vector<int>> zero_num(int* p)
	{
		int i, j;
		int k = 0;

		vector<vector<int>> v(16, vector<int>());

		for (i = 0; i<4; i++)
		{
			for (j = 0; j<4; j++)
			{
				if (_arr[i][j] == 0)
				{
					v[k].push_back(i);
					v[k].push_back(j);
					k++;
				}
			}
		}
		*p = k;
		return v;
	}

	bool CreatNumber()
	{
		int k = 0;
		vector<vector<int>> v;
		v = zero_num(&k);

		if (k>0)
		{
			srand(time(0));
			int m = rand() % k;
			int x = v[m][0];
			int y = v[m][1];
			srand(time(0));
			int z = rand() % 2 + 1;
			_arr[x][y] = pow(2.0, z);
			return true;
		}
		return false;
	}

	void Process(int res)
	{
		switch (res)
		{
		case 'w':
			for (int row = 1; row < ROW; ++row)
			{
				for (int tmp = row; tmp >= 1; --tmp)
				{
					for (int col = 0; col < COL; ++col)
					{
						if (_arr[tmp - 1][col] == 0)
						{
							_arr[tmp - 1][col] = _arr[tmp][col];
							_arr[tmp][col] = 0;
						}
						else
						{
							if (_arr[tmp - 1][col] == _arr[tmp][col])
							{
								_arr[tmp - 1][col] *= 2;
								_arr[tmp][col] = 0;
							}

						}
					}
				}
			}
			break;
		case 's':
			for (int row = ROW - 2; row >= 0; --row)
			{
				for (int tmp = row; tmp < ROW - 1; ++tmp)
				{
					for (int col = 0; col < COL; ++col)
					{
						if (_arr[tmp + 1][col] == 0)
						{
							_arr[tmp + 1][col] = _arr[tmp][col];
							_arr[tmp][col] = 0;
						}
						else
						{
							if (_arr[tmp + 1][col] == _arr[tmp][col])
							{
								_arr[tmp + 1][col] *= 2;
								_arr[tmp][col] = 0;
							}

						}
					}
				}
			}
			break;
		case 'a':
			for (int col = 1; col < COL; ++col)
			{
				for (int tmp = col; tmp >= 1; --tmp)
				{
					for (int row = 0; row < ROW; ++row)
					{
						if (_arr[row][tmp - 1] == 0)
						{
							_arr[row][tmp - 1] = _arr[row][tmp];
							_arr[row][tmp] = 0;
						}
						else
						{
							if (_arr[row][tmp - 1] == _arr[row][tmp])
							{
								_arr[row][tmp - 1] *= 2;
								_arr[row][tmp] = 0;
							}

						}
					}
				}
			}
			break;
		case 'd':
			for (int col = COL - 2; col >= 0; --col)
			{
				for (int tmp = col; tmp <= COL - 2; ++tmp)
				{
					for (int row = 0; row < ROW; ++row)
					{
						if (_arr[row][tmp + 1] == 0)
						{
							_arr[row][tmp + 1] = _arr[row][tmp];
							_arr[row][tmp] = 0;
						}
						else
						{
							if (_arr[row][tmp + 1] == _arr[row][tmp])
							{
								_arr[row][tmp + 1] *= 2;
								_arr[row][tmp] = 0;
							}

						}
					}
				}
			}
			break;
		default:break;
		}
		CreatNumber();
	}

	bool isWin()
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				if (_arr[i][j] == 2048)
				{
					return true;
				}
			}
		}
		return false;
	}

	bool isLose()
	{
		for (int i = 0; i < ROW; ++i)
		{
			for (int j = 0; j < COL - 1; ++j)
			{
				if (!_arr[i][j] || (_arr[i][j] == _arr[i][j + 1]))
				{
					return false;
					break;
				}
			}
		}
		for (int j = 0; j< COL; ++j)
		{
			for (int i = 0; i < ROW - 1; ++i)
			{
				if (!_arr[i][j] || (_arr[i][j] == _arr[i + 1][j]))
				{
					return false;
					break;
				}
			}
		}
		return true;
	}

	void GameReady()
	{
		setbkmode(TRANSPARENT);
		setfont(15, 0, "楷体");
		setcolor(LIGHTRED);
		outtextxy(170, 80, "游戏操作：");
		outtextxy(260, 80, "Esc：退出游戏");
		outtextxy(380, 80, "上->W 下->S 左->A 右->D");
		outtextxy(290, 610, "按任意键进入游戏！");
	}

private:
	int _arr[ROW][COL];
};

int main()
{
	while (1)
	{
		Game game;
		initgraph(724, 690);
		PIMAGE img;
		img = newimage();
		getimage(img, "game.gif");
		putimage(60, 50, img);
		game.GameReady();
		getch();
		int res = 0;
		for (; is_run(); delay_fps(60))
		{
			if (game.isWin())
			{
				cleardevice();
				getimage(img, "win.gif");
				putimage(60, 50, img);
				break;
			}
			if (game.isLose())
			{
				cleardevice();
				getimage(img, "lose.gif");
				putimage(60, 50, img);
				break;
			}
			cleardevice();
			game.draw();
			res = getch(); 
			if (res == 27)
			{
				while (1)
				{
					setbkmode(TRANSPARENT);
					setfont(20, 0, "楷体");
					setcolor(LIGHTRED);
					outtextxy(290, 350, "是否退出游戏？");
					outtextxy(330, 380, "y or n");
					res = getch();
					if (res == 'n')
					{
						break;
					}
					else if (res == 'y')
					{
						return 0;
					}
				}
			}
			if (res == 'w' || res == 's' || res == 'a' || res == 'd')
			{
				game.Process(res);
			}
		}
		while (1)
		{
			setbkmode(TRANSPARENT);
			setfont(38, 0, "楷体");
			setcolor(LIGHTRED);
			outtextxy(290, 350, "是否重新开始游戏？");
			outtextxy(330, 380, "y or n");
			res = getch();
			if (res == 'n')
			{
				return 0;
			}
			else if (res == 'y')
			{
				break;
			}
		}
	}
	closegraph();
	return 0;
}
