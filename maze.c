#include <stdio.h>
#include <stdlib.h>

struct Maze {
    char **maze;
    int x;
    int y;
};
void print_maze(struct Maze *maze);
void create_maze(struct Maze *maze)
{
    int x, y;
    char c;

    scanf("%d %d", &x, &y);
    maze->x = x;
    maze->y = y;
    getchar();

    maze->maze = malloc(y * sizeof(char*));
    for (int i = 0; i < y; ++i) {
        maze->maze[i] = malloc(sizeof(char *));
    }

    for (int i = 0; i < y; ++i) {
        for (int n = 0; n < (x + 1); ++n) {
            c = getchar();
            if (c != '\n') {
                maze->maze[i][n] = c;
            } else {
                maze->maze[i][n] = '\0';
            }
        }
    }
}
void destroy_maze(struct Maze *maze)
{
    for (int i = 0; i < maze->y; ++i) {
        free(maze->maze[i]);
    }
    free(maze->maze);
    free(maze);
}
void traverse_maze(struct Maze *maze, int from_x, int from_y)
{
    int pos_x[] = { 0, -1,  1,  0,};
    int pos_y[] = {-1,  0,  0,  1};
    int spaces = 0, tmp_x, tmp_y;
    char current;
    int special = 0, special_count = 0;

    for (int i = 0; i < 4; ++i) {
        tmp_x = from_x + pos_x[i];
        tmp_y = from_y + pos_y[i];
        current = maze->maze[tmp_y][tmp_x];

        if (!(tmp_x < 1 || tmp_x > (maze->x - 2) ||
              tmp_y < 1 || tmp_y > (maze->y - 2))) {
            if (current == 'S' || current == 'E' || current == '#') {
                ++special_count;
                special = 1;
            } else if (current == '.') {
                ++spaces;
                if (spaces == 2) {
                    break;
                }
            }
        }
    }
    if (special) {
        if (spaces == 1) {
            maze->maze[from_y][from_x] = '#';
        } else if (special_count > 1) {
            maze->maze[from_y][from_x] = '#';
        }
        special = 0;
    } else if (spaces == 1) {
        maze->maze[from_y][from_x] = '-';
    }
    special_count = 0;
}
void solve_maze(struct Maze *maze)
{
    int cur_x, cur_y;
    char current;
    int changed = 1;

    while (changed) {
        changed = 0;
        for (cur_y = 1; cur_y < (maze->y - 1); ++cur_y) {
            for (cur_x = 1; cur_x < (maze->x - 1); ++cur_x) {
                current = maze->maze[cur_y][cur_x];
                if (current == '.') {
                    changed = 1;
                    traverse_maze(maze, cur_x, cur_y);
                }
            }
        }
    }
}
void print_maze(struct Maze *maze)
{
    for (int i = 0; i < maze->y; ++i) {
        for (int n = 0; maze->maze[i][n] != '\0'; ++n) {
            printf("%c", maze->maze[i][n]);
        }
        printf("\n");
    }
}
void clear_maze(struct Maze *maze)
{
    char current;

    for (int i = 1; i < (maze->y - 1); ++i) {
        for (int j = 1; j < (maze->x - 1); ++j) {
            current = maze->maze[i][j];
            if (current == '-') {
                maze->maze[i][j] = ' ';
            }
        }
    }
}
int main(int argc, char *argv[])
{
    struct Maze *maze = malloc(sizeof(struct Maze));

    create_maze(maze);
    solve_maze(maze);
    clear_maze(maze);
    print_maze(maze);
    destroy_maze(maze);

    return 0;
}
