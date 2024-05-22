#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
//int x1,y1,x2,y2;
int n;
int endpoints[8][4];
void draw_pixel(int x,int y){
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void draw_line(int x1,int y1,int x2,int y2){
	int dx = x2 - x1;
	int dy = y2 - y1;
	int i=0;int steps=0;
	// calculate steps required for generating pixels
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	// calculate increment in x & y for each steps
	float Xinc = dx / (float) steps;
	float Yinc = dy / (float) steps;
	// Put pixel for each step
	float X = x1;
	float Y = y1;
	for (i = 0; i <= steps; i++)
	{
		draw_pixel(round(X),round(Y)); // put pixel at (X,Y)
		X += Xinc; // increment in x at each step
		Y += Yinc; // increment in y at each step
		//delay(100); // for visualization of line-
		// generation step by step
	}	
}
void drawText(int x,int y,char* s){
	int i=0;
	glColor3f(1.0,0.0,0.0);
	glRasterPos2i(x,y);
	for(i=0;s[i]!='\0';i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
	}
}
void DDA(){
	int i;
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	for(i=0;i<n;i++){
		//x1=endpoints[i][0];y1=endpoints[i][1];x2=endpoints[i][2];y2=endpoints[i][3];
		draw_line(endpoints[i][0],endpoints[i][1],endpoints[i][2],endpoints[i][3]);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINES);
		glVertex2i(endpoints[i][0],endpoints[i][1]);
		glVertex2i(endpoints[i][2],endpoints[i][3]);
		glEnd();
		//printf("The points are %d %d %d %d\n",x1,y1,x2,y2);
		glFlush();
	}
	drawText(220,475,"DDA Line drawing algorithm");
	glFlush();
}
void myInit(){
	//glClearColor(1.0,1.0,1.0,1.0);
	//glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}
void main(int argc,char** argv){
	int i;
	printf("Enter number of endpoints:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the endpoints of line %d\n",i+1);
		scanf("%d%d%d%d",&endpoints[i][0],&endpoints[i][1],&endpoints[i][2],&endpoints[i][3]);
	}
	//printf("Ener the endpoints of line segment");
	//scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("DDA line drawing");
	glutDisplayFunc(DDA);
	myInit();
	glutMainLoop();
}
