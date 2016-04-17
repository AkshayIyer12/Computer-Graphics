#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
GLint xc,yc,r;
int x1,x2,y5,y2;
void draw_pixel(GLint cx,GLint cy)
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2i(cx, cy);
	glEnd();
}
void plotpixels(GLint h, GLint k,GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}
void circle_draw(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
        while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0)	d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}
void cylinderdraw()
{
	
	GLint i,n=50;
	for(i=0;i<n;i+=3)
	{
		circle_draw(xc,yc+i,r);
	}
}
void parallelpiped(int x1,int x2,int y5,int y2)
{
	glColor3f(0.0,0.0,1.0);
	glPointSize(2.0);
	glBegin(GL_LINE_LOOP);
		glVertex2i(x1,y5);
		glVertex2i(x2,y5);
		glVertex2i(x2,y2);
		glVertex2i(x1,y2);
	glEnd();
}
void parallelpiped_draw()
{
	
	GLint i,n=40;
	for(i=0;i<n;i+=2)
	{
		parallelpiped(x1+i,x2+i,y5+i,y2+i);
	}
}
void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,400.0,0.0,300.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	cylinderdraw();
	parallelpiped_draw();
	glFlush();
}
void main(int argc, char **argv)
{	printf("\nEnter the coordinates of circle: ");
	scanf("%d %d",&xc,&yc);	
	printf("\nEnter the readius of circle:");
	scanf("%d",&r);
	printf("\nEnter the coordinates of Quadrilateral:");
	scanf("%d %d %d %d",&x1,&x2,&y5,&y2); 
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Cylinder & ParallelPiped");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}