#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void DDA(int,int,int,int);
int main()
{
	initwindow(1000,1000,"DDA");
	int x1,x2,y1,y2;
	printf("enter two end points:\n");
	printf("first point(x1,y1):\n");
	printf("x1:");
	scanf("%d",&x1);
	printf("y1:");
	scanf("%d",&y1);
	printf("second point(x2,y2):\n");
	printf("x2:");
	scanf("%d",&x2);
	printf("y2:");
	scanf("%d",&y2);
	DDA(x1,y1,x2,y2);
	getch();
	closegraph();
	return 0;	
}
void DDA(int x1, int y1, int x2, int y2)
{
	int dx=x2-x1;
	int dy=y2-y1;
	int steps;
	if(abs(dx)>=abs(dy))
	{
	steps=abs(dx);	
	}
	else
	{
		steps=abs(dy);
	}
	float xinc=dx/(float)steps;
	float yinc=dy/(float)steps;
	float x=x1;
	float y=y1;
	for(int i=0;i<=steps;i++)
	{
	putpixel(round(x),round(y),WHITE);
		x +=xinc;
		y +=yinc;
		delay(1000);
	}
}
