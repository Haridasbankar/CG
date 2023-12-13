/*
Program No:-01
AIM:-Write C++/Java program to draw line using DDA and Bresenham‘s algorithm. Inherit pixel class and Use function overloading.*/

#include<iostream>
#include<graphics.h>
#include<stdlib.h>
using namespace std;
class pt
{
	protected: int xco,yco,color;
	public:
		pt()
	{
		xco=0;
		yco=0;color=15;
	}
	void setco(int x,int y)
	{
		xco=x;
		yco=y;
	}
	void setcolor(int c)
	{
		color=c;
	}
	void draw()
	{
		putpixel(xco,yco,color); 
	}
};
class dline:public pt
{
private:int x2,y2;
public:
	    dline():pt()
	{
      x2=0;
	  y2=0;
	}
	void setline(int x,int y,int xx,int yy)
	{
		pt::setco(x,y);
		x2=xx;
		y2=yy;
	}

    void draw(int colour)
	{
		float x,y,dx,dy,length;
		int i;
		pt::setcolor(colour);
		dx=abs(x2-xco);
                dy=abs(y2-yco);
        if(dx>dy)
		{
			length=dx;
		}
		else
		{
			length=dy;
		}
		dx=(x2-xco)/length;
                dy=(y2-yco)/length;
		x=xco+0.5;
        y=yco+0.5;
		i=1;
		while(i<=length)
		{
			pt::setco(x,y);
			pt::draw();
			x=x+dx;
			y=dy+y;
			i=i+1;
		}
		pt::setco(x,y);
		pt::draw();
	}
	void draw(int colour,int xo,int yo)
	{
		float x,y,dx,dy,e,temp;
		 int i,gd,gm,s1,s2,ex;
		 pt::setcolor(colour);

		 dx=abs(x2-xco);
                 dy=abs(y2-yco);
		x=xco;
		y=yco;
		putpixel(x+xo,yo=y,15);
		if(x2>xco)
		{
			s1=1;
		}
		if(x2==xco)
		{
			s1=0;
		}
		if(x2<xco)
		{
			s1=-1;
		}
		if(y2>yco)
		{
			s2=1;
		}
		if(y2==yco)
		{
			s2=0;
		}
		if(y2<yco)
		{
			s2=-1;
		}
		if(dy>dx)
		{
			temp=dx;
			dx=dy;
			dy=temp;
			ex=1;
		}
		else
		{
			ex=0;
		}
		e=2*dy-dx;
		i=1;
		do
		{
		while(e>=0)
		{
			if(ex==1)
			{
				x=x+s1;
			}
			else
			{
				y=y+s2;
			}
			e=e-2*dx;
		}
		if(ex==1)
			{
			y=y+s2;
			}
		else
			{
			x=x+s1;
			}
			e=e+2*dy;
			putpixel(x+xo,yo-y,15);
			i=i+1;
		}
		while(i<=dx);
	}
};
int main()
{
	int gd,gm=VGAMAX;gd=DETECT;
	int x1,x2,y1,y2,xmax,ymax,xmid,ymid;
	pt p1;
	p1.setco(100,100);
	p1.setcolor(14);
	dline l;
	cout<<"\n enter two end points of line";
     cout<<"\n Enter value of x1";
	 cin>>x1;
     cout<<"\n Enter value of y1";
     cin>>y1;
	 cout<<"\nEnter value of x2";
     cin>>x2;
	 cout<<"\nEnter value of x2";
      cin>>y2;

	  int ch;
	  cout<<"________________________";
	  cout<<"\n 1.DDA ALGO";
	  cout<<"\n 2. BRESANHAMS ALGO";
	  cout<<"_________________________";
	  cout<<"\n Enter your choice";
	  cin>>ch;
	  initgraph(&gd,&gm,NULL);
	  xmax=getmaxx();
	  ymax=getmaxy();
	  xmid=xmax/2;
	  ymid=ymax/2;
	  line(xmid,0,xmid,ymax);
	  line(0,ymid,xmax,ymid);

	  switch(ch)
	{
		  case 1:
			  l.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
		  l.draw(15);
		  break;

          case 2:
			  l.setline(x1,y1,x2,y2);
		  l.draw(15,xmid,ymid);
		  break;
	}
	getch();
	closegraph();
	return 0;
}

********output****************
ubantu@ubantu-ThinkCentre-M72e:~$ g++ exp1.cpp -o exp1.o -lgraph
ubantu@ubantu-ThinkCentre-M72e:~$ 
ubantu@ubantu-ThinkCentre-M72e:~$ ./exp1.o

 enter two end points of line
 Enter value of x110

 Enter value of y120

Enter value of x2100

Enter value of x2150
________________________
 1.DDA ALGO
 2. BRESANHAMS ALGO_________________________
 Enter your choice1


