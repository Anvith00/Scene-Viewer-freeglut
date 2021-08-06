#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <math.h>
#include <time.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif
#define X .525731112119133606
#define Z .850650808352039932
using namespace std;
// function prototyping
void display();
void specialKeys();
// global declarations
bool mouseDown = false;
bool keyDown = false;
static GLfloat vdata[12][3] = {
    { -X, 0.0, Z },{ X, 0.0, Z },{ -X, 0.0, -Z },{ X, 0.0, -Z },
    { 0.0, Z, X },{ 0.0, Z, -X },{ 0.0, -Z, X },{ 0.0, -Z, -X },
    { Z, X, 0.0 },{ -Z, X, 0.0 },{ Z, -X, 0.0 },{ -Z, -X, 0.0 }
};
static GLuint tindices[20][3] = {
    { 0,4,1 },{ 0,9,4 },{ 9,5,4 },{ 4,5,8 },{ 4,8,1 },
    { 8,10,1 },{ 8,3,10 },{ 5,3,8 },{ 5,2,3 },{ 2,7,3 },
    { 7,10,3 },{ 7,6,10 },{ 7,11,6 },{ 11,0,6 },{ 0,1,6 },
    { 6,1,10 },{ 9,0,11 },{ 9,11,2 },{ 9,2,5 },{ 7,2,11 } };
int i;
int flag = 1;
double xrot1= 0.0f;
double yrot1= 0.0f;
float xrot2 = 0.0f;
float yrot2 = 0.0f;
float xrot3 = 0.0f;
float yrot3 = 0.0f;
float xdiff1 = 0.0f;
float ydiff1 = 0.0f;
float xdiff2 = 0.0f;
float ydiff2 = 0.0f;
float xdiff3 = 0.0f;
float ydiff3 = 0.0f;
float eyeX = 0.0f;
float eyeZ = 2.0f;

void displayCube() {
  glTranslatef(eyeX, 0.0f, 0.0f);
  gluLookAt(0.0f, 0.0f, eyeZ, 0.0f, 0.0f , 0.0f, 0.0f, 1.0f, 0.0f);

  // Rotate when user changes rotate_x and rotate_y
  glRotatef( xrot1, 1.0, 0.0, 0.0 );
  glRotatef( yrot1, 0.0, 1.0, 0.0 );

glColor3f(0.3f, 0.7f, 0.5f);
glBegin(GL_QUADS);
glVertex3f(-300.0f, -6.0f, -300.0f);
glVertex3f(-300.0f, -6.0f,  300.0f);
glVertex3f( 300.0f, -6.0f,  300.0f);
glVertex3f( 300.0f, -6.0f, -300.0f);
	glEnd();

  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 0.3 );     glVertex3f(  0.5, -0.5, -0.5 );   glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );   glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );    glVertex3f(  0.5, -0.5, 0.5 );    glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );    glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0 );    glVertex3f( 0.5, -0.5, -0.5 );  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );    glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );   glVertex3f( -0.5, -0.5,  0.5 ); glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );   glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );   glVertex3f(  0.5,  0.5,  0.5 ); glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );   glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );   glVertex3f(  0.5, -0.5, -0.5 ); glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );   glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
}

void displayIcosahedron() {

  glTranslatef(eyeX, 0.0f, 0.0f);
  gluLookAt(0.0f, 0.0f, eyeZ,0.0f, 0.0f, 0.0f,0.0f, 1.0f, 0.0f);

  glRotatef( xrot2, 1.0, 0.0, 0.0 );
  glRotatef( yrot2, 0.0, 1.0, 0.0 );

glColor3f(0.3f, 0.7f, 0.5f);
glBegin(GL_QUADS);
glVertex3f(-300.0f, -6.0f, -300.0f);
glVertex3f(-300.0f, -6.0f,  300.0f);
glVertex3f( 300.0f, -6.0f,  300.0f);
glVertex3f( 300.0f, -6.0f, -300.0f);
glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f( 0.1,0.5 ,0.6 );
    glVertex3fv(&vdata[tindices[0][0]][0]);     glVertex3fv(&vdata[tindices[0][1]][0]);
    glVertex3fv(&vdata[tindices[0][2]][0]);     glVertex3fv(&vdata[tindices[1][0]][0]);
    glVertex3fv(&vdata[tindices[1][1]][0]);     glVertex3fv(&vdata[tindices[1][2]][0]);

    glColor3f( 0.4, 0.8, 0.1);
    glVertex3fv(&vdata[tindices[2][0]][0]);     glVertex3fv(&vdata[tindices[2][1]][0]);
    glVertex3fv(&vdata[tindices[2][2]][0]);     glVertex3fv(&vdata[tindices[3][0]][0]);
    glVertex3fv(&vdata[tindices[3][1]][0]);     glVertex3fv(&vdata[tindices[3][2]][0]);

    glColor3f( 1.0, 0.3, 0.4);
    glVertex3fv(&vdata[tindices[4][0]][0]);     glVertex3fv(&vdata[tindices[4][1]][0]);
    glVertex3fv(&vdata[tindices[4][2]][0]);     glVertex3fv(&vdata[tindices[5][0]][0]);
    glVertex3fv(&vdata[tindices[5][1]][0]);     glVertex3fv(&vdata[tindices[5][2]][0]);

    glColor3f( 0.7, 0.6, 0.5);
    glVertex3fv(&vdata[tindices[6][0]][0]);     glVertex3fv(&vdata[tindices[6][1]][0]);
    glVertex3fv(&vdata[tindices[6][2]][0]);     glVertex3fv(&vdata[tindices[7][0]][0]);
    glVertex3fv(&vdata[tindices[7][1]][0]);     glVertex3fv(&vdata[tindices[7][2]][0]);

    glColor3f( 0.1, 0.2, 0.7);
    glVertex3fv(&vdata[tindices[8][0]][0]);     glVertex3fv(&vdata[tindices[8][1]][0]);
    glVertex3fv(&vdata[tindices[8][2]][0]);     glVertex3fv(&vdata[tindices[9][0]][0]);
    glVertex3fv(&vdata[tindices[9][1]][0]);     glVertex3fv(&vdata[tindices[9][2]][0]);

    glColor3f( 0.9, 0.8, 0.1);
    glVertex3fv(&vdata[tindices[10][0]][0]);    glVertex3fv(&vdata[tindices[10][1]][0]);
    glVertex3fv(&vdata[tindices[10][2]][0]);    glVertex3fv(&vdata[tindices[11][0]][0]);
    glVertex3fv(&vdata[tindices[11][1]][0]);    glVertex3fv(&vdata[tindices[11][2]][0]);

    glColor3f( 0.05, 0.081, 0.076);
    glVertex3fv(&vdata[tindices[12][0]][0]);    glVertex3fv(&vdata[tindices[12][1]][0]);
    glVertex3fv(&vdata[tindices[12][2]][0]);    glVertex3fv(&vdata[tindices[13][0]][0]);
    glVertex3fv(&vdata[tindices[13][1]][0]);    glVertex3fv(&vdata[tindices[13][2]][0]);

    glColor3f( 0.23, 0.56, 0.78);
    glVertex3fv(&vdata[tindices[14][0]][0]);    glVertex3fv(&vdata[tindices[14][1]][0]);
    glVertex3fv(&vdata[tindices[14][2]][0]);    glVertex3fv(&vdata[tindices[15][0]][0]);
    glVertex3fv(&vdata[tindices[15][1]][0]);    glVertex3fv(&vdata[tindices[15][2]][0]);

    glColor3f( 0.59, 0.07, 0.91);
    glVertex3fv(&vdata[tindices[16][0]][0]);    glVertex3fv(&vdata[tindices[16][1]][0]);
    glVertex3fv(&vdata[tindices[16][2]][0]);    glVertex3fv(&vdata[tindices[17][0]][0]);
    glVertex3fv(&vdata[tindices[17][1]][0]);    glVertex3fv(&vdata[tindices[17][2]][0]);

    glColor3f( 0.65, 0.66, 0.72);
    glVertex3fv(&vdata[tindices[18][0]][0]);    glVertex3fv(&vdata[tindices[18][1]][0]);
    glVertex3fv(&vdata[tindices[18][2]][0]);    glVertex3fv(&vdata[tindices[19][0]][0]);
    glVertex3fv(&vdata[tindices[19][1]][0]);    glVertex3fv(&vdata[tindices[19][2]][0]);
    glEnd();
}

void displayPyramid() {
  glTranslatef(eyeX, 0.0f, 0.0f);
  gluLookAt(0.0f, 0.0f, eyeZ,0.0f, 0.0f, 0.0f,0.0f, 1.0f, 0.0f);

  glRotatef( xrot3, 1.0, 0.0, 0.0 );
  glRotatef( yrot3, 0.0, 1.0, 0.0 );

glColor3f(0.3f, 0.7f, 0.5f);
glBegin(GL_QUADS);
glVertex3f(-300.0f, -6.0f, -300.0f);
glVertex3f(-300.0f, -6.0f,  300.0f);
glVertex3f( 300.0f, -6.0f,  300.0f);
glVertex3f( 300.0f, -6.0f, -300.0f);
glEnd();
glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
// Front
glColor3f(1.0f, 0.0f, 0.0f);     // Red
glVertex3f( 0.0f, 0.75f, 0.0f);      glVertex3f(-0.75f, -0.75f, 0.75f);
glVertex3f(0.75f, -0.75f, 0.75f);
// Right
glColor3f(0.0f, 0.0f, 1.0f);     // Blue
glVertex3f(0.0f, 0.75f, 0.0f);      glVertex3f(0.75f, -0.75f, 0.75f);
glVertex3f(0.75f, -0.75f, -0.75f);

// Back
glColor3f(0.0f, 1.0f, 0.0f);     // Green
glVertex3f(0.0f, 0.75f, 0.0f);      glVertex3f(0.75f, -0.75f, -0.75f);
glVertex3f(-0.75f, -0.75f, -0.75f);

// Left
glColor3f(1.0f,1.0f,0.0f);
glVertex3f( 0.0f, 0.75f, 0.0f);    glVertex3f(-0.75f,-0.75f,-0.75f);
glVertex3f(-0.75f,-0.75f, 0.75f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,1.0f);
glVertex3f(-0.75f, -0.75f, -0.75f);
glVertex3f(-0.75f, -0.75f,  0.75f);
glVertex3f( 0.75f, -0.75f,  0.75f);
glVertex3f( 0.75f, -0.75f, -0.75f);
glEnd();   // Done drawing the pyramid
}

void display(){

     gluLookAt(0.0f, 0.0f, eyeZ,0.0f, 0.0f, 0.0f,0.0f, 1.0f, 0.0f);
        glMatrixMode(GL_MODELVIEW);

  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


        srand(time(0));
	for(int j = 0; j < 500; j++) {
	glColor3f(1.0, 1.0, 1.0);
    glPointSize(4.0);
	glBegin(GL_POINTS);
	float x = rand()/10000000.0;
	float y = rand()/10000000.0;
    float z = rand()/10000000.0;
    glVertex3f(x, y, z);
    glVertex3f(x, y, -z);
    glVertex3f(-x, y, z);
    glVertex3f(-x, y, -z);
    glVertex3f(x, -y, z);
    glVertex3f(x, -y, -z);
    glVertex3f(-x, -y, z);
    glVertex3f(-x, -y, -z);
	}
	glEnd();

  // Reset transformations
  glLoadIdentity();
  glColor3f(1.0f, 1.0f, 1.0f);
  glRasterPos2f(-0.8f, 0.64f);
  glutBitmapString(GLUT_BITMAP_HELVETICA_12,(const unsigned char*)"F1: switch to a Cube scene" );

  glRasterPos2f(-0.8f, 0.56f);
  glutBitmapString(GLUT_BITMAP_HELVETICA_12 ,(const unsigned char*)"F2: switch to an Icosahedron scene" );

  glRasterPos2f(-0.8f, 0.48f);
  glutBitmapString(GLUT_BITMAP_HELVETICA_12 ,(const unsigned char*)"F3: switch to a five-faced Pyramid scene" );
  glEnd();

   glRasterPos2f(0.4f, -0.06f);
  glutBitmapString(GLUT_BITMAP_HELVETICA_12 ,(const unsigned char*)"I: Zoom in" );
  glEnd();

   glRasterPos2f(0.4f, -0.14f);
  glutBitmapString(GLUT_BITMAP_HELVETICA_12 ,(const unsigned char*)"K: Zoom out" );
  glEnd();

   glRasterPos2f(0.4f, -0.22f);
  glutBitmapString(GLUT_BITMAP_HELVETICA_12 ,(const unsigned char*)"J: Strafe left" );
  glEnd();

   glRasterPos2f(0.4f, -0.3f);
  glutBitmapString(GLUT_BITMAP_HELVETICA_12 ,(const unsigned char*)"L: Strafe right" );
  glEnd();

   glRasterPos2f(0.4f, -0.38f);
  glutBitmapString(GLUT_BITMAP_HELVETICA_12 ,(const unsigned char*)"R: Reset position" );
  glEnd();

  if(flag == 1)
    displayCube();
  if(flag == 2)
    displayIcosahedron();
   if(flag == 3)
    displayPyramid();
  glFlush();
  glutSwapBuffers();
}

void specialKeys( int key, int x1, int y1) {
{/*  if (key == GLUT_KEY_RIGHT && flag == 1)
    rotate_y += 5;
  else if (key == GLUT_KEY_LEFT && flag == 1)
    rotate_y -= 5;
  else if (key == GLUT_KEY_UP && flag == 1)
    rotate_x += 5;
  else if (key == GLUT_KEY_DOWN && flag == 1)
    rotate_x -= 5;
    // Icosahedron
  if (key == GLUT_KEY_RIGHT && flag == 2)
    yrot += 5;
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT && flag == 2)
    yrot -= 5;
  else if (key == GLUT_KEY_UP && flag == 2)
    xrot += 5;
  else if (key == GLUT_KEY_DOWN && flag == 2)
    xrot -= 5;*/}
    if (key == GLUT_KEY_F1)
    flag = 1;

    if (key == GLUT_KEY_F2)
    flag = 2;

    if (key == GLUT_KEY_F3)
    flag = 3;

    glFlush();
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x  ,int y){
    if (key == 'j'){
    eyeX +=0.5;
    cout << "J pressed\n";
    }

    if (key == 'l'){
    eyeX -= 0.5;
    cout << "L pressed\n";
    }

    if (key == 'i'){
    eyeZ -= 1.0;
    cout << "I pressed\n";
    }


    if (key == 'k'){
    eyeZ += 1.0;
    cout << "K pressed\n";
    }

    if (key == 'r'){
    eyeX = 0.0f;
    eyeZ = 2.0f;
    xrot1 =0.0f;
    yrot1 =0.0f;
    xrot2 =0.0f;
    yrot2 =0.0f;
    xrot3 =0.0f;
    yrot3 =0.0f;
    cout << "R pressed\n";
    }
      glFlush();
    glutPostRedisplay();
}


void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON & state == GLUT_DOWN && flag == 1) {
        mouseDown = true;
        xdiff1 = x - yrot1;
        ydiff1 = -y + xrot1;
    }
    else if (button == GLUT_LEFT_BUTTON & state == GLUT_DOWN && flag == 2) {
        mouseDown = true;
        xdiff2 = x - yrot2;
        ydiff2 = -y + xrot2;
    }
    else if (button == GLUT_LEFT_BUTTON & state == GLUT_DOWN && flag == 3) {
        mouseDown = true;
        xdiff3 = x - yrot3;
        ydiff3 = -y + xrot3;
    }

    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown && flag == 1) {
        yrot1 = x - xdiff1;
        xrot1 = y + ydiff1;
        glutPostRedisplay();
    }
    if (mouseDown && flag == 2) {
        yrot2 = x - xdiff2;
        xrot2 = y + ydiff2;
        glutPostRedisplay();
    }
    if (mouseDown && flag == 3) {
        yrot3 = x - xdiff3;
        xrot3 = y + ydiff3;
        glutPostRedisplay();
    }
  printf("rotate_x: %d\n", &xdiff1);
  printf("rotate_y: %d\n", &ydiff1);
  printf("xrot: %d\n", &xdiff2);
  printf("yrot: %d\n", &ydiff2);
  printf("xrot: %d\n", &xdiff3);
  printf("yrot: %d\n", &ydiff3);
}

void resize(int w, int h) {
	if(h == 0)
		h = 1;
	float ratio = 1.0* w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45,ratio,1,1000);
}

int main(int argc, char* argv[]){
  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);
  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  // Create window
  glutInitWindowSize(600, 600);
  glutCreateWindow("Scene-Viewer-freeglut");
  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);
  // Enable Lighting
  float ambient[]={1.0,1.0,1.0,1.0};
  float light_pos1[]={27,80,2,3};
  float light_pos2[]={-27,-80,-2,-3};
  float  light_pos3[] ={1, 1, 2, 3};
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_COLOR_MATERIAL);
{
GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat _light_position[] = {1.0, 1.0, 1.0, 1.0};
GLfloat _spotlight_position[] = {0.0, -1.0, 0.0};
glLightfv(GL_LIGHT0, GL_POSITION, _light_position);
}
  // Enable lighting on color
  glEnable(GL_COLOR_MATERIAL);
  // Callback functions
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  glutMotionFunc(mouseMotion);
  glutReshapeFunc(resize);
  //  Pass control to GLUT for events
  glutMainLoop();
  //  Return to OS
  return 0;
}
