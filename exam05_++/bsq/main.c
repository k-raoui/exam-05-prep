#include <stdio.h>
#include <stdlib.h>

void free_array(void** arr, int size, FILE *f) {
    int i = 0;
    while (i < size) {
        free(arr[i]);
        arr[i] = NULL;
        i++;
    }
    if (f != NULL && f != stdin)
        fclose(f);
}

int validate_line(char *line, char empty, char obs, char full) {
    int i = 0;
    while (line[i]) {
        if (line[i] != empty && line[i] != obs && line[i] != full)
            return 0;
        i++;
    }
    return 1;
}

int validate_args(char empty, char obs, char full) {
    if (empty == obs || obs == full || empty == full)
        return 0;
    if (!(empty >= 13 && empty < 127))
        return 0;
    if (!(obs >= 13 && obs < 127))
        return 0;
    if (!(full >= 13 && full < 127))
        return 0;
    return 1;
}

int strlen_(char *s) {
    int i = 0;
    // if (!s)
    //     return 0;
    while (s[i])
        i++;
    return i;
}

int min_(int a, int b) {
    return a < b ? a : b;
}

int main (int ac, char **av) {
    FILE *f = stdin;
    if (ac == 2)
        f = fopen(av[1], "r");
    if (!f)
        return (printf("Error: invalid map\n") ,1);

    int height;
    char empty, obs, full;
    if (fscanf(f, "%d%c%c%c\n", &height, &empty, &obs, &full) != 4 || !validate_args(empty, obs, full))
        return (printf("Error: invalid map\n") ,1);
    printf("hh\n");
    char **grid = calloc(height, sizeof(char*));
    if (!grid)
        return (printf("Error: allocation\n") ,1);

    int width = 0;

    for (int i = 0; i < height; i++) {
        char *line = NULL;
        size_t s;

        if (getline(&line, &s, f) == -1) {
            return (free_array((void**)grid, i, f), free(grid) , 1);
        }

        grid[i] = line;
        if (i == 0)
            width = strlen_(grid[i]) - 1;

        if (grid[i][width] == '\n')
            grid[i][width] = '\0';

        if (width != strlen_(grid[i]) || !validate_line(line, empty, obs, full))
            return (free_array((void**)grid, height, f), free(grid), 1);
    }
    
    int **dp = calloc(height, sizeof(int*));
    if (!dp)
        return (free_array((void**)grid, height, f), free(grid), 1);
    for (int i = 0; i < height; i++) {
        dp[i] = calloc(width, sizeof(int));
        if (!dp[i]) {
            (free_array((void**)grid, height, f), free(grid));
            (free_array((void**)dp, height, f), free(dp));
            return (1);
        }
    }
    
    int max_size = 0;
    int max_i = 0;
    int max_j = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == obs)
                dp[i][j] = 0;
            else if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 1 + min_(dp[i][j - 1], min_(dp[i - 1][j - 1], dp[i - 1][j]));
            if (dp[i][j] > max_size) {
                max_size = dp[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    
    for(int i = 0; i < height; i++){
    	for(int j = 0; j < width; j++){
    		printf("%d ", dp[i][j]);
    	}
        printf("\n");
    }
        printf("\n");


    int start_i = max_i - max_size + 1;
    int start_j = max_j - max_size + 1;
    for (int i = start_i; i < start_i + max_size ;i++) {
        for (int j = start_j; j < start_j + max_size ;j++) {
            grid[i][j] = full;
        }
    }

    for (int i = 0; i < height; i++) {
        fputs(grid[i], stdout);
        fputs("\n", stdout);
    }
    free_array((void**)grid, height, f);
    free(grid);
    free_array((void**)dp, height, NULL);
    free(dp);
    return 0;
}

