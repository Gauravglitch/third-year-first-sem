#include<graphics.h>
#include<stdio.h>
#include<conio.h>
int main()
{
    initwindow(600,600,"project1");
    //forZ word
	line(100,100,200,100);
    line(100,200,200,200);
    line(200,100,100,200);
    //for E
    line(300,100,400,100);
    line(300,150,400,150);
    line(300,200,400,200);
    line(300,100,300,200);
	//for R
	line(100,350,100,400);
	rectangle(100,300,200,350);
	line(100,350,200,400);
	//for G
	line(300,300,400,300);
	line(300,300,300,400);
	line(300,400,400,400);
	line(400,400,400,350);
	line(380,350,420,350);
	
	getch();
    closegraph();
    return 0;
}
