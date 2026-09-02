#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_game{
    int h;
    int w;
    int i;
    int j;
    int it;
    char **bd;
}t_game;

void free_m(t_game *g){
    for(int i = 0; i < g->h; i++){
        free(g->bd[i]);
    }
    free(g->bd);
}
int fill(t_game *g){
    for(int i = 0; i < g->h; i++){
        // puts("hhh");
        g->bd[i] = calloc(g->w + 1, sizeof(char));
        if(!g->bd[i]){
            g->h = i;
            free_m(g);
            return 1;
        }
        for(int j = 0; j < g->w; j++){
            // puts("hhh");
            g->bd[i][j] = ' ';
        }
    }
    char c;
    int draw = 0;
    while(read(0, &c, 1) == 1){
        if(c == 'a' && g->j > 0) g->j--;
        if(c == 'd' && g->j < g->w - 1) g->j++;
        if(c == 'w' && g->i > 0) g->i--;
        if(c == 's' && g->i < g->h - 1) g->i++;
        if(c == 'x') draw = !draw;

        if(draw )
            g->bd[g->i][g->j] = 'O';
    }
    return 0;
}

void print_m(t_game *g){
    for(int i = 0; i < g->h; i++){
        puts(g->bd[i]);
        // putchar('\n');
    }
}
int check(t_game *g, int i, int j){
    int c = 0;
    for(int ii = i - 1; ii <= i + 1; ii++){
        for(int jj = j - 1; jj <= j + 1; jj++){
            if(ii >= 0 && ii < g->h && jj >= 0 && jj < g->w){
                if(g->bd[ii][jj] == 'O')
                    c++;
            }
        }
    }
    if(g->bd[i][j] == 'O')
        return c == 3 || c == 4;
    return c == 3;
}
int play(t_game *g){
    while(g->it--){
        char **tmp = calloc(g->h, sizeof(char *));
        if(!tmp){
            free_m(g);
            return -1;
        }
        for(int i = 0; i < g->h; i++){
            tmp[i] = calloc(g->w + 1, sizeof(char));
            if(!tmp[i]){
                free_m(g);
                g->bd = tmp;
                g->h = i;
                free_m(g);
                return -1;
            }
            for(int j = 0; j < g->w ; j++){
                tmp[i][j] = check(g, i, j) ? 'O' : ' ';
            }
        }
        free_m(g);
        g->bd = tmp;
    }
    return 0;
}

int main(int ac, char **av){
    if(ac != 4)
        return 1;
    t_game g;
    g.w = atoi(av[1]);
    g.h = atoi(av[2]);
    g.it = atoi(av[3]);
    g.i = 0;
    g.j = 0;
    g.bd = calloc(g.h, sizeof(char *));
    if(!g.bd)
        return 1;

    if(fill(&g))
        return 1;
    // puts("hhh");
    // print_m(&g);

    if(play(&g)){
        return 1;
    }
    print_m(&g);
    free_m(&g);
    return 0;
}