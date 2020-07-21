#include <windows.h>
#include <stdlib.h>
#include <gl/glut.h>
#include <stdbool.h>
#include <math.h>


void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void reshape(int w, int h);

void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;


void lapangan();
void bangun();
void atap();


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (1000, 600);
   glutInitWindowPosition (100, 50);
   glutCreateWindow ("TR");
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);

   glutMouseFunc(mouse);
   glutMotionFunc(mouseMotion);

   glutMainLoop();
   return 0;
}

void init(void)
{
     GLfloat LightPosition[] = {0.0f, 0.0f, 10.0f, 0.0f};
     glShadeModel(GL_SMOOTH);
     glEnable(GL_DEPTH_TEST);
     glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
     glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glEnable(GL_COLOR_MATERIAL);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glPointSize(1.0);
    glLineWidth(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}

void display(void)
{
//	if(is_depth)
//		glClear(GL_COLOR_BUFFER_BIT);
//	else
	    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	bangun();
	atap();
    lapangan();


	glFlush ();
	glutSwapBuffers();
}

void bangun()
{
     //bangun kiri
	//p1
	glBegin(GL_QUADS);
	glColor3f(0,0.5,1);
	glVertex3f(-35,-25,34);
	glVertex3f(-35,-25,-29);
	glVertex3f(-45,-16,-29);
	glVertex3f(-45,-16,34);
	glEnd();
	//bagian sampingnya
	glBegin(GL_TRIANGLES);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-35,-25,-29);
	glVertex3f(-45,-25,-29);
	glVertex3f(-45,-16,-29);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-45,-25,-29);
	glVertex3f(-45,-16,-29);
	glVertex3f(-46,-16,-29);
	glVertex3f(-46,-25,-29);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-35,-25,34);
	glVertex3f(-45,-25,34);
	glVertex3f(-45,-16,34);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-45,-25,34);
	glVertex3f(-45,-16,34);
	glVertex3f(-46,-16,34);
	glVertex3f(-46,-25,34);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-45,-16,-29);
	glVertex3f(-45,-16,34);
	glVertex3f(-46,-16,34);
	glVertex3f(-46,-16,-29);
	glEnd();
	//p2
	glBegin(GL_QUADS);
	glColor3f(0,0.5,1);
	glVertex3f(-46,-15,34);
	glVertex3f(-46,-15,-29);
	glVertex3f(-60,-6,-29);
	glVertex3f(-60,-6,34);
	glEnd();
	//bagian samping
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-46,-15,-29);
	glVertex3f(-46,-25,-29);
	glVertex3f(-60,-25,-29);
	glVertex3f(-60,-6,-29);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-46,-15,34);
	glVertex3f(-46,-25,34);
	glVertex3f(-60,-25,34);
	glVertex3f(-60,-6,34);
	glEnd();
	//bagian depan
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-46,-15,34);
	glVertex3f(-46,-15,-29);
	glVertex3f(-46,-25,-29);
	glVertex3f(-46,-25,34);
	glEnd();
	//p3
	glBegin(GL_QUADS);
	glColor3f(1,0.5,0.5);
	glVertex3f(-77,10,34);
	glVertex3f(-77,10,-29);
	glVertex3f(-60,-2,-29);
	glVertex3f(-60,-2,34);
	glEnd();
    //bagian samping
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-77,10,-29);
	glVertex3f(-77,-25,-29);
	glVertex3f(-60,-25,-29);
	glVertex3f(-60,-2,-29);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-77,10,34);
	glVertex3f(-77,-25,34);
	glVertex3f(-60,-25,34);
	glVertex3f(-60,-2,34);
	glEnd();
	//bagian depan
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-60,-2,34);
	glVertex3f(-60,-2,-29);
	glVertex3f(-60,-25,-29);
	glVertex3f(-60,-25,34);
	glEnd();


	//bangun depan
	//p1
	glBegin(GL_QUADS);
	glColor3f(0,0.5,1);
	glVertex3f(34,-25,35);
	glVertex3f(-25,-25,35);
	glVertex3f(-25,-16,40);
	glVertex3f(34,-16,40);
	glEnd();
	//bagian sampingnya
	glBegin(GL_TRIANGLES);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-25,-25,35);
	glVertex3f(-25,-25,40);
	glVertex3f(-25,-16,40);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-25,-25,40);
	glVertex3f(-25,-16,40);
	glVertex3f(-25,-16,42);
	glVertex3f(-25,-25,42);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(34,-25,35);
	glVertex3f(34,-25,40);
	glVertex3f(34,-16,40);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(34,-25,40);
	glVertex3f(34,-16,40);
	glVertex3f(34,-16,42);
	glVertex3f(34,-25,42);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-25,-16,40);
	glVertex3f(34,-16,40);
	glVertex3f(34,-16,42);
	glVertex3f(-25,-16,42);
	glEnd();
	//p2
	glBegin(GL_QUADS);
	glColor3f(0,0.5,1);
	glVertex3f(34,-15,42);
	glVertex3f(-25,-15,42);
	glVertex3f(-25,-6,50);
	glVertex3f(34,-6,50);
	glEnd();
	//bagian samping
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-25,-15,42);
	glVertex3f(-25,-25,42);
	glVertex3f(-25,-25,50);
	glVertex3f(-25,-6,50);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(34,-15,42);
	glVertex3f(34,-25,42);
	glVertex3f(34,-25,50);
	glVertex3f(34,-6,50);
	glEnd();
	//bagian depan
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(34,-15,42);
	glVertex3f(-25,-15,42);
	glVertex3f(-25,-25,42);
	glVertex3f(34,-25,42);
	glEnd();
	//p3
	glBegin(GL_QUADS);
	glColor3f(1,0.5,0.5);
	glVertex3f(34,5,57);
	glVertex3f(-25,5,57);
	glVertex3f(-25,-2,50);
	glVertex3f(34,-2,50);
	glEnd();
    //bagian samping
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-25,5,57);
	glVertex3f(-25,-25,57);
	glVertex3f(-25,-25,50);
	glVertex3f(-25,-2,50);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(34,5,57);
	glVertex3f(34,-25,57);
	glVertex3f(34,-25,50);
	glVertex3f(34,-2,50);
	glEnd();
	//bagian depan
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);;
	glVertex3f(34,-2,50);
	glVertex3f(-25,-2,50);
	glVertex3f(-25,-25,50);
	glVertex3f(34,-25,50);
	glEnd();
//bangun kanan
	//p1
	glBegin(GL_QUADS);
	glColor3f(0,0.5,1);
	glVertex3f(35,-25,34);
	glVertex3f(35,-25,-29);
	glVertex3f(40,-16,-29);
	glVertex3f(40,-16,34);
	glEnd();
	//bagian sampingnya
	glBegin(GL_TRIANGLES);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(35,-25,-29);
	glVertex3f(40,-25,-29);
	glVertex3f(40,-16,-29);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(40,-25,-29);
	glVertex3f(40,-16,-29);
	glVertex3f(42,-16,-29);
	glVertex3f(42,-25,-29);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(35,-25,34);
	glVertex3f(40,-25,34);
	glVertex3f(40,-16,34);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(40,-25,34);
	glVertex3f(40,-16,34);
	glVertex3f(42,-16,34);
	glVertex3f(42,-25,34);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(40,-16,-29);
	glVertex3f(40,-16,34);
	glVertex3f(42,-16,34);
	glVertex3f(42,-16,-29);
	glEnd();
	//p2
	glBegin(GL_QUADS);
	glColor3f(0,0.5,1);
	glVertex3f(42,-15,34);
	glVertex3f(42,-15,-29);
	glVertex3f(50,-6,-29);
	glVertex3f(50,-6,34);
	glEnd();
	//bagian samping
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(42,-15,-29);
	glVertex3f(42,-25,-29);
	glVertex3f(50,-25,-29);
	glVertex3f(50,-6,-29);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(42,-15,34);
	glVertex3f(42,-25,34);
	glVertex3f(50,-25,34);
	glVertex3f(50,-6,34);
	glEnd();
	//bagian depan
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(42,-15,34);
	glVertex3f(42,-15,-29);
	glVertex3f(42,-25,-29);
	glVertex3f(42,-25,34);
	glEnd();
	//p3
	glBegin(GL_QUADS);
	glColor3f(1,0.5,0.5);
	glVertex3f(60,10,34);
	glVertex3f(60,10,-29);
	glVertex3f(50,-2,-29);
	glVertex3f(50,-2,34);
	glEnd();
    //bagian samping
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(60,10,-29);
	glVertex3f(60,-25,-29);
	glVertex3f(50,-25,-29);
	glVertex3f(50,-2,-29);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(60,10,34);
	glVertex3f(60,-25,34);
	glVertex3f(50,-25,34);
	glVertex3f(50,-2,34);
	glEnd();
	//bagian depan
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(50,-2,34);
	glVertex3f(50,-2,-29);
	glVertex3f(50,-25,-29);
	glVertex3f(50,-25,34);
	glEnd();
//bangun belakang
	//p1
	glBegin(GL_QUADS);
	glColor3f(0,0.5,1);
	glVertex3f(34,-25,-30);
	glVertex3f(-25,-25,-30);
	glVertex3f(-25,-16,-45);
	glVertex3f(34,-16,-45);
	glEnd();
	//bagian sampingnya
	glBegin(GL_TRIANGLES);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-25,-25,-30);
	glVertex3f(-25,-25,-45);
	glVertex3f(-25,-16,-45);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-25,-25,-45);
	glVertex3f(-25,-16,-45);
	glVertex3f(-25,-16,-50);
	glVertex3f(-25,-25,-50);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(34,-25,-30);
	glVertex3f(34,-25,-45);
	glVertex3f(34,-16,-45);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(34,-25,-45);
	glVertex3f(34,-16,-45);
	glVertex3f(34,-16,-50);
	glVertex3f(34,-25,-50);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-25,-16,-45);
	glVertex3f(34,-16,-45);
	glVertex3f(34,-16,-50);
	glVertex3f(-25,-16,-50);
	glEnd();
	//p2
	glBegin(GL_QUADS);
	glColor3f(0,0.5,1);
	glVertex3f(34,-15,-50);
	glVertex3f(-25,-15,-50);
	glVertex3f(-25,-6,-60);
	glVertex3f(34,-6,-60);
	glEnd();
	//bagian samping
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-25,-15,-50);
	glVertex3f(-25,-25,-50);
	glVertex3f(-25,-25,-60);
	glVertex3f(-25,-6,-60);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(34,-15,-50);
	glVertex3f(34,-25,-50);
	glVertex3f(34,-25,-60);
	glVertex3f(34,-6,-60);
	glEnd();
	//bagian depan
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(34,-15,-50);
	glVertex3f(-25,-15,-50);
	glVertex3f(-25,-25,-50);
	glVertex3f(34,-25,-50);
	glEnd();
	//p3
	glBegin(GL_QUADS);
	glColor3f(1,0.5,0.5);
	glVertex3f(34,5,-80);
	glVertex3f(-25,5,-80);
	glVertex3f(-25,-2,-60);
	glVertex3f(34,-2,-60);
	glEnd();
    //bagian samping
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(-25,5,-80);
	glVertex3f(-25,-25,-80);
	glVertex3f(-25,-25,-60);
	glVertex3f(-25,-2,-60);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(34,5,-80);
	glVertex3f(34,-25,-80);
	glVertex3f(34,-25,-60);
	glVertex3f(34,-2,-60);
	glEnd();
	//bagian depan
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.6, 0.7);
	glVertex3f(34,-2,-60);
	glVertex3f(-25,-2,-60);
	glVertex3f(-25,-25,-60);
	glVertex3f(34,-25,-60);
	glEnd();
}

void atap()
{
 //atap kiri
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-50.0,10.0,40.0);
	glVertex3f(-50.0,15.0,40.0);
	glVertex3f(-30.0,12.0,40.0);
	glVertex3f(-30.0,7.0,40.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-50.0,15.0,40.0);
	glVertex3f(-50.0,20.0,40.0);
	glVertex3f(-50.0,20.0,-30.0);
	glVertex3f(-50.0,15.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-55.0,15.0,40.0);
	glVertex3f(-55.0,20.0,40.0);
	glVertex3f(-55.0,20.0,-30.0);
	glVertex3f(-55.0,15.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-50.0,20.0,40.0);
	glVertex3f(-55.0,20.0,40.0);
	glVertex3f(-55.0,20.0,-30.0);
	glVertex3f(-50.0,20.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-30.0,7.0,40.0);
	glVertex3f(-30.0,12.0,40.0);
	glVertex3f(-30.0,12.0,-30.0);
	glVertex3f(-30.0,7.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-50.0,10.0,-30.0);
	glVertex3f(-50.0,15.0,-30.0);
	glVertex3f(-30.0,12.0,-30.0);
	glVertex3f(-30.0,7.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(-30.0,12.0,40.0);
	glVertex3f(-50.0,15.0,40.0);
	glVertex3f(-50.0,15.0,-30.0);
	glVertex3f(-30.0,12.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(-30.0,7.0,40.0);
	glVertex3f(-50.0,10.0,40.0);
	glVertex3f(-50.0,10.0,-30.0);
	glVertex3f(-30.0,7.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-55.0,10.0,40.0);
	glVertex3f(-55.0,15.0,40.0);
	glVertex3f(-80.0,15.0,40.0);
	glVertex3f(-80.0,10.0,40.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-55.0,10.0,-30.0);
	glVertex3f(-55.0,15.0,-30.0);
	glVertex3f(-80.0,15.0,-30.0);
	glVertex3f(-80.0,10.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-80.0,5.0,-30.0);
	glVertex3f(-80.0,15.0,-30.0);
	glVertex3f(-80.0,15.0,40.0);
	glVertex3f(-80.0,5.0,40.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-77.0,0.0,40.0);
	glVertex3f(-80.0,5.0,40.0);
	glVertex3f(-80.0,5.0,-30.0);
	glVertex3f(-77.0,0.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(-77.0,0.0,40.0);
	glVertex3f(-77.0,10.0,40.0);
	glVertex3f(-77.0,10.0,-30.0);
	glVertex3f(-77.0,0.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-80.0,15.0,40.0);
	glVertex3f(-80.0,15.0,-30.0);
	glVertex3f(-55.0,15.0,-30.0);
	glVertex3f(-55.0,15.0,40.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-80.0,10.0,40.0);
	glVertex3f(-80.0,10.0,-30.0);
	glVertex3f(-50.0,10.0,-30.0);
	glVertex3f(-50.0,10.0,40.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(-55.0,10.0,40.0);
	glVertex3f(-55.0,20.0,40.0);
	glVertex3f(-50.0,20.0,40.0);
	glVertex3f(-50.0,10.0,40.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(-55.0,10.0,-30.0);
	glVertex3f(-55.0,20.0,-30.0);
	glVertex3f(-50.0,20.0,-30.0);
	glVertex3f(-50.0,10.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-47.0,15.1,35.0);
	glVertex3f(-47.0,15.1,30.0);
	glVertex3f(-31.0,12.1,30.0);
	glVertex3f(-31.0,12.1,35.0);

	glVertex3f(-47.0,15.1,28.0);
	glVertex3f(-47.0,15.1,23.0);
	glVertex3f(-31.0,12.1,23.0);
	glVertex3f(-31.0,12.1,28.0);

	glVertex3f(-47.0,15.1,21.0);
	glVertex3f(-47.0,15.1,16.0);
	glVertex3f(-31.0,12.1,16.0);
	glVertex3f(-31.0,12.1,21.0);

	glVertex3f(-47.0,15.1,5.0);
	glVertex3f(-47.0,15.1,0.0);
	glVertex3f(-31.0,12.1,0.0);
	glVertex3f(-31.0,12.1,5.0);

	glVertex3f(-47.0,15.1,-2.0);
	glVertex3f(-47.0,15.1,-7.0);
	glVertex3f(-31.0,12.1,-7.0);
	glVertex3f(-31.0,12.1,-2.0);

	glVertex3f(-47.0,15.1,-9.0);
	glVertex3f(-47.0,15.1,-14.0);
	glVertex3f(-31.0,12.1,-14.0);
	glVertex3f(-31.0,12.1,-9.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-80.0,15.1,35.0);
	glVertex3f(-80.0,15.1,33.0);
	glVertex3f(-60.0,15.1,33.0);
	glVertex3f(-60.0,15.1,35.0);

	glVertex3f(-80.0,15.1,32.0);
	glVertex3f(-80.0,15.1,30.0);
	glVertex3f(-60.0,15.1,30.0);
	glVertex3f(-60.0,15.1,32.0);

	glVertex3f(-80.0,15.1,29.0);
	glVertex3f(-80.0,15.1,27.0);
	glVertex3f(-60.0,15.1,27.0);
	glVertex3f(-60.0,15.1,29.0);

	glVertex3f(-80.0,15.1,26.0);
	glVertex3f(-80.0,15.1,24.0);
	glVertex3f(-60.0,15.1,24.0);
	glVertex3f(-60.0,15.1,26.0);

	glVertex3f(-80.0,15.1,23.0);
	glVertex3f(-80.0,15.1,21.0);
	glVertex3f(-60.0,15.1,21.0);
	glVertex3f(-60.0,15.1,23.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-80.0,15.1,18.0);
	glVertex3f(-80.0,15.1,16.0);
	glVertex3f(-75.0,15.1,16.0);
	glVertex3f(-75.0,15.1,18.0);

	glVertex3f(-80.0,15.1,15.0);
	glVertex3f(-80.0,15.1,13.0);
	glVertex3f(-75.0,15.1,13.0);
	glVertex3f(-75.0,15.1,15.0);

	glVertex3f(-80.0,15.1,12.0);
	glVertex3f(-80.0,15.1,10.0);
	glVertex3f(-75.0,15.1,10.0);
	glVertex3f(-75.0,15.1,12.0);

	glVertex3f(-80.0,15.1,9.0);
	glVertex3f(-80.0,15.1,7.0);
	glVertex3f(-75.0,15.1,7.0);
	glVertex3f(-75.0,15.1,9.0);

	glVertex3f(-80.0,15.1,6.0);
	glVertex3f(-80.0,15.1,4.0);
	glVertex3f(-75.0,15.1,4.0);
	glVertex3f(-75.0,15.1,6.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-72.0,15.1,18.0);
	glVertex3f(-72.0,15.1,16.0);
	glVertex3f(-67.0,15.1,16.0);
	glVertex3f(-67.0,15.1,18.0);

	glVertex3f(-72.0,15.1,15.0);
	glVertex3f(-72.0,15.1,13.0);
	glVertex3f(-67.0,15.1,13.0);
	glVertex3f(-67.0,15.1,15.0);

	glVertex3f(-72.0,15.1,12.0);
	glVertex3f(-72.0,15.1,10.0);
	glVertex3f(-67.0,15.1,10.0);
	glVertex3f(-67.0,15.1,12.0);

	glVertex3f(-72.0,15.1,9.0);
	glVertex3f(-72.0,15.1,7.0);
	glVertex3f(-67.0,15.1,7.0);
	glVertex3f(-67.0,15.1,9.0);

	glVertex3f(-72.0,15.1,6.0);
	glVertex3f(-72.0,15.1,4.0);
	glVertex3f(-67.0,15.1,4.0);
	glVertex3f(-67.0,15.1,6.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-64.0,15.1,18.0);
	glVertex3f(-64.0,15.1,16.0);
	glVertex3f(-55.0,15.1,16.0);
	glVertex3f(-55.0,15.1,18.0);

	glVertex3f(-64.0,15.1,15.0);
	glVertex3f(-64.0,15.1,13.0);
	glVertex3f(-55.0,15.1,13.0);
	glVertex3f(-55.0,15.1,15.0);

	glVertex3f(-64.0,15.1,12.0);
	glVertex3f(-64.0,15.1,10.0);
	glVertex3f(-55.0,15.1,10.0);
	glVertex3f(-55.0,15.1,12.0);

	glVertex3f(-64.0,15.1,9.0);
	glVertex3f(-64.0,15.1,7.0);
	glVertex3f(-55.0,15.1,7.0);
	glVertex3f(-55.0,15.1,9.0);

	glVertex3f(-64.0,15.1,6.0);
	glVertex3f(-64.0,15.1,4.0);
	glVertex3f(-55.0,15.1,4.0);
	glVertex3f(-55.0,15.1,6.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-75.0,15.1,2.0);
	glVertex3f(-75.0,15.1,0.0);
	glVertex3f(-63.0,15.1,0.0);
	glVertex3f(-63.0,15.1,2.0);

	glVertex3f(-75.0,15.1,-1.0);
	glVertex3f(-75.0,15.1,-3.0);
	glVertex3f(-63.0,15.1,-3.0);
	glVertex3f(-63.0,15.1,-1.0);

	glVertex3f(-75.0,15.1,-4.0);
	glVertex3f(-75.0,15.1,-6.0);
	glVertex3f(-63.0,15.1,-6.0);
	glVertex3f(-63.0,15.1,-4.0);

	glVertex3f(-75.0,15.1,-7.0);
	glVertex3f(-75.0,15.1,-9.0);
	glVertex3f(-63.0,15.1,-9.0);
	glVertex3f(-63.0,15.1,-7.0);

	glVertex3f(-75.0,15.1,-10.0);
	glVertex3f(-75.0,15.1,-12.0);
	glVertex3f(-63.0,15.1,-12.0);
	glVertex3f(-63.0,15.1,-10.0);

	glVertex3f(-75.0,15.1,-13.0);
	glVertex3f(-75.0,15.1,-15.0);
	glVertex3f(-63.0,15.1,-15.0);
	glVertex3f(-63.0,15.1,-13.0);

	glVertex3f(-75.0,15.1,-16.0);
	glVertex3f(-75.0,15.1,-18.0);
	glVertex3f(-63.0,15.1,-18.0);
	glVertex3f(-63.0,15.1,-16.0);

	glVertex3f(-75.0,15.1,-19.0);
	glVertex3f(-75.0,15.1,-21.0);
	glVertex3f(-63.0,15.1,-21.0);
	glVertex3f(-63.0,15.1,-19.0);

	glVertex3f(-75.0,15.1,-22.0);
	glVertex3f(-75.0,15.1,-24.0);
	glVertex3f(-63.0,15.1,-24.0);
	glVertex3f(-63.0,15.1,-22.0);

	glVertex3f(-75.0,15.1,-25.0);
	glVertex3f(-75.0,15.1,-27.0);
	glVertex3f(-63.0,15.1,-27.0);
	glVertex3f(-63.0,15.1,-25.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-70.0,-15.0,40.0);
	glVertex3f(-70.0,-25.0,40.0);
	glVertex3f(-50.0,-25.0,40.0);
	glVertex3f(-50.0,-15.0,40.0);

	glVertex3f(-77.0,0.0,40.0);
	glVertex3f(-77.0,-25.0,40.0);
	glVertex3f(-65.0,-25.0,40.0);
	glVertex3f(-65.0,0.0,40.0);

	glVertex3f(-77.0,0.0,45.0);
	glVertex3f(-77.0,-25.0,45.0);
	glVertex3f(-65.0,-25.0,45.0);
	glVertex3f(-65.0,0.0,45.0);

	glVertex3f(-70.0,-15.0,45.0);
	glVertex3f(-70.0,-25.0,45.0);
	glVertex3f(-50.0,-25.0,45.0);
	glVertex3f(-50.0,-15.0,45.0);

	glVertex3f(-77.0,0.0,45.0);
	glVertex3f(-77.0,-25.0,45.0);
	glVertex3f(-77.0,-25.0,40.0);
	glVertex3f(-77.0,0.0,40.0);

	glVertex3f(-65.0,-15.0,45.0);
	glVertex3f(-65.0,0.0,45.0);
	glVertex3f(-65.0,0.0,40.0);
	glVertex3f(-65.0,-15.0,40.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-77.0,0.0,45.0);
	glVertex3f(-77.0,0.0,40.0);
	glVertex3f(-71.0,5.0,40.0);
	glVertex3f(-71.0,5.0,45.0);

	glVertex3f(-71.0,5.0,45.0);
	glVertex3f(-71.0,5.0,40.0);
	glVertex3f(-65.0,0.0,40.0);
	glVertex3f(-65.0,0.0,45.0);

	glVertex3f(-65.0,-15.0,45.0);
	glVertex3f(-65.0,-15.0,40.0);
	glVertex3f(-50.0,-15.0,40.0);
	glVertex3f(-50.0,-15.0,45.0);

	glColor3f(1.0,0.5,0.3);
	glVertex3f(-50.0,-15.0,45.0);
	glVertex3f(-50.0,-15.0,40.0);
	glVertex3f(-50.0,-25.0,40.0);
	glVertex3f(-50.0,-25.0,45.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-77.0,0.0,40.0);
	glVertex3f(-65.0,0.0,40.0);
	glVertex3f(-71.0,5.0,40.0);

	glVertex3f(-77.0,0.0,45.0);
	glVertex3f(-65.0,0.0,45.0);
	glVertex3f(-71.0,5.0,45.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-85.0,-20.0,45.0);
	glVertex3f(-85.0,-25.0,45.0);
	glVertex3f(-80.0,-25.0,45.0);
	glVertex3f(-80.0,-20.0,45.0);

	glVertex3f(-85.0,-20.0,45.0);
	glVertex3f(-85.0,-25.0,45.0);
	glVertex3f(-85.0,-25.0,-30.0);
	glVertex3f(-85.0,-20.0,-30.0);

	glVertex3f(-80.0,-20.0,45.0);
	glVertex3f(-80.0,-25.0,45.0);
	glVertex3f(-80.0,-25.0,-30.0);
	glVertex3f(-80.0,-20.0,-30.0);

	glVertex3f(-85.0,-25.0,-30.0);
	glVertex3f(-85.0,-20.0,-30.0);
	glVertex3f(-80.0,-20.0,-30.0);
	glVertex3f(-80.0,-25.0,-30.0);

	glColor3f(0.9,0.9,1.0);
	glVertex3f(-85.0,-20.0,45.0);
	glVertex3f(-80.0,-20.0,45.0);
	glVertex3f(-80.0,-20.0,-30.0);
	glVertex3f(-85.0,-20.0,-30.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-84.0,-5.0,44.0);
	glVertex3f(-84.0,-20.0,44.0);
	glVertex3f(-80.0,-20.0,44.0);
	glVertex3f(-80.0,-5.0,44.0);

	glVertex3f(-84.0,-5.0,34.0);
	glVertex3f(-84.0,-20.0,34.0);
	glVertex3f(-80.0,-20.0,34.0);
	glVertex3f(-80.0,-5.0,34.0);

	glVertex3f(-84.0,-5.0,44.0);
	glVertex3f(-84.0,-20.0,44.0);
	glVertex3f(-84.0,-20.0,34.0);
	glVertex3f(-84.0,-5.0,34.0);

	glVertex3f(-80.0,-5.0,44.0);
	glVertex3f(-80.0,-20.0,44.0);
	glVertex3f(-80.0,-20.0,34.0);
	glVertex3f(-80.0,-5.0,34.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-84.0,-5.0,44.0);
	glVertex3f(-84.0,-5.0,34.0);
	glVertex3f(-84.0,0.0,39.0);

	glVertex3f(-80.0,-5.0,44.0);
	glVertex3f(-80.0,-5.0,34.0);
	glVertex3f(-80.0,0.0,39.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-84.0,-5.0,44.0);
	glVertex3f(-84.0,0.0,39.0);
	glVertex3f(-80.0,0.0,39.0);
	glVertex3f(-80.0,-5.0,44.0);

	glVertex3f(-84.0,-5.0,34.0);
	glVertex3f(-84.0,0.0,39.0);
	glVertex3f(-80.0,0.0,39.0);
	glVertex3f(-80.0,-5.0,34.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-84.0,-5.0,20.0);
	glVertex3f(-84.0,-20.0,20.0);
	glVertex3f(-80.0,-20.0,20.0);
	glVertex3f(-80.0,-5.0,20.0);

	glVertex3f(-84.0,-5.0,0.0);
	glVertex3f(-84.0,-20.0,0.0);
	glVertex3f(-80.0,-20.0,0.0);
	glVertex3f(-80.0,-5.0,0.0);

	glVertex3f(-84.0,-5.0,20.0);
	glVertex3f(-84.0,-20.0,20.0);
	glVertex3f(-84.0,-20.0,0.0);
	glVertex3f(-84.0,-5.0,0.0);

	glVertex3f(-80.0,-5.0,20.0);
	glVertex3f(-80.0,-20.0,20.0);
	glVertex3f(-80.0,-20.0,0.0);
	glVertex3f(-80.0,-5.0,0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-84.0,-5.0,20.0);
	glVertex3f(-84.0,-5.0,10.0);
	glVertex3f(-84.0,0.0,15.0);

	glVertex3f(-80.0,-5.0,20.0);
	glVertex3f(-80.0,-5.0,10.0);
	glVertex3f(-80.0,0.0,15.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-84.0,-5.0,10.0);
	glVertex3f(-84.0,-5.0,0.0);
	glVertex3f(-84.0,0.0,5.0);

	glVertex3f(-80.0,-5.0,10.0);
	glVertex3f(-80.0,-5.0,0.0);
	glVertex3f(-80.0,0.0,5.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-84.0,-5.0,20.0);
	glVertex3f(-84.0,0.0,15.0);
	glVertex3f(-80.0,0.0,15.0);
	glVertex3f(-80.0,-5.0,20.0);

	glVertex3f(-84.0,-5.0,10.0);
	glVertex3f(-84.0,0.0,15.0);
	glVertex3f(-80.0,0.0,15.0);
	glVertex3f(-80.0,-5.0,10.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-84.0,-5.0,10.0);
	glVertex3f(-84.0,0.0,5.0);
	glVertex3f(-80.0,0.0,5.0);
	glVertex3f(-80.0,-5.0,10.0);

	glVertex3f(-84.0,-5.0,0.0);
	glVertex3f(-84.0,0.0,5.0);
	glVertex3f(-80.0,0.0,5.0);
	glVertex3f(-80.0,-5.0,0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-84.0,-5.0,-19.0);
	glVertex3f(-84.0,-20.0,-19.0);
	glVertex3f(-80.0,-20.0,-19.0);
	glVertex3f(-80.0,-5.0,-19.0);

	glVertex3f(-84.0,-5.0,-29.0);
	glVertex3f(-84.0,-20.0,-29.0);
	glVertex3f(-80.0,-20.0,-29.0);
	glVertex3f(-80.0,-5.0,-29.0);

	glVertex3f(-84.0,-5.0,-19.0);
	glVertex3f(-84.0,-20.0,-19.0);
	glVertex3f(-84.0,-20.0,-29.0);
	glVertex3f(-84.0,-5.0,-29.0);

	glVertex3f(-80.0,-5.0,-19.0);
	glVertex3f(-80.0,-20.0,-19.0);
	glVertex3f(-80.0,-20.0,-29.0);
	glVertex3f(-80.0,-5.0,-29.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-84.0,-5.0,-19.0);
	glVertex3f(-84.0,-5.0,-29.0);
	glVertex3f(-84.0,0.0,-24.0);

	glVertex3f(-80.0,-5.0,-19.0);
	glVertex3f(-80.0,-5.0,-29.0);
	glVertex3f(-80.0,0.0,-24.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-84.0,-5.0,-19.0);
	glVertex3f(-84.0,0.0,-24.0);
	glVertex3f(-80.0,0.0,-24.0);
	glVertex3f(-80.0,-5.0,-19.0);

	glVertex3f(-84.0,-5.0,-29.0);
	glVertex3f(-84.0,0.0,-24.0);
	glVertex3f(-80.0,0.0,-24.0);
	glVertex3f(-80.0,-5.0,-29.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-85.0,-20.0,35.0);
	glVertex3f(-85.0,-25.0,35.0);
	glVertex3f(-89.0,-25.0,35.0);
	glVertex3f(-89.0,-20.0,35.0);

	glVertex3f(-85.0,-20.0,20.0);
	glVertex3f(-85.0,-25.0,20.0);
	glVertex3f(-89.0,-25.0,20.0);
	glVertex3f(-89.0,-20.0,20.0);

	glVertex3f(-89.0,-20.0,35.0);
	glVertex3f(-89.0,-25.0,35.0);
	glVertex3f(-89.0,-25.0,20.0);
	glVertex3f(-89.0,-20.0,20.0);

	glColor3f(0.9,0.9,1.0);
	glVertex3f(-89.0,-20.0,35.0);
	glVertex3f(-85.0,-20.0,35.0);
	glVertex3f(-85.0,-20.0,20.0);
	glVertex3f(-89.0,-20.0,20.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-89.0,-21.0,35.0);
	glVertex3f(-89.0,-25.0,35.0);
	glVertex3f(-93.0,-25.0,35.0);
	glVertex3f(-93.0,-21.0,35.0);

	glVertex3f(-89.0,-21.0,20.0);
	glVertex3f(-89.0,-25.0,20.0);
	glVertex3f(-93.0,-25.0,20.0);
	glVertex3f(-93.0,-21.0,20.0);

	glVertex3f(-93.0,-21.0,35.0);
	glVertex3f(-93.0,-25.0,35.0);
	glVertex3f(-93.0,-25.0,20.0);
	glVertex3f(-93.0,-21.0,20.0);

	glColor3f(0.9,0.9,1.0);
	glVertex3f(-93.0,-21.0,35.0);
	glVertex3f(-89.0,-21.0,35.0);
	glVertex3f(-89.0,-21.0,20.0);
	glVertex3f(-93.0,-21.0,20.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-93.0,-23.0,35.0);
	glVertex3f(-93.0,-25.0,35.0);
	glVertex3f(-97.0,-25.0,35.0);
	glVertex3f(-97.0,-23.0,35.0);

	glVertex3f(-93.0,-23.0,20.0);
	glVertex3f(-93.0,-25.0,20.0);
	glVertex3f(-97.0,-25.0,20.0);
	glVertex3f(-97.0,-23.0,20.0);

	glVertex3f(-97.0,-23.0,35.0);
	glVertex3f(-97.0,-25.0,35.0);
	glVertex3f(-97.0,-25.0,20.0);
	glVertex3f(-97.0,-23.0,20.0);

	glColor3f(0.9,0.9,1.0);
	glVertex3f(-97.0,-23.0,35.0);
	glVertex3f(-93.0,-23.0,35.0);
	glVertex3f(-93.0,-23.0,20.0);
	glVertex3f(-97.0,-23.0,20.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-85.0,-20.0,20.0);
	glVertex3f(-85.0,-25.0,20.0);
	glVertex3f(-89.0,-25.0,20.0);
	glVertex3f(-89.0,-20.0,20.0);

	glVertex3f(-85.0,-20.0,0.0);
	glVertex3f(-85.0,-25.0,0.0);
	glVertex3f(-89.0,-25.0,0.0);
	glVertex3f(-89.0,-20.0,0.0);

	glVertex3f(-89.0,-20.0,20.0);
	glVertex3f(-89.0,-25.0,20.0);
	glVertex3f(-89.0,-25.0,0.0);
	glVertex3f(-89.0,-20.0,0.0);

	glColor3f(0.9,0.9,1.0);
	glVertex3f(-89.0,-20.0,20.0);
	glVertex3f(-85.0,-20.0,20.0);
	glVertex3f(-85.0,-20.0,0.0);
	glVertex3f(-89.0,-20.0,0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-89.0,-21.0,20.0);
	glVertex3f(-89.0,-25.0,20.0);
	glVertex3f(-96.0,-25.0,20.0);
	glVertex3f(-96.0,-21.0,20.0);

	glVertex3f(-89.0,-21.0,0.0);
	glVertex3f(-89.0,-25.0,0.0);
	glVertex3f(-96.0,-25.0,0.0);
	glVertex3f(-96.0,-21.0,0.0);

	glVertex3f(-96.0,-21.0,20.0);
	glVertex3f(-96.0,-25.0,20.0);
	glVertex3f(-96.0,-25.0,0.0);
	glVertex3f(-96.0,-21.0,0.0);

	glColor3f(0.9,0.9,1.0);
	glVertex3f(-96.0,-21.0,20.0);
	glVertex3f(-89.0,-21.0,20.0);
	glVertex3f(-89.0,-21.0,0.0);
	glVertex3f(-96.0,-21.0,0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-96.0,-23.0,20.0);
	glVertex3f(-96.0,-25.0,20.0);
	glVertex3f(-110.0,-25.0,20.0);
	glVertex3f(-110.0,-23.0,20.0);

	glVertex3f(-96.0,-23.0,0.0);
	glVertex3f(-96.0,-25.0,0.0);
	glVertex3f(-110.0,-25.0,0.0);
	glVertex3f(-110.0,-23.0,0.0);

	glVertex3f(-110.0,-23.0,0.0);
	glVertex3f(-110.0,-25.0,0.0);
	glVertex3f(-110.0,-25.0,20.0);
	glVertex3f(-110.0,-23.0,20.0);

	glColor3f(0.9,0.9,1.0);
	glVertex3f(-110.0,-23.0,0.0);
	glVertex3f(-96.0,-23.0,0.0);
	glVertex3f(-96.0,-23.0,20.0);
	glVertex3f(-110.0,-23.0,20.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-85.0,-20.0,0.0);
	glVertex3f(-85.0,-25.0,0.0);
	glVertex3f(-89.0,-25.0,0.0);
	glVertex3f(-89.0,-20.0,0.0);

	glVertex3f(-85.0,-20.0,-15.0);
	glVertex3f(-85.0,-25.0,-15.0);
	glVertex3f(-89.0,-25.0,-15.0);
	glVertex3f(-89.0,-20.0,-15.0);

	glVertex3f(-89.0,-20.0,0.0);
	glVertex3f(-89.0,-25.0,0.0);
	glVertex3f(-89.0,-25.0,-15.0);
	glVertex3f(-89.0,-20.0,-15.0);

	glColor3f(0.9,0.9,1.0);
	glVertex3f(-89.0,-20.0,0.0);
	glVertex3f(-85.0,-20.0,0.0);
	glVertex3f(-85.0,-20.0,-15.0);
	glVertex3f(-89.0,-20.0,-15.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-89.0,-21.0,0.0);
	glVertex3f(-89.0,-25.0,0.0);
	glVertex3f(-93.0,-25.0,0.0);
	glVertex3f(-93.0,-21.0,0.0);

	glVertex3f(-89.0,-21.0,-15.0);
	glVertex3f(-89.0,-25.0,-15.0);
	glVertex3f(-93.0,-25.0,-15.0);
	glVertex3f(-93.0,-21.0,-15.0);

	glVertex3f(-93.0,-21.0,0.0);
	glVertex3f(-93.0,-25.0,0.0);
	glVertex3f(-93.0,-25.0,-15.0);
	glVertex3f(-93.0,-21.0,-15.0);

	glColor3f(0.9,0.9,1.0);
	glVertex3f(-93.0,-21.0,0.0);
	glVertex3f(-89.0,-21.0,0.0);
	glVertex3f(-89.0,-21.0,-15.0);
	glVertex3f(-93.0,-21.0,-15.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,0.5,0.3);
	glVertex3f(-93.0,-23.0,0.0);
	glVertex3f(-93.0,-25.0,0.0);
	glVertex3f(-97.0,-25.0,0.0);
	glVertex3f(-97.0,-23.0,0.0);

	glVertex3f(-93.0,-23.0,-15.0);
	glVertex3f(-93.0,-25.0,-15.0);
	glVertex3f(-97.0,-25.0,-15.0);
	glVertex3f(-97.0,-23.0,-15.0);

	glVertex3f(-97.0,-23.0,0.0);
	glVertex3f(-97.0,-25.0,0.0);
	glVertex3f(-97.0,-25.0,-15.0);
	glVertex3f(-97.0,-23.0,-15.0);

	glColor3f(0.9,0.9,1.0);
	glVertex3f(-97.0,-23.0,0.0);
	glVertex3f(-93.0,-23.0,0.0);
	glVertex3f(-93.0,-23.0,-15.0);
	glVertex3f(-97.0,-23.0,-15.0);
	glEnd();


	//atap 2 atap depan
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-25.0,5.0,35.0);
	glVertex3f(-25.0,10.0,35.0);
	glVertex3f(40.0,10.0,35.0);
	glVertex3f(40.0,5.0,35.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-25.0,0.0,60.0);
	glVertex3f(-25.0,10.0,60.0);
	glVertex3f(40.0,10.0,60.0);
	glVertex3f(40.0,0.0,60.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-25.0,-5.0,57.0);
	glVertex3f(-25.0,0.0,60.0);
	glVertex3f(40.0,0.0,60.0);
	glVertex3f(40.0,-5.0,57.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-25.0,-5.0,57.0);
	glVertex3f(-25.0,5.0,57.0);
	glVertex3f(40.0,5.0,57.0);
	glVertex3f(40.0,-5.0,57.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-25.0,10.0,60.0);
	glVertex3f(-25.0,10.0,35.0);
	glVertex3f(40.0,10.0,35.0);
	glVertex3f(40.0,10.0,60.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(-25.0,5.0,57.0);
	glVertex3f(-25.0,5.0,35.0);
	glVertex3f(40.0,5.0,35.0);
	glVertex3f(40.0,5.0,57.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(-25.0,10.0,60.0);
	glVertex3f(-25.0,0.0,60.0);
	glVertex3f(-25.0,-5.0,57.0);
	glVertex3f(-25.0,10.0,57.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(40.0,10.0,60.0);
	glVertex3f(40.0,0.0,60.0);
	glVertex3f(40.0,-5.0,57.0);
	glVertex3f(40.0,10.0,57.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(-25.0,10.0,60.0);
	glVertex3f(-25.0,5.0,60.0);
	glVertex3f(-25.0,5.0,35.0);
	glVertex3f(-25.0,10.0,35.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(40.0,10.0,60.0);
	glVertex3f(40.0,5.0,60.0);
	glVertex3f(40.0,5.0,35.0);
	glVertex3f(40.0,10.0,35.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-20.0,10.1,58.0);
	glVertex3f(-20.0,10.1,53.0);
	glVertex3f(-18.0,10.1,53.0);
	glVertex3f(-18.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-17.0,10.1,58.0);
	glVertex3f(-17.0,10.1,53.0);
	glVertex3f(-15.0,10.1,53.0);
	glVertex3f(-15.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-14.0,10.1,58.0);
	glVertex3f(-14.0,10.1,53.0);
	glVertex3f(-12.0,10.1,53.0);
	glVertex3f(-12.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-11.0,10.1,58.0);
	glVertex3f(-11.0,10.1,53.0);
	glVertex3f(-9.0,10.1,53.0);
	glVertex3f(-9.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-8.0,10.1,58.0);
	glVertex3f(-8.0,10.1,53.0);
	glVertex3f(-6.0,10.1,53.0);
	glVertex3f(-6.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-5.0,10.1,58.0);
	glVertex3f(-5.0,10.1,53.0);
	glVertex3f(-3.0,10.1,53.0);
	glVertex3f(-3.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-2.0,10.1,58.0);
	glVertex3f(-2.0,10.1,53.0);
	glVertex3f(0.0,10.1,53.0);
	glVertex3f(0.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(1.0,10.1,58.0);
	glVertex3f(1.0,10.1,53.0);
	glVertex3f(3.0,10.1,53.0);
	glVertex3f(3.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(4.0,10.1,58.0);
	glVertex3f(4.0,10.1,53.0);
	glVertex3f(6.0,10.1,53.0);
	glVertex3f(6.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(7.0,10.1,58.0);
	glVertex3f(7.0,10.1,53.0);
	glVertex3f(9.0,10.1,53.0);
	glVertex3f(9.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(10.0,10.1,58.0);
	glVertex3f(10.0,10.1,53.0);
	glVertex3f(12.0,10.1,53.0);
	glVertex3f(12.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(13.0,10.1,58.0);
	glVertex3f(13.0,10.1,53.0);
	glVertex3f(15.0,10.1,53.0);
	glVertex3f(15.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(16.0,10.1,58.0);
	glVertex3f(16.0,10.1,53.0);
	glVertex3f(18.0,10.1,53.0);
	glVertex3f(18.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(19.0,10.1,58.0);
	glVertex3f(19.0,10.1,53.0);
	glVertex3f(21.0,10.1,53.0);
	glVertex3f(21.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(22.0,10.1,58.0);
	glVertex3f(22.0,10.1,53.0);
	glVertex3f(24.0,10.1,53.0);
	glVertex3f(24.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(25.0,10.1,58.0);
	glVertex3f(25.0,10.1,53.0);
	glVertex3f(27.0,10.1,53.0);
	glVertex3f(27.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(28.0,10.1,58.0);
	glVertex3f(28.0,10.1,53.0);
	glVertex3f(30.0,10.1,53.0);
	glVertex3f(30.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(31.0,10.1,58.0);
	glVertex3f(31.0,10.1,53.0);
	glVertex3f(33.0,10.1,53.0);
	glVertex3f(33.0,10.1,58.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(34.0,10.1,58.0);
	glVertex3f(34.0,10.1,53.0);
	glVertex3f(36.0,10.1,53.0);
	glVertex3f(36.0,10.1,58.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-20.0,10.1,48.0);
	glVertex3f(-20.0,10.1,43.0);
	glVertex3f(-18.0,10.1,43.0);
	glVertex3f(-18.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-17.0,10.1,48.0);
	glVertex3f(-17.0,10.1,43.0);
	glVertex3f(-15.0,10.1,43.0);
	glVertex3f(-15.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-14.0,10.1,48.0);
	glVertex3f(-14.0,10.1,43.0);
	glVertex3f(-12.0,10.1,43.0);
	glVertex3f(-12.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-11.0,10.1,48.0);
	glVertex3f(-11.0,10.1,43.0);
	glVertex3f(-9.0,10.1,43.0);
	glVertex3f(-9.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-8.0,10.1,48.0);
	glVertex3f(-8.0,10.1,43.0);
	glVertex3f(-6.0,10.1,43.0);
	glVertex3f(-6.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-5.0,10.1,48.0);
	glVertex3f(-5.0,10.1,43.0);
	glVertex3f(-3.0,10.1,43.0);
	glVertex3f(-3.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-2.0,10.1,48.0);
	glVertex3f(-2.0,10.1,43.0);
	glVertex3f(0.0,10.1,43.0);
	glVertex3f(0.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(1.0,10.1,48.0);
	glVertex3f(1.0,10.1,43.0);
	glVertex3f(3.0,10.1,43.0);
	glVertex3f(3.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(4.0,10.1,48.0);
	glVertex3f(4.0,10.1,43.0);
	glVertex3f(6.0,10.1,43.0);
	glVertex3f(6.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(7.0,10.1,48.0);
	glVertex3f(7.0,10.1,43.0);
	glVertex3f(9.0,10.1,43.0);
	glVertex3f(9.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(10.0,10.1,48.0);
	glVertex3f(10.0,10.1,43.0);
	glVertex3f(12.0,10.1,43.0);
	glVertex3f(12.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(13.0,10.1,48.0);
	glVertex3f(13.0,10.1,43.0);
	glVertex3f(15.0,10.1,43.0);
	glVertex3f(15.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(16.0,10.1,48.0);
	glVertex3f(16.0,10.1,43.0);
	glVertex3f(18.0,10.1,43.0);
	glVertex3f(18.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(19.0,10.1,48.0);
	glVertex3f(19.0,10.1,43.0);
	glVertex3f(21.0,10.1,43.0);
	glVertex3f(21.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(22.0,10.1,48.0);
	glVertex3f(22.0,10.1,43.0);
	glVertex3f(24.0,10.1,43.0);
	glVertex3f(24.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(25.0,10.1,48.0);
	glVertex3f(25.0,10.1,43.0);
	glVertex3f(27.0,10.1,43.0);
	glVertex3f(27.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(28.0,10.1,48.0);
	glVertex3f(28.0,10.1,43.0);
	glVertex3f(30.0,10.1,43.0);
	glVertex3f(30.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(31.0,10.1,48.0);
	glVertex3f(31.0,10.1,43.0);
	glVertex3f(33.0,10.1,43.0);
	glVertex3f(33.0,10.1,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(34.0,10.1,48.0);
	glVertex3f(34.0,10.1,43.0);
	glVertex3f(36.0,10.1,43.0);
	glVertex3f(36.0,10.1,48.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-20.0,10.1,42.0);
	glVertex3f(-20.0,10.1,37.0);
	glVertex3f(-18.0,10.1,37.0);
	glVertex3f(-18.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-17.0,10.1,42.0);
	glVertex3f(-17.0,10.1,37.0);
	glVertex3f(-15.0,10.1,37.0);
	glVertex3f(-15.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-14.0,10.1,42.0);
	glVertex3f(-14.0,10.1,37.0);
	glVertex3f(-12.0,10.1,37.0);
	glVertex3f(-12.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-11.0,10.1,42.0);
	glVertex3f(-11.0,10.1,37.0);
	glVertex3f(-9.0,10.1,37.0);
	glVertex3f(-9.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-8.0,10.1,42.0);
	glVertex3f(-8.0,10.1,37.0);
	glVertex3f(-6.0,10.1,37.0);
	glVertex3f(-6.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-5.0,10.1,42.0);
	glVertex3f(-5.0,10.1,37.0);
	glVertex3f(-3.0,10.1,37.0);
	glVertex3f(-3.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-2.0,10.1,42.0);
	glVertex3f(-2.0,10.1,37.0);
	glVertex3f(0.0,10.1,37.0);
	glVertex3f(0.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(1.0,10.1,42.0);
	glVertex3f(1.0,10.1,37.0);
	glVertex3f(3.0,10.1,37.0);
	glVertex3f(3.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(4.0,10.1,42.0);
	glVertex3f(4.0,10.1,37.0);
	glVertex3f(6.0,10.1,37.0);
	glVertex3f(6.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(7.0,10.1,42.0);
	glVertex3f(7.0,10.1,37.0);
	glVertex3f(9.0,10.1,37.0);
	glVertex3f(9.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(10.0,10.1,42.0);
	glVertex3f(10.0,10.1,37.0);
	glVertex3f(12.0,10.1,37.0);
	glVertex3f(12.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(13.0,10.1,42.0);
	glVertex3f(13.0,10.1,37.0);
	glVertex3f(15.0,10.1,37.0);
	glVertex3f(15.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(16.0,10.1,42.0);
	glVertex3f(16.0,10.1,37.0);
	glVertex3f(18.0,10.1,37.0);
	glVertex3f(18.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(19.0,10.1,42.0);
	glVertex3f(19.0,10.1,37.0);
	glVertex3f(21.0,10.1,37.0);
	glVertex3f(21.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(22.0,10.1,42.0);
	glVertex3f(22.0,10.1,37.0);
	glVertex3f(24.0,10.1,37.0);
	glVertex3f(24.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(25.0,10.1,42.0);
	glVertex3f(25.0,10.1,37.0);
	glVertex3f(27.0,10.1,37.0);
	glVertex3f(27.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(28.0,10.1,42.0);
	glVertex3f(28.0,10.1,37.0);
	glVertex3f(30.0,10.1,37.0);
	glVertex3f(30.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(31.0,10.1,42.0);
	glVertex3f(31.0,10.1,37.0);
	glVertex3f(33.0,10.1,37.0);
	glVertex3f(33.0,10.1,42.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(34.0,10.1,42.0);
	glVertex3f(34.0,10.1,37.0);
	glVertex3f(36.0,10.1,37.0);
	glVertex3f(36.0,10.1,42.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-25.0,0.0,60.1);
	glVertex3f(40.0,0.0,60.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(-25.0,-25.0,55.0);
	glVertex3f(-25.0,5.0,55.0);
	glVertex3f(-22.0,5.0,55.0);
	glVertex3f(-22.0,-25.0,55.0);

	glVertex3f(-25.0,-25.0,57.0);
	glVertex3f(-25.0,0.0,57.0);
	glVertex3f(-22.0,0.0,57.0);
	glVertex3f(-22.0,-25.0,57.0);

	glVertex3f(-25.0,-25.0,57.0);
	glVertex3f(-25.0,5.0,57.0);
	glVertex3f(-25.0,5.0,55.0);
	glVertex3f(-25.0,-25.0,55.0);

	glVertex3f(-22.0,-25.0,57.0);
	glVertex3f(-22.0,5.0,57.0);
	glVertex3f(-22.0,5.0,55.0);
	glVertex3f(-22.0,-25.0,55.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(-15.0,-25.0,55.0);
	glVertex3f(-15.0,5.0,55.0);
	glVertex3f(-12.0,5.0,55.0);
	glVertex3f(-12.0,-25.0,55.0);

	glVertex3f(-15.0,-25.0,57.0);
	glVertex3f(-15.0,0.0,57.0);
	glVertex3f(-12.0,0.0,57.0);
	glVertex3f(-12.0,-25.0,57.0);

	glVertex3f(-15.0,-25.0,57.0);
	glVertex3f(-15.0,5.0,57.0);
	glVertex3f(-15.0,5.0,55.0);
	glVertex3f(-15.0,-25.0,55.0);

	glVertex3f(-12.0,-25.0,57.0);
	glVertex3f(-12.0,5.0,57.0);
	glVertex3f(-12.0,5.0,55.0);
	glVertex3f(-12.0,-25.0,55.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(-5.0,-25.0,55.0);
	glVertex3f(-5.0,5.0,55.0);
	glVertex3f(-2.0,5.0,55.0);
	glVertex3f(-2.0,-25.0,55.0);

	glVertex3f(-5.0,-25.0,57.0);
	glVertex3f(-5.0,0.0,57.0);
	glVertex3f(-2.0,0.0,57.0);
	glVertex3f(-2.0,-25.0,57.0);

	glVertex3f(-5.0,-25.0,57.0);
	glVertex3f(-5.0,5.0,57.0);
	glVertex3f(-5.0,5.0,55.0);
	glVertex3f(-5.0,-25.0,55.0);

	glVertex3f(-2.0,-25.0,57.0);
	glVertex3f(-2.0,5.0,57.0);
	glVertex3f(-2.0,5.0,55.0);
	glVertex3f(-2.0,-25.0,55.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(-1.0,-25.0,55.0);
	glVertex3f(-1.0,5.0,55.0);
	glVertex3f(2.0,5.0,55.0);
	glVertex3f(2.0,-25.0,55.0);

	glVertex3f(-1.0,-25.0,57.0);
	glVertex3f(-1.0,5.0,57.0);
	glVertex3f(2.0,5.0,57.0);
	glVertex3f(2.0,-25.0,57.0);

	glVertex3f(-1.0,-25.0,57.0);
	glVertex3f(-1.0,5.0,57.0);
	glVertex3f(-1.0,5.0,55.0);
	glVertex3f(-1.0,-25.0,55.0);

	glVertex3f(2.0,-25.0,57.0);
	glVertex3f(2.0,5.0,57.0);
	glVertex3f(2.0,5.0,55.0);
	glVertex3f(2.0,-25.0,55.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(3.0,-25.0,55.0);
	glVertex3f(3.0,5.0,55.0);
	glVertex3f(6.0,5.0,55.0);
	glVertex3f(6.0,-25.0,55.0);

	glVertex3f(3.0,-25.0,57.0);
	glVertex3f(3.0,5.0,57.0);
	glVertex3f(6.0,5.0,57.0);
	glVertex3f(6.0,-25.0,57.0);

	glVertex3f(3.0,-25.0,57.0);
	glVertex3f(3.0,5.0,57.0);
	glVertex3f(3.0,5.0,55.0);
	glVertex3f(3.0,-25.0,55.0);

	glVertex3f(6.0,-25.0,57.0);
	glVertex3f(6.0,5.0,57.0);
	glVertex3f(6.0,5.0,55.0);
	glVertex3f(6.0,-25.0,55.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(13.0,-25.0,55.0);
	glVertex3f(13.0,5.0,55.0);
	glVertex3f(16.0,5.0,55.0);
	glVertex3f(16.0,-25.0,55.0);

	glVertex3f(13.0,-25.0,57.0);
	glVertex3f(13.0,5.0,57.0);
	glVertex3f(16.0,5.0,57.0);
	glVertex3f(16.0,-25.0,57.0);

	glVertex3f(13.0,-25.0,57.0);
	glVertex3f(13.0,5.0,57.0);
	glVertex3f(13.0,5.0,55.0);
	glVertex3f(13.0,-25.0,55.0);

	glVertex3f(16.0,-25.0,57.0);
	glVertex3f(16.0,5.0,57.0);
	glVertex3f(16.0,5.0,55.0);
	glVertex3f(16.0,-25.0,55.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(23.0,-25.0,55.0);
	glVertex3f(23.0,5.0,55.0);
	glVertex3f(26.0,5.0,55.0);
	glVertex3f(26.0,-25.0,55.0);

	glVertex3f(23.0,-25.0,57.0);
	glVertex3f(23.0,5.0,57.0);
	glVertex3f(26.0,5.0,57.0);
	glVertex3f(26.0,-25.0,57.0);

	glVertex3f(23.0,-25.0,57.0);
	glVertex3f(23.0,5.0,57.0);
	glVertex3f(23.0,5.0,55.0);
	glVertex3f(23.0,-25.0,55.0);

	glVertex3f(26.0,-25.0,57.0);
	glVertex3f(26.0,5.0,57.0);
	glVertex3f(26.0,5.0,55.0);
	glVertex3f(26.0,-25.0,55.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(27.0,-25.0,55.0);
	glVertex3f(27.0,5.0,55.0);
	glVertex3f(30.0,5.0,55.0);
	glVertex3f(30.0,-25.0,55.0);

	glVertex3f(27.0,-25.0,57.0);
	glVertex3f(27.0,5.0,57.0);
	glVertex3f(30.0,5.0,57.0);
	glVertex3f(30.0,-25.0,57.0);

	glVertex3f(27.0,-25.0,57.0);
	glVertex3f(27.0,5.0,57.0);
	glVertex3f(27.0,5.0,55.0);
	glVertex3f(27.0,-25.0,55.0);

	glVertex3f(30.0,-25.0,57.0);
	glVertex3f(30.0,5.0,57.0);
	glVertex3f(30.0,5.0,55.0);
	glVertex3f(30.0,-25.0,55.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(31.0,-25.0,55.0);
	glVertex3f(31.0,5.0,55.0);
	glVertex3f(34.0,5.0,55.0);
	glVertex3f(34.0,-25.0,55.0);

	glVertex3f(31.0,-25.0,57.0);
	glVertex3f(31.0,5.0,57.0);
	glVertex3f(34.0,5.0,57.0);
	glVertex3f(34.0,-25.0,57.0);

	glVertex3f(31.0,-25.0,57.0);
	glVertex3f(31.0,5.0,57.0);
	glVertex3f(31.0,5.0,55.0);
	glVertex3f(31.0,-25.0,55.0);

	glVertex3f(34.0,-25.0,57.0);
	glVertex3f(34.0,5.0,57.0);
	glVertex3f(34.0,5.0,55.0);
	glVertex3f(34.0,-25.0,55.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(37.0,-25.0,55.0);
	glVertex3f(37.0,5.0,55.0);
	glVertex3f(40.0,5.0,55.0);
	glVertex3f(40.0,-25.0,55.0);

	glVertex3f(37.0,-25.0,57.0);
	glVertex3f(37.0,5.0,57.0);
	glVertex3f(40.0,5.0,57.0);
	glVertex3f(40.0,-25.0,57.0);

	glVertex3f(37.0,-25.0,57.0);
	glVertex3f(37.0,5.0,57.0);
	glVertex3f(37.0,5.0,55.0);
	glVertex3f(37.0,-25.0,55.0);

	glVertex3f(40.0,-25.0,57.0);
	glVertex3f(40.0,5.0,57.0);
	glVertex3f(40.0,5.0,55.0);
	glVertex3f(40.0,-25.0,55.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(-25.0,-25.0,55.0);
	glVertex3f(-25.0,-20.0,55.0);
	glVertex3f(40.0,-20.0,55.0);
	glVertex3f(40.0,-25.0,55.0);

	glVertex3f(-25.0,-25.0,57.0);
	glVertex3f(-25.0,-20.0,57.0);
	glVertex3f(40.0,-20.0,57.0);
	glVertex3f(40.0,-25.0,57.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(-28.0,-25.0,45.0);
	glVertex3f(-28.0,-5.0,45.0);
	glVertex3f(-25.0,-5.0,45.0);
	glVertex3f(-25.0,-25.0,45.0);

	glVertex3f(-28.0,-25.0,48.0);
	glVertex3f(-28.0,-5.0,48.0);
	glVertex3f(-25.0,-5.0,48.0);
	glVertex3f(-25.0,-25.0,48.0);

	glVertex3f(-28.0,-25.0,48.0);
	glVertex3f(-28.0,10.0,48.0);
	glVertex3f(-28.0,10.0,45.0);
	glVertex3f(-28.0,-25.0,45.0);

	glVertex3f(-25.0,-25.0,48.0);
	glVertex3f(-25.0,10.0,48.0);
	glVertex3f(-25.0,10.0,45.0);
	glVertex3f(-25.0,-25.0,45.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(-50.0,-25.0,45.0);
	glVertex3f(-50.0,-5.0,45.0);
	glVertex3f(-47.0,-5.0,45.0);
	glVertex3f(-47.0,-25.0,45.0);

	glVertex3f(-50.0,-25.0,48.0);
	glVertex3f(-50.0,-5.0,48.0);
	glVertex3f(-47.0,-5.0,48.0);
	glVertex3f(-47.0,-25.0,48.0);

	glVertex3f(-50.0,-25.0,48.0);
	glVertex3f(-50.0,10.0,48.0);
	glVertex3f(-50.0,10.0,45.0);
	glVertex3f(-50.0,-25.0,45.0);

	glVertex3f(-47.0,-25.0,48.0);
	glVertex3f(-47.0,10.0,48.0);
	glVertex3f(-47.0,10.0,45.0);
	glVertex3f(-47.0,-25.0,45.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-50.0,-5.0,45.0);
	glVertex3f(-50.0,10.0,45.0);
	glVertex3f(-25.0,10.0,45.0);
	glVertex3f(-25.0,-5.0,45.0);

	glVertex3f(-50.0,-5.0,48.0);
	glVertex3f(-50.0,10.0,48.0);
	glVertex3f(-25.0,10.0,48.0);
	glVertex3f(-25.0,-5.0,48.0);

	glVertex3f(-50.0,10.0,48.0);
	glVertex3f(-50.0,10.0,45.0);
	glVertex3f(-25.0,10.0,45.0);
	glVertex3f(-25.0,10.0,48.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(40.0,-25.0,50.0);
	glVertex3f(40.0,-15.0,50.0);
	glVertex3f(47.0,-15.0,50.0);
	glVertex3f(47.0,-25.0,50.0);

	glVertex3f(40.0,-25.0,55.0);
	glVertex3f(40.0,-15.0,55.0);
	glVertex3f(47.0,-15.0,55.0);
	glVertex3f(47.0,-25.0,55.0);

	glVertex3f(53.0,-25.0,50.0);
	glVertex3f(53.0,-15.0,50.0);
	glVertex3f(60.0,-15.0,50.0);
	glVertex3f(60.0,-25.0,50.0);

	glVertex3f(53.0,-25.0,55.0);
	glVertex3f(53.0,-15.0,55.0);
	glVertex3f(60.0,-15.0,55.0);
	glVertex3f(60.0,-25.0,55.0);

	glVertex3f(60.0,-25.0,55.0);
	glVertex3f(60.0,-15.0,55.0);
	glVertex3f(60.0,-15.0,50.0);
	glVertex3f(60.0,-25.0,50.0);

	glColor3f(0.9,0.9,0.3);
	glVertex3f(47.0,-25.0,55.0);
	glVertex3f(47.0,-15.0,55.0);
	glVertex3f(47.0,-15.0,50.0);
	glVertex3f(47.0,-25.0,50.0);

	glVertex3f(53.0,-25.0,55.0);
	glVertex3f(53.0,-15.0,55.0);
	glVertex3f(53.0,-15.0,50.0);
	glVertex3f(53.0,-25.0,50.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(40.0,-15.0,56.0);
	glVertex3f(40.0,-15.0,49.0);
	glVertex3f(60.0,-15.0,49.0);
	glVertex3f(60.0,-15.0,56.0);

	glVertex3f(40.1,-15.0,56.0);
	glVertex3f(40.1,-12.0,56.0);
	glVertex3f(40.1,-12.0,49.0);
	glVertex3f(40.1,-15.0,49.0);

	glVertex3f(60.0,-15.0,56.0);
	glVertex3f(60.0,-12.0,56.0);
	glVertex3f(60.0,-12.0,49.0);
	glVertex3f(60.0,-15.0,49.0);

	glVertex3f(40.0,-12.0,56.0);
	glVertex3f(40.0,-12.0,49.0);
	glVertex3f(60.0,-12.0,49.0);
	glVertex3f(60.0,-12.0,56.0);

	glVertex3f(40.0,-15.0,56.0);
	glVertex3f(40.0,-12.0,56.0);
	glVertex3f(60.0,-12.0,56.0);
	glVertex3f(60.0,-15.0,56.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(40.0,-25.0,48.0);
	glVertex3f(40.0,-5.0,48.0);
	glVertex3f(60.0,-5.0,48.0);
	glVertex3f(60.0,-25.0,48.0);

	glVertex3f(40.0,-25.0,36.0);
	glVertex3f(40.0,-5.0,36.0);
	glVertex3f(60.0,-5.0,36.0);
	glVertex3f(60.0,-25.0,36.0);

	glVertex3f(40.0,-25.0,48.0);
	glVertex3f(40.0,-5.0,48.0);
	glVertex3f(40.0,-5.0,36.0);
	glVertex3f(40.0,-25.0,36.0);

	glVertex3f(60.0,-25.0,48.0);
	glVertex3f(60.0,-5.0,48.0);
	glVertex3f(60.0,-5.0,36.0);
	glVertex3f(60.0,-25.0,36.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(39.0,-5.0,49.0);
	glVertex3f(39.0,-1.0,49.0);
	glVertex3f(61.0,-1.0,49.0);
	glVertex3f(61.0,-5.0,49.0);

	glVertex3f(39.0,-5.0,49.0);
	glVertex3f(39.0,-1.0,49.0);
	glVertex3f(39.0,-1.0,33.0);
	glVertex3f(39.0,-5.0,33.0);

	glVertex3f(61.0,-5.0,49.0);
	glVertex3f(61.0,-1.0,49.0);
	glVertex3f(61.0,-1.0,33.0);
	glVertex3f(61.0,-5.0,33.0);

	glVertex3f(39.0,-1.0,49.0);
	glVertex3f(39.0,-1.0,33.0);
	glVertex3f(61.0,-1.0,33.0);
	glVertex3f(61.0,-1.0,49.0);
	glEnd();


	glBegin(GL_LINES);
	glLineWidth(4.0);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-20.0,1.0,60.1);
	glVertex3f(-18.0,5.0,60.1);
	glVertex3f(-18.0,5.0,60.1);
	glVertex3f(-16.0,1.0,60.1);

	glVertex3f(-12.0,5.0,60.1);
	glVertex3f(-15.0,5.0,60.1);
	glVertex3f(-15.0,5.0,60.1);
	glVertex3f(-15.0,3.0,60.1);
	glVertex3f(-15.0,3.0,60.1);
	glVertex3f(-12.0,3.0,60.1);
	glVertex3f(-12.0,3.0,60.1);
	glVertex3f(-12.0,1.0,60.1);
	glVertex3f(-12.0,1.0,60.1);
	glVertex3f(-15.0,1.0,60.1);

	glVertex3f(-8.0,5.0,60.1);
	glVertex3f(-11.0,5.0,60.1);
	glVertex3f(-9.5,5.0,60.1);
	glVertex3f(-9.5,1.0,60.1);

	glVertex3f(-4.0,5.0,60.1);
	glVertex3f(-7.0,5.0,60.1);
	glVertex3f(-7.0,5.0,60.1);
	glVertex3f(-7.0,1.0,60.1);
	glVertex3f(-7.0,1.0,60.1);
	glVertex3f(-4.0,1.0,60.1);
	glVertex3f(-4.0,1.0,60.1);
	glVertex3f(-4.0,5.0,60.1);

	glVertex3f(-3.0,1.0,60.1);
	glVertex3f(-3.0,5.0,60.1);
	glVertex3f(-3.0,5.0,60.1);
	glVertex3f(0.0,1.0,60.1);
	glVertex3f(0.0,1.0,60.1);
	glVertex3f(0.0,5.0,60.1);

	glVertex3f(5.0,5.0,60.1);
	glVertex3f(6.5,1.0,60.1);
	glVertex3f(6.5,1.0,60.1);
	glVertex3f(8.0,5.0,60.1);

	glVertex3f(9.0,5.0,60.1);
	glVertex3f(9.0,1.0,60.1);

	glVertex3f(10.0,5.0,60.1);
	glVertex3f(10.0,1.0,60.1);
	glVertex3f(10.0,1.0,60.1);
	glVertex3f(12.0,1.0,60.1);

	glVertex3f(13.0,5.0,60.1);
	glVertex3f(13.0,1.0,60.1);
	glVertex3f(13.0,1.0,60.1);
	glVertex3f(15.0,1.0,60.1);

	glVertex3f(16.0,1.0,60.1);
	glVertex3f(17.5,5.0,60.1);
	glVertex3f(17.5,5.0,60.1);
	glVertex3f(19.0,1.0,60.1);

	glVertex3f(24.0,1.0,60.1);
	glVertex3f(24.0,5.0,60.1);
	glVertex3f(24.0,5.0,60.1);
	glVertex3f(27.0,5.0,60.1);
	glVertex3f(24.0,3.0,60.1);
	glVertex3f(27.0,3.0,60.1);

	glVertex3f(31.0,1.0,60.1);
	glVertex3f(28.0,1.0,60.1);
	glVertex3f(28.0,1.0,60.1);
	glVertex3f(28.0,5.0,60.1);
	glVertex3f(28.0,5.0,60.1);
	glVertex3f(31.0,5.0,60.1);
	glEnd();





	//atap 3 atap kanan
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(35.0,5.0,30.0);
	glVertex3f(35.0,10.0,30.0);
	glVertex3f(60.0,12.0,30.0);
	glVertex3f(60.0,7.0,30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(35.0,5.0,-25.0);
	glVertex3f(35.0,10.0,-25.0);
	glVertex3f(60.0,12.0,-25.0);
	glVertex3f(60.0,7.0,-25.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(35.0,5.0,30.0);
	glVertex3f(35.0,10.0,30.0);
	glVertex3f(35.0,10.0,-25.0);
	glVertex3f(35.0,5.0,-25.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(60.0,12.0,30.0);
	glVertex3f(60.0,7.0,30.0);
	glVertex3f(60.0,7.0,-25.0);
	glVertex3f(60.0,12.0,-25.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(35.0,10.0,30.0);
	glVertex3f(35.0,10.0,-25.0);
	glVertex3f(60.0,12.0,-25.0);
	glVertex3f(60.0,12.0,30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(35.0,5.0,30.0);
	glVertex3f(35.0,5.0,-25.0);
	glVertex3f(60.0,7.0,-25.0);
	glVertex3f(60.0,7.0,30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(43.0,-25.0,30.0);
	glVertex3f(43.0,15.0,30.0);
	glVertex3f(45.0,15.0,30.0);
	glVertex3f(45.0,-25.0,30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(43.0,-25.0,35.0);
	glVertex3f(43.0,15.0,35.0);
	glVertex3f(45.0,15.0,35.0);
	glVertex3f(45.0,-25.0,35.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(43.0,-25.0,35.0);
	glVertex3f(43.0,15.0,35.0);
	glVertex3f(43.0,15.0,30.0);
	glVertex3f(43.0,-25.0,30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(45.0,-25.0,35.0);
	glVertex3f(45.0,15.0,35.0);
	glVertex3f(45.0,15.0,30.0);
	glVertex3f(45.0,-25.0,30.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(43.0,-25.0,-25.0);
	glVertex3f(43.0,15.0,-25.0);
	glVertex3f(45.0,15.0,-25.0);
	glVertex3f(45.0,-25.0,-25.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(43.0,-25.0,-30.0);
	glVertex3f(43.0,15.0,-30.0);
	glVertex3f(45.0,15.0,-30.0);
	glVertex3f(45.0,-25.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(43.0,-25.0,-25.0);
	glVertex3f(43.0,15.0,-25.0);
	glVertex3f(43.0,15.0,-30.0);
	glVertex3f(43.0,-25.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(45.0,-25.0,-25.0);
	glVertex3f(45.0,15.0,-25.0);
	glVertex3f(45.0,15.0,-30.0);
	glVertex3f(45.0,-25.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(43.0,15.0,35.0);
	glVertex3f(43.0,17.0,35.0);
	glVertex3f(43.0,17.0,-30.0);
	glVertex3f(43.0,15.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(45.0,15.0,35.0);
	glVertex3f(45.0,17.0,35.0);
	glVertex3f(45.0,17.0,-30.0);
	glVertex3f(45.0,15.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(43.0,15.0,35.0);
	glVertex3f(45.0,15.0,35.0);
	glVertex3f(45.0,15.0,-30.0);
	glVertex3f(43.0,15.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(60.0,-25.0,34.0);
	glVertex3f(58.0,6.0,34.0);
	glVertex3f(58.0,6.0,-29.0);
	glVertex3f(60.0,-25.0,-29.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(58.5,0.0,30.0);
	glVertex3f(59.2,-5.0,30.0);
	glVertex3f(59.2,-5.0,-26.0);
	glVertex3f(58.5,0.0,-26.0);

	glVertex3f(58.9,-7.0,30.0);
	glVertex3f(59.6,-12.0,30.0);
	glVertex3f(59.6,-12.0,-26.0);
	glVertex3f(58.9,-7.0,-26.0);

	glVertex3f(59.6,-14.0,30.0);
	glVertex3f(60.0,-19.0,30.0);
	glVertex3f(60.0,-19.0,-26.0);
	glVertex3f(59.6,-14.0,-26.0);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(43.0,15.0,30.0);
	glVertex3f(43.0,10.0,25.0);
	glVertex3f(43.0,10.0,25.0);
	glVertex3f(43.0,15.0,20.0);
	glVertex3f(43.0,15.0,20.0);
	glVertex3f(43.0,10.0,15.0);
	glVertex3f(43.0,10.0,15.0);
	glVertex3f(43.0,15.0,10.0);
	glVertex3f(43.0,15.0,10.0);
	glVertex3f(43.0,10.0,5.0);
	glVertex3f(43.0,10.0,5.0);
	glVertex3f(43.0,15.0,0.0);
	glVertex3f(43.0,15.0,0.0);
	glVertex3f(43.0,10.0,-5.0);
	glVertex3f(43.0,10.0,-5.0);
	glVertex3f(43.0,15.0,-10.0);
	glVertex3f(43.0,15.0,-10.0);
	glVertex3f(43.0,10.0,-15.0);
	glVertex3f(43.0,10.0,-15.0);
	glVertex3f(43.0,15.0,-20.0);
	glVertex3f(43.0,15.0,-20.0);
	glVertex3f(43.0,10.0,-25.0);
	glVertex3f(43.0,10.0,-25.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(43.0,10.0,30.0);
	glVertex3f(43.0,15.0,25.0);
	glVertex3f(43.0,15.0,25.0);
	glVertex3f(43.0,10.0,20.0);
	glVertex3f(43.0,10.0,20.0);
	glVertex3f(43.0,15.0,15.0);
	glVertex3f(43.0,15.0,15.0);
	glVertex3f(43.0,10.0,10.0);
	glVertex3f(43.0,10.0,10.0);
	glVertex3f(43.0,15.0,5.0);
	glVertex3f(43.0,15.0,5.0);
	glVertex3f(43.0,10.0,0.0);
	glVertex3f(43.0,10.0,0.0);
	glVertex3f(43.0,15.0,-5.0);
	glVertex3f(43.0,15.0,-5.0);
	glVertex3f(43.0,10.0,-10.0);
	glVertex3f(43.0,10.0,-10.0);
	glVertex3f(43.0,15.0,-15.0);
	glVertex3f(43.0,15.0,-15.0);
	glVertex3f(43.0,10.0,-20.0);
	glVertex3f(43.0,10.0,-20.0);
	glVertex3f(43.0,15.0,-25.0);
	glVertex3f(43.0,15.0,-25.0);
	glEnd();


	//atap 4 belakang
	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(-40.0,0.0,-30.0);
	glVertex3f(-40.0,5.0,-30.0);
	glVertex3f(40.0,5.0,-30.0);
	glVertex3f(40.0,0.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-40.0,5.0,-30.0);
	glVertex3f(-40.0,0.0,-30.0);
	glVertex3f(-40.0,2.0,-70.0);
	glVertex3f(-40.0,7.0,-70.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(40.0,5.0,-30.0);
	glVertex3f(40.0,0.0,-30.0);
	glVertex3f(40.0,2.0,-70.0);
	glVertex3f(40.0,7.0,-70.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(-30.0,2.0,-80.0);
	glVertex3f(-30.0,7.0,-80.0);
	glVertex3f(30.0,7.0,-80.0);
	glVertex3f(30.0,2.0,-80.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(-40.0,7.0,-70.0);
	glVertex3f(-40.0,2.0,-70.0);
	glVertex3f(-30.0,2.0,-80.0);
	glVertex3f(-30.0,7.0,-80.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(40.0,7.0,-70.0);
	glVertex3f(40.0,2.0,-70.0);
	glVertex3f(30.0,2.0,-80.0);
	glVertex3f(30.0,7.0,-80.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(-40.0,5.0,-30.0);
	glVertex3f(-40.0,7.0,-70.0);
	glVertex3f(-30.0,7.0,-80.0);
	glVertex3f(30.0,7.0,-80.0);
	glVertex3f(40.0,7.0,-70.0);
	glVertex3f(40.0,5.0,-30.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(-40.0,0.0,-30.0);
	glVertex3f(-40.0,2.0,-70.0);
	glVertex3f(-30.0,2.0,-80.0);
	glVertex3f(30.0,2.0,-80.0);
	glVertex3f(40.0,2.0,-70.0);
	glVertex3f(40.0,0.0,-30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(-30.0,-25.0,-85.0);
	glVertex3f(-30.0,0.0,-85.0);
	glVertex3f(30.0,0.0,-85.0);
	glVertex3f(30.0,-25.0,-85.0);

	glBegin(GL_QUADS);
	glVertex3f(-40.0,-25.0,-75.0);
	glVertex3f(-40.0,0.0,-75.0);
	glVertex3f(-30.0,0.0,-85.0);
	glVertex3f(-30.0,-25.0,-85.0);

	glBegin(GL_QUADS);
	glVertex3f(-40.0,-25.0,-70.0);
	glVertex3f(-40.0,0.0,-70.0);
	glVertex3f(-40.0,0.0,-75.0);
	glVertex3f(-40.0,-25.0,-75.0);

	glBegin(GL_QUADS);
	glVertex3f(40.0,-25.0,-75.0);
	glVertex3f(40.0,0.0,-75.0);
	glVertex3f(30.0,0.0,-85.0);
	glVertex3f(30.0,-25.0,-85.0);

	glBegin(GL_QUADS);
	glVertex3f(40.0,-25.0,-70.0);
	glVertex3f(40.0,0.0,-70.0);
	glVertex3f(40.0,0.0,-75.0);
	glVertex3f(40.0,-25.0,-75.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(30.0,0.0,-85.0);
	glVertex3f(30.0,2.0,-80.0);
	glVertex3f(-30.0,2.0,-80.0);
	glVertex3f(-30.0,0.0,-85.0);

	glVertex3f(40.0,0.0,-75.0);
	glVertex3f(40.0,2.0,-70.0);
	glVertex3f(30.0,2.0,-80.0);
	glVertex3f(30.0,0.0,-85.0);

	glVertex3f(-40.0,0.0,-75.0);
	glVertex3f(-40.0,2.0,-70.0);
	glVertex3f(-30.0,2.0,-80.0);
	glVertex3f(-30.0,0.0,-85.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-38.0,-7.0,-78.0);
	glVertex3f(-38.0,-2.0,-78.0);
	glVertex3f(-33.0,-2.0,-83.0);
	glVertex3f(-33.0,-7.0,-83.0);

	glColor3f(1.0,1.0,1.0);
	glVertex3f(-38.0,-13.0,-78.0);
	glVertex3f(-38.0,-8.0,-78.0);
	glVertex3f(-33.0,-8.0,-83.0);
	glVertex3f(-33.0,-13.0,-83.0);

	glColor3f(1.0,1.0,1.0);
	glVertex3f(-38.0,-19.0,-78.0);
	glVertex3f(-38.0,-14.0,-78.0);
	glVertex3f(-33.0,-14.0,-83.0);
	glVertex3f(-33.0,-19.0,-83.0);

	glColor3f(1.0,1.0,1.0);
	glVertex3f(38.0,-7.0,-78.0);
	glVertex3f(38.0,-2.0,-78.0);
	glVertex3f(33.0,-2.0,-83.0);
	glVertex3f(33.0,-7.0,-83.0);

	glColor3f(1.0,1.0,1.0);
	glVertex3f(38.0,-13.0,-78.0);
	glVertex3f(38.0,-8.0,-78.0);
	glVertex3f(33.0,-8.0,-83.0);
	glVertex3f(33.0,-13.0,-83.0);

	glColor3f(1.0,1.0,1.0);
	glVertex3f(38.0,-19.0,-78.0);
	glVertex3f(38.0,-14.0,-78.0);
	glVertex3f(33.0,-14.0,-83.0);
	glVertex3f(33.0,-19.0,-83.0);

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-28.0,-7.0,-85.1);
	glVertex3f(-28.0,-2.0,-85.1);
	glVertex3f(-23.0,-2.0,-85.1);
	glVertex3f(-23.0,-7.0,-85.1);

	glVertex3f(-22.0,-7.0,-85.1);
	glVertex3f(-22.0,-2.0,-85.1);
	glVertex3f(-17.0,-2.0,-85.1);
	glVertex3f(-17.0,-7.0,-85.1);

	glVertex3f(-16.0,-7.0,-85.1);
	glVertex3f(-16.0,-2.0,-85.1);
	glVertex3f(-11.0,-2.0,-85.1);
	glVertex3f(-11.0,-7.0,-85.1);

	glVertex3f(-10.0,-7.0,-85.1);
	glVertex3f(-10.0,-2.0,-85.1);
	glVertex3f(-5.0,-2.0,-85.1);
	glVertex3f(-5.0,-7.0,-85.1);

	glVertex3f(-4.0,-7.0,-85.1);
	glVertex3f(-4.0,-2.0,-85.1);
	glVertex3f(1.0,-2.0,-85.1);
	glVertex3f(1.0,-7.0,-85.1);

	glVertex3f(2.0,-7.0,-85.1);
	glVertex3f(2.0,-2.0,-85.1);
	glVertex3f(7.0,-2.0,-85.1);
	glVertex3f(7.0,-7.0,-85.1);

	glVertex3f(8.0,-7.0,-85.1);
	glVertex3f(8.0,-2.0,-85.1);
	glVertex3f(13.0,-2.0,-85.1);
	glVertex3f(13.0,-7.0,-85.1);

	glVertex3f(14.0,-7.0,-85.1);
	glVertex3f(14.0,-2.0,-85.1);
	glVertex3f(19.0,-2.0,-85.1);
	glVertex3f(19.0,-7.0,-85.1);

	glVertex3f(20.0,-7.0,-85.1);
	glVertex3f(20.0,-2.0,-85.1);
	glVertex3f(25.0,-2.0,-85.1);
	glVertex3f(25.0,-7.0,-85.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-28.0,-13.0,-85.1);
	glVertex3f(-28.0,-8.0,-85.1);
	glVertex3f(-23.0,-8.0,-85.1);
	glVertex3f(-23.0,-13.0,-85.1);

	glVertex3f(-22.0,-13.0,-85.1);
	glVertex3f(-22.0,-8.0,-85.1);
	glVertex3f(-17.0,-8.0,-85.1);
	glVertex3f(-17.0,-13.0,-85.1);

	glVertex3f(-16.0,-13.0,-85.1);
	glVertex3f(-16.0,-8.0,-85.1);
	glVertex3f(-11.0,-8.0,-85.1);
	glVertex3f(-11.0,-13.0,-85.1);

	glVertex3f(-10.0,-13.0,-85.1);
	glVertex3f(-10.0,-8.0,-85.1);
	glVertex3f(-5.0,-8.0,-85.1);
	glVertex3f(-5.0,-13.0,-85.1);

	glVertex3f(-4.0,-13.0,-85.1);
	glVertex3f(-4.0,-8.0,-85.1);
	glVertex3f(1.0,-8.0,-85.1);
	glVertex3f(1.0,-13.0,-85.1);

	glVertex3f(2.0,-13.0,-85.1);
	glVertex3f(2.0,-8.0,-85.1);
	glVertex3f(7.0,-8.0,-85.1);
	glVertex3f(7.0,-13.0,-85.1);

	glVertex3f(8.0,-13.0,-85.1);
	glVertex3f(8.0,-8.0,-85.1);
	glVertex3f(13.0,-8.0,-85.1);
	glVertex3f(13.0,-13.0,-85.1);

	glVertex3f(14.0,-13.0,-85.1);
	glVertex3f(14.0,-8.0,-85.1);
	glVertex3f(19.0,-8.0,-85.1);
	glVertex3f(19.0,-13.0,-85.1);

	glVertex3f(20.0,-13.0,-85.1);
	glVertex3f(20.0,-8.0,-85.1);
	glVertex3f(25.0,-8.0,-85.1);
	glVertex3f(25.0,-13.0,-85.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(-28.0,-19.0,-85.1);
	glVertex3f(-28.0,-14.0,-85.1);
	glVertex3f(-23.0,-14.0,-85.1);
	glVertex3f(-23.0,-19.0,-85.1);

	glVertex3f(-22.0,-19.0,-85.1);
	glVertex3f(-22.0,-14.0,-85.1);
	glVertex3f(-17.0,-14.0,-85.1);
	glVertex3f(-17.0,-19.0,-85.1);

	glVertex3f(-16.0,-19.0,-85.1);
	glVertex3f(-16.0,-14.0,-85.1);
	glVertex3f(-11.0,-14.0,-85.1);
	glVertex3f(-11.0,-19.0,-85.1);

	glVertex3f(-10.0,-19.0,-85.1);
	glVertex3f(-10.0,-14.0,-85.1);
	glVertex3f(-5.0,-14.0,-85.1);
	glVertex3f(-5.0,-19.0,-85.1);

	glVertex3f(-4.0,-19.0,-85.1);
	glVertex3f(-4.0,-14.0,-85.1);
	glVertex3f(1.0,-14.0,-85.1);
	glVertex3f(1.0,-19.0,-85.1);

	glVertex3f(2.0,-19.0,-85.1);
	glVertex3f(2.0,-14.0,-85.1);
	glVertex3f(7.0,-14.0,-85.1);
	glVertex3f(7.0,-19.0,-85.1);

	glVertex3f(8.0,-19.0,-85.1);
	glVertex3f(8.0,-14.0,-85.1);
	glVertex3f(13.0,-14.0,-85.1);
	glVertex3f(13.0,-19.0,-85.1);

	glVertex3f(14.0,-19.0,-85.1);
	glVertex3f(14.0,-14.0,-85.1);
	glVertex3f(19.0,-14.0,-85.1);
	glVertex3f(19.0,-19.0,-85.1);

	glVertex3f(20.0,-19.0,-85.1);
	glVertex3f(20.0,-14.0,-85.1);
	glVertex3f(25.0,-14.0,-85.1);
	glVertex3f(25.0,-19.0,-85.1);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(-40.0,-25.0,-31.0);
	glVertex3f(-40.0,0.0,-31.0);
	glVertex3f(-40.0,2.0,-70.0);
	glVertex3f(-40.0,-25.0,-70.0);

	glColor3f(0.9,0.9,1.0);
	glVertex3f(-40.1,-5.0,-34.0);
	glVertex3f(-40.1,-10.0,-34.0);
	glVertex3f(-40.1,-10.0,-44.0);
	glVertex3f(-40.1,-5.0,-44.0);

	glVertex3f(-40.1,-5.0,-46.0);
	glVertex3f(-40.1,-10.0,-46.0);
	glVertex3f(-40.1,-10.0,-56.0);
	glVertex3f(-40.1,-5.0,-56.0);

	glVertex3f(-40.1,-5.0,-58.0);
	glVertex3f(-40.1,-10.0,-58.0);
	glVertex3f(-40.1,-10.0,-68.0);
	glVertex3f(-40.1,-5.0,-68.0);

	glColor3f(0.9,0.9,1.0);
	glVertex3f(-40.1,-12.0,-34.0);
	glVertex3f(-40.1,-17.0,-34.0);
	glVertex3f(-40.1,-17.0,-44.0);
	glVertex3f(-40.1,-12.0,-44.0);

	glVertex3f(-40.1,-12.0,-46.0);
	glVertex3f(-40.1,-17.0,-46.0);
	glVertex3f(-40.1,-17.0,-56.0);
	glVertex3f(-40.1,-12.0,-56.0);

	glVertex3f(-40.1,-12.0,-58.0);
	glVertex3f(-40.1,-17.0,-58.0);
	glVertex3f(-40.1,-17.0,-68.0);
	glVertex3f(-40.1,-12.0,-68.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.5,0.3);
	glVertex3f(41.0,-25.0,-31.0);
	glVertex3f(41.0,-15.0,-31.0);
	glVertex3f(50.0,-15.0,-31.0);
	glVertex3f(50.0,-25.0,-31.0);

	glVertex3f(35.0,-25.0,-50.0);
	glVertex3f(35.0,-15.0,-50.0);
	glVertex3f(55.0,-15.0,-50.0);
	glVertex3f(55.0,-25.0,-50.0);

	glVertex3f(41.0,-25.0,-50.0);
	glVertex3f(41.0,-15.0,-50.0);
	glVertex3f(41.0,-15.0,-31.0);
	glVertex3f(41.0,-25.0,-31.0);

	glVertex3f(50.0,-25.0,-40.0);
	glVertex3f(50.0,-15.0,-40.0);
	glVertex3f(50.0,-15.0,-31.0);
	glVertex3f(50.0,-25.0,-31.0);

	glVertex3f(45.0,-25.0,-40.0);
	glVertex3f(45.0,-15.0,-40.0);
	glVertex3f(55.0,-15.0,-40.0);
	glVertex3f(55.0,-25.0,-40.0);

	glVertex3f(55.0,-25.0,-40.0);
	glVertex3f(55.0,-15.0,-40.0);
	glVertex3f(55.0,-15.0,-50.0);
	glVertex3f(55.0,-25.0,-50.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.9,0.9,1.0);
	glVertex3f(41.0,-15.0,-31.0);
	glVertex3f(41.0,-12.0,-31.0);
	glVertex3f(51.0,-12.0,-31.0);
	glVertex3f(51.0,-15.0,-31.0);

	glVertex3f(51.0,-15.0,-31.0);
	glVertex3f(51.0,-12.0,-31.0);
	glVertex3f(51.0,-12.0,-39.0);
	glVertex3f(51.0,-15.0,-39.0);

	glVertex3f(51.0,-15.0,-39.0);
	glVertex3f(51.0,-12.0,-39.0);
	glVertex3f(56.0,-12.0,-39.0);
	glVertex3f(56.0,-15.0,-39.0);

	glVertex3f(56.0,-15.0,-39.0);
	glVertex3f(56.0,-12.0,-39.0);
	glVertex3f(56.0,-12.0,-51.0);
	glVertex3f(56.0,-15.0,-51.0);

	glVertex3f(35.0,-15.0,-51.0);
	glVertex3f(35.0,-12.0,-51.0);
	glVertex3f(56.0,-12.0,-51.0);
	glVertex3f(56.0,-15.0,-51.0);

	glVertex3f(41.0,-12.0,-31.0);
	glVertex3f(41.0,-12.0,-39.0);
	glVertex3f(51.0,-12.0,-39.0);
	glVertex3f(51.0,-12.0,-31.0);

	glVertex3f(35.0,-12.0,-39.0);
	glVertex3f(35.0,-12.0,-51.0);
	glVertex3f(56.0,-12.0,-51.0);
	glVertex3f(56.0,-12.0,-39.0);
	glEnd();


	glBegin(GL_LINES);
	glLineWidth(4.0);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-35.0,5.0,-30.0);
	glVertex3f(-35.0,7.0,-31.0);
	glVertex3f(-35.0,7.0,-31.0);
	glVertex3f(-35.0,11.0,-77.0);
	glVertex3f(-35.0,11.0,-77.0);
	glVertex3f(-35.0,2.0,-80.0);

	glVertex3f(-30.0,5.0,-30.0);
	glVertex3f(-30.0,7.0,-31.0);
	glVertex3f(-30.0,7.0,-31.0);
	glVertex3f(-30.0,11.0,-82.0);
	glVertex3f(-30.0,11.0,-82.0);
	glVertex3f(-30.0,1.0,-85.0);

	glVertex3f(-25.0,5.0,-30.0);
	glVertex3f(-25.0,7.0,-31.0);
	glVertex3f(-25.0,7.0,-31.0);
	glVertex3f(-25.0,11.0,-82.0);
	glVertex3f(-25.0,11.0,-82.0);
	glVertex3f(-25.0,1.0,-85.0);

	glVertex3f(-20.0,5.0,-30.0);
	glVertex3f(-20.0,7.0,-31.0);
	glVertex3f(-20.0,7.0,-31.0);
	glVertex3f(-20.0,11.0,-82.0);
	glVertex3f(-20.0,11.0,-82.0);
	glVertex3f(-20.0,1.0,-85.0);

	glVertex3f(-15.0,5.0,-30.0);
	glVertex3f(-15.0,7.0,-31.0);
	glVertex3f(-15.0,7.0,-31.0);
	glVertex3f(-15.0,11.0,-82.0);
	glVertex3f(-15.0,11.0,-82.0);
	glVertex3f(-15.0,1.0,-85.0);

	glVertex3f(-10.0,5.0,-30.0);
	glVertex3f(-10.0,7.0,-31.0);
	glVertex3f(-10.0,7.0,-31.0);
	glVertex3f(-10.0,11.0,-82.0);
	glVertex3f(-10.0,11.0,-82.0);
	glVertex3f(-10.0,1.0,-85.0);

	glVertex3f(-5.0,5.0,-30.0);
	glVertex3f(-5.0,7.0,-31.0);
	glVertex3f(-5.0,7.0,-31.0);
	glVertex3f(-5.0,11.0,-82.0);
	glVertex3f(-5.0,11.0,-82.0);
	glVertex3f(-5.0,1.0,-85.0);

	glVertex3f(0.0,5.0,-30.0);
	glVertex3f(0.0,7.0,-31.0);
	glVertex3f(0.0,7.0,-31.0);
	glVertex3f(0.0,11.0,-82.0);
	glVertex3f(0.0,11.0,-82.0);
	glVertex3f(0.0,1.0,-85.0);

	glVertex3f(5.0,5.0,-30.0);
	glVertex3f(5.0,7.0,-31.0);
	glVertex3f(5.0,7.0,-31.0);
	glVertex3f(5.0,11.0,-82.0);
	glVertex3f(5.0,11.0,-82.0);
	glVertex3f(5.0,1.0,-85.0);

	glVertex3f(10.0,5.0,-30.0);
	glVertex3f(10.0,7.0,-31.0);
	glVertex3f(10.0,7.0,-31.0);
	glVertex3f(10.0,11.0,-82.0);
	glVertex3f(10.0,11.0,-82.0);
	glVertex3f(10.0,1.0,-85.0);

	glVertex3f(15.0,5.0,-30.0);
	glVertex3f(15.0,7.0,-31.0);
	glVertex3f(15.0,7.0,-31.0);
	glVertex3f(15.0,11.0,-82.0);
	glVertex3f(15.0,11.0,-82.0);
	glVertex3f(15.0,1.0,-85.0);

	glVertex3f(20.0,5.0,-30.0);
	glVertex3f(20.0,7.0,-31.0);
	glVertex3f(20.0,7.0,-31.0);
	glVertex3f(20.0,11.0,-82.0);
	glVertex3f(20.0,11.0,-82.0);
	glVertex3f(20.0,1.0,-85.0);

	glVertex3f(25.0,5.0,-30.0);
	glVertex3f(25.0,7.0,-31.0);
	glVertex3f(25.0,7.0,-31.0);
	glVertex3f(25.0,11.0,-82.0);
	glVertex3f(25.0,11.0,-82.0);
	glVertex3f(25.0,1.0,-85.0);

	glVertex3f(30.0,5.0,-30.0);
	glVertex3f(30.0,7.0,-31.0);
	glVertex3f(30.0,7.0,-31.0);
	glVertex3f(30.0,11.0,-82.0);
	glVertex3f(30.0,11.0,-82.0);
	glVertex3f(30.0,1.0,-85.0);

	glVertex3f(35.0,5.0,-30.0);
	glVertex3f(35.0,7.0,-31.0);
	glVertex3f(35.0,7.0,-31.0);
	glVertex3f(35.0,11.0,-77.0);
	glVertex3f(35.0,11.0,-77.0);
	glVertex3f(35.0,2.0,-80.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-35.0,7.0,-50.0);
	glVertex3f(-15.0,11.0,-82.0);

	glVertex3f(-30.0,7.0,-31.0);
	glVertex3f(0.0,11.0,-82.0);

	glVertex3f(-20.0,7.0,-31.0);
	glVertex3f(0.0,9.0,-65.0);

	glVertex3f(-10.0,7.0,-31.0);
	glVertex3f(0.0,8.0,-50.0);

	glVertex3f(0.0,8.0,-50.0);
	glVertex3f(10.0,7.0,-31.0);

	glVertex3f(0.0,9.0,-65.0);
	glVertex3f(20.0,7.0,-31.0);

	glVertex3f(0.0,11.0,-82.0);
	glVertex3f(30.0,7.0,-31.0);

	glVertex3f(15.0,11.0,-82.0);
	glVertex3f(35.0,9.0,-50.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-36.0,5.2,-34.0);
	glVertex3f(-36.0,6.0,-44.0);
	glVertex3f(-34.0,6.0,-44.0);
	glVertex3f(-34.0,5.2,-34.0);

	glVertex3f(-33.0,5.2,-34.0);
	glVertex3f(-33.0,6.0,-44.0);
	glVertex3f(-31.0,6.0,-44.0);
	glVertex3f(-31.0,5.2,-34.0);

	glVertex3f(-30.0,5.2,-34.0);
	glVertex3f(-30.0,6.0,-44.0);
	glVertex3f(-28.0,6.0,-44.0);
	glVertex3f(-28.0,5.2,-34.0);

	glVertex3f(-26.0,5.2,-34.0);
	glVertex3f(-26.0,6.0,-44.0);
	glVertex3f(-24.0,6.0,-44.0);
	glVertex3f(-24.0,5.2,-34.0);

	glVertex3f(-23.0,5.2,-34.0);
	glVertex3f(-23.0,6.0,-44.0);
	glVertex3f(-21.0,6.0,-44.0);
	glVertex3f(-21.0,5.2,-34.0);

	glVertex3f(-20.0,5.2,-34.0);
	glVertex3f(-20.0,6.0,-44.0);
	glVertex3f(-18.0,6.0,-44.0);
	glVertex3f(-18.0,5.2,-34.0);

	glVertex3f(-16.0,5.2,-34.0);
	glVertex3f(-16.0,6.0,-44.0);
	glVertex3f(-14.0,6.0,-44.0);
	glVertex3f(-14.0,5.2,-34.0);

	glVertex3f(-13.0,5.2,-34.0);
	glVertex3f(-13.0,6.0,-44.0);
	glVertex3f(-11.0,6.0,-44.0);
	glVertex3f(-11.0,5.2,-34.0);

	glVertex3f(-10.0,5.2,-34.0);
	glVertex3f(-10.0,6.0,-44.0);
	glVertex3f(-8.0,6.0,-44.0);
	glVertex3f(-8.0,5.2,-34.0);

	glVertex3f(-6.0,5.2,-34.0);
	glVertex3f(-6.0,6.0,-44.0);
	glVertex3f(-4.0,6.0,-44.0);
	glVertex3f(-4.0,5.2,-34.0);

	glVertex3f(-3.0,5.2,-34.0);
	glVertex3f(-3.0,6.0,-44.0);
	glVertex3f(-1.0,6.0,-44.0);
	glVertex3f(-1.0,5.2,-34.0);

	glVertex3f(0.0,5.2,-34.0);
	glVertex3f(0.0,6.0,-44.0);
	glVertex3f(2.0,6.0,-44.0);
	glVertex3f(2.0,5.2,-34.0);

	glVertex3f(4.0,5.2,-34.0);
	glVertex3f(4.0,6.0,-44.0);
	glVertex3f(6.0,6.0,-44.0);
	glVertex3f(6.0,5.2,-34.0);

	glVertex3f(7.0,5.2,-34.0);
	glVertex3f(7.0,6.0,-44.0);
	glVertex3f(9.0,6.0,-44.0);
	glVertex3f(9.0,5.2,-34.0);

	glVertex3f(10.0,5.2,-34.0);
	glVertex3f(10.0,6.0,-44.0);
	glVertex3f(12.0,6.0,-44.0);
	glVertex3f(12.0,5.2,-34.0);

	glVertex3f(14.0,5.2,-34.0);
	glVertex3f(14.0,6.0,-44.0);
	glVertex3f(16.0,6.0,-44.0);
	glVertex3f(16.0,5.2,-34.0);

	glVertex3f(17.0,5.2,-34.0);
	glVertex3f(17.0,6.0,-44.0);
	glVertex3f(19.0,6.0,-44.0);
	glVertex3f(19.0,5.2,-34.0);

	glVertex3f(20.0,5.2,-34.0);
	glVertex3f(20.0,6.0,-44.0);
	glVertex3f(22.0,6.0,-44.0);
	glVertex3f(22.0,5.2,-34.0);

	glVertex3f(24.0,5.2,-34.0);
	glVertex3f(24.0,6.0,-44.0);
	glVertex3f(26.0,6.0,-44.0);
	glVertex3f(26.0,5.2,-34.0);

	glVertex3f(27.0,5.2,-34.0);
	glVertex3f(27.0,6.0,-44.0);
	glVertex3f(29.0,6.0,-44.0);
	glVertex3f(29.0,5.2,-34.0);

	glVertex3f(30.0,5.2,-34.0);
	glVertex3f(30.0,6.0,-44.0);
	glVertex3f(32.0,6.0,-44.0);
	glVertex3f(32.0,5.2,-34.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-36.0,6.0,-50.0);
	glVertex3f(-36.0,7.0,-60.0);
	glVertex3f(-34.0,7.0,-60.0);
	glVertex3f(-34.0,6.0,-50.0);

	glVertex3f(-33.0,6.0,-50.0);
	glVertex3f(-33.0,7.0,-60.0);
	glVertex3f(-31.0,7.0,-60.0);
	glVertex3f(-31.0,6.0,-50.0);

	glVertex3f(-30.0,6.0,-50.0);
	glVertex3f(-30.0,7.0,-60.0);
	glVertex3f(-28.0,7.0,-60.0);
	glVertex3f(-28.0,6.0,-50.0);

	glVertex3f(-26.0,6.0,-50.0);
	glVertex3f(-26.0,7.0,-60.0);
	glVertex3f(-24.0,7.0,-60.0);
	glVertex3f(-24.0,6.0,-50.0);

	glVertex3f(-23.0,6.0,-50.0);
	glVertex3f(-23.0,7.0,-60.0);
	glVertex3f(-21.0,7.0,-60.0);
	glVertex3f(-21.0,6.0,-50.0);

	glVertex3f(-20.0,6.0,-50.0);
	glVertex3f(-20.0,7.0,-60.0);
	glVertex3f(-18.0,7.0,-60.0);
	glVertex3f(-18.0,6.0,-50.0);

	glVertex3f(-16.0,6.0,-50.0);
	glVertex3f(-16.0,7.0,-60.0);
	glVertex3f(-14.0,7.0,-60.0);
	glVertex3f(-14.0,6.0,-50.0);

	glVertex3f(-13.0,6.0,-50.0);
	glVertex3f(-13.0,7.0,-60.0);
	glVertex3f(-11.0,7.0,-60.0);
	glVertex3f(-11.0,6.0,-50.0);

	glVertex3f(-10.0,6.0,-50.0);
	glVertex3f(-10.0,7.0,-60.0);
	glVertex3f(-8.0,7.0,-60.0);
	glVertex3f(-8.0,6.0,-50.0);

	glVertex3f(-6.0,6.0,-50.0);
	glVertex3f(-6.0,7.0,-60.0);
	glVertex3f(-4.0,7.0,-60.0);
	glVertex3f(-4.0,6.0,-50.0);

	glVertex3f(-3.0,6.0,-50.0);
	glVertex3f(-3.0,7.0,-60.0);
	glVertex3f(-1.0,7.0,-60.0);
	glVertex3f(-1.0,6.0,-50.0);

	glVertex3f(0.0,6.0,-50.0);
	glVertex3f(0.0,7.0,-60.0);
	glVertex3f(2.0,7.0,-60.0);
	glVertex3f(2.0,6.0,-50.0);

	glVertex3f(4.0,6.0,-50.0);
	glVertex3f(4.0,7.0,-60.0);
	glVertex3f(6.0,7.0,-60.0);
	glVertex3f(6.0,6.0,-50.0);

	glVertex3f(7.0,6.0,-50.0);
	glVertex3f(7.0,7.0,-60.0);
	glVertex3f(9.0,7.0,-60.0);
	glVertex3f(9.0,6.0,-50.0);

	glVertex3f(10.0,6.0,-50.0);
	glVertex3f(10.0,7.0,-60.0);
	glVertex3f(12.0,7.0,-60.0);
	glVertex3f(12.0,6.0,-50.0);

	glVertex3f(14.0,6.0,-50.0);
	glVertex3f(14.0,7.0,-60.0);
	glVertex3f(16.0,7.0,-60.0);
	glVertex3f(16.0,6.0,-50.0);

	glVertex3f(17.0,6.0,-50.0);
	glVertex3f(17.0,7.0,-60.0);
	glVertex3f(19.0,7.0,-60.0);
	glVertex3f(19.0,6.0,-50.0);

	glVertex3f(20.0,6.0,-50.0);
	glVertex3f(20.0,7.0,-60.0);
	glVertex3f(22.0,7.0,-60.0);
	glVertex3f(22.0,6.0,-50.0);

	glVertex3f(24.0,6.0,-50.0);
	glVertex3f(24.0,7.0,-60.0);
	glVertex3f(26.0,7.0,-60.0);
	glVertex3f(26.0,6.0,-50.0);

	glVertex3f(27.0,6.0,-50.0);
	glVertex3f(27.0,7.0,-60.0);
	glVertex3f(29.0,7.0,-60.0);
	glVertex3f(29.0,6.0,-50.0);

	glVertex3f(30.0,6.0,-50.0);
	glVertex3f(30.0,7.0,-60.0);
	glVertex3f(32.0,7.0,-60.0);
	glVertex3f(32.0,6.0,-50.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.0);
	glVertex3f(-32.0,7.0,-65.0);
	glVertex3f(-32.0,8.0,-75.0);
	glVertex3f(-30.0,8.0,-75.0);
	glVertex3f(-30.0,7.0,-65.0);

	glVertex3f(-29.0,7.0,-65.0);
	glVertex3f(-29.0,8.0,-75.0);
	glVertex3f(-27.0,8.0,-75.0);
	glVertex3f(-27.0,7.0,-65.0);

	glVertex3f(-26.0,7.0,-65.0);
	glVertex3f(-26.0,8.0,-75.0);
	glVertex3f(-24.0,8.0,-75.0);
	glVertex3f(-24.0,7.0,-65.0);

	glVertex3f(-22.0,7.0,-65.0);
	glVertex3f(-22.0,8.0,-75.0);
	glVertex3f(-20.0,8.0,-75.0);
	glVertex3f(-20.0,7.0,-65.0);

	glVertex3f(-19.0,7.0,-65.0);
	glVertex3f(-19.0,8.0,-75.0);
	glVertex3f(-17.0,8.0,-75.0);
	glVertex3f(-17.0,7.0,-65.0);

	glVertex3f(-16.0,7.0,-65.0);
	glVertex3f(-16.0,8.0,-75.0);
	glVertex3f(-14.0,8.0,-75.0);
	glVertex3f(-14.0,7.0,-65.0);

	glVertex3f(-12.0,7.0,-65.0);
	glVertex3f(-12.0,8.0,-75.0);
	glVertex3f(-10.0,8.0,-75.0);
	glVertex3f(-10.0,7.0,-65.0);

	glVertex3f(-9.0,7.0,-65.0);
	glVertex3f(-9.0,8.0,-75.0);
	glVertex3f(-7.0,8.0,-75.0);
	glVertex3f(-7.0,7.0,-65.0);

	glVertex3f(-6.0,7.0,-65.0);
	glVertex3f(-6.0,8.0,-75.0);
	glVertex3f(-4.0,8.0,-75.0);
	glVertex3f(-4.0,7.0,-65.0);

	glVertex3f(-2.0,7.0,-65.0);
	glVertex3f(-2.0,8.0,-75.0);
	glVertex3f(0.0,8.0,-75.0);
	glVertex3f(0.0,7.0,-65.0);

	glVertex3f(2.0,7.0,-65.0);
	glVertex3f(2.0,8.0,-75.0);
	glVertex3f(4.0,8.0,-75.0);
	glVertex3f(4.0,7.0,-65.0);

	glVertex3f(6.0,7.0,-65.0);
	glVertex3f(6.0,8.0,-75.0);
	glVertex3f(8.0,8.0,-75.0);
	glVertex3f(8.0,7.0,-65.0);

	glVertex3f(10.0,7.0,-65.0);
	glVertex3f(10.0,8.0,-75.0);
	glVertex3f(12.0,8.0,-75.0);
	glVertex3f(12.0,7.0,-65.0);

	glVertex3f(13.0,7.0,-65.0);
	glVertex3f(13.0,8.0,-75.0);
	glVertex3f(15.0,8.0,-75.0);
	glVertex3f(15.0,7.0,-65.0);

	glVertex3f(16.0,7.0,-65.0);
	glVertex3f(16.0,8.0,-75.0);
	glVertex3f(18.0,8.0,-75.0);
	glVertex3f(18.0,7.0,-65.0);

	glVertex3f(20.0,7.0,-65.0);
	glVertex3f(20.0,8.0,-75.0);
	glVertex3f(22.0,8.0,-75.0);
	glVertex3f(22.0,7.0,-65.0);

	glVertex3f(23.0,7.0,-65.0);
	glVertex3f(23.0,8.0,-75.0);
	glVertex3f(25.0,8.0,-75.0);
	glVertex3f(25.0,7.0,-65.0);

	glVertex3f(26.0,7.0,-65.0);
	glVertex3f(26.0,8.0,-75.0);
	glVertex3f(28.0,8.0,-75.0);
	glVertex3f(28.0,7.0,-65.0);
	glEnd();
}

void lapangan()
{
// Bawah
 glBegin(GL_QUADS);
 glColor3f(0.0, 1.0, 0.0);
 glVertex3f(-25.0,-25.0,25.0);
 glVertex3f(25.0, -25.0,25.0);
 glVertex3f(25.0, -25.0,-20.0);
 glVertex3f(-25.0,-25.0,-20.0);
 //pinggir kiri
  glColor3f(0.5, 0.3,0.3);
 glVertex3f(-35.0,-25.0,35.0);
 glVertex3f(-25.0, -25.0,35.0);
 glVertex3f(-25.0, -25.0,-30.0);
 glVertex3f(-35.0,-25.0,-30.0);

//pinggir kanan
 glVertex3f(35.0,-25.0,35.0);
 glVertex3f(25.0, -25.0,35.0);
 glVertex3f(25.0, -25.0,-30.0);
 glVertex3f(35.0,-25.0,-30.0);

 glVertex3f(35.0,-25.0,35.0);
 glVertex3f(25.0, -25.0,35.0);
 glVertex3f(25.0, -25.0,-30.0);
 glVertex3f(35.0,-25.0,-30.0);
 //pinggir belakang
 glVertex3f(-25.0,-25.0,-20.0);
 glVertex3f(25.0, -25.0,-20.0);
 glVertex3f(25.0, -25.0,-30.0);
 glVertex3f(-25.0,-25.0,-30.0);
//pinggir depan
 glVertex3f(-25.0,-25.0,25.0);
 glVertex3f(25.0, -25.0,25.0);
 glVertex3f(25.0, -25.0,35.0);
 glVertex3f(-25.0,-25.0,35.0);

 glColor3f(0.0, 0.3,1.0);
 glVertex3f(-35.0,-25.0,35.0);
 glVertex3f(-35.0, -20.0,35.0);
 glVertex3f(-35.0, -20.0,-30.0);
 glVertex3f(-35.0,-25.0,-30.0);

 glVertex3f(35.0,-25.0,35.0);
 glVertex3f(35.0, -20.0,35.0);
 glVertex3f(35.0, -20.0,-30.0);
 glVertex3f(35.0,-25.0,-30.0);

 glVertex3f(-35.0,-25.0,-30.0);
 glVertex3f(35.0, -25.0,-30.0);
 glVertex3f(35.0, -20.0,-30.0);
 glVertex3f(-35.0,-20.0,-30.0);

 glVertex3f(-35.0,-25.0,35.0);
 glVertex3f(35.0, -25.0,35.0);
 glVertex3f(35.0, -20.0,35.0);
 glVertex3f(-35.0,-20.0,35.0);
 glEnd();
 glBegin(GL_LINE_LOOP);
 glColor3f(1.0, 1.0, 1.0);

 glVertex3f(-23.0,-25.0,23.0);
 glVertex3f(23.0, -25.0,23.0);
 glVertex3f(23.0, -25.0,-18.0);
 glVertex3f(-23.0,-25.0,-18.0);

 glVertex3f(-23.0,-25.0,11.0);
 glVertex3f(-18.0, -25.0,11.0);
 glVertex3f(-18.0, -25.0,-6.0);
 glVertex3f(-23.0,-25.0,-6.0);

 glVertex3f(-23.0,-25.0,15.0);
 glVertex3f(-14.0, -25.0,15.0);
 glVertex3f(-14.0, -25.0,-10.0);
 glVertex3f(-23.0,-25.0,-10.0);
 glEnd();
 glBegin(GL_LINE_LOOP);
 glVertex3f(23.0,-25.0,11.0);
 glVertex3f(18.0, -25.0,11.0);
 glVertex3f(18.0, -25.0,-6.0);
 glVertex3f(23.0,-25.0,-6.0);

 glVertex3f(23.0,-25.0,15.0);
 glVertex3f(14.0, -25.0,15.0);
 glVertex3f(14.0, -25.0,-10.0);
 glVertex3f(23.0,-25.0,-10.0);
 glEnd();
 glBegin(GL_LINES);
 glVertex3f(0.0,-25.0,23.0);
 glVertex3f(0.0,-25.0,-18.0);

  glVertex3f(0.0,-25.0,-3.0);
  glVertex3f(1.0,-25.0,-3.0);

  glVertex3f(1.0,-25.0,-3.0);
  glVertex3f(2.0,-25.0,-2.0);

  glVertex3f(2.0,-25.0,-2.0);
  glVertex3f(3.0,-25.0,0.0);

  glVertex3f(3.0,-25.0,0.0);
  glVertex3f(3.0,-25.0,2.0);

  glVertex3f(3.0,-25.0,2.0);
  glVertex3f(2.0,-25.0,4.0);

  glVertex3f(2.0,-25.0,4.0);
  glVertex3f(1.0,-25.0,5.0);

  glVertex3f(1.0,-25.0,5.0);
  glVertex3f(0.0,-25.0,5.0);

  //
  glVertex3f(14.0,-25.0,-3.0);
  glVertex3f(13.0,-25.0,-3.0);

  glVertex3f(13.0,-25.0,-3.0);
  glVertex3f(12.0,-25.0,-2.0);

  glVertex3f(12.0,-25.0,-2.0);
  glVertex3f(11.0,-25.0,0.0);

  glVertex3f(11.0,-25.0,0.0);
  glVertex3f(11.0,-25.0,2.0);

  glVertex3f(11.0,-25.0,2.0);
  glVertex3f(12.0,-25.0,4.0);

  glVertex3f(12.0,-25.0,4.0);
  glVertex3f(13.0,-25.0,5.0);

  glVertex3f(13.0,-25.0,5.0);
  glVertex3f(14.0,-25.0,5.0);

  //
  glVertex3f(0.0,-25.0,5.0);
  glVertex3f(-1.0,-25.0,5.0);

  glVertex3f(-1.0,-25.0,5.0);
  glVertex3f(-2.0,-25.0,4.0);

  glVertex3f(-2.0,-25.0,4.0);
  glVertex3f(-3.0,-25.0,2.0);

  glVertex3f(-3.0,-25.0,2.0);
  glVertex3f(-3.0,-25.0,0.0);

  glVertex3f(-3.0,-25.0,0.0);
  glVertex3f(-2.0,-25.0,-2.0);

  glVertex3f(-2.0,-25.0,-2.0);
  glVertex3f(-1.0,-25.0,-3.0);

  glVertex3f(-1.0,-25.0,-3.0);
  glVertex3f(0.0,-25.0,-3.0);

  glVertex3f(-14.0,-25.0,-3.0);
  glVertex3f(-13.0,-25.0,-3.0);

  glVertex3f(-13.0,-25.0,-3.0);
  glVertex3f(-12.0,-25.0,-2.0);

  glVertex3f(-12.0,-25.0,-2.0);
  glVertex3f(-11.0,-25.0,0.0);

  glVertex3f(-11.0,-25.0,0.0);
  glVertex3f(-11.0,-25.0,2.0);

  glVertex3f(-11.0,-25.0,2.0);
  glVertex3f(-12.0,-25.0,4.0);

  glVertex3f(-12.0,-25.0,4.0);
  glVertex3f(-13.0,-25.0,5.0);

  glVertex3f(-13.0,-25.0,5.0);
  glVertex3f(-14.0,-25.0,5.0);

 glEnd();


 //tiang1 dan 2
 glBegin(GL_QUADS);
 glColor3f(1.0,1.0, 1.0);
 glVertex3f(-23.0,-25.0,11.0);
 glVertex3f(-23.0, -16.0, 11.0);
 glVertex3f(-22.0, -16.0, 11.0);
 glVertex3f(-22.0,-25.0,11.0);

 glVertex3f(-23.0,-25.0,10.0);
 glVertex3f(-23.0, -16.0,10.0);
 glVertex3f(-22.0, -16.0,10.0);
 glVertex3f(-22.0,-25.0,10.0);

 glVertex3f(-22.0, -16.0, 11.0);
 glVertex3f(-22.0,-25.0,11.0);
 glVertex3f(-22.0,-25.0,10.0);
 glVertex3f(-22.0, -16.0,10.0);

 glVertex3f(-23.0,-25.0,11.0);
 glVertex3f(-23.0,-16.0, 11.0);
 glVertex3f(-23.0,-16.0,10.0);
 glVertex3f(-23.0,-25.0,10.0);

 glVertex3f(-23.0,-25.0,-6.0);
 glVertex3f(-23.0, -16.0,-6.0);
 glVertex3f(-22.0, -16.0,-6.0);
 glVertex3f(-22.0,-25.0,-6.0);

 glVertex3f(-23.0,-25.0,-5.0);
 glVertex3f(-23.0, -16.0,-5.0);
 glVertex3f(-22.0, -16.0,-5.0);
 glVertex3f(-22.0,-25.0,-5.0);

 glVertex3f(-22.0, -16.0, -6.0);
 glVertex3f(-22.0,-25.0,-6.0);
 glVertex3f(-22.0,-25.0,-5.0);
 glVertex3f(-22.0, -16.0,-5.0);

 glVertex3f(-23.0,-25.0,-6.0);
 glVertex3f(-23.0,-16.0, -6.0);
 glVertex3f(-23.0,-16.0,-5.0);
 glVertex3f(-23.0,-25.0,-5.0);

 //ti ki
  glColor3f(1.0,0.0, 0.0);
  glVertex3f(-32.0,-25.0,12.0);
 glVertex3f(-32.0, -16.0, 12.0);
 glVertex3f(-31.5, -16.0, 12.0);
 glVertex3f(-31.5,-25.0,12.0);
 glVertex3f(-32.0,-25.0,11.5);
 glVertex3f(-32.0, -16.0,11.5);
 glVertex3f(-31.5, -16.0,11.5);
 glVertex3f(-31.5,-25.0,11.5);
 glVertex3f(-31.5, -16.0, 12.0);
 glVertex3f(-31.5,-25.0,12.0);
 glVertex3f(-31.5,-25.0,11.5);
 glVertex3f(-31.5, -16.0,11.5);
 glVertex3f(-32.0,-25.0,12.0);
 glVertex3f(-32.0,-16.0, 12.0);
 glVertex3f(-32.0,-16.0,11.5);
 glVertex3f(-32.0,-25.0,11.5);
 glVertex3f(-32.0,-25.0,-7.0);
 glVertex3f(-32.0, -16.0,-7.0);
 glVertex3f(-31.5, -16.0,-7.0);
 glVertex3f(-31.5,-25.0,-7.0);
 glVertex3f(-32.0,-25.0,-6.5);
 glVertex3f(-32.0, -16.0,-6.5);
 glVertex3f(-31.5, -16.0,-6.5);
 glVertex3f(-31.5,-25.0,-6.5);
 glVertex3f(-31.5, -16.0, -7.0);
 glVertex3f(-31.5,-25.0,-7.0);
 glVertex3f(-31.5,-25.0,-6.5);
 glVertex3f(-31.5, -16.0,-6.5);
 glVertex3f(-32.0,-25.0,-7.0);
 glVertex3f(-32.0,-16.0, -7.0);
 glVertex3f(-32.0,-16.0,-6.5);
 glVertex3f(-32.0,-25.0,-6.5);

  //ti ka
  glColor3f(1.0,0.0, 0.0);
  glVertex3f(32.0,-25.0,12.0);
 glVertex3f(32.0, -16.0, 12.0);
 glVertex3f(31.5, -16.0, 12.0);
 glVertex3f(31.5,-25.0,12.0);
 glVertex3f(32.0,-25.0,11.5);
 glVertex3f(32.0, -16.0,11.5);
 glVertex3f(31.5, -16.0,11.5);
 glVertex3f(31.5,-25.0,11.5);
 glVertex3f(31.5, -16.0, 12.0);
 glVertex3f(31.5,-25.0,12.0);
 glVertex3f(31.5,-25.0,11.5);
 glVertex3f(31.5, -16.0,11.5);
 glVertex3f(32.0,-25.0,12.0);
 glVertex3f(32.0,-16.0, 12.0);
 glVertex3f(32.0,-16.0,11.5);
 glVertex3f(32.0,-25.0,11.5);
 glVertex3f(32.0,-25.0,-7.0);
 glVertex3f(32.0, -16.0,-7.0);
 glVertex3f(31.5, -16.0,-7.0);
 glVertex3f(31.5,-25.0,-7.0);
 glVertex3f(32.0,-25.0,-6.5);
 glVertex3f(32.0, -16.0,-6.5);
 glVertex3f(31.5, -16.0,-6.5);
 glVertex3f(31.5,-25.0,-6.5);
 glVertex3f(31.5, -16.0, -7.0);
 glVertex3f(31.5,-25.0,-7.0);
 glVertex3f(31.5,-25.0,-6.5);
 glVertex3f(31.5, -16.0,-6.5);
 glVertex3f(32.0,-25.0,-7.0);
 glVertex3f(32.0,-16.0, -7.0);
 glVertex3f(32.0,-16.0,-6.5);
 glVertex3f(32.0,-25.0,-6.5);
 glEnd();
 //tiang 3 dan 4
 glBegin(GL_QUADS);
 glColor3f(1.0,1.0, 1.0);
 glVertex3f(23.0,-25.0,-6.0);
 glVertex3f(23.0, -16.0,-6.0);
 glVertex3f(22.0, -16.0,-6.0);
 glVertex3f(22.0,-25.0,-6.0);
 glVertex3f(23.0,-25.0,-5.0);
 glVertex3f(23.0, -16.0,-5.0);
 glVertex3f(22.0, -16.0,-5.0);
 glVertex3f(22.0,-25.0,-5.0);
 glVertex3f(22.0, -16.0, -6.0);
 glVertex3f(22.0,-25.0,-6.0);
 glVertex3f(22.0,-25.0,-5.0);
 glVertex3f(22.0, -16.0,-5.0);
 glVertex3f(23.0,-25.0,-6.0);
 glVertex3f(23.0,-16.0, -6.0);
 glVertex3f(23.0,-16.0,-5.0);
 glVertex3f(23.0,-25.0,-5.0);
 glVertex3f(23.0,-25.0,11.0);
 glVertex3f(23.0, -16.0, 11.0);
 glVertex3f(22.0, -16.0, 11.0);
 glVertex3f(22.0,-25.0,11.0);
 glVertex3f(23.0,-25.0,10.0);
 glVertex3f(23.0, -16.0,10.0);
 glVertex3f(22.0, -16.0,10.0);
 glVertex3f(22.0,-25.0,10.0);
 glVertex3f(22.0, -16.0, 11.0);
 glVertex3f(22.0,-25.0,11.0);
 glVertex3f(22.0,-25.0,10.0);
 glVertex3f(22.0, -16.0,10.0);
 glVertex3f(23.0,-25.0,11.0);
 glVertex3f(23.0,-16.0, 11.0);
 glVertex3f(23.0,-16.0,10.0);
 glVertex3f(23.0,-25.0,10.0);
 glEnd();
 // tiang atas
 glBegin(GL_QUADS);
 glVertex3f(-22.0,-17.0,10.0);
 glVertex3f(-22.0,-16.0, 10.0);
 glVertex3f(-22.0, -16.0,-6.0);
 glVertex3f(-22.0, -17.0,-6.0);
 glVertex3f(-23.0,-17.0,10.0);
 glVertex3f(-23.0,-16.0, 10.0);
 glVertex3f(-23.0, -16.0,-6.0);
 glVertex3f(-23.0, -17.0,-6.0);
 glVertex3f(-22.0,-17.0,10.0);
 glVertex3f(-23.0,-17.0, 10.0);
 glVertex3f(-23.0, -17.0, -6.0);
 glVertex3f(-22.0, -17.0, -6.0);
 glVertex3f(-22.0,-16.0,10.0);
 glVertex3f(-23.0,-16.0, 10.0);
 glVertex3f(-23.0, -16.0, -6.0);
 glVertex3f(-22.0, -16.0, -6.0);

 glVertex3f(22.0,-17.0,10.0);
 glVertex3f(22.0,-16.0, 10.0);
 glVertex3f(22.0, -16.0,-6.0);
 glVertex3f(22.0, -17.0,-6.0);

 glVertex3f(23.0,-17.0,10.0);
 glVertex3f(23.0,-16.0, 10.0);
 glVertex3f(23.0, -16.0,-6.0);
 glVertex3f(23.0, -17.0,-6.0);

 glVertex3f(22.0,-17.0,10.0);
 glVertex3f(23.0,-17.0, 10.0);
 glVertex3f(23.0, -17.0, -6.0);
 glVertex3f(22.0, -17.0, -6.0);

 glVertex3f(22.0,-16.0,10.0);
 glVertex3f(23.0,-16.0, 10.0);
 glVertex3f(23.0, -16.0, -6.0);
 glVertex3f(22.0, -16.0, -6.0);
 glEnd();
 //jaring kanan
 glLineWidth(2.0);
 glBegin(GL_LINES);
 glVertex3f(23.0,-16.5,11.0);
 glVertex3f(27.0,-18.0,11.0);
 glVertex3f(27.0,-18.0,11.0);
 glVertex3f(27.0,-25.0,11.0);
 glVertex3f(23.0,-16.5,8.0);
 glVertex3f(27.0,-18.0,8.0);
 glVertex3f(27.0,-18.0,8.0);
 glVertex3f(27.0,-25.0,8.0);
 glVertex3f(23.0,-16.5,5.0);
 glVertex3f(27.0,-18.0,5.0);
 glVertex3f(27.0,-18.0,5.0);
 glVertex3f(27.0,-25.0,5.0);
 glVertex3f(23.0,-16.5,2.0);
 glVertex3f(27.0,-18.0,2.0);
 glVertex3f(27.0,-18.0,2.0);
 glVertex3f(27.0,-25.0,2.0);
 glVertex3f(23.0,-16.5,-1.0);
 glVertex3f(27.0,-18.0,-1.0);
 glVertex3f(27.0,-18.0,-1.0);
 glVertex3f(27.0,-25.0,-1.0);
 glVertex3f(23.0,-16.5,-4.0);
 glVertex3f(27.0,-18.0,-4.0);
 glVertex3f(27.0,-18.0,-4.0);
 glVertex3f(27.0,-25.0,-4.0);
 glVertex3f(23.0,-16.5,-6.0);
 glVertex3f(27.0,-18.0,-6.0);
 glVertex3f(27.0,-18.0,-6.0);
 glVertex3f(27.0,-25.0,-6.0);
 glVertex3f(27.0,-18.0,-6.0);
 glVertex3f(31.5,-17.0,-7.0);
 glVertex3f(27.0,-18.0,11.0);
 glVertex3f(31.5,-17.0,12.0);
 glVertex3f(-27.0,-18.0,-6.0);
 glVertex3f(-31.5,-17.0,-7.0);
 glVertex3f(-27.0,-18.0,11.0);
 glVertex3f(-31.5,-17.0,12.0);
 glVertex3f(23.0,-25,11.0);
 glVertex3f(27.0,-25.,11.0);
 glVertex3f(27.0,-25.0,11.0);
 glVertex3f(27.0,-25.0,-6.0);
 glVertex3f(27.0,-25.0,-6.0);
 glVertex3f(23.0,-25.0,-6.0);

 glVertex3f(23.0,-22,11.0);
 glVertex3f(27.0,-22.,11.0);
 glVertex3f(27.0,-22.0,11.0);
 glVertex3f(27.0,-22.0,-6.0);
 glVertex3f(27.0,-22.0,-6.0);
 glVertex3f(23.0,-22.0,-6.0);

 glVertex3f(23.0,-19,11.0);
 glVertex3f(27.0,-19.,11.0);
 glVertex3f(27.0,-19.0,11.0);
 glVertex3f(27.0,-19.0,-6.0);
 glVertex3f(27.0,-19.0,-6.0);
 glVertex3f(23.0,-19.0,-6.0);

 glVertex3f(25.0,-17.0,11.0);
 glVertex3f(25.0,-25.0,11.0);
 glVertex3f(25.0,-17.0,11.0);
 glVertex3f(25.0,-17.0,-6.0);
 glVertex3f(25.0,-17.0,-6.0);
 glVertex3f(25.0,-25.0,-6.0);
 glEnd();
  //jaring kiri
 glLineWidth(2.0);
 glBegin(GL_LINES);
 glVertex3f(-23.0,-16.5,11.0);
 glVertex3f(-27.0,-18.0,11.0);
 glVertex3f(-27.0,-18.0,11.0);
 glVertex3f(-27.0,-25.0,11.0);
 glVertex3f(-23.0,-16.5,8.0);
 glVertex3f(-27.0,-18.0,8.0);
 glVertex3f(-27.0,-18.0,8.0);
 glVertex3f(-27.0,-25.0,8.0);
 glVertex3f(-23.0,-16.5,5.0);
 glVertex3f(-27.0,-18.0,5.0);
 glVertex3f(-27.0,-18.0,5.0);
 glVertex3f(-27.0,-25.0,5.0);
 glVertex3f(-23.0,-16.5,2.0);
 glVertex3f(-27.0,-18.0,2.0);
 glVertex3f(-27.0,-18.0,2.0);
 glVertex3f(-27.0,-25.0,2.0);
 glVertex3f(-23.0,-16.5,-1.0);
 glVertex3f(-27.0,-18.0,-1.0);
 glVertex3f(-27.0,-18.0,-1.0);
 glVertex3f(-27.0,-25.0,-1.0);
 glVertex3f(-23.0,-16.5,-4.0);
 glVertex3f(-27.0,-18.0,-4.0);
 glVertex3f(-27.0,-18.0,-4.0);
 glVertex3f(-27.0,-25.0,-4.0);
 glVertex3f(-23.0,-16.5,-6.0);
 glVertex3f(-27.0,-18.0,-6.0);
 glVertex3f(-27.0,-18.0,-6.0);
 glVertex3f(-27.0,-25.0,-6.0);


 glVertex3f(-23.0,-25,11.0);
 glVertex3f(-27.0,-25.,11.0);
 glVertex3f(-27.0,-25.0,11.0);
 glVertex3f(-27.0,-25.0,-6.0);
 glVertex3f(-27.0,-25.0,-6.0);
 glVertex3f(-23.0,-25.0,-6.0);

 glVertex3f(-23.0,-22,11.0);
 glVertex3f(-27.0,-22.,11.0);
 glVertex3f(-27.0,-22.0,11.0);
 glVertex3f(-27.0,-22.0,-6.0);
 glVertex3f(-27.0,-22.0,-6.0);
 glVertex3f(-23.0,-22.0,-6.0);

 glVertex3f(-23.0,-19,11.0);
 glVertex3f(-27.0,-19.,11.0);
 glVertex3f(-27.0,-19.0,11.0);
 glVertex3f(-27.0,-19.0,-6.0);
 glVertex3f(-27.0,-19.0,-6.0);
 glVertex3f(-23.0,-19.0,-6.0);

 glVertex3f(-25.0,-17.0,11.0);
 glVertex3f(-25.0,-25.0,11.0);
 glVertex3f(-25.0,-17.0,11.0);
 glVertex3f(-25.0,-17.0,-6.0);
 glVertex3f(-25.0,-17.0,-6.0);
 glVertex3f(-25.0,-25.0,-6.0);
 glEnd();


}

void reshape(int w, int h)
{
	if (h == 0) h =1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, w / h, 5.0, 500.0);
	glTranslatef(0.0,-5.0,-150.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      	case 27:
         	exit(0);
         	break;
		case 'w':
		case 'W':
             //zoom out
			glTranslatef(0.0,0.0,1.0);
			break;
		case 'd':
		case 'D':
             //move kanan
			glTranslatef(1.0,0.0,0.0);
			break;
		case 's':
		case 'S':
             //zoom in
			glTranslatef(0.0,0.0,-1.0);
			break;
		case 'a':
		case 'A':
             //move kiri
			glTranslatef(-1.0,0.0,0.0);
			break;
		case '1':
             //putar bawah
			glRotatef(5.0,1.0,0.0,0.0);
			break;
		case '2':
             //putar atas
			glRotatef(5.0,-1.0,0.0,0.0);
			break;
		case '3':
             //putar kanan
			glRotatef(5.0,0.0,1.0,0.0);
			break;
		case '4':
             //putar kiri
			glRotatef(5.0,0.0,-1.0,0.0);
			break;
		case '6':
             //putar kiri season 2
			glRotatef(5.0,0.0,0.0,1.0);
			break;
		case '7':
             //putar kanan season 2
			glRotatef(5.0,0.0,0.0,-1.0);
			break;
		case '8':
             //perkecil
             glScalef(0.5,0.5,0.5);
             break;
        case '9':
             //perbesar
             glScalef(1.5,1.5,1.5);
             break;
   }
   display();
}

void mouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}
void mouseMotion(int x, int y){
	if(mouseDown){
		yrot = x - xdiff;
		xrot = y + ydiff;
		glutPostRedisplay();
	}
	glLoadIdentity();
	gluLookAt(0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	glRotatef(xrot,1.0f,0.0f,0.0f);
	glRotatef(yrot,0.0f,1.0f,0.0f);
}
