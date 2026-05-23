#include <iostream>
#include <Windows.h>

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

const int WIDHT = 17;
const int HEIGHT = 10;
const int MAX_LEN_SNAKE = (WIDHT - 3) * (HEIGHT - 2);

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

int snake_dir = UP;

bool isRunning = true;

char map[] =
"###############\n"
"#             #\n"
"#             #\n"
"#             #\n"
"#             #\n"
"#             #\n"
"#             #\n"
"#             #\n"
"###############\n";

char snake = '0';
int snake_x[MAX_LEN_SNAKE] = { 0 };
int snake_y[MAX_LEN_SNAKE] = { 0 };
int snake_len = 1;

int main()
{
    snake_x[0] = WIDHT / 2;
    snake_y[0] = HEIGHT / 2;
    int time = clock();
    while (isRunning) {
        if ((clock() - time) / CLOCKS_PER_SEC >= 1) {
            time = clock();
            for (int i = snake_len - 2; i >= 0; --i) {
                snake_x[i + 1] = snake_x[i];
                snake_y[i + 1] = snake_y[i];
            }

            if (snake_dir == UP) {
                --snake_y[0];
            }
            if (snake_dir == DOWN) {
                ++snake_x[0];
            }
            if (snake_dir == LEFT) {
                ++snake_x[0];
            }
            if (snake_dir == RIGHT) {
                --snake_x[0];
            }

            gotoxy(0, 0);
            std::cout << "Length: " << snake_len << std::endl;
            for (int i = 0; i < snake_len; ++i) {
                map[snake_y[i] * WIDHT + snake_x[i]] = snake;

            }
            std::cout << map;
            for (int i = 0; i < snake_len; i++) {
                map[snake_y[i] * WIDHT + snake_x[i]] = ' ';
            }
        }
    }
}
