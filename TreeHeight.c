#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 9
#define max(x,y) (((x)>(y))?(x):(y))

bool adj[MAX][MAX];

void init()
{
    printf("Reading map... \n");

    int i, j;
    for (i=0; i<MAX; i++)
        for (j=0; j<MAX; j++) {
            char c = getchar();
            if(c == '\n') c = getchar();
            adj[i][j] = (c == '1')?true:false;
        }

    printf("done\n\n");
}
int  DFS(int x, int px) // px is the parent of x
{
    int h = 0;

    for (int y=0; y<MAX; y++)
        if (adj[x][y] && y != px) // Not be parent so be child.
            h = max(h, DFS(y, x)+1);

    return h;
}
void show(int root, int height)
{
    printf("Use %d as root, height will be %d\n", root, height);
}
int main(int argc, char ** argv)
{
    int root;
    init();

    printf("Enter root to perform DFS tree building\n");
    while (scanf("%d", &root) && (root > 0) && root < MAX)
    {
        int height = DFS(root, root); 
        show(root, height);
    }
    return 0;
}

