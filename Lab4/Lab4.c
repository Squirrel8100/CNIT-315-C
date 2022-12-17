/******************************************************************************
Logan Fish
CNIT 315 Lab Section 002 Wednesday 3:30 - 5:20
Lab 4 Maze Solution Program. 
*******************************************************************************/
#include <stdio.h>
#define columns 6
#define rows 6

int i; 
int k; 

// Maze
char maze[rows][columns] = {{'#', '#', '#', 'S', '#', '#'},
                         {'.', '.', '.', '.', '.', '#'},
                         {'#', '.', '#', '#', '#', '#'},
                         {'#', '.', '#', '#', '#', '#'},
                         {'.', '.', '.', '#', '.', 'G'},
                         {'#', '#', '.', '.', '.', '#'}};

void startLocation(int *SLrow, int *SLcol); //startLocation 
int mazeGo(int x, int y, char maze[rows][columns]); //mazeGo 
void Solution(); //Solution 

int main() // main
{
    int e, n;
    startLocation(&e, &n); // calling startLocation
    int x = 0, y = 0;
   
    if(mazeGo(e, n, maze)) //calling mazeGo
    {
        maze[e][n] = 'S';
        Solution(); // calling Solution
    }
    else
        printf("Solution is not available\n"); //not avbailable message
    return 0;
}


int mazeGo(int x, int y, char maze[rows][columns]) //mazeGo function
{
    printf("%d %d\n", x, y);
    Solution();
   
    if(x >= 0 && y >= 0 && x < rows && y < columns)
    {
        if(maze[x][y] == 'G') // success if the robot reaches the end of the maze.
        {
            return 1;
        }
       
        else
        if(maze[x][y] == '.' || maze[x][y] == 'S')
        {
            maze[x][y] = '+';
       
       
            if(mazeGo(x, y + 1, maze)) //robot go South.
            {
                return 1;
            }
       
            if(mazeGo(x, y - 1, maze)) //robot go North.
            {
                return 1;
            }
       
            if(mazeGo(x + 1, y, maze)) //robot go East.
            {
                return 1;
            }
       
            if(mazeGo(x - 1, y, maze)) //robot go West.
            {
                return 1;
            }
       
            maze[x][y] = '.'; // returning back into the maze.
            return 0;
        }
        return 0;
    }
    return 0;
}

void Solution() //Solution Function
{
   
    for(i = 0; i<rows; i++)
    {
        for(k=0;k<columns;k++)
        {
            printf("%c\t", maze[i][k]);
        }
        printf("\n\n");
    }
}

void startLocation(int *SLrow, int *SLcol) //startLocation function
{
   
    for(i=0; i<rows; i++)
    {
        for(k =0; k<columns; k++)
        {
            if(maze[i][k] == 'S')
            {
                *SLrow = i;
                *SLcol = k;
            }
        }
       
       
    }
}




