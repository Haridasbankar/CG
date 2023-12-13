/*Program No:-05
AIM:-Write C++/Java program to draw the following pattern using any Line drawing algorithms.
*/
#include<graphics.h>
#include<iostream>
using namespace std;

class dline
{
	private:
		int x1,y1,x2,y2;
	public:
		void drawl(int x1,int y1,int x2,int y2)
		{
			float x,y,dx,dy,len;
			int i;
			
			dx=abs(x2-x1);
			dy=abs(y2-y1);

			if(dx>=dy)
			{
				len=dx;
			}
			else
			{
				len=dy;
			}

			dx=(x2-x1)/len;
			dy=(y2-y1)/len;

			x=x1+0.5;
			y=y1+0.5;

			i=1;

			while(i<=len)
			{
				putpixel(x,y,15);
				x=x+dx;
				y=y+dy;
				i=i+1;
			}

			putpixel(x,y,15);
		}
};

void drawfig(int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy,int n)

{
	int m1x,m1y,m2x,m2y,m3x,m3y,m4x,m4y;
	dline l1;

	l1.drawl(ax,ay,bx,by);

	l1.drawl(bx,by,cx,cy);

	l1.drawl(cx,cy,dx,dy);

	l1.drawl(dx,dy,ax,ay);

	m1x = (ax+bx)/2;
	m1y = (ay+by)/2;
	m2x = (bx+cx)/2;
	m2y = (by+cy)/2;
	m3x = (cx+dx)/2;
	m3y = (cy+dy)/2;
	m4x = (dx+ax)/2;
	m4y = (dy+ay)/2;

	n--;

	if(n!=0)
	{
		drawfig(m1x,m1y,m2x,m2y,m3x,m3y,m4x,m4y,n);
	}
}


int main()
{
	int gd=DETECT,gm;
	int x1,y1,x2,y2;

	cout<<"\nEnter left bottom x1:";
	cin>>x1;
	cout<<"\nEnter left bottom y1:";
	cin>>y1;
	cout<<"\nEnter right top x2:";
	cin>>x2;
	cout<<"\nEnter right top y2:";
	cin>>y2;

	initgraph(&gd,&gm,NULL);

	drawfig(x1,y1,x1,y2,x2,y2,x2,y1,3);
	getch();

	closegraph();
	return 0;
}
/*

--------------------------------Output--------------------------------
root1@root1-ThinkCentre-M60e:~$ g++ rec.cpp -lgraph
root1@root1-ThinkCentre-M60e:~$ ./a.out

Enter left bottom x1:10

Enter left bottom y1:10

Enter right top x2:100

Enter right top y2:100
*/
