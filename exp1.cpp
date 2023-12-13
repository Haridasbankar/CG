#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
//#include<conio.h>
using namespace std;
class dline
{
public:
int x1, y1, x2, y2, xo, yo, style;

dline()
{
x1 = 0;
y1 = 0;
x2 = 0;
y2 = 0;
xo = 0;
yo = 0;
}
public:
void setoff(int x, int y);
void setstyle(int s);
void draw1(int x1, int x2, int y1, int y2);
};


void dline::setoff(int x, int y)
{
xo = x;
yo = y;
}

void dline::setstyle(int s)
{
style = s;
}
void dline::draw1(int x1, int x2, int y1, int y2) /* DDA line drawing algorithm */
{
float x, y, dx, dy, length;
int i, flag =0;
dx = abs(x2-x1);
dy = abs(y2-y1);
if(dx >= dy)
{
length = dx;
}
else
{
length = dy;
}
dx = (x2-x1)/length;
dy = (y2-y1)/length;
x = x1+0.5;		/* Factor 0.5 is added to round the values */
y = y1+0.5;		/* Factor 0.5 is added to round the values */
i=1;			/* Initialize loop counter */
while(i<=length)
{
switch (style)
{
 case 1:
	 putpixel (x+xo, yo-y, 15);
	 break;
 case 2:
	 if (flag==0)
	 {
	 putpixel (x+xo, yo-y, 15);
	 }
	 if(i%5==0)
	 {
	    if(flag==1)
	    {
	     flag=0;
	    }
	    else
	    {
	     flag=1;
	    }
	 }
	 break;
case 3:
	if(flag==0)
	{
	  putpixel (x + xo, yo-y, 15);
	}
	else
	{
	  if(i%3==0)
	  {
	  putpixel (x + xo, yo-y, 15);
	  }
	}
	if(i%5==0)
	{
	 if(flag==1)
	 {
	  flag=0;
	 }
	 else
	 {
	  flag=1;
	 }
	}
	break;
case 4:
       putpixel(x+xo,yo-y,15);
	break;
}
x=x+dx;
y=y+dy;
i=i+1;
}
putpixel(x+xo,yo-y,15);
}
int main()
{

dline l;
int gm,gd=DETECT;

int i,st,x1,x2,y1,y2,xmax,ymax,xmid,ymid,wx,wy,thickness;


cout<<"\n Enter two end-points of the line:";
cout<<"\n Enter the value of x1:";
cin>>x1;
cout<<"\n Enter the value of x2:";
cin>>x2;
cout<<"\n Enter the value of y1:";
cin>>y1;
cout<<"\n Enter the value of y2:";
cin>>y2;

cout<<"\n Enter line style:";
cout<<"\n 1 : simple";
cout<<"\n 2 : dash";
cout<<"\n 3 : dash dot";
cout<<"\n 4 : thick";
cout<<"\n Enter correct option:";
cin>>st;

if(st==4)
{
cout<<"\n Enter the thickness of line:";
cin>>thickness;
}

initgraph(&gd,&gm,NULL); 		// Initialize graphics
xmax=getmaxx();			// Get maximum x co-ordinate
ymax=getmaxy();			// Get maximum y co-ordinate
xmid = xmax/2;			// Get the center x co-ordinate
ymid=ymax/2;		       // Get the center y co-ordinate
setcolor(15);
l.setoff(xmid,ymid);	       // Set offset
l.setstyle(st);		       // Set line style
line(xmid,0,xmid,ymax);	       // Draw y co-ordinate
line(0,ymid,xmax,ymid);	       // Draw x co-ordinate

if(st<=3)		       // Draw line with simple, dash or dash dot
{
l.draw1(x1,y1,x2,y2);			// DDA line draw
}
else
{
l.draw1(x1,y1,x2,y2);

if((y2-y1)/(x2-x1) < 1)
{
wy=(thickness-1)*sqrt(pow((x2-x1),2) + pow((y2-y1),2))/(2*fabs(x2-x1));
for(i=0;i<wy;i++)
{
l.draw1(x1,y1-i,x2,y2-i);
l.draw1(x1,y1+i,x2,y2+i);
}
}
else
{
wx=(thickness-1)*sqrt(pow((x2-x1),2) + pow((y2-y1),2))/(2*fabs(y2-y1));
for(i=0;i<wx;i++)
{
l.draw1(x1-i,y1,x2-i,y2);
l.draw1(x1+i,y1,x2+i,y2);
}
}
}
getch();			// wait for key press
closegraph();			// close graphics system
return 0;
}



