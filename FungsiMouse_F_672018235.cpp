#include <GL/glut.h>
#include<windows.h>
#include <GL/freeglut.h>
#include <stdlib.h>


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
//void idle();
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
bool mouseDown = false;
int is_depth;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;

float xpos = 0.0f;
float ypos = 0.0f;
float zpos = 0.0f;


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("Tarsisius Eko Prasetyo - 672018235");
	init();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutDisplayFunc(tampil);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);
	glutMainLoop();
	return 0;
}

void init(void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glEnable(GL_DEPTH_TEST);
//pencahayaan
glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
//set cahaya
GLfloat qaAmbientLight[] = { 0.2,0.2,0.2,1.0 };
GLfloat qaDiffuseLight[] = { 1,1,1,1 };
GLfloat qaSpecularLight[] = { 1,1,1,1 };
glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
//posisi cahaya
GLfloat posisilampu[] = { 0,160,200,1 };
glLightfv(GL_LIGHT0, GL_POSITION, posisilampu);
glEnable(GL_COLOR_MATERIAL);
glShadeModel(GL_SMOOTH);
glMatrixMode(GL_MODELVIEW);
glOrtho(-30, 30, -30, 30, -30, 30);
glPointSize(2.0);
glLineWidth(2.0);
}

void rumah(void){
//Rumah
	//bagian depan
    glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,0.5);
	glVertex3f(-30.0,-10.0, 10.0);
	glVertex3f(-30.0, 20.0, 10.0);
	glVertex3f(10.0, 35.0, 10.0);
	glVertex3f(50.0, 20.0, 10.0);
    glVertex3f(50.0,-10.0, 10.0);
	glEnd();
	//bagian belakang
	glColor3f(1.0,1.0,0.5);
    glBegin(GL_POLYGON);
	glVertex3f(-30.0,-10.0, -50.0);
	glVertex3f(-30.0, 20.0, -50.0);
	glVertex3f(10.0, 35.0, -50.0);
	glVertex3f(50.0, 20.0, -50.0);
    glVertex3f(50.0,-10.0, -50.0);
	glEnd();
	//pagar samping kanan
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,0.5);
    glVertex3f(50.0,-10.0,-50.0);
	glVertex3f(50.0, 20.0,-50.0);
	glVertex3f(50.0, 20.0, 10.0);
    glVertex3f(50.0,-10.0,10.0);
    //pagar samping kiri
    glVertex3f(-30.0,-10.0,-50.0);
	glVertex3f(-30.0, 20.0,-50.0);
	glVertex3f(-30.0, 20.0, 10.0);
    glVertex3f(-30.0,-10.0,10.0);
    //bawah
    glColor3f(0.0,0.0,0.0);
    //atap kiri
	glVertex3f(-33, 19,13.0);
	glVertex3f(10, 35.0,13.0);
	glVertex3f(10, 35.0,-53.0);
	glVertex3f(-33, 19,-53.0);
    //atap kanan
	glVertex3f(53, 19,13.0);
	glVertex3f(10, 35.0,13.0);
	glVertex3f(10, 35.0,-53.0);
	glVertex3f(53, 19,-53.0);
	//atas
	glColor3f(0.5,0.4,0.1);
	 //atap kiri
	glVertex3f(-33, 20.3,13.0);
	glVertex3f(10, 36.0,13.0);
	glVertex3f(10, 36.0,-53.0);
	glVertex3f(-33, 20.3,-53.0);
	//tutup kiri depan
	glVertex3f(10.0,35, 13.0);
	glVertex3f(10.0, 36.0, 13.0);
	glVertex3f(-33.0, 20.3, 13.0);
    glVertex3f(-33.0,19, 13.0);
    //tutup samping kiri
	glVertex3f(-33.0, 19, 13.0);
	glVertex3f(-33.0, 20.3, 13.0);
	glVertex3f(-33.0, 20.3, -53.0);
    glVertex3f(-33.0,19, -53.0);
    //tutup kiri belakang
	glVertex3f(10.0,35, -53.0);
	glVertex3f(10.0, 36.0, -53.0);
	glVertex3f(-33.0, 20.3, -53.0);
    glVertex3f(-33.0,19, -53.0);

    //atap kanan
	glVertex3f(53, 20.3,13.0);
	glVertex3f(10, 36.0,13.0);
	glVertex3f(10, 36.0,-53.0);
	glVertex3f(53, 20.3,-53.0);
	//tutup kanan depan
	glVertex3f(10.0,35, 13.0);
	glVertex3f(10.0, 36.0, 13.0);
	glVertex3f(53.0, 20.3, 13.0);
    glVertex3f(53.0,19, 13.0);
    //tutup samping kanan
	glVertex3f(53.0, 19, 13.0);
	glVertex3f(53.0, 20.3, 13.0);
	glVertex3f(53.0, 20.3, -53.0);
    glVertex3f(53.0, 19, -53.0);
    //tutup kanan belakang
	glVertex3f(10.0,35, -53.0);
	glVertex3f(10.0, 36.0, -53.0);
	glVertex3f(53.0, 20.3, -53.0);
    glVertex3f(53.0,19, -53.0);

    glEnd();

}

void tiang(void){
//tiang kiri
	//samping kiri
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,0.5);
	glVertex3f(-30.0, 0.0, 30.0);
	glVertex3f(-30.0, 15.65, 30.0);
	glVertex3f(-30.0, 16.05, 28.0);
    glVertex3f(-30.0, 0.0,28.0);
    //samping kanan
    glVertex3f(-28.0, 0.0, 30.0);
	glVertex3f(-28.0, 15.65, 30.0);
	glVertex3f(-28.0, 16.05, 28.0);
    glVertex3f(-28.0, 0.0,28.0);
    //depan
    glVertex3f(-28, 15.65, 30.0);
	glVertex3f(-30, 15.65,30.0);
	glVertex3f(-30, 0.0,30.0);
	glVertex3f(-28, 0.0,30.0);
	//belakang
    glVertex3f(-28, 16.05, 28.0);
	glVertex3f(-30, 16.05, 28.0);
	glVertex3f(-30, 0.0, 28.0);
	glVertex3f(-28, 0.0, 28.0);

	//tiang kanan 1
    //samping kiri
	glVertex3f(1.0, 0.0, 30.0);
	glVertex3f(1.0, 15.65, 30.0);
	glVertex3f(1.0, 15.65, 28.0);
    glVertex3f(1.0, 0.0,28.0);
    //samping kanan
    glVertex3f(3.0, 0.0, 30.0);
	glVertex3f(3.0, 15.65, 30.0);
	glVertex3f(3.0, 15.65, 28.0);
    glVertex3f(3.0, 0.0,28.0);
    //depan
    glVertex3f(3, 15.65, 30.0);
	glVertex3f(1, 15.65,30.0);
	glVertex3f(1, 0.0,30.0);
	glVertex3f(3, 0.0,30.0);
	//belakang
    glVertex3f(3, 15.65, 28.0);
	glVertex3f(1, 15.65, 28.0);
	glVertex3f(1, 0.0, 28.0);
	glVertex3f(3, 0.0, 28.0);


	//tiang kanan 2
    //samping kiri
	glVertex3f(30.0, 0.0, 30.0);
	glVertex3f(30.0, 15.65, 30.0);
	glVertex3f(30.0, 15.65, 28.0);
    glVertex3f(30.0, 0.0, 28.0);
    //samping kanan
    glVertex3f(28.0, 0.0, 30.0);
	glVertex3f(28.0, 15.65, 30.0);
	glVertex3f(28.0, 15.65, 28.0);
    glVertex3f(28.0, 0.0,28.0);
    //depan
    glVertex3f(30, 15.65, 30.0);
	glVertex3f(28, 15.65,30.0);
	glVertex3f(28, 0.0,30.0);
	glVertex3f(30, 0.0,30.0);
	//belakang
    glVertex3f(30, 15.65, 28.0);
	glVertex3f(28, 15.65, 28.0);
	glVertex3f(28, 0.0, 28.0);
	glVertex3f(30, 0.0, 28.0);

    // kayu penyangga depan
    glColor3f(0.5,0.4,0.1);
	glVertex3f(-32, 14.9, 29.5);
	glVertex3f(32, 14.9, 29.5);
	glVertex3f(32, 14.9, 28.5);
	glVertex3f(-32, 14.9 ,28.5);
	glVertex3f(-32, 15.75, 29.5);//bagian atas
	glVertex3f(32, 15.75, 29.5);
	glVertex3f(32, 15.75, 28.5);
	glVertex3f(-32, 15.75 ,28.5);
	glVertex3f(-32, 14.9, 29.5);//bagian samping depan
	glVertex3f(32, 14.9, 29.5);
	glVertex3f(32, 15.75, 29.5);
	glVertex3f(-32, 15.75 ,29.5);
	glVertex3f(-32, 14.9, 28.5);//bagian samping belakang
	glVertex3f(32, 14.9, 28.5);
	glVertex3f(32, 15.75, 28.5);
	glVertex3f(-32, 15.75 ,28.5);
	glVertex3f(32, 14.9, 29.5);//tutup kanan
	glVertex3f(32, 15.75, 29.5);
	glVertex3f(32, 15.75, 28.5);
	glVertex3f(32, 14.9 ,28.5);
    glVertex3f(-32, 14.9, 29.5);//tutup kiri
	glVertex3f(-32, 15.75, 29.5);
	glVertex3f(-32, 15.75, 28.5);
	glVertex3f(-32, 14.9 ,28.5);
//*/
	// kayu penyangga belakang
    glColor3f(0.5,0.4,0.1);
    glVertex3f(-32, 18.9, 11);
	glVertex3f(32, 18.9, 11);
	glVertex3f(32, 18.9, 10);
	glVertex3f(-32, 18.9 ,10);
	glVertex3f(-32, 19.4, 11);//bagian atas
	glVertex3f(32, 19.4, 11);
	glVertex3f(32, 19.4, 10);
	glVertex3f(-32, 19.4 ,10);
	glVertex3f(-32, 18.9, 11);//bagian samping depan
	glVertex3f(32, 18.9, 11);
	glVertex3f(32, 19.4, 11);
	glVertex3f(-32, 19.4 ,11);
	glVertex3f(-32, 18.9, 10);//bagian samping belakang
	glVertex3f(32, 18.9, 10);
	glVertex3f(32, 19.4, 10);
	glVertex3f(-32, 19.4 ,10);

    glVertex3f(32, 18.9, 11);//tutup kanan
	glVertex3f(32, 19.4, 11);
	glVertex3f(32, 19.4, 10);
	glVertex3f(32, 18.9 ,10);
    glVertex3f(-32, 18.9, 11);//tutup kiri
	glVertex3f(-32, 19.4, 11);
	glVertex3f(-32, 19.4, 10);
	glVertex3f(-32, 18.9 ,10);

	// kayu penyangga lurus
    glColor3f(0.5,0.4,0.1);
	glVertex3f(28.5, 15.43, 31.0);
	glVertex3f(29.5, 15.43, 31.0);
	glVertex3f(29.5, 19.9, 10.0);
	glVertex3f(28.5, 19.9 ,10.0);
	glVertex3f(28.5, 14.93, 31.0);//bawah
	glVertex3f(29.5, 14.93, 31.0);
	glVertex3f(29.5, 19.4, 10.0);
	glVertex3f(28.5, 19.4 ,10.0);
	glVertex3f(28.5, 14.93, 31.0);//samping
	glVertex3f(28.5, 15.43, 31.0);
	glVertex3f(28.5, 19.9, 10.0);
	glVertex3f(28.5, 19.4 ,10.0);
    glVertex3f(29.5, 14.93, 31.0);//samping2
	glVertex3f(29.5, 15.43, 31.0);
	glVertex3f(29.5, 19.9, 10.0);
	glVertex3f(29.5, 19.4 ,10.0);

	// kayu penyangga lurus 2
	glVertex3f(1.5, 15.43, 31.0);
	glVertex3f(2.5, 15.43, 31.0);
	glVertex3f(2.5, 19.9, 10.0);
	glVertex3f(1.5, 19.9 ,10.0);
	glVertex3f(1.5, 14.93, 31.0);//bawah
	glVertex3f(2.5, 14.93, 31.0);
	glVertex3f(2.5, 19.4, 10.0);
	glVertex3f(1.5, 19.4 ,10.0);
	glVertex3f(1.5, 14.93, 31.0);//samping
	glVertex3f(1.5, 15.43, 31.0);
	glVertex3f(1.5, 19.9, 10.0);
	glVertex3f(1.5, 19.4 ,10.0);
    glVertex3f(2.5, 14.93, 31.0);//samping2
	glVertex3f(2.5, 15.43, 31.0);
	glVertex3f(2.5, 19.9, 10.0);
	glVertex3f(2.5, 19.4 ,10.0);

	// kayu penyangga lurus 3
    glVertex3f(-28.5, 15.43, 31.0);
	glVertex3f(-29.5, 15.43, 31.0);
	glVertex3f(-29.5, 19.9, 10.0);
	glVertex3f(-28.5, 19.9 ,10.0);
	glVertex3f(-28.5, 14.93, 31.0);//bawah
	glVertex3f(-29.5, 14.93, 31.0);
	glVertex3f(-29.5, 19.4, 10.0);
	glVertex3f(-28.5, 19.4 ,10.0);
	glVertex3f(-28.5, 14.93, 31.0);//samping
	glVertex3f(-28.5, 15.43, 31.0);
	glVertex3f(-28.5, 19.9, 10.0);
	glVertex3f(-28.5, 19.4 ,10.0);
    glVertex3f(-29.5, 14.93, 31.0);//samping2
	glVertex3f(-29.5, 15.43, 31.0);
	glVertex3f(-29.5, 19.9, 10.0);
	glVertex3f(-29.5, 19.4 ,10.0);

    //atap kanopi
    glColor3f(0.1,1.0,0.8);
	glVertex3f(-33, 15, 33.0);
	glVertex3f(33, 15.0, 33.0);
	glVertex3f(33, 20.0, 10.0);
	glVertex3f(-33, 20 ,10.0);
	//talang air
	//belakang
	glColor3f(0.2,0.7,0.6);
	glVertex3f(-33, 13, 32.5);
	glVertex3f(33, 13.0, 32.5);
	glVertex3f(33, 15.04, 32.6);
	glVertex3f(-33, 15.04 ,32.6);
	glVertex3f(-33, 13, 32.5);
	glVertex3f(33, 13.0, 32.5);
	glVertex3f(33, 15.04, 32.6);
	glVertex3f(-33, 15.04 ,32.6);
	//depan
	glVertex3f(-33, 13, 33.5);
	glVertex3f(33, 13.0, 33.5);
	glVertex3f(33, 15.04, 33.6);
	glVertex3f(-33, 15.04 ,33.6);
	//bawah
	glVertex3f(-33, 13, 32.5);
	glVertex3f(33, 13.0, 32.5);
	glVertex3f(33, 13.0, 33.5);
	glVertex3f(-33, 13.0 ,33.5);
	//tutup kiri
	glVertex3f(-33.0, 13.0, 32.5);
	glVertex3f(-33.0, 15.05, 32.6);
	glVertex3f(-33.0, 15, 33.6);
    glVertex3f(-33.0, 13.0, 33.5);
//*/
    glEnd();
}

void pagar(void){
   //kanan
	//pagar depan
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,0.5);
	glVertex3f(-10.0,-10.0,30.0);
	glVertex3f(-10.0, -2.0, 30.0);
	glVertex3f(30.0, -2.0, 30.0);
    glVertex3f(30.0,-10.0,30.0);
    //belakang
    glVertex3f(-10.0,-10.0,28.0);
	glVertex3f(-10.0, -2.0, 28.0);
	glVertex3f(28.0, -2.0, 28.0);
    glVertex3f(28.0,-10.0,28.0);
    //pagar samping depan
    glVertex3f(30.0,-10.0,30.0);
	glVertex3f(30.0, -2.0,30.0);
	glVertex3f(30.0, -2.0, 10.0);
    glVertex3f(30.0,-10.0,10.0);
    //belakang
    glVertex3f(28.0,-10.0,28.0);
	glVertex3f(28.0, -2.0,28.0);
	glVertex3f(28.0, -2.0, 10.0);
    glVertex3f(28.0,-10.0,10.0);
    //tutup
    glVertex3f(-10, -10.0, 30.0);
	glVertex3f(-10,-2.0,30.0);
	glVertex3f(-10,-2.0,28.0);
	glVertex3f(-10,-10.0,28.0);
    //atas a
    glColor3f(0.2,0.7,0.6);
    glVertex3f(-10, 0.0, 32.0);
	glVertex3f(32,0.0,32.0);
	glVertex3f(32,0.0,26.0);
	glVertex3f(-10,0.0,26.0);
	//atas a
	glVertex3f(26, 0.0, 10.0);
	glVertex3f(32,0.0,10.0);
	glVertex3f(32,0.0,28.0);
	glVertex3f(26,0.0,28.0);
	//atas b
	glColor3f(0.2,0.7,0.6);
    glVertex3f(-10, -2.0, 32.0);
	glVertex3f(32,-2.0,32.0);
	glVertex3f(32,-2.0,26.0);
	glVertex3f(-10,-2.0,26.0);
    //atas b
    glVertex3f(26, -2.0, 10.0);
	glVertex3f(32,-2.0,10.0);
	glVertex3f(32,-2.0,28.0);
	glVertex3f(26,-2.0,28.0);
	//tutup depan
    glColor3f(1.0,1.0,0.5);
    glVertex3f(-10, -2.0, 32.0);
	glVertex3f(-10, 0.0,32.0);
	glVertex3f(-10, 0.0,26.0);
	glVertex3f(-10,-2.0,26.0);
	//tutup belakang depan kecil
    glVertex3f(-10.0,-2.0,32.0);
	glVertex3f(-10.0, 0.0, 32.0);
	glVertex3f(32.0, 0.0, 32.0);
    glVertex3f(32.0,-2.0,32.0);
    glVertex3f(-10.0,-2.0,26.0);//belakang
	glVertex3f(-10.0, 0.0, 26.0);
	glVertex3f(26.0, 0.0, 26.0);
    glVertex3f(26.0,-2.0,26.0);
   //tutup samping kanan kecil
    glVertex3f(32.0, 0.0,32.0);
	glVertex3f(32.0, -2.0,32.0);
	glVertex3f(32.0, -2.0, 10.0);
    glVertex3f(32.0, 0.0,10.0);
    glVertex3f(26.0, 0.0,30.0);//belakang
	glVertex3f(26.0, -2.0,30.0);
	glVertex3f(26.0, -2.0, 10.0);
    glVertex3f(26.0, 0.0,10.0);

    //kiri
    //pagar depan
    glColor3f(1.0,1.0,0.5);
    glVertex3f(-20.0,-10.0,30.0);
	glVertex3f(-20.0, -2.0, 30.0);
	glVertex3f(-30.0, -2.0, 30.0);
    glVertex3f(-30.0,-10.0, 30.0);
	//tutup
	glColor3f(1.0,1.0,0.5);
    glVertex3f(-20, -10.0, 30.0);
	glVertex3f(-20,-2.0,30.0);
	glVertex3f(-20,-2.0,28.0);
	glVertex3f(-20,-10.0,28.0);
	//belakang
	glVertex3f(-20.0,-10.0,28.0);
	glVertex3f(-20.0, -2.0, 28.0);
	glVertex3f(-28.0, -2.0, 28.0);
    glVertex3f(-28.0,-10.0, 28.0);
    //pagar samping depan
    glVertex3f(-30.0,-10.0,30.0);
	glVertex3f(-30.0, -2.0,30.0);
	glVertex3f(-30.0, -2.0, 10.0);
    glVertex3f(-30.0,-10.0,10.0);
    //belakang
    glVertex3f(-28.0,-10.0,30.0);
	glVertex3f(-28.0, -2.0,30.0);
	glVertex3f(-28.0, -2.0, 10.0);
    glVertex3f(-28.0,-10.0,10.0);
    //atas a
    glColor3f(0.2,0.7,0.6);
    glVertex3f(-26, -2.0, 10.0);
	glVertex3f(-32,-2.0,10.0);
	glVertex3f(-32,-2.0,28.0);
	glVertex3f(-26,-2.0,28.0);
	//atas a
    glVertex3f(-20, -2.0, 32.0);
	glVertex3f(-32,-2.0,32.0);
	glVertex3f(-32,-2.0,26.0);
	glVertex3f(-20,-2.0,26.0);
    //atas b
    glColor3f(0.2,0.7,0.6);
    glVertex3f(-26, 0.0, 10.0);
	glVertex3f(-32,0.0,10.0);
	glVertex3f(-32,0.0,28.0);
	glVertex3f(-26,0.0,28.0);
	//atas b
	glColor3f(0.2,0.7,0.6);
    glVertex3f(-20, 0.0, 32.0);
	glVertex3f(-32,0.0,32.0);
	glVertex3f(-32,0.0,26.0);
	glVertex3f(-20,0.0,26.0);
	//tutup
	glColor3f(1.0,1.0,0.5);
    glVertex3f(-20, -2.0, 32.0);
	glVertex3f(-20, 0.0,32.0);
	glVertex3f(-20, 0.0,26.0);
	glVertex3f(-20,-2.0,26.0);
	//tutup belakang depan kecil
    glVertex3f(-20.0, 0.0,32.0);
	glVertex3f(-20.0, -2.0, 32.0);
	glVertex3f(-32.0, -2.0, 32.0);
    glVertex3f(-32.0, 0.0, 32.0);
    glVertex3f(-20.0, 0.0,26.0);//belakang
	glVertex3f(-20.0, -2.0, 26.0);
	glVertex3f(-30.0, -2.0, 26.0);
    glVertex3f(-30.0, 0.0, 26.0);
   //tutup samping kiri
    glVertex3f(-32.0, 0.0,32.0);
	glVertex3f(-32.0, -2.0,32.0);
	glVertex3f(-32.0, -2.0, 10.0);
    glVertex3f(-32.0, 0.0,10.0);
    glVertex3f(-26.0, 0.0,30.0);//belakang
	glVertex3f(-26.0, -2.0,30.0);
	glVertex3f(-26.0, -2.0, 10.0);
    glVertex3f(-26.0, 0.0,10.0);



    glEnd();
}

void jendela(void){
    //jendela
    glBegin(GL_QUADS);
    //jendela2
    glColor3f(0.5,0.4,0.1);
	glVertex3f(-9.0, -1,10.05);
	glVertex3f(-9.0, 17.0, 10.05);
	glVertex3f(-25.0, 17.0, 10.05);
    glVertex3f(-25.0, -1,10.05);
    glColor3f(0.3,0.0,0.1);//kaca1
	glVertex3f(-10.8, 13.3,10.052);
	glVertex3f(-10.8, 1.0, 10.052);
	glVertex3f(-15.3, 1.0, 10.052);
    glVertex3f(-15.3, 13.3,10.052);
	glVertex3f(-18.1, 13.3,10.052);//kaca2
	glVertex3f(-18.1, 1.0, 10.052);
	glVertex3f(-22.9, 1.0, 10.052);
    glVertex3f(-22.9, 13.3,10.052);
	glVertex3f(-10.0, 15,10.052);//ventilasi
	glVertex3f(-10.0, 16.0, 10.052);
	glVertex3f(-16.5, 16.0, 10.052);
    glVertex3f(-16.5, 15,10.052);
	glVertex3f(-17.5, 15,10.052);//ventilasi
	glVertex3f(-17.5, 16.0, 10.052);
	glVertex3f(-24.0, 16.0, 10.052);
    glVertex3f(-24.0, 15,10.052);

    //jendela1
    glColor3f(0.5,0.4,0.1);
	glVertex3f(8.0, -1,10.05);
	glVertex3f(8.0, 17.0, 10.05);
	glVertex3f(23.0, 17.0, 10.05);
    glVertex3f(23.0, -1, 10.05);
    glColor3f(0.3,0.0,0.1);//kaca1
	glVertex3f(10.1, 13.3, 10.052);
	glVertex3f(10.1, 1.0, 10.052);
	glVertex3f(14.3, 1.0, 10.052);
    glVertex3f(14.3, 13.3, 10.052);
	glVertex3f(17, 13.3, 10.052);//kaca2
	glVertex3f(17, 1.0, 10.052);
	glVertex3f(21.5, 1.0, 10.052);
    glVertex3f(21.5, 13.3, 10.052);
    glVertex3f(9, 15, 10.052);//ventilasi
	glVertex3f(9, 16.0, 10.052);
	glVertex3f(15, 16.0, 10.052);
    glVertex3f(15, 15, 10.052);
	glVertex3f(16, 15, 10.052);//ventilasi
	glVertex3f(16, 16.0, 10.052);
	glVertex3f(22.0, 16.0, 10.052);
    glVertex3f(22.0, 15, 10.052);

    glColor3f(0.5,0.4,0.1); //jendela kecil
	glVertex3f(38.5, 3,10.05);
	glVertex3f(38.5, 13.9, 10.05);
	glVertex3f(44.5, 13.9, 10.05);
    glVertex3f(44.5, 3, 10.05);
    glColor3f(0.1,1.0,0.8);//kaca1
	glVertex3f(39, 13.3, 10.052);
	glVertex3f(39, 3.6, 10.052);
	glVertex3f(44, 3.6, 10.052);
    glVertex3f(44, 13.3, 10.052);
    glEnd();

    glBegin(GL_LINES);
    //list
    glColor3f(0.0,0.0,0.0); //2.1
	glVertex3f(-17.5, 0,10.052);
	glVertex3f(-23.8, 0, 10.052);
	glVertex3f(-23.8, 14.0, 10.052);
    glVertex3f(-23.8, 0,10.052);
	glVertex3f(-16.3, 0,10.052); //2.2
    glVertex3f(-16.3, 14.0, 10.052);
	glVertex3f(-16.3, 0 , 10.052);
    glVertex3f(-10, 0 ,10.052);

    glColor3f(0.0,0.0,0.0); //1.1
	glVertex3f( 15, 0, 10.052);
	glVertex3f( 9.2, 0, 10.052);
	glVertex3f(9.2, 14.0, 10.052);
    glVertex3f(9.2, 0,10.052);
	glVertex3f(16.3, 0, 10.052); //1.2
	glVertex3f(16.3, 14.0, 10.052);
	glVertex3f(16.3, 0 , 10.052);
    glVertex3f(22, 0 ,10.052);

    glColor3f(1.0,1.0,1.0); //jendela kecil
	glVertex3f( 39, 11, 10.0521);
	glVertex3f( 44.05, 11, 10.0521);
	glVertex3f( 39, 8.5, 10.0521);
	glVertex3f( 44.05, 8.5, 10.0521);
	glVertex3f( 39, 6, 10.0521);
	glVertex3f( 44.05, 6, 10.0521);

    glEnd();
}

void pintu(void){
    glBegin(GL_QUADS);
    //pintu
    glColor3f(0.5,0.4,0.1);
	glVertex3f( 8.2, -10,10.0521);
	glVertex3f( 8.2, 17.0, 10.0521);
	glVertex3f(-1.0, 17.0, 10.0521);
    glVertex3f(-1.0, -10,10.0521);

    glColor3f(0.3,0.0,0.1);
    glVertex3f(7.5, 15, 10.053);//ventilasi
	glVertex3f(7.5, 16.0, 10.053);
	glVertex3f(0.2, 16.0, 10.053);
    glVertex3f(0.2, 15, 10.053);

    glColor3f(1.0,1.0,1.0);
    glVertex3f(5, 5, 10.552);
	glVertex3f(6.2, 5, 10.552);
	glVertex3f(6.2, 5.5, 10.552);
    glVertex3f(5, 5.5, 10.552);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);//garis pintu
	glVertex3f( 7.0, -10,10.053);
	glVertex3f( 7.0, 14.0, 10.053);
	glVertex3f( 7.0, 14, 10.053);
    glVertex3f( 0.2, 14,10.053);
    glVertex3f( 0.2, -10, 10.053);
    glVertex3f( 0.2, 14,10.053);

    glEnd();
}

void atribut(void){
    //meteran listrik
    glBegin(GL_QUADS);
    glColor3f(0.2,0.7,0.6);//
	glVertex3f(-4, 13.3, 10.051);
	glVertex3f(-4, 7.3, 10.051);
	glVertex3f(-7, 7.3, 10.051);
    glVertex3f(-7, 13.3, 10.051);
    //kabel
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-5.3, 19.8,10.051);
	glVertex3f(-5.3, 13.3, 10.051);
	glVertex3f(-5.5, 13.3, 10.051);
    glVertex3f(-5.5, 19.8, 10.051);

    //kotak atas
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-6.2, 12., 10.552);
    glColor3f(1.0,1.0,1.0);
	glVertex3f(-6.2, 11, 10.552);
	glVertex3f(-4.5, 11, 10.552);
    glVertex3f(-4.5, 12., 10.552);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(-4.4, 12., 10.052);//
	glVertex3f(-4.4, 11, 10.052);
	 glColor3f(1.0,1.0,1.0);
	glVertex3f(-4.5, 11, 10.552);
    glVertex3f(-4.5, 12., 10.552);

     glColor3f(0.0,0.0,0.0);
    glVertex3f(-6.3, 12., 10.052);//
    glColor3f(1.0,1.0,1.0);
	glVertex3f(-6.3, 11, 10.052);
	glVertex3f(-6.2, 11, 10.552);
    glVertex3f(-6.2, 12., 10.552);

    //tutup
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-6.3, 12., 10.052);//atas
	glVertex3f(-6.2, 12., 10.552);
	glVertex3f(-4.5, 12., 10.552);
    glVertex3f(-4.4, 12., 10.052);
    glVertex3f(-6.3, 11., 10.052);//bawah
	glVertex3f(-6.2, 11., 10.552);
	glVertex3f(-4.5, 11., 10.552);
    glVertex3f(-4.4, 11., 10.052);

    //kotak atas kecil
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-5.7, 11., 10.352);
    glColor3f(1.0,1.0,1.0);
	glVertex3f(-5.7, 10.5, 10.352);
	glVertex3f(-5, 10.5, 10.352);
    glVertex3f(-5, 11., 10.352);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(-4.9, 11.1, 10.052);//
	glVertex3f(-4.9, 10.5, 10.052);
	 glColor3f(1.0,1.0,1.0);
	glVertex3f(-5, 10.5, 10.352);
    glVertex3f(-5, 11.1, 10.352);

     glColor3f(0.0,0.0,0.0);
    glVertex3f(-5.8, 11.1, 10.052);//
    glColor3f(1.0,1.0,1.0);
	glVertex3f(-5.8, 10.5, 10.052);
	glVertex3f(-5.7, 10.5, 10.352);
    glVertex3f(-5.7, 11.1, 10.352);

    //tutup
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-5.8, 10.5, 10.052);//bawah
	glVertex3f(-5.7, 10.5, 10.352);
	glVertex3f(-5, 10.5, 10.352);
    glVertex3f(-4.9, 10.5, 10.052);

    //bawah kotak
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-5.8, 9., 10.552);
    glColor3f(1.0,1.0,1.0);
	glVertex3f(-5.8, 8.5, 10.552);
	glVertex3f(-5., 8.5, 10.552);
    glVertex3f(-5., 9., 10.552);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(-5.6, 8.85, 10.553);
	glVertex3f(-5.6, 8.65, 10.553);
	glVertex3f(-5.2, 8.65, 10.553);
    glVertex3f(-5.2, 8.85, 10.553);

    glColor3f(1.0,1.0,1.0);
    glVertex3f(-5.55, 8.8, 10.554);
	glVertex3f(-5.55, 8.7, 10.554);
	glVertex3f(-5.25, 8.7, 10.554);
    glVertex3f(-5.25, 8.8, 10.554);

    glColor3f(0.0,0.0,1.0);
    glVertex3f(-5.55, 8.8, 10.555);
	glVertex3f(-5.55, 8.7, 10.555);
	glVertex3f(-5.4, 8.7, 10.555);
    glVertex3f(-5.4, 8.8, 10.555);

    glColor3f(0.0,0.0,0.0); //
    glVertex3f(-6.2, 9., 10.052);
    glColor3f(1.0,1.0,1.0);
	glVertex3f(-6.2, 8.5, 10.052);
	glVertex3f(-5.8, 8.5, 10.552);
    glVertex3f(-5.8, 9., 10.552);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-4.6, 9., 10.052);//
    glColor3f(1.0,1.0,1.0);
	glVertex3f(-4.6, 8.5, 10.052);
	glVertex3f(-5., 8.5, 10.552);
    glVertex3f(-5., 9., 10.552);
    //tutup
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-6.2, 9., 10.052);//atas
	glVertex3f(-5.8, 9., 10.552);
	glVertex3f(-5, 9., 10.552);
    glVertex3f(-4.6, 9., 10.052);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-6.2, 8.5, 10.052);//bawah
	glVertex3f(-5.8, 8.5, 10.552);
	glVertex3f(-5, 8.5, 10.552);
    glVertex3f(-4.6, 8.5, 10.052);


    glEnd();
}

void lemari(void){

    glBegin(GL_QUADS);
      //rak
    //tiang 1
    glColor3f(0.3,0.3,0.1); //belakang
    glVertex3f(-25.5, 17,10.5);
	glVertex3f(-25.5, -10, 10.5);
	glVertex3f(-26, -10, 10.5);
    glVertex3f(-26, 17, 10.5);
    glVertex3f(-26, -10,10.5);//samping kiri
	glVertex3f(-26, -10, 11);
	glVertex3f(-26, 17, 11);
    glVertex3f(-26, 17, 10.5);
    glVertex3f(-25.5, -10,10.5);//samping kanan
	glVertex3f(-25.5, -10, 11);
	glVertex3f(-25.5, 17, 11);
    glVertex3f(-25.5, 17, 10.5);
    glVertex3f(-25.5, 17,11);//depan
	glVertex3f(-25.5, -10, 11);
	glVertex3f(-26, -10, 11);
    glVertex3f(-26, 17, 11);

    //tiang 2
    glColor3f(0.3,0.3,0.1); //belakang
    glVertex3f(-19, 17,10.5);
	glVertex3f(-19, -10, 10.5);
	glVertex3f(-18.5, -10, 10.5);
    glVertex3f(-18.5, 17, 10.5);
    glVertex3f(-18.5, -10,10.5);//samping kiri
	glVertex3f(-18.5, -10, 11);
	glVertex3f(-18.5, 17, 11);
    glVertex3f(-18.5, 17, 10.5);
    glVertex3f(-19, -10,10.5);//samping kanan
	glVertex3f(-19, -10, 11);
	glVertex3f(-19, 17, 11);
    glVertex3f(-19, 17, 10.5);
    glVertex3f(-19, 17,11);//depan
	glVertex3f(-19, -10, 11);
	glVertex3f(-18.5, -10, 11);
    glVertex3f(-18.5, 17, 11);

    //tiang 3 depan
    glColor3f(0.3,0.3,0.1); //belakang
    glVertex3f(-19, 17,16.5);
	glVertex3f(-19, -10, 16.5);
	glVertex3f(-18.5, -10, 16.5);
    glVertex3f(-18.5, 17, 16.5);
    glVertex3f(-18.5, -10,16.5);//samping kiri
	glVertex3f(-18.5, -10, 16);
	glVertex3f(-18.5, 17, 16);
    glVertex3f(-18.5, 17, 16.5);
    glVertex3f(-19, -10,16.5);//samping kanan
	glVertex3f(-19, -10, 16);
	glVertex3f(-19, 17, 16);
    glVertex3f(-19, 17, 16.5);
    glVertex3f(-19, 17,16);//depan
	glVertex3f(-19, -10, 16);
	glVertex3f(-18.5, -10, 16);
    glVertex3f(-18.5, 17, 16);

    //tiang 4 depan
    glColor3f(0.3,0.3,0.1); //belakang
    glVertex3f(-25.5, 17,16);
	glVertex3f(-25.5, -10, 16);
	glVertex3f(-26, -10, 16);
    glVertex3f(-26, 17, 16);
    glVertex3f(-26, -10,16);//samping kiri
	glVertex3f(-26, -10, 16.5);
	glVertex3f(-26, 17, 16.5);
    glVertex3f(-26, 17, 16);
    glVertex3f(-25.5, -10,16);//samping kanan
	glVertex3f(-25.5, -10, 16.5);
	glVertex3f(-25.5, 17, 16.5);
    glVertex3f(-25.5, 17, 16);
    glVertex3f(-25.5, 17,16.5);//depan
	glVertex3f(-25.5, -10, 16.5);
	glVertex3f(-26, -10, 16.5);
    glVertex3f(-26, 17, 16.5);

    //tiang penyambung
    //belakang
	glColor3f(0.3,0.3,0.1);//
	glVertex3f(-26, 16.5, 10.5);
	glVertex3f(-18.5, 16.5, 10.5);
	glVertex3f(-18.5, 17, 10.5);
	glVertex3f(-26, 17 ,10.5);
	glVertex3f(-26, 16.5, 11);//
	glVertex3f(-18.5, 16.5, 11);
	glVertex3f(-18.5, 17, 11);
	glVertex3f(-26, 17 ,11);
    glVertex3f(-26, 17, 10.5);//atas
	glVertex3f(-18.5, 17, 10.5);
	glVertex3f(-18.5, 17, 11);
	glVertex3f(-26, 17 ,11);
	glVertex3f(-26, 16.5, 10.5);//
	glVertex3f(-18.5, 16.5, 10.5);
	glVertex3f(-18.5, 16.5, 11);
	glVertex3f(-26, 16.5 ,11);

	//depan
	glVertex3f(-26, 16.5, 16);
	glVertex3f(-18.5, 16.5, 16);
	glVertex3f(-18.5, 17, 16);
	glVertex3f(-26, 17 ,16);
	glVertex3f(-26, 16.5, 16.5);//
	glVertex3f(-18.5, 16.5, 16.5);
	glVertex3f(-18.5, 17, 16.5);
	glVertex3f(-26, 17 ,16.5);
    glVertex3f(-26, 17, 16);//atas
	glVertex3f(-18.5, 17, 16);
	glVertex3f(-18.5, 17, 16.5);
	glVertex3f(-26, 17 ,16.5);
	glVertex3f(-26, 16.5, 16);//
	glVertex3f(-18.5, 16.5, 16);
	glVertex3f(-18.5, 16.5, 16.5);
	glVertex3f(-26, 16.5 ,16.5);

	//samping kiri atas
    glVertex3f(-25.5, 17, 16.5);
	glVertex3f(-26, 17, 16.5);
	glVertex3f(-26, 17, 10.5);
	glVertex3f(-25.5, 17 ,10.5);
	glVertex3f(-25.5, 16.5, 16.5);//bawah
	glVertex3f(-26, 16.5, 16.5);
	glVertex3f(-26, 16.5, 10.5);
	glVertex3f(-25.5, 16.5 ,10.5);
	glVertex3f(-25.5, 16.5, 16.5);//samping
	glVertex3f(-25.5, 17, 16.5);
	glVertex3f(-25.5, 17, 10.5);
	glVertex3f(-25.5, 16.5 ,10.5);
    glVertex3f(-26, 16.5, 16.5);//samping2
	glVertex3f(-26, 17, 16.5);
	glVertex3f(-26, 17, 10.5);
	glVertex3f(-26, 16.5 ,10.5);

	//samping kanan atas
    glVertex3f(-18.5, 17, 16.5);
	glVertex3f(-19, 17, 16.5);
	glVertex3f(-19, 17, 10.5);
	glVertex3f(-18.5, 17 ,10.5);
	glVertex3f(-18.5, 16.5, 16.5);//bawah
	glVertex3f(-19, 16.5, 16.5);
	glVertex3f(-19, 16.5, 10.5);
	glVertex3f(-18.5, 16.5 ,10.5);
	glVertex3f(-18.5, 16.5, 16.5);//samping
	glVertex3f(-18.5, 17, 16.5);
	glVertex3f(-18.5, 17, 10.5);
	glVertex3f(-18.5, 16.5 ,10.5);
    glVertex3f(-19, 16.5, 16.5);//samping2
	glVertex3f(-19, 17, 16.5);
	glVertex3f(-19, 17, 10.5);
	glVertex3f(-19, 16.5 ,10.5);

	//step penyambung
	//belakang
	glColor3f(0.3,0.3,0.1);//
	glVertex3f(-26, 7, 10.5);
	glVertex3f(-18.5, 7, 10.5);
	glVertex3f(-18.5, 7.5, 10.5);
	glVertex3f(-26, 7.5 ,10.5);
	glVertex3f(-26, 7, 11);//
	glVertex3f(-18.5, 7, 11);
	glVertex3f(-18.5, 7.5, 11);
	glVertex3f(-26, 7.5 ,11);
    glVertex3f(-26, 7.5, 10.5);//atas
	glVertex3f(-18.5, 7.5, 10.5);
	glVertex3f(-18.5, 7.5, 11);
	glVertex3f(-26, 7.5 ,11);
	glVertex3f(-26, 7, 10.5);//
	glVertex3f(-18.5, 7, 10.5);
	glVertex3f(-18.5, 7, 11);
	glVertex3f(-26, 7 ,11);

	//depan
	glVertex3f(-26, 7, 16);
	glVertex3f(-18.5, 7, 16);
	glVertex3f(-18.5, 7.5, 16);
	glVertex3f(-26, 7.5 ,16);
	glVertex3f(-26, 7, 16.5);//
	glVertex3f(-18.5, 7, 16.5);
	glVertex3f(-18.5, 7.5, 16.5);
	glVertex3f(-26, 7.5 ,16.5);
    glVertex3f(-26, 7.5, 16);//atas
	glVertex3f(-18.5, 7.5, 16);
	glVertex3f(-18.5, 7.5, 16.5);
	glVertex3f(-26, 7.5 ,16.5);
	glVertex3f(-26, 7, 16);//
	glVertex3f(-18.5, 7, 16);
	glVertex3f(-18.5, 7, 16.5);
	glVertex3f(-26, 7 ,16.5);

	//samping kiri tengah
    glVertex3f(-25.5, 7.5, 16.5);
	glVertex3f(-26, 7.5, 16.5);
	glVertex3f(-26, 7.5, 10.5);
	glVertex3f(-25.5, 7.5 ,10.5);
	glVertex3f(-25.5, 7, 16.5);//bawah
	glVertex3f(-26, 7, 16.5);
	glVertex3f(-26, 7, 10.5);
	glVertex3f(-25.5, 7 ,10.5);
	glVertex3f(-25.5, 7, 16.5);//samping
	glVertex3f(-25.5, 7.5, 16.5);
	glVertex3f(-25.5, 7.5, 10.5);
	glVertex3f(-25.5, 7 ,10.5);
    glVertex3f(-26, 7, 16.5);//samping2
	glVertex3f(-26, 7.5, 16.5);
	glVertex3f(-26, 7.5, 10.5);
	glVertex3f(-26, 7 ,10.5);

	//samping kanan tengah
    glVertex3f(-18.5, 7.5, 16.5);
	glVertex3f(-19, 7.5, 16.5);
	glVertex3f(-19, 7.5, 10.5);
	glVertex3f(-18.5, 7.5 ,10.5);
	glVertex3f(-18.5, 7, 16.5);//bawah
	glVertex3f(-19, 7, 16.5);
	glVertex3f(-19, 7, 10.5);
	glVertex3f(-18.5, 7 ,10.5);
	glVertex3f(-18.5, 7, 16.5);//samping
	glVertex3f(-18.5, 7.5, 16.5);
	glVertex3f(-18.5, 7.5, 10.5);
	glVertex3f(-18.5, 7 ,10.5);
    glVertex3f(-19, 7, 16.5);//samping2
	glVertex3f(-19, 7.5, 16.5);
	glVertex3f(-19, 7.5, 10.5);
	glVertex3f(-19, 7 ,10.5);

    //step penyambung bawah
	//belakang
	glColor3f(0.3,0.3,0.1);//
	glVertex3f(-26, -5.5, 10.5);
	glVertex3f(-18.5, -5.5, 10.5);
	glVertex3f(-18.5, -5, 10.5);
	glVertex3f(-26, -5 ,10.5);
	glVertex3f(-26, -5.5, 11);//
	glVertex3f(-18.5, -5.5, 11);
	glVertex3f(-18.5, -5, 11);
	glVertex3f(-26, -5 ,11);
    glVertex3f(-26, -5, 10.5);//atas
	glVertex3f(-18.5, -5, 10.5);
	glVertex3f(-18.5, -5, 11);
	glVertex3f(-26, -5 ,11);
	glVertex3f(-26, -5.5, 10.5);//
	glVertex3f(-18.5, -5.5, 10.5);
	glVertex3f(-18.5, -5.5, 11);
	glVertex3f(-26, -5.5 ,11);

	//depan
	glVertex3f(-26, -5.5, 16);
	glVertex3f(-18.5, -5.5, 16);
	glVertex3f(-18.5, -5, 16);
	glVertex3f(-26, -5 ,16);
	glVertex3f(-26, -5.5, 16.5);//
	glVertex3f(-18.5, -5.5, 16.5);
	glVertex3f(-18.5, -5, 16.5);
	glVertex3f(-26, -5 ,16.5);
    glVertex3f(-26, -5, 16);//atas
	glVertex3f(-18.5, -5, 16);
	glVertex3f(-18.5, -5, 16.5);
	glVertex3f(-26, -5 ,16.5);
	glVertex3f(-26, -5.5, 16);//
	glVertex3f(-18.5, -5.5, 16);
	glVertex3f(-18.5, -5.5, 16.5);
	glVertex3f(-26, -5.5 ,16.5);

	//samping kiri bawah
    glVertex3f(-25.5, -5, 16.5);
	glVertex3f(-26, -5, 16.5);
	glVertex3f(-26, -5, 10.5);
	glVertex3f(-25.5, -5 ,10.5);
	glVertex3f(-25.5, -5.5, 16.5);//bawah
	glVertex3f(-26, -5.5, 16.5);
	glVertex3f(-26, -5.5, 10.5);
	glVertex3f(-25.5, -5.5 ,10.5);
	glVertex3f(-25.5, -5.5, 16.5);//samping
	glVertex3f(-25.5, -5, 16.5);
	glVertex3f(-25.5, -5, 10.5);
	glVertex3f(-25.5, -5.5 ,10.5);
    glVertex3f(-26, -5.5, 16.5);//samping2
	glVertex3f(-26, -5, 16.5);
	glVertex3f(-26, -5, 10.5);
	glVertex3f(-26, -5.5 ,10.5);

	//samping kanan bawah
    glVertex3f(-18.5, -5, 16.5);
	glVertex3f(-19, -5, 16.5);
	glVertex3f(-19, -5, 10.5);
	glVertex3f(-18.5, -5 ,10.5);
	glVertex3f(-18.5, -5.5, 16.5);//bawah
	glVertex3f(-19, -5.5, 16.5);
	glVertex3f(-19, -5.5, 10.5);
	glVertex3f(-18.5, -5.5 ,10.5);
	glVertex3f(-18.5, -5.5, 16.5);//samping kanan
	glVertex3f(-18.5, -5, 16.5);
	glVertex3f(-18.5, -5, 10.5);
	glVertex3f(-18.5, -5.5 ,10.5);
    glVertex3f(-25.5, -5.5, 16.5);//samping kiri
	glVertex3f(-25.5, -5, 16.5);
	glVertex3f(-25.5, -5, 10.5);
	glVertex3f(-25.5, -5.5 ,10.5);

	//tutup lemari tengah
	glColor3f(0.0,1.0,0.0);//belakang
	glVertex3f(-26, 17, 10.5);
	glVertex3f(-18.5, 17, 10.5);
	glVertex3f(-18.5, -5, 10.5);
	glVertex3f(-26, -5 ,10.5);
    glVertex3f(-19, 7.5, 16);//samping kanan
	glVertex3f(-19, 11, 16);
	glVertex3f(-19, 11, 11);
	glVertex3f(-19, 7.5 ,11);
    glVertex3f(-25.5, 7.5, 16);//samping kiri
	glVertex3f(-25.5, 11, 16);
	glVertex3f(-25.5, 11, 11);
	glVertex3f(-25.5, 7.5 ,11);
	glVertex3f(-25.5, 7.5, 16.5);//alas
	glVertex3f(-18.5, 7.5, 16.5);
	glVertex3f(-18.5, 7.5, 10.5);
	glVertex3f(-25.5, 7.5 ,10.5);

	//tutup lemari tengah
	glColor3f(0.0,1.0,0.0);//belakang
	glVertex3f(-26, 17, 10.5);
	glVertex3f(-18.5, 17, 10.5);
	glVertex3f(-18.5, -5, 10.5);
	glVertex3f(-26, -5 ,10.5);
    glVertex3f(-19, 7.5, 16);//samping kanan
	glVertex3f(-19, 11, 16);
	glVertex3f(-19, 11, 11);
	glVertex3f(-19, 7.5 ,11);
    glVertex3f(-25.5, 7.5, 16);//samping kiri
	glVertex3f(-25.5, 11, 16);
	glVertex3f(-25.5, 11, 11);
	glVertex3f(-25.5, 7.5 ,11);
	glVertex3f(-25.5, 7.5, 16.5);//alas
	glVertex3f(-18.5, 7.5, 16.5);
	glVertex3f(-18.5, 7.5, 10.5);
	glVertex3f(-25.5, 7.5 ,10.5);

	//tutup lemari bawah
    glVertex3f(-19, -5.5, 16);//samping kanan
	glVertex3f(-19, 3, 16);
	glVertex3f(-19, 3, 11);
	glVertex3f(-19, -5.5 ,11);
    glVertex3f(-25.5, -5.5, 16);//samping kiri
	glVertex3f(-25.5, 3, 16);
	glVertex3f(-25.5, 3, 11);
	glVertex3f(-25.5, -5.5 ,11);
	glVertex3f(-25.5, -5.5, 16.5);//alas
	glVertex3f(-18.5, -5.5, 16.5);
	glVertex3f(-18.5, -5.5, 10.5);
	glVertex3f(-25.5, -5.5 ,10.5);

    glEnd();
}

void ground(void){
    glBegin(GL_QUADS);
    glColor3f(0.7,0.6,0.4);
	glVertex3f(-30, -12, 30.0);
	glVertex3f(30,-12,30.0);
	glVertex3f(30,-10,30.0);
	glVertex3f(-30,-10,30.0);
	glVertex3f( 30, -10, 10.0);//samping kanan
	glVertex3f( 30,-12,10.0);
	glVertex3f( 30,-12,30.0);
	glVertex3f( 30,-10,30.0);
	glVertex3f( 30, -12, 10.0);//samping kanan
	glVertex3f( 50,-12,10.0);
	glVertex3f( 50,-10,10.0);
	glVertex3f( 30,-10,10.0);
	glVertex3f( 50, -10, 10.0);// samping kanan
	glVertex3f( 50,-12,10.0);
	glVertex3f( 50,-12,-50.0);
	glVertex3f( 50,-10,-50.0);
    glVertex3f(-30,-10, 30.0);//samping kiri
	glVertex3f(-30,-12,30.0);
	glVertex3f(-30,-12,-50.0);
	glVertex3f(-30,-10,-50.0);
	glVertex3f(-30, -12, -50.0);//belakang
	glVertex3f(50,-12,-50.0);
	glVertex3f(50,-10,-50.0);
	glVertex3f(-30,-10,-50.0);

	//tangga
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-20, -11.0, 30.0);
	glVertex3f(-10,-11.0,30.0);
	glColor3f(0.2,0.7,0.6);
	glVertex3f(-10,-11.0,31.5);
	glVertex3f(-20,-11.0,31.5);
	glVertex3f(-20, -12, 30.05);//
	glVertex3f(-10,-12,30.05);
	glVertex3f(-10,-10,30.05);
	glVertex3f(-20,-10,30.05);
	glVertex3f(-20, -11.0, 31.5);//
	glVertex3f(-10,-11.0,31.5);
	glVertex3f(-10,-12.0,31.5);
	glVertex3f(-20,-12.0,31.5);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-10,-11.0,30.0);//
	glVertex3f(-10,-12.0,30.0);
	glVertex3f(-10,-12.0,31.5);
	glVertex3f(-10,-11.0,31.5);
	glVertex3f(-20,-11.0,30.0);//
	glVertex3f(-20,-12.0,30.0);
	glVertex3f(-20,-12.0,31.5);
	glVertex3f(-20,-11.0,31.5);
    glColor3f(0.2,0.7,0.6);
	glVertex3f(-18, -10.0, 30.0);//miring
	glVertex3f(-12,-10.0,30.0);
	glVertex3f(-12,-12.0,33.0);
	glVertex3f(-18,-12.0,33.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0,0.0,0.0);
    glVertex3f(-12,-10.0,30.0);//
	glVertex3f(-12,-12.0,30.0);
	glVertex3f(-12,-12.0,33.0);
	glVertex3f(-18,-10.0,30.0);//
	glVertex3f(-18,-12.0,30.0);
	glVertex3f(-18,-12.0,33.0); //*/
    glEnd();
}

void keramik(void){
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);//belakang/rumah
	glVertex3f(-30, -9.9, -50.0);
	glVertex3f(50,-9.9, -50.0);
	glVertex3f(50,-9.9, 10.0);
	glVertex3f(-30,-9.9, 10.0);
	glColor3f(1.0,1.0,1.0);//depan
	glVertex3f(-30, -9.9, 30.0);
	glVertex3f(30,-9.9, 30.0);
	glVertex3f(30,-9.9, 10.0);
	glVertex3f(-30,-9.9, 10.0);
	glEnd();

    //keramik
	glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
	glVertex3f(-30, -9.89, 25.0);
	glVertex3f(30,-9.89,25.0);
	glVertex3f(-30,-9.89,20.0);
	glVertex3f(30,-9.89, 20.0);
    glVertex3f(-30,-9.89,15.0);
	glVertex3f(30,-9.89, 15.0);
	glVertex3f(-30,-9.89,10.0);
	glVertex3f(30,-9.89, 10.0);
    glVertex3f(-25,-9.89,30.0);//
	glVertex3f(-25,-9.89, 10.0);
	glVertex3f(-20,-9.89,30.0);
	glVertex3f(-20,-9.89, 10.0);
    glVertex3f(-15,-9.89,30.0);
	glVertex3f(-15,-9.89, 10.0);
	glVertex3f(-10,-9.89,30.0);
	glVertex3f(-10,-9.89, 10.0);
	glVertex3f(-5,-9.89,30.0);
	glVertex3f(-5,-9.89, 10.0);
    glVertex3f(-0,-9.89,30.0);
	glVertex3f(-0,-9.89, 10.0);
    glVertex3f(5,-9.89,30.0);
	glVertex3f(5,-9.89, 10.0);
    glVertex3f(10,-9.89,30.0);
	glVertex3f(10,-9.89, 10.0);
    glVertex3f(15,-9.89,30.0);
	glVertex3f(15,-9.89, 10.0);
	glVertex3f(20,-9.89,30.0);
	glVertex3f(20,-9.89, 10.0);
	glVertex3f(25,-9.89,30.0);
	glVertex3f(25,-9.89, 10.0);
    glEnd();
}

void atk_dalam(void){
 glBegin(GL_QUADS);
 //lemari
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-30, -2, -17.5);//tengah
	glVertex3f(-23, -2, -17.5);
	glVertex3f(-23, -2, 7.5);
	glVertex3f(-30, -2, 7.5);
	glColor3f(1.0,1.0,1.0);
    glVertex3f(-29.99,-10.0,-17.5);//belakang
	glVertex3f(-29.99, 5.0,-17.5);
	glVertex3f(-29.99, 5.0, 7.5);
    glVertex3f(-29.99,-10.0, 7.5);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-23, -10.0, -17.5);//depan
	glVertex3f(-23, -2.0, -17.5);
	glVertex3f(-23, -2.0, 7.5);
    glVertex3f(-23, -10.0, 7.5);
    glVertex3f(-27, 4.5, -17.5);//depan tutup atas
	glVertex3f(-27, 5.0, -17.5);
	glVertex3f(-27, 5.0, 7.5);
    glVertex3f(-27, 4.5, 7.5);
    glVertex3f(-27, -2, 7.0);//depan tutup samping kiri
	glVertex3f(-27, 5.0, 7.0);
	glVertex3f(-27, 5.0, 7.5);
    glVertex3f(-27, -2, 7.5);
    glVertex3f(-27, -2, 2.0);//depan tutup samping tengah 1
	glVertex3f(-27, 5.0, 2.0);
	glVertex3f(-27, 5.0, 2.5);
    glVertex3f(-27, -2, 2.5);
    glVertex3f(-27, -2, -12.0);//depan tutup samping tengah 2
	glVertex3f(-27, 5.0, -12.0);
	glVertex3f(-27, 5.0, -12.5);
    glVertex3f(-27, -2, -12.5);
    glVertex3f(-27, -2, -17.0);//depan tutup samping kanan
	glVertex3f(-27, 5.0, -17.0);
	glVertex3f(-27, 5.0, -17.5);
    glVertex3f(-27, -2, -17.5);
    glVertex3f(-30, 5.0, -17.5);//atas
	glVertex3f(-27, 5.0, -17.5);
	glVertex3f(-27, 5.0, 7.5);
	glVertex3f(-30, 5.0, 7.5);
	glVertex3f(-30, 4.5, -17.0);//atas2
	glVertex3f(-27, 4.5, -17.0);
	glVertex3f(-27, 4.5, 7.0);
	glVertex3f(-30, 4.5, 7.0);
 	glVertex3f(-30.0,-10.0, 7.5);//samping kiri
	glVertex3f(-30.0, 5.0, 7.5);
	glVertex3f(-27.0, 5.0, 7.5);
    glVertex3f(-27.0,-10.0, 7.5);
    glVertex3f(-30.0,-2.0, 7.0);//samping kiri2
	glVertex3f(-30.0, 4.5, 7.0);
	glVertex3f(-27.0, 4.5, 7.0);
    glVertex3f(-27.0,-2.0, 7.0);
    glVertex3f(-23.0,-10, 7.5);//samping kiri3
	glVertex3f(-23.0, -2, 7.5);
	glVertex3f(-27.0, -2, 7.5);
    glVertex3f(-27.0,-10.0, 7.5);
    glVertex3f(-30.0,-2.0, -12.5);//samping tengah 1.1
	glVertex3f(-30.0, 5.0, -12.5);
	glVertex3f(-27.0, 5.0, -12.5);
    glVertex3f(-27.0,-2.0, -12.5);
    glVertex3f(-30.0,-2.0, -12.0);//samping tengah 1.2
	glVertex3f(-30.0, 5.0, -12.0);
	glVertex3f(-27.0, 5.0, -12.0);
    glVertex3f(-27.0,-2.0, -12.0);
    glVertex3f(-30.0,-2.0, 2.5);//samping tengah 2.1
	glVertex3f(-30.0, 5.0, 2.5);
	glVertex3f(-27.0, 5.0, 2.5);
    glVertex3f(-27.0,-2.0, 2.5);
    glVertex3f(-30.0,-2.0, 2);//samping tengah 2.2
	glVertex3f(-30.0, 5.0, 2);
	glVertex3f(-27.0, 5.0, 2);
    glVertex3f(-27.0,-2.0, 2);
    glVertex3f(-30.0,-10.0, -17.5);//samping kanan
	glVertex3f(-30.0, 5.0, -17.5);
	glVertex3f(-27.0, 5.0, -17.5);
    glVertex3f(-27.0,-10.0, -17.5);
    glVertex3f(-30.0,-2.0, -17.0);//samping kanan2
	glVertex3f(-30.0, 4.5, -17.0);
	glVertex3f(-27.0, 4.5, -17.0);
    glVertex3f(-27.0,-2.0, -17.0);
    glVertex3f(-23.0,-10, -17.5);//samping kanan3
	glVertex3f(-23.0, -2, -17.5);
	glVertex3f(-27.0, -2, -17.5);
    glVertex3f(-27.0,-10.0, -17.5);


    //sofa
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-20.0, -7.0, -19.995);// sofa belakang
	glVertex3f(-20.0, 0.0, -19.995);
	glVertex3f(15.0, 0.0, -19.995);
    glVertex3f(15.0,-7.0, -19.995);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-20.0, -6.5, -19.495);// sofa belakang 2
    glColor3f(1.0,0.0,0.0);
	glVertex3f(-20.0, 0.0, -19.495);
	glVertex3f(15.0, 0.0, -19.495);
	glColor3f(0.0,0.0,0.0);
    glVertex3f(15.0,-6.5, -19.495);
    //tutup atas
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-20, 0, -19.995);//alas bawah
	glVertex3f( 15, 0, -19.995);
	glVertex3f( 15, 0, -19.495);
	glVertex3f(-20, 0, -19.495);
    glColor3f(1.0,0.0,0.0);
    //alas
    glVertex3f(-20, -7, -19.995);//alas bawah
	glVertex3f( 15, -7, -19.995);
	glVertex3f( 15, -7, -13.0);
	glVertex3f(-20, -7, -13.0);
	glVertex3f(-20, -6.5, -19.495);// alas atas
	glVertex3f( 15, -6.5, -19.495);
	glVertex3f( 15, -6.5, -13.0);
	glVertex3f(-20, -6.5, -13.0);

    //tutup alas
    glColor3f(1.0,1.0,1.0);
	glVertex3f(-20, -7.0, -13);// tutup alas depan
	glVertex3f(-20, -6.5, -13);
	glVertex3f(15, -6.5, -13);
    glVertex3f(15, -7.0, -13);
    glVertex3f(15.0, -7.0, -20);// tutup alas depan kiri
	glVertex3f(15.0, -6.5, -20);
	glVertex3f(15.0, -6.5, -13);
    glVertex3f(15.0, -7.0, -13);
    glVertex3f(-20, -7.0, -20);// tutup alas depan kanan
	glVertex3f(-20, -6.5, -20);
	glVertex3f(-20, -6.5, -13);
    glVertex3f(-20, -7.0, -13);

    glColor3f(1.0,0.0,0.0);
    glVertex3f(-20.0, -10.0, -19.995);// sofa kaki kiri
	glVertex3f(-20.0, -7.0, -19.995);
	glVertex3f(-19.5, -7.0, -19.995);
    glVertex3f(-19.5, -10.0, -19.995);
    glVertex3f(-20.0, -10.0, -19.495);// sofa kaki kiri 2
	glVertex3f(-20.0, -7.0, -19.495);
	glVertex3f(-19.5, -7.0, -19.495);
    glVertex3f(-19.5, -10.0, -19.495);
    glVertex3f(-20.0, -10.0, -19.995);// sofa kaki kiri samping + tutup
	glVertex3f(-20.0, 0.0, -19.995);
	glVertex3f(-20.0, 0.0, -19.495);
    glVertex3f(-20.0, -10.0, -19.495);
    glVertex3f(-19.5, -10.0, -19.995);// sofa kaki kiri samping 2
	glVertex3f(-19.5, -7.0, -19.995);
	glVertex3f(-19.5, -7.0, -19.495);
    glVertex3f(-19.5, -10.0, -19.495);

    glVertex3f(14.5, -10.0, -19.995);// sofa kaki kanan
	glVertex3f(14.5, -7.0, -19.995);
	glVertex3f(15, -7.0, -19.995);
    glVertex3f(15, -10.0, -19.995);
    glVertex3f(14.5, -10.0, -19.495);// sofa kaki kanan 2
	glVertex3f(14.5, -7.0, -19.495);
	glVertex3f(15, -7.0, -19.495);
    glVertex3f(15, -10.0, -19.495);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(15.0, -10.0, -19.995);// sofa kaki kanan samping +tutup
	glVertex3f(15.0, 0.0, -19.995);
	glVertex3f(15.0, 0.0, -19.495);
    glVertex3f(15.0, -10.0, -19.495);
    glVertex3f(14.5, -10.0, -19.995);// sofa kaki kanan samping 2
	glVertex3f(14.5, -7.0, -19.995);
	glVertex3f(14.5, -7.0, -19.495);
    glVertex3f(14.5, -10.0, -19.495);

    //depan
    glVertex3f(-20.0, -10.0, -13);// sofa kaki kiri
	glVertex3f(-20.0, -4.0, -13);
	glVertex3f(-19.5, -4.0, -13);
    glVertex3f(-19.5, -10.0, -13);
    glVertex3f(-20.0, -10.0, -13.5);// sofa kaki kiri 2
	glVertex3f(-20.0, -4.0, -13.5);
	glVertex3f(-19.5, -4.0, -13.5);
    glVertex3f(-19.5, -10.0, -13.5);
    glVertex3f(-20.0, -10.0, -13.5);// sofa kaki kiri samping
	glVertex3f(-20.0, -4.0, -13.5);
	glVertex3f(-20.0, -4.0, -13);
    glVertex3f(-20.0, -10.0, -13);
    glVertex3f(-19.5, -10.0, -13.5);// sofa kaki kiri samping 2
	glVertex3f(-19.5, -4.0, -13.5);
	glVertex3f(-19.5, -4.0, -13);
    glVertex3f(-19.5, -10.0, -13);

    glVertex3f(14.5, -10.0, -13);// sofa kaki kanan
	glVertex3f(14.5, -4.0, -13);
	glVertex3f(15, -4.0, -13);
    glVertex3f(15, -10.0, -13);
    glVertex3f(14.5, -10.0, -13.5);// sofa kaki kanan 2
	glVertex3f(14.5, -4.0, -13.5);
	glVertex3f(15, -4.0, -13.5);
    glVertex3f(15, -10.0, -13.5);
    glVertex3f(15.0, -10.0, -13.5);// sofa kaki kanan samping
	glVertex3f(15.0, -4.0, -13.5);
	glVertex3f(15.0, -4.0, -13);
    glVertex3f(15.0, -10.0, -13);
    glVertex3f(14.5, -10.0, -13.5);// sofa kaki kanan samping 2
	glVertex3f(14.5, -4.0, -13.5);
	glVertex3f(14.5, -4.0, -13);
    glVertex3f(14.5, -10.0, -13);

    //pagar
    glVertex3f( -19.5, -4, -19.995);// alas atas
	glVertex3f( -20, -4, -19.995);
	glVertex3f( -20, -4, -13.0);
	glVertex3f( -19.5, -4, -13.0);
	glVertex3f( -19.5, -3.5, -19.995);// alas atas
	glVertex3f( -20, -3.5, -19.995);
	glVertex3f( -20, -3.5, -13.0);
	glVertex3f( -19.5, -3.5, -13.0);
    glVertex3f( -20, -4.0, -19.995);// tutup alas depan kanan
	glVertex3f( -20, -3.5, -19.995);
	glVertex3f( -20, -3.5, -13);
    glVertex3f( -20, -4.0, -13);
    glVertex3f( -19.5, -4.0, -19.995);// tutup alas depan kanan 2
	glVertex3f( -19.5, -3.5, -19.995);
	glVertex3f( -19.5, -3.5, -13);
    glVertex3f( -19.5, -4.0, -13);

    glVertex3f( 14.5, -4, -19.995);// alas atas
	glVertex3f( 15, -4, -19.995);
	glVertex3f( 15, -4, -13.0);
	glVertex3f( 14.5, -4, -13.0);
	glVertex3f( 14.5, -3.5, -19.995);// alas atas
	glVertex3f( 15, -3.5, -19.995);
	glVertex3f( 15, -3.5, -13.0);
	glVertex3f( 14.5, -3.5, -13.0);
    glVertex3f( 15, -4.0, -19.995);// tutup alas depan kanan
	glVertex3f( 15, -3.5, -19.995);
	glVertex3f( 15, -3.5, -13);
    glVertex3f( 15, -4.0, -13);
    glVertex3f( 14.5, -4.0, -19.995);// tutup alas depan kanan 2
	glVertex3f( 14.5, -3.5, -19.995);
	glVertex3f( 14.5, -3.5, -13);
    glVertex3f( 14.5, -4.0, -13);

glEnd();
}

void meja(void){
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f( -20, -5, -11);// meja atas
	glVertex3f( 15, -5, -11);
	glVertex3f( 15, -5, 0);
	glVertex3f( -20, -5, 0);
    glVertex3f( -20, -7, -11);// meja atas 2
	glVertex3f( 15, -7, -11);
	glVertex3f( 15, -7, 0);
	glVertex3f( -20, -7 , 0);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-20, -7.0, 0);// tutup meja depan
	glVertex3f(-20, -5, 0);
	glVertex3f(15, -5, 0);
    glVertex3f(15, -7.0, 0);
    glVertex3f(-20, -7.0, -11);// tutup meja belakang
	glVertex3f(-20, -5, -11);
	glVertex3f(15, -5, -11);
    glVertex3f(15, -7.0, -11);
    glVertex3f( -20, -7.0, -11);// tutup meja kiri
	glVertex3f( -20, -5, -11);
	glVertex3f( -20, -5, 0);
    glVertex3f( -20, -7.0, 0);
    glVertex3f( 15, -7.0, -11);// tutup meja kanan
	glVertex3f( 15, -5, -11);
	glVertex3f( 15, -5, 0);
    glVertex3f( 15, -7.0, 0);

    glColor3f(0.0,1.0,1.0);
    glVertex3f(14, -10.0, -10);// meja kaki kanan
	glVertex3f(14, -5.5, -10);
	glVertex3f(15, -5.5, -10);
    glVertex3f(15, -10.0, -10);
    glVertex3f(14, -10.0, -11);// meja kaki kanan 2
	glVertex3f(14, -5.5, -11);
	glVertex3f(15, -5.5, -11);
    glVertex3f(15, -10.0, -11);
    glVertex3f(15.0, -10.0, -11);// meja kaki kanan samping
	glVertex3f(15.0, -5.5, -11);
	glVertex3f(15.0, -5.5, -10);
    glVertex3f(15.0, -10.0, -10);
    glVertex3f(14, -10.0, -11);// meja kaki kanan samping 2
	glVertex3f(14, -5.5, -11);
	glVertex3f(14, -5.5, -10);
    glVertex3f(14, -10.0, -10);

    glColor3f(0.0,1.0,1.0);
    glVertex3f(-19, -10.0, -10);// meja kaki kanan
	glVertex3f(-19, -5.5, -10);
	glVertex3f(-20, -5.5, -10);
    glVertex3f(-20, -10.0, -10);
    glVertex3f(-19, -10.0, -11);// meja kaki kanan 2
	glVertex3f(-19, -5.5, -11);
	glVertex3f(-20, -5.5, -11);
    glVertex3f(-20, -10.0, -11);
    glVertex3f(-20.0, -10.0, -11);// meja kaki kanan samping
	glVertex3f(-20.0, -5.5, -11);
	glVertex3f(-20.0, -5.5, -10);
    glVertex3f(-20.0, -10.0, -10);
    glVertex3f(-19, -10.0, -11);// meja kaki kanan samping 2
	glVertex3f(-19, -5.5, -11);
	glVertex3f(-19, -5.5, -10);
    glVertex3f(-19, -10.0, -10);

    //depan
    glVertex3f(14, -10.0, 0);// meja kaki kanan
	glVertex3f(14, -5.5, 0);
	glVertex3f(15, -5.5, 0);
    glVertex3f(15, -10.0, 0);
    glVertex3f(14, -10.0, -1);// meja kaki kanan 2
	glVertex3f(14, -5.5, -1);
	glVertex3f(15, -5.5, -1);
    glVertex3f(15, -10.0, -1);
    glVertex3f(15.0, -10.0, -1);// meja kaki kanan samping
	glVertex3f(15.0, -5.5, -1);
	glVertex3f(15.0, -5.5, 0);
    glVertex3f(15.0, -10.0, 0);
    glVertex3f(14, -10.0, -1);// meja kaki kanan samping 2
	glVertex3f(14, -5.5, -1);
	glVertex3f(14, -5.5, 0);
    glVertex3f(14, -10.0, 0);

    glVertex3f(-19, -10.0, 0);// meja kaki kanan
	glVertex3f(-19, -5.5, 0);
	glVertex3f(-20, -5.5, 0);
    glVertex3f(-20, -10.0, 0);
    glVertex3f(-19, -10.0, -1);// meja kaki kanan 2
	glVertex3f(-19, -5.5, -1);
	glVertex3f(-20, -5.5, -1);
    glVertex3f(-20, -10.0, -1);
    glVertex3f(-20.0, -10.0, -1);// meja kaki kanan samping
	glVertex3f(-20.0, -5.5, -1);
	glVertex3f(-20.0, -5.5, 0);
    glVertex3f(-20.0, -10.0, 0);
    glVertex3f(-19, -10.0, -1);// meja kaki kanan samping 2
	glVertex3f(-19, -5.5, -1);
	glVertex3f(-19, -5.5, 0);
    glVertex3f(-19, -10.0, 0);

    //bawah list meja
    //depan
    glVertex3f(-20, -8.5, 0);// tutup meja depan
	glVertex3f(-20, -8, 0);
	glVertex3f(15, -8, 0);
    glVertex3f(15, -8.5, 0);
    glVertex3f(-20, -8.5, -1);// tutup meja depan 2
	glVertex3f(-20, -8, -1);
	glVertex3f(15, -8, -1);
    glVertex3f(15, -8.5, -1);
    glVertex3f( -20, -8, -1);// tutup meja bawah
	glVertex3f( 15, -8, -1);
	glVertex3f( 15, -8, 0);
	glVertex3f( -20, -8, 0);
    glVertex3f( -20, -8.5, -1);// tutup meja bawah
	glVertex3f( 15, -8.5, -1);
	glVertex3f( 15, -8.5, 0);
	glVertex3f( -20, -8.5, 0);

	//belakang
    glVertex3f(-20, -8.5, -10);// tutup meja depan
	glVertex3f(-20, -8, -10);
	glVertex3f(15, -8, -10);
    glVertex3f(15, -8.5, -10);
    glVertex3f(-20, -8.5, -11);// tutup meja depan 2
	glVertex3f(-20, -8, -11);
	glVertex3f(15, -8, -11);
    glVertex3f(15, -8.5, -11);
    glVertex3f( -20, -8, -11);// tutup meja atas
	glVertex3f( 15, -8, -11);
	glVertex3f( 15, -8, -10);
	glVertex3f( -20, -8, -10);
    glVertex3f( -20, -8.5, -11);// tutup meja bawah
	glVertex3f( 15, -8.5, -11);
	glVertex3f( 15, -8.5, -10);
	glVertex3f( -20, -8.5, -10);

    //tutup
    //samping
    glVertex3f(-20, -8.5, -11);// tutup kaki kiri samping
	glVertex3f(-20, -8.0, -11);
	glVertex3f(-20, -8.0, 0);
    glVertex3f(-20, -8.5, 0);
    glVertex3f(-19, -8.5, -11);// tutup kaki kiri samping 2
	glVertex3f(-19, -8.0, -11);
	glVertex3f(-19, -8.0, 0);
    glVertex3f(-19, -8.5, 0);
    glVertex3f( -20, -8, -11);// tutup meja atas
	glVertex3f( -19, -8, -11);
	glVertex3f( -19, -8, 0);
	glVertex3f( -20, -8, 0);
    glVertex3f( -20, -8.5, -11);// tutup meja atas 2
	glVertex3f( -19, -8.5, -11);
	glVertex3f( -19, -8.5, 0);
	glVertex3f( -20, -8.5, 0);


    glVertex3f(15, -8.5, -11);// tutup kaki kanan samping
	glVertex3f(15, -8.0, -11);
	glVertex3f(15, -8.0, 0);
    glVertex3f(15, -8.5, 0);
    glVertex3f(14, -8.5, -11);// tutup kaki kanan samping 2
	glVertex3f(14, -8.0, -11);
	glVertex3f(14, -8.0, 0);
    glVertex3f(14, -8.5, 0);
    glVertex3f( 15, -8, -11);// tutup meja atas
	glVertex3f( 14, -8, -11);
	glVertex3f( 14, -8, 0);
	glVertex3f( 15, -8, 0);
    glVertex3f( 15, -8.5, -11);// tutup meja atas 2
	glVertex3f( 14, -8.5, -11);
	glVertex3f( 14, -8.5, 0);
	glVertex3f( 15, -8.5, 0);

	//jari jari
	//kanan 1
	glVertex3f(-17.5, -8.5, -11);// tutup kaki kiri samping
	glVertex3f(-17.5, -8.0, -11);
	glVertex3f(-17.5, -8.0, 0);
    glVertex3f(-17.5, -8.5, 0);
    glVertex3f(-15.5, -8.5, -11);// tutup kaki kiri samping 2
	glVertex3f(-15.5, -8.0, -11);
	glVertex3f(-15.5, -8.0, 0);
    glVertex3f(-15.5, -8.5, 0);
    glVertex3f( -17.5, -8, -11);// tutup meja atas
	glVertex3f( -15.5, -8, -11);
	glVertex3f( -15.5, -8, 0);
	glVertex3f( -17.5, -8, 0);
    glVertex3f( -17.5, -8.5, -11);// tutup meja atas 2
	glVertex3f( -15.5, -8.5, -11);
	glVertex3f( -15.5, -8.5, 0);
	glVertex3f( -17.5, -8.5, 0);
	//2
	glVertex3f(-14, -8.5, -11);// tutup kaki kiri samping
	glVertex3f(-14, -8.0, -11);
	glVertex3f(-14, -8.0, 0);
    glVertex3f(-14, -8.5, 0);
    glVertex3f(-12, -8.5, -11);// tutup kaki kiri samping 2
	glVertex3f(-12, -8.0, -11);
	glVertex3f(-12, -8.0, 0);
    glVertex3f(-12, -8.5, 0);
    glVertex3f( -14, -8, -11);// tutup meja atas
	glVertex3f( -12, -8, -11);
	glVertex3f( -12, -8, 0);
	glVertex3f( -14, -8, 0);
    glVertex3f( -14, -8.5, -11);// tutup meja atas 2
	glVertex3f( -12, -8.5, -11);
	glVertex3f( -12, -8.5, 0);
	glVertex3f( -14, -8.5, 0);
	//3
    glVertex3f(-8.5, -8.5, -11);// tutup kaki kiri samping
	glVertex3f(-8.5, -8.0, -11);
	glVertex3f(-8.5, -8.0, 0);
    glVertex3f(-8.5, -8.5, 0);
    glVertex3f(-10.5, -8.5, -11);// tutup kaki kiri samping 2
	glVertex3f(-10.5, -8.0, -11);
	glVertex3f(-10.5, -8.0, 0);
    glVertex3f(-10.5, -8.5, 0);
    glVertex3f( -8.5, -8, -11);// tutup meja atas
	glVertex3f( -10.5, -8, -11);
	glVertex3f( -10.5, -8, 0);
	glVertex3f( -8.5, -8, 0);
    glVertex3f( -8.5, -8.5, -11);// tutup meja atas 2
	glVertex3f( -10.5, -8.5, -11);
	glVertex3f( -10.5, -8.5, 0);
	glVertex3f( -8.5, -8.5, 0);
    //4
    glVertex3f(-5, -8.5, -11);// tutup kaki kiri samping
	glVertex3f(-5, -8.0, -11);
	glVertex3f(-5, -8.0, 0);
    glVertex3f(-5, -8.5, 0);
    glVertex3f(-7, -8.5, -11);// tutup kaki kiri samping 2
	glVertex3f(-7, -8.0, -11);
	glVertex3f(-7, -8.0, 0);
    glVertex3f(-7, -8.5, 0);
    glVertex3f( -5, -8, -11);// tutup meja atas
	glVertex3f( -7, -8, -11);
	glVertex3f( -7, -8, 0);
	glVertex3f( -5, -8, 0);
    glVertex3f( -5, -8.5, -11);// tutup meja atas 2
	glVertex3f( -7, -8.5, -11);
	glVertex3f( -7, -8.5, 0);
	glVertex3f( -5, -8.5, 0);
    //5
    glVertex3f(-1.5, -8.5, -11);// tutup kaki kiri samping
	glVertex3f(-1.5, -8.0, -11);
	glVertex3f(-1.5, -8.0, 0);
    glVertex3f(-1.5, -8.5, 0);
    glVertex3f(-3.5, -8.5, -11);// tutup kaki kiri samping 2
	glVertex3f(-3.5, -8.0, -11);
	glVertex3f(-3.5, -8.0, 0);
    glVertex3f(-3.5, -8.5, 0);
    glVertex3f( -1.5, -8, -11);// tutup meja atas
	glVertex3f( -3.5, -8, -11);
	glVertex3f( -3.5, -8, 0);
	glVertex3f( -1.5, -8, 0);
    glVertex3f( -1.5, -8.5, -11);// tutup meja atas 2
	glVertex3f( -3.5, -8.5, -11);
	glVertex3f( -3.5, -8.5, 0);
	glVertex3f( -1.5, -8.5, 0);
	//6
    glVertex3f(0, -8.5, -11);// tutup kaki kiri samping
	glVertex3f(0, -8.0, -11);
	glVertex3f(0, -8.0, 0);
    glVertex3f(0, -8.5, 0);
    glVertex3f(2, -8.5, -11);// tutup kaki kiri samping 2
	glVertex3f(2, -8.0, -11);
	glVertex3f(2, -8.0, 0);
    glVertex3f(2, -8.5, 0);
    glVertex3f( 0, -8, -11);// tutup meja atas
	glVertex3f( 2, -8, -11);
	glVertex3f( 2, -8, 0);
	glVertex3f( 0, -8, 0);
    glVertex3f( 0, -8.5, -11);// tutup meja atas 2
	glVertex3f( 2, -8.5, -11);
	glVertex3f( 2, -8.5, 0);
	glVertex3f( 0, -8.5, 0);
    //7
    glVertex3f(3.5, -8.5, -11);// tutup kaki kiri samping
	glVertex3f(3.5, -8.0, -11);
	glVertex3f(3.5, -8.0, 0);
    glVertex3f(3.5, -8.5, 0);
    glVertex3f(5.5, -8.5, -11);// tutup kaki kiri samping 2
	glVertex3f(5.5, -8.0, -11);
	glVertex3f(5.5, -8.0, 0);
    glVertex3f(5.5, -8.5, 0);
    glVertex3f( 3.5, -8, -11);// tutup meja atas
	glVertex3f( 5.5, -8, -11);
	glVertex3f( 5.5, -8, 0);
	glVertex3f( 3.5, -8, 0);
    glVertex3f( 3.5, -8.5, -11);// tutup meja atas 2
	glVertex3f( 5.5, -8.5, -11);
	glVertex3f( 5.5, -8.5, 0);
	glVertex3f( 3.5, -8.5, 0);
	//8
    glVertex3f(7, -8.5, -11);// tutup kaki kiri samping
	glVertex3f(7, -8.0, -11);
	glVertex3f(7, -8.0, 0);
    glVertex3f(7, -8.5, 0);
    glVertex3f(9, -8.5, -11);// tutup kaki kiri samping 2
	glVertex3f(9, -8.0, -11);
	glVertex3f(9, -8.0, 0);
    glVertex3f(9, -8.5, 0);
    glVertex3f( 7, -8, -11);// tutup meja atas
	glVertex3f( 9, -8, -11);
	glVertex3f( 9, -8, 0);
	glVertex3f( 7, -8, 0);
    glVertex3f( 7, -8.5, -11);// tutup meja atas 2
	glVertex3f( 9, -8.5, -11);
	glVertex3f( 9, -8.5, 0);
	glVertex3f( 7, -8.5, 0);
    //9
    glVertex3f(10.5, -8.5, -11);// tutup kaki kiri samping
	glVertex3f(10.5, -8.0, -11);
	glVertex3f(10.5, -8.0, 0);
    glVertex3f(10.5, -8.5, 0);
    glVertex3f(12.5, -8.5, -11);// tutup kaki kiri samping 2
	glVertex3f(12.5, -8.0, -11);
	glVertex3f(12.5, -8.0, 0);
    glVertex3f(12.5, -8.5, 0);
    glVertex3f( 10.5, -8, -11);// tutup meja atas
	glVertex3f( 12.5, -8, -11);
	glVertex3f( 12.5, -8, 0);
	glVertex3f( 10.5, -8, 0);
    glVertex3f( 10.5, -8.5, -11);// tutup meja atas 2
	glVertex3f( 12.5, -8.5, -11);
	glVertex3f( 12.5, -8.5, 0);
	glVertex3f( 10.5, -8.5, 0);

 glEnd();
}

void tv(void){
  glBegin(GL_QUADS);
  glColor3f(1.0,0.0,0.0);
  //tv
    glVertex3f(48, 8, -30);//  tv belakang
	glVertex3f(48, 1, -30);
	glVertex3f(48, 1, -45);
    glVertex3f(48, 8, -45);
    glVertex3f(47.5, 8, -30);// tv depan
	glVertex3f(47.5, 1, -30);
	glVertex3f(47.5, 1, -45);
    glVertex3f(47.5, 8, -45);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(47.499, 7.5, -31);// tv depan
	glVertex3f(47.499, 1.5, -31);
	glVertex3f(47.499, 1.5, -44);
    glVertex3f(47.499, 7.5, -44);

    //tutup tv
    glColor3f(1.0,1.0,1.0);
    glVertex3f( 48, 1, -45);// tv bawah
	glVertex3f( 47.5, 1, -45);
	glVertex3f( 47.5, 1, -30);
	glVertex3f( 48, 1, -30);
	glVertex3f( 48, 8, -45);// tv bawah
	glVertex3f( 47.5, 8, -45);
	glVertex3f( 47.5, 8, -30);
	glVertex3f( 48, 8, -30);
	glVertex3f(47.5, 8, -30);// kaki tv kanan samping
	glVertex3f(47.5, 1, -30);
	glVertex3f(48, 1, -30);
    glVertex3f(48, 8, -30);
    glVertex3f(47.5, 8, -45);// kaki tv kiri samping
	glVertex3f(47.5, 1, -45);
	glVertex3f(48, 1, -45);
    glVertex3f(48, 8, -45);

    //kaki tv
    glColor3f(0.0,0.0,1.0);
    glVertex3f( 48, 1, -40);// kaki atas
	glVertex3f( 47.5, 1, -40);
	glVertex3f( 47.5, 1, -35);
	glVertex3f( 48, 1, -35);
    glVertex3f( 48, 1, -40);// kaki atas
	glVertex3f( 47.5, 1, -40);
	glVertex3f( 47.5, 1, -35);
	glVertex3f( 48, 1, -35);

	//tutup kaki
    glVertex3f(47.5, 1, -35);// tv depang
	glVertex3f(47, 0.5, -35);
	glVertex3f(47, 0.5, -40);
    glVertex3f(47.5, 1, -40);
    glVertex3f(48.5, 1, -35);// tv belakang
	glVertex3f(48, 0.5, -35);
	glVertex3f(48, 0.5, -40);
    glVertex3f(48.5, 1, -40);
    glVertex3f(47.5, 1.0, -35);// kaki tv kanan samping
	glVertex3f(47, 0.5, -35);
	glVertex3f(48.5, 0.5, -35);
    glVertex3f(48, 1.0, -35);
    glVertex3f(47.5, 1.0, -35);// kaki tv kanan samping
	glVertex3f(47, 0.5, -35);
	glVertex3f(48.5, 0.5, -35);
    glVertex3f(48, 1.0, -35);
    glVertex3f(47.5, 1.0, -40);// kaki tv kiri samping
	glVertex3f(47, 0.5, -40);
	glVertex3f(48.5, 0.5, -40);
    glVertex3f(48, 1.0, -40);


    glColor3f(1.0,0.0,0.0);
  //meja
    glVertex3f( 50, 0, -45);// meja atas
	glVertex3f( 45, 0, -45);
	glVertex3f( 45, 0, -30);
	glVertex3f( 50, 0, -30);
    glVertex3f( 50, 0.5, -45);// meja atas 2
	glVertex3f( 45, 0.5, -45);
	glVertex3f( 45, 0.5, -30);
	glVertex3f( 50, 0.5, -30);
    glVertex3f( 50, -5, -45);// meja atas bawah
	glVertex3f( 45, -5, -45);
	glVertex3f( 45, -5, -30);
	glVertex3f( 50, -5, -30);
    glVertex3f( 50, -5.5, -45);// meja atas bawah
	glVertex3f( 45, -5.5, -45);
	glVertex3f( 45, -5.5, -30);
	glVertex3f( 50, -5.5, -30);

	//kaki kiri belakang
	glVertex3f(49, -10.0, -45);// meja kaki kiri samping
	glVertex3f(49, -5, -45);
	glVertex3f(50, -5, -45);
    glVertex3f(50, -10.0, -45);
    glVertex3f(49, -10.0, -44);// meja kaki kiri samping 2
	glVertex3f(49, -5, -44);
	glVertex3f(50, -5, -44);
    glVertex3f(50, -10.0, -44);
    glVertex3f(50.0, -10.0, -44);// meja kaki kiri
	glVertex3f(50.0, -5, -44);
	glVertex3f(50.0, -5, -45);
    glVertex3f(50.0, -10.0, -45);
    glVertex3f(49, -10.0, -44);// meja kaki kiri 2
	glVertex3f(49, -5, -44);
	glVertex3f(49, -5, -45);
    glVertex3f(49, -10.0, -45);

    //kaki kanan belakang
	glVertex3f(49, -10.0, -31);// meja kaki kanan
	glVertex3f(49, 0, -31);
	glVertex3f(50, 0, -31);
    glVertex3f(50, -10.0, -31);
    glVertex3f(49, -10.0, -30);// meja kaki kanan 2
	glVertex3f(49, 0, -30);
	glVertex3f(50, 0, -30);
    glVertex3f(50, -10.0, -30);
    glVertex3f(50.0, -10.0, -30);// meja kaki kanan samping
	glVertex3f(50.0, 0.0, -30);
	glVertex3f(50.0, 0, -31);
    glVertex3f(50.0, -10.0, -31);
    glVertex3f(49, -10.0, -30);// meja kaki kanan samping 2
	glVertex3f(49, 0, -30);
	glVertex3f(49, 0, -31);
    glVertex3f(49, -10.0, -31);

    //kaki kiri depan
    glColor3f(1.0,0.0,0.0);
	glVertex3f(45, -10.0, -45);// meja kaki kiri samping
	glVertex3f(45, 0, -45);
	glVertex3f(46, 0, -45);
    glVertex3f(46, -10.0, -45);
    glVertex3f(45, -10.0, -44);// meja kaki kiri samping 2
	glVertex3f(45, 0, -44);
	glVertex3f(46, 0, -44);
    glVertex3f(46, -10.0, -44);
    glVertex3f(46.0, -10.0, -44);// meja kaki kiri
	glVertex3f(46.0, 0, -44);
	glVertex3f(46.0, 0, -45);
    glVertex3f(46.0, -10.0, -45);
    glVertex3f(45, -10.0, -44);// meja kaki kiri 2
	glVertex3f(45, 0, -44);
	glVertex3f(45, 0, -45);
    glVertex3f(45, -10.0, -45);

    //kaki kanan belakang
	glVertex3f(45, -10.0, -31);// meja kaki kanan samping
	glVertex3f(45, 0, -31);
	glVertex3f(46, 0, -31);
    glVertex3f(46, -10.0, -31);
    glVertex3f(45, -10.0, -30);// meja kaki kanan samping 2
	glVertex3f(45, 0, -30);
	glVertex3f(46, 0, -30);
    glVertex3f(46, -10.0, -30);
    glVertex3f(46.0, -10.0, -30);// meja kaki kanan
	glVertex3f(46.0, 0, -30);
	glVertex3f(46.0, 0, -31);
    glVertex3f(46.0, -10.0, -31);
    glVertex3f(45, -10.0, -30);// meja kaki kanan 2
	glVertex3f(45, -0, -30);
	glVertex3f(45, -0, -31);
    glVertex3f(45, -10.0, -31);

    //tutup besar
    glColor3f(1.0,1.0,1.0);
    glVertex3f(45, -5, -31);// meja kaki kanan samping atas
	glVertex3f(45, 0, -31);
	glVertex3f(50, 0, -31);
    glVertex3f(50, -5, -31);
    glVertex3f(45, -5, -44);// meja kaki kiri samping atas
	glVertex3f(45, 0, -44);
	glVertex3f(50, 0, -44);
    glVertex3f(50, -5, -44);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(45, -5, -30);// meja kaki depan
	glVertex3f(45, 0, -30);
	glVertex3f(45, 0, -45);
    glVertex3f(45, -5, -45);
    glVertex3f(50, -5, -30);// meja kaki belakang
	glVertex3f(50, 0, -30);
	glVertex3f(50, 0, -45);
    glVertex3f(50, -5, -45);

    //tutup kecil
     glColor3f(1.0,1.0,1.0);
    glVertex3f(45, 0.5, -30);// meja kaki kanan samping atas
	glVertex3f(45, 0, -30);
	glVertex3f(50, 0, -30);
    glVertex3f(50, 0.5, -30);
    glVertex3f(45, 0.5, -45);// meja kaki kiri samping atas
	glVertex3f(45, 0, -45);
	glVertex3f(50, 0, -45);
    glVertex3f(50, 0.5, -45);
    glVertex3f(45, 0.5, -30);// meja kaki depan
	glVertex3f(45, 0, -30);
	glVertex3f(45, 0, -45);
    glVertex3f(45, 0.5, -45);
    glVertex3f(50, 0.5, -30);// meja kaki belakang
	glVertex3f(50, 0, -30);
	glVertex3f(50, 0, -45);
    glVertex3f(50, 0.5, -45);

    glVertex3f(45, -5.5, -30);// meja kaki kanan samping bawah
	glVertex3f(45, -5, -30);
	glVertex3f(50, -5, -30);
    glVertex3f(50, -5.5, -30);
    glVertex3f(45, -5.5, -45);// meja kaki kiri samping bawah
	glVertex3f(45, -5, -45);
	glVertex3f(50, -5, -45);
    glVertex3f(50, -5.5, -45);
    glVertex3f(45, -5.5, -30);// meja kaki depan
	glVertex3f(45, -5, -30);
	glVertex3f(45, -5, -45);
    glVertex3f(45, -5.5, -45);
    glVertex3f(50, -5.5, -30);// meja kaki belakang
	glVertex3f(50, -5, -30);
	glVertex3f(50, -5, -45);
    glVertex3f(50, -5.5, -45);

  glEnd();
}

void kasur(void){
  glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-20, -6.5, -45);// alas atas
	glVertex3f( 15, -6.5, -45);
	glVertex3f( 15, -6.5, -25.0);
	glVertex3f(-20, -6.5, -25.0);
	glVertex3f(-20, -9.89, -45);// alas bawah
	glVertex3f( 15, -9.89, -45);
	glVertex3f( 15, -9.89, -25.0);
	glVertex3f(-20, -9.89, -25.0);
	glVertex3f( 15, -9.89, -45);// tutup kasur kanan
	glVertex3f( 15, -6.5, -45);
	glVertex3f( 15, -6.5, -25);
    glVertex3f( 15, -9.89, -25);
    glVertex3f( -20, -9.89, -45);// tutup kasur kiri
	glVertex3f( -20, -6.5, -45);
	glVertex3f( -20, -6.5, -25);
    glVertex3f( -20, -9.89, -25);
    glVertex3f(-20, -9.89, -25);// tutup kasur depan
	glVertex3f(-20, -6.5, -25);
	glVertex3f(15, -6.5, -25);
    glVertex3f(15, -9.89, -25);
    glVertex3f(-20, -9.89, -45);// tutup kasur belakang
	glVertex3f(-20, -6.5, -45);
	glVertex3f(15, -6.5, -45);
    glVertex3f(15, -9.89, -45);
    glColor3f(1.0,0.0,1.0);
    glVertex3f( 0, -6.495, -45);// selimut atas
	glVertex3f( 15, -6.495, -45);
	glVertex3f( 15, -6.495, -25.0);
	glVertex3f( 0, -6.495, -25.0);
	glVertex3f( 15.05, -9.89, -45);// selimut kanan
	glVertex3f( 15.05, -6.5, -45);
	glVertex3f( 15.05, -6.5, -25);
    glVertex3f( 15.05, -9.89, -25);
    glVertex3f( 0, -9.89, -24.99);// tutup kasur depan
	glVertex3f( 0, -6.5, -24.99);
	glVertex3f(15, -6.5, -24.99);
    glVertex3f(15, -9.89, -24.99);
    glVertex3f( 0, -9.89, -45.05);// tutup kasur depan
	glVertex3f( 0, -6.5, -45.05);
	glVertex3f(15, -6.5, -45.05);
    glVertex3f(15, -9.89, -45.05);
    glVertex3f(-20, -6.495, -40);// bantal
	glVertex3f( -15, -6.495, -40);
	glVertex3f( -15, -6.495, -30.0);
	glVertex3f(-20, -6.495, -30.0);
  glEnd();
}

void pintu_dalam(void){
    glBegin(GL_QUADS);
    //pintu
    glColor3f(0.5,0.4,0.1);
	glVertex3f( 8.2, -10,9.99);
	glVertex3f( 8.2, 17.0, 9.99);
	glVertex3f(-1.0, 17.0, 9.99);
    glVertex3f(-1.0, -10,9.99);

    glColor3f(0.3,0.0,0.1);
    glVertex3f(7.5, 15, 9.98);//ventilasi
	glVertex3f(7.5, 16.0, 9.98);
	glVertex3f(0.2, 16.0, 9.98);
    glVertex3f(0.2, 15, 9.98);

    glColor3f(1.0,1.0,1.0);
    glVertex3f(5, 5, 9.995);
	glVertex3f(6.2, 5, 9.995);
	glVertex3f(6.2, 5.5, 9.995);
    glVertex3f(5, 5.5, 9.995);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);//garis pintu
	glVertex3f( 7.0, -10,9.98);
	glVertex3f( 7.0, 14.0, 9.98);
	glVertex3f( 7.0, 14, 9.98);
    glVertex3f( 0.2, 14, 9.98);
    glVertex3f( 0.2, -10, 9.98);
    glVertex3f( 0.2, 14, 9.98);

    glEnd();
}

void jendela_dalam(void){
    //jendela
    glBegin(GL_QUADS);
    //jendela2
    glColor3f(0.5,0.4,0.1);
	glVertex3f(-9.0, -1, 9.99);
	glVertex3f(-9.0, 17.0, 9.99);
	glVertex3f(-25.0, 17.0, 9.99);
    glVertex3f(-25.0, -1, 9.99);
    glColor3f(0.3,0.0,0.1);//kaca1
	glVertex3f(-10.8, 13.3, 9.95);
	glVertex3f(-10.8, 1.0, 9.95);
	glVertex3f(-15.3, 1.0, 9.95);
    glVertex3f(-15.3, 13.3, 9.95);
	glVertex3f(-18.1, 13.3, 9.95);//kaca2
	glVertex3f(-18.1, 1.0, 9.95);
	glVertex3f(-22.9, 1.0, 9.95);
    glVertex3f(-22.9, 13.3, 9.95);
	glVertex3f(-10.0, 15, 9.95);//ventilasi
	glVertex3f(-10.0, 16.0, 9.95);
	glVertex3f(-16.5, 16.0, 9.95);
    glVertex3f(-16.5, 15, 9.95);
	glVertex3f(-17.5, 15, 9.95);//ventilasi
	glVertex3f(-17.5, 16.0, 9.95);
	glVertex3f(-24.0, 16.0, 9.95);
    glVertex3f(-24.0, 15, 9.95);

    //jendela1
    glColor3f(0.5,0.4,0.1);
	glVertex3f(8.0, -1, 9.99);
	glVertex3f(8.0, 17.0, 9.99);
	glVertex3f(23.0, 17.0, 9.99);
    glVertex3f(23.0, -1, 9.99);
    glColor3f(0.3,0.0,0.1);//kaca1
	glVertex3f(10.1, 13.3, 9.95);
	glVertex3f(10.1, 1.0, 9.95);
	glVertex3f(14.3, 1.0, 9.95);
    glVertex3f(14.3, 13.3, 9.95);
	glVertex3f(17, 13.3, 9.95);//kaca2
	glVertex3f(17, 1.0, 9.95);
	glVertex3f(21.5, 1.0, 9.95);
    glVertex3f(21.5, 13.3, 9.95);
    glVertex3f(9, 15, 9.95);//ventilasi
	glVertex3f(9, 16.0, 9.95);
	glVertex3f(15, 16.0, 9.95);
    glVertex3f(15, 15, 9.95);
	glVertex3f(16, 15, 9.95);//ventilasi
	glVertex3f(16, 16.0, 9.95);
	glVertex3f(22.0, 16.0, 9.95);
    glVertex3f(22.0, 15, 9.95);

    glColor3f(0.5,0.4,0.1); //jendela kecil
	glVertex3f(38.5, 3, 9.99);
	glVertex3f(38.5, 13.9, 9.99);
	glVertex3f(44.5, 13.9, 9.99);
    glVertex3f(44.5, 3, 9.99);
    glColor3f(0.1,1.0,0.8);//kaca1
	glVertex3f(39, 13.3, 9.95);
	glVertex3f(39, 3.6, 9.95);
	glVertex3f(44, 3.6, 9.95);
    glVertex3f(44, 13.3, 9.95);
    glEnd();

    glBegin(GL_LINES);
    //list
    glColor3f(0.0,0.0,0.0); //2.1
	glVertex3f(-17.5, 0, 9.95);
	glVertex3f(-23.8, 0, 9.95);
	glVertex3f(-23.8, 14.0, 9.95);
    glVertex3f(-23.8, 0, 9.95);
	glVertex3f(-16.3, 0, 9.95); //2.2
    glVertex3f(-16.3, 14.0, 9.95);
	glVertex3f(-16.3, 0 , 9.95);
    glVertex3f(-10, 0 , 9.95);

    glColor3f(0.0,0.0,0.0); //1.1
	glVertex3f( 15, 0, 9.95);
	glVertex3f( 9.2, 0, 9.95);
	glVertex3f(9.2, 14.0, 9.95);
    glVertex3f(9.2, 0, 9.95);
	glVertex3f(16.3, 0, 9.95); //1.2
	glVertex3f(16.3, 14.0, 9.95);
	glVertex3f(16.3, 0 , 9.95);
    glVertex3f(22, 0 , 9.95);

    glColor3f(1.0,1.0,1.0); //jendela kecil
	glVertex3f( 39, 11, 9.949);
	glVertex3f( 44.05, 11, 9.949);
	glVertex3f( 39, 8.5, 9.949);
	glVertex3f( 44.05, 8.5, 9.949);
	glVertex3f( 39, 6, 9.949);
	glVertex3f( 44.05, 6, 9.949);

    glEnd();
}

void tampil(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(xpos, ypos, zpos);
	glRotatef(xrot + 10, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot - 10, 0.0f, 1.0f, 0.0f);

	pagar();
    rumah();
    tiang();
    jendela();
    pintu();
    keramik();
    ground();
    atribut();
    lemari();
    atk_dalam();
    meja();
    tv();
    kasur();
    pintu_dalam();
    jendela_dalam();

	glFlush();
	glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':
		case 'W':
		zpos += 3.0;
		glTranslatef(0.0, 0.0, 3.0);
		break;
		case 'd':
		case 'D':
		xpos += 3.0;
		glTranslatef(3.0, 0.0, 0.0);
		break;
		case 's':
		case 'S':
		zpos += -3.0;
		glTranslatef(0.0, 0.0, -3.0);
		break;
		case 'a':
		case 'A':
		xpos += -3.0;
		glTranslatef(-3.0, 0.0, 0.0);
		break;
		case 'q':
		case 'Q':
		xpos = 0.0f;
        ypos = 0.0f;
        zpos = 0.0f;
		glTranslatef(0.0, 0.0, 0.0);
		break;
		case '5':
		if (is_depth)
		{
			is_depth =0;
			glDisable(GL_DEPTH_TEST);
		} else
		{
			is_depth=1;
			glEnable(GL_DEPTH_TEST);
		}
		break;
	}
	tampil();
}

/*void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}*/

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}

void mouseMotion(int x, int y)
{

	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

	glutPostRedisplay();

	}
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}
