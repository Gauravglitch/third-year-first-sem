#include <graphics.h>
#include <dos.h>
#include<stdlib.h>
#include <stdio.h>
void standard_delay(){
    delay(5);//delay between two frames
}
//moving functions
void down_move(int x , int y1,int y2 , int width , int height , int color){
    for(int i=y1;i<=y2;i++){
        setfillstyle(SOLID_FILL,color);
        bar(x,i,x+width,i+height);
        standard_delay();
        setfillstyle(SOLID_FILL,0);
        bar(x,i,x+width,i+height);
    }
}
void up_move(int x , int y1,int y2 , int width , int height , int color){
    for(int i=y1;i>=y2;i--){
        setfillstyle(SOLID_FILL,color);
        bar(x,i,x+width,i+height);
        standard_delay();
        setfillstyle(SOLID_FILL,0);
        bar(x,i,x+width,i+height);
    }
}
void right_move(int x1, int x2,int y, int width , int height , int color){
    for(int i=x1;i<=x2;i++){
        setfillstyle(SOLID_FILL,color);
        bar(i,y,i+width,y+height);
        standard_delay();
        setfillstyle(SOLID_FILL,0);
        bar(i,y,i+width,y+height);
    }
}
void left_move(int x1, int x2,int y, int width , int height , int color){
    for(int i=x1;i>=x2;i--){
        setfillstyle(SOLID_FILL,color);
        bar(i,y,i+width,y+height);
        standard_delay();
        setfillstyle(SOLID_FILL,0);
        bar(i,y,i+width,y+height);
    }
}
int block_x(int column , int row , int board[][3]){
    int n = board[row][column];
    return 150 + 250*column - (25*n)/2;
}
int block_y(int column , int row){
    return 550 - 25*row - 25;
}
void draw_first(int board[][3],int c){
    int n,x,y;
    for(int column = 0 ; column<3;column++){
        for(int row = 0 ; row<c;row++){
            n = board[row][column];
            if(n!=0){
                x = block_x(column,row,board);
                y = block_y(column,row);
                setfillstyle(SOLID_FILL,n);
                bar(x,y,x+25*n,y+20);
            }
        }
    }
}
int helper_column(int s , int e){
    return 3-s-e;
}
/*
void print_board(int board[][3],int block_count){
        for(int j=0;j<block_count;j++){
            for(int i=0;i<3;i++){
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
}*/
int push(int board[][3],int column,int block_count,int n){
    //returns the index that item placed
    int i = block_count -1;
    while(i>0){
        if(board[i-1][column] !=0){
            board[i][column] = n;
            return i;
        }
        i--;
    }
    board[i][column]=n;
    return i;
}
int index_to_pull(int board[][3],int column,int block_count){
    int i = block_count-1;
    while(i>-1){
        if(board[i][column] != 0){
            return i;
        }
        i--;
    }
    return -1;//failure
}
int pull(int board[][3],int column,int block_count){
    int n;
    n = board[index_to_pull(board,column,block_count)][column];
    board[index_to_pull(board,column,block_count)][column] = 0;
    return n;
}
void move(int board[][3],int s,int block_count , int e){
    int row,n,final_row,x,y,x_final,max_y;
    row = index_to_pull(board,s,block_count);
    x = block_x(s,row,board);
    y = block_y(s,row);
    n = pull(board,s,block_count);
    final_row = push(board,e,block_count,n);
    max_y = block_y(0,block_count-1) -50;
    //animation
    if(s<e){
        up_move(x,y,max_y,25*n,20,n);
        x_final = block_x(e,final_row,board);
        y = block_y(e,final_row);
        right_move(x,x_final,max_y,25*n,20,n);
        down_move(x_final,max_y,y,25*n,20,n);
    }else if(s>e){
        up_move(x,y,max_y,25*n,20,n);
        x_final = block_x(e,final_row,board);
        y = block_y(e,final_row);
        left_move(x,x_final,max_y,25*n,20,n);
        down_move(x_final,max_y,y,25*n,20,n);
    }
    //drawing at final position
    setfillstyle(SOLID_FILL,n);
    bar(x_final,y,x_final+25*n,y+20);
}
void transfer(int board[][3],int s ,int e,int t,int block_count){
    if(t>1){
        int k = helper_column(s,e);
        transfer(board,s,k,t-1,block_count);
        move(board,s,block_count,e);
        transfer(board,k,e,t-1,block_count);
    }else if(t==1){
        move(board,s,block_count,e);
    }
}
int main()
{
    int block_count;
	  printf("\t\t\tTOWER OF HANOI VISUALIZER\n\n\n\n");
	  printf("\t\t\tGaurav Maharjan   [KAN077BCT035]\n");
	  printf("\t\t\tDavid Maharjan    [KAN077BCT030]\n");
	  printf("\t\t\tKeshab Kamal      [KAN077BCT044]\n");
	  system("pause");
	  system ("cls");
    printf("Enter the no of blocks to insert in tower:");
    scanf("%d",&block_count);
    int board[block_count][3];
    for(int i=block_count-1;i>=0;i--){
        board[i][0] = block_count-i;
        board[i][1] = 0;
        board[i][2] = 0;
    }
    initwindow(800,600);
    line(25,550,775,550);
    draw_first(board,block_count);
    transfer(board,0,2,block_count,block_count);
    getch();
    closegraph();
    return 0;
}
