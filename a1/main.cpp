// 
// Ocean Cheung
// 1316057
// Assignment 1
// Oct 5, 2017
// 

#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/freeglut.h>
#endif

#include "objects.cpp"
#include "mouse.cpp"
#include "keyboard.cpp"
#include "selectMenu.cpp"

void init(void) {
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);

	gluOrtho2D(0.0, w, 0.0, h);

	for(Point i : points) {
		glBegin(GL_POINTS);
		glColor3f(i.r, i.g, i.b);
		glVertex2f(i.x, i.y);
		glEnd();
	}

	glutSwapBuffers();
}

void FPSTimer(int value) {
	glutTimerFunc(17, FPSTimer, 0);
	glutPostRedisplay();
}

/* main function - program entry point */
int main(int argc, char** argv) {
	glutInit(&argc, argv);		//starts up GLUT
	glutInitDisplayMode(GLUT_DOUBLE);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("Assignment 1");

	glutDisplayFunc(display);

	// keyboard callbacks
	glutKeyboardFunc(keyboard);

	// mouse callbacks
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);

	createMenu();

	glutTimerFunc(17, FPSTimer, 0);
	init();

	printf("Press q to exit the program\n");
	printf("Press w to use the point tool. You can draw individual points or hold the mouse to draw multiple points at once. \n");
	printf("Press e to use the line tool. The first click will specify a start point, and the second click will specify the end point. \n");
	printf("Press r to use the rectangle tool. The first click will specify the first corner, and the second click will specify the opposite corner. \n");
	printf("Press t to use the circle tool. The first click will specify the middle of the circle, and the second click will be the edge. \n");
	printf("Press y to use the radial brush. Have fun. \n");
	printf("Press c to clear the paint drawing\n");
	printf("Right click inside the program window to access the options to change colour and brushes\n");

	glutMainLoop();
	return(0);
}
