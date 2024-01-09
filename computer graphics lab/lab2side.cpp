#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void DDA(int,int,int,int);
int main()
{
	initwindow(1000,1000,"DDA");
	int x1,x2,y1,y2;
	printf("enter two end points:(x1,y1,x2,y2)\n");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	DDA(x1,y1,x2,y2);
	getch();
	closegraph();
	return 0;	
}
void DDA(int x1, int y1, int x2, int y2)
{
	int delx=x2-x1;
	int dely=y2-y1;
	int steps;
	if(abs(delx)>=abs(dely))
	{
	steps=abs(delx);	
	}
	else
	{
		steps=abs(dely);
	}
	float dx=delx/(float)steps;
	float dy=dely/(float)steps;
	float x=x1;
	float y=y1;
	for(int i=0;i<=steps;i++)
	{
	putpixel(round(x),round(y),WHITE);
		x +=dx;
		y +=dy;
		delay(100);
	}
}
