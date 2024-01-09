#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main()
{
	initwindow(1000,1000,"lab1");
	int x,y;
	x=getmaxx();
	y=getmaxy();
	line(0,0,x,0);
	line(0,0,0,y);
	line(0,y,x,y);
	line(x,y,x,0);
	line(0,0,x,y);
	line(x,0,0,y);
	line(x/2,0,x/2,y);
	line(0,y/2,x,y/2);
	line(0,y/4,x,y/4);
	line(x/4,0,x/4,y);
	line(0,3*y/4,x,3*y/4);
	line(3*x/4,0,3*x/4,y);
	line(x/2,0,0,y/2);
	line(x/2,0,x,y/2);
	line(0,y/2,x,y/2);
	line(x,y/2,x/2,y);
	getch();
	closegraph();
	return 0;	
}
