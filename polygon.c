#include<stdio.h>
#include<GL/glut.h>
void display(void)
{
	int i,n;
	float a[10][10];
	printf("Enter the no of vertices:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the values for traingle vertex %d: ",i+1);
		scanf("%f %f %f",&a[i][0],&a[i][1],&a[i][2]);
	}
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1.0,0.0);
	glBegin(GL_POLYGON);
	for(i=0;i<n;i++)
		glVertex3f(a[i][0],a[i][1],a[i][2]);
	glEnd();
	glFlush();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600,600);
	glutCreateWindow("triangle input");
	glClearColor(1.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,10.0,0.0,10.0,-1.0,1.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
