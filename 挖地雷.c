#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Menu() {
	printf("=============\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("=============\n");
	printf("请输入你的选择：");
	int choice;
	scanf("%d", &choice);
	return choice;
}
#define ROW 9
#define COL 9
#define mine_count 10
void Init(char show_map[ROW+2][COL+2],	char mine_map[ROW + 2][COL + 2]) {
	for (int row = 0; row < ROW + 2; ++row) {
		for (int col = 0; col < COL + 2; ++col) {
			show_map[row][col] = ' ';
		}
	}
	for (int row = 0; row < ROW + 2; ++row) {
		for (int col = 0; col < COL + 2; ++col) {
			mine_map[row][col] = '0';
		}
	}
	int Mine_count = mine_count;
	while (Mine_count>0) {
		int row = rand() % ROW + 1;
		int col = rand() % COL + 1;
		if (mine_map[row][col] == '1') {
			continue;
		}
		mine_map[row][col] = '1';
		--Mine_count;
	}
} 
void DisplayMap(char map[ROW + 2][COL + 2]) {
	printf("    ");
	for (int i = 1; i <= ROW; ++i) {
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= ROW; ++i) {
		printf("---");
	}
	printf("\n");
	for (int row = 1; row <= ROW; ++row) {
		printf(" %d| ",row);
		for (int col = 1; col <= COL; ++col) {
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}

void UpdateShowMap(char show_map[ROW + 2][COL + 2], char mine_map[ROW + 2][COL + 2], int row, int col) {
	int count = 0;
	if (mine_map[row - 1][col - 1] == '1') {
		++count; 
	}
	if (mine_map[row - 1][col] == '1') {
		++count;
	}
	if (mine_map[row - 1][col + 1] == '1') {
		++count;
	}
	if (mine_map[row][col - 1] == '1') {
		++count;
	}
	if (mine_map[row][col + 1] == '1') {
		++count;
	}
	if (mine_map[row + 1][col - 1] == '1') {
		++count;
	}
	if (mine_map[row + 1][col] == '1') {
		++count;
	}
	if (mine_map[row + 1][col + 1] == '1') {
		++count;
	}
	show_map[row][col] = '0' + count;
}

//int print(int row, int col, char mine_map[ROW+2][COL+2],char show_map[ROW+2][COL+2]) {
//	for (row = 0; row <= ROW; ++row) {
//		for (col = 0; col <= COL; ++col) {
//			if (mine_map[row][col] == '0') {
//				show_map[row][col] = 0;
//			} 
//		}
//	}
//	return show_map[row][col];
//}

void Game() {
	//在地图的外侧加上一圈边框，
	char show_map[ROW + 2][COL + 2];
	char mine_map[ROW + 2][COL + 2];
	//由于数组作为参数会隐式转换为指针；
	Init(show_map, mine_map);
	int safe_blank_count = 0;
	while (1) {
		DisplayMap(show_map);
		int row = 0;	
		int col = 0;
		printf("请输入坐标:");
		scanf("%d %d", &row, &col);
		if (row < 1 || row > ROW || col <1  || col > COL) {
		printf("您输入的坐标不合法，请重新输入！\n"); 
		continue;
		}
		if (mine_map[row][col] == '1') {
			printf("游戏结束！扫雷失败\n");
			break;
		}
		//if (mine_map[row][col] == '0') {
		//	print(row, col,mine_map,show_map);
		//}
		//验证是否扫雷成功
		++safe_blank_count;
		if (safe_blank_count == ROW*COL - mine_count) {
			printf("游戏结束，扫雷成功\n");
			break;
		}
		UpdateShowMap(show_map,mine_map,row,col);
		system("cls");
	}
	DisplayMap(mine_map);
}
int main() {
	srand((unsigned int)time(0));
	while (1) {
		int choice = Menu();
		if (choice == 0) {
			printf("goodbye!\n");
			break;
		}
		if (choice == 1) {
			Game();
		}
	}
	system("pause");
	return 0;
}