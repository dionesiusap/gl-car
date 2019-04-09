#include <GL/glut.h>
#include <math.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble size=1.0;
void display(void);

void idle(void) {
	// xRotated = xRotated + 0.01;
	yRotated += 0.01;
    // zRotated += 0.01; 
    display();
}

void fuckingshitwtf() {
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void display(void) {
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    // rotation about X axis
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation
    glScalef(1.25,1.0,1.0);
    glTranslatef(-0.5,0,0);
    glutSolidCube(size);

    glTranslatef(0.7,-0.25,0.0);
    glScalef(1.0/1.25,1.0,2.0);
    glutSolidCube(0.5);

    glFlush();
   glutSwapBuffers();
}

void myReshape(GLsizei w, GLsizei h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-1.5, 1.5, -1.5*(GLfloat)480/(GLfloat)640, 
        1.5*(GLfloat)480/(GLfloat)640, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    //glViewport(0,0,w,h);  //Use the whole window for rendering
    glLoadIdentity();
}


int main(int argc,char** argv) {
	glutInit(&argc,argv);
    glutInitWindowSize (640,480);
    glutInitWindowPosition (200,200);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
    xRotated = 10.0;
    yRotated = 30.0;
    zRotated = 0.0;
	glutCreateWindow("MOBILBOXBANGST");
    glutDisplayFunc(display);
    glutReshapeFunc (myReshape);
    fuckingshitwtf();
	glutIdleFunc(idle);
    glutMainLoop();
}
