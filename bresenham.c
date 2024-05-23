#include<stdio.h>
#include<GL/glut.h>
int x1[10],y1[10],x2[10],y2[10];
int n;
void draw_pixel(int x, int y)
{ glColor3f(0.0,0.0,1.0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void drawText(int x,int y, char *s){
	int i=0;
	glColor3f(0,1,0);
	glRasterPos2i(x,y);
	for(i=0;s[i]!='\0';i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,s[i]);
}
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,100,0,100);
	glMatrixMode(GL_MODELVIEW);
}
void draw_line(int x1,int y1, int x2, int y2)
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;
	dx = x2-x1;
	dy = y2-y1;
	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	char s[10];
	sprintf(s,"(%d,%d)",x,y);
	drawText(x+2,y+1,s);
	if (dx > dy) //slope lessthan 1
	{
		draw_pixel(x, y);
		e = 2 * dy-dx;// initial decision parameter
		inc1 = 2*(dy-dx);//upper pixel
		inc2 = 2*dy; // lower pixel
		for (i=0; i<dx; i++)
		{
			if (e >= 0)
			{y += incy;
				e += inc1;} //selection of upper pixel
			else
				e += inc2; //selection of Lower pixel
			x += incx;
			draw_pixel(x, y);
		}
	}
	else
	{
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++)
		{
			if (e >= 0)
			{
				x+= incx; //upper pixel
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
	sprintf(s,"(%d,%d)",x,y);
	drawText(x+2,y+1,s);
}
void Bresenham()
{	
	int i; 	
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);
	drawText(10,90,"USN");
	drawText(10,95,"Name");
	for(i=0;i<n;i++){
		draw_line(x1[i],y1[i],x2[i],y2[i]);
		glColor3f(0.0,1.0,0.0);
		glBegin(GL_LINES);
		glVertex2i(x1[i],y1[i]);
		glVertex2i(x2[i],y2[i]);
		glEnd();
		glFlush();
	}
}
void main(int argc,char ** argv)
{	
	int i;
	printf("Enter the number lines: ");
	scanf("%d",&n); 
	for(i=0;i<n;i++){
		printf("Enter the endpoints of the line segment %d: ",(i+1));
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Bresenham Line Algorithm");
	glutDisplayFunc(Bresenham);
	myinit();
	glutMainLoop();
}
