#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 9

bool adj[MAX][MAX];
int  depth[MAX];

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

    printf("done\n");
}
void DFS(int x, int px) // px is the parent of x
{
    for (int y=0; y<MAX; y++)
        if (adj[x][y] && y != px) // Not be parent so be child.
        {
            depth[y] = depth[x] + 1;
            DFS(y, x);
        }
}
void show(int root)
{
    printf("Depth of each node\n");
    printf("Root is %d\n", root+1);
    printf("--------------------------\n");

    for (int i=0; i<MAX; i++)
        printf("%d ", i+1);

    printf("\n");

    for (int i=0; i<MAX; i++) {
        printf("%d ", depth[i]);
    }

    printf("\n\n");
}
int main(int argc, char ** argv)
{
    int root;
    init();

    printf("Enter root to perform DFS tree building\n");
    while (scanf("%d", &root) && (root > 0) && root < MAX)
    {
        memset(depth, 0, sizeof(depth));
        DFS(root, root); 
        show(root);
    }
    return 0;
}

