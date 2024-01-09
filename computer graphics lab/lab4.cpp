#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main()
{
	initwindow(1000,1000,"Midpiont ellipse algorithm");
	float xc,yc,rx,ry;
	printf("enter the values of xc and yc:");
	scanf(" %f%f",&xc,&yc);
	printf("enter the values of rx and ry:");
	scanf(" %f%f",&rx,&ry);
	float x=0;
	float y=ry;
	//region  1
	float p1=(ry*ry)-(rx*rx*ry)+(1/4)*rx*rx;
	while((2*ry*ry*x)<(2*rx*rx*y))
	{
		putpixel(x+xc,y+yc,9);delay(5);
		putpixel(-x+xc,y+yc,9);delay(5);
		putpixel(x+xc,-y+yc,9);delay(5);
		putpixel(-x+xc,-y+yc,9);delay(5);
		if(p1<0)
		{
			x+=1;
			p1+=2*ry*ry*x+ry*ry;
		}
		else
		{
			x+=1;
			y-=1;
			p1+=2*ry*ry*x+ry*ry-2*rx*rx*y;
		}
	}

	float p2=ry*ry*((x+0.5)*(x+0.5))+rx*rx*((y-1)*(y-1))-(rx*rx*ry*ry);
		while(y>=0)
	{
		putpixel(x+xc,y+yc,9);delay(5);
		putpixel(-x+xc,y+yc,9);delay(5);
		putpixel(x+xc,-y+yc,9);delay(5);
		putpixel(-x+xc,-y+yc,9);delay(5);
		if(p2>0)
		{
			y-=1;
			p2-=2*rx*rx*y+rx*rx;
		}
		else
		{
			x+=1;
			y-=1;
			p2+=2*ry*ry*x+rx*rx-2*rx*rx*y;	
		}
		
	}
	getch();
	closegraph();
	return 0;
	
}
