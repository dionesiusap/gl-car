#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <GL/glu.h>
#include <iostream>

using namespace std;

GLfloat xRotated, yRotated, zRotated;
GLfloat scale;
GLuint tex;
GLdouble size=1.0;
void display(void);

void idle(void) {
    display();
}

void make_tex(void)
{
    // GLuint loadBMP_custom(const char * imagepath);
    // GLuint image = loadBMP_custom("./my_texture.bmp");
    // Data read from the header of the BMP file
    unsigned char header[54]; // Each BMP file begins by a 54-bytes header
    unsigned int dataPos;     // Position in the file where the actual data begins
    unsigned int width, height;
    unsigned int imageSize;   // = width*height*3
    // Actual RGB data
    unsigned char * data;

    FILE * file = fopen("./Image9.bmp","rb");
    if (!file){printf("Image could not be opened\n"); /*return 0;*/}
    if ( fread(header, 1, 54, file)!=54 ){ // If not 54 bytes read : problem
        printf("Not a correct BMP file\n");
        // return false;
    }

    // Read ints from the byte array
    dataPos    = *(int*)&(header[0x0A]);
    imageSize  = *(int*)&(header[0x22]);
    width      = *(int*)&(header[0x12]);
    height     = *(int*)&(header[0x16]);

    // Some BMP files are misformatted, guess missing information
    if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
    if (dataPos==0)      dataPos=54; // The BMP header is done that way

    // Create a buffer
    data = new unsigned char [imageSize];

    // Read the actual data from the file into the buffer
    fread(data,1,imageSize,file);

    //Everything is in memory now, the file can be closed
    fclose(file);

    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
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
    glScalef(scale, scale, scale);
    // glScalef(1.25,1.0,1.0);
    glTranslatef(-0.5,0,0);
    glutSolidCube(size);

    glTranslatef(0.7,-0.25,0.0);
    glScalef(1.0/1.25,1.0,2.0);
    glutSolidCube(0.5);

    GLUquadricObj *disk;
    disk = gluNewQuadric();
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();

    glTranslatef(-0.25,-0.3,0.2);
    glRotatef(0.0f, 90.0f, 1.0f, 0.0f);
    gluQuadricDrawStyle(quadratic, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, tex);
    gluQuadricTexture(quadratic, GL_TRUE);
    gluQuadricNormals(quadratic, GLU_SMOOTH);
    gluQuadricDrawStyle(disk, GLU_FILL);
    // glBindTexture(GL_TEXTURE_2D, tex);
    gluQuadricTexture(disk, GL_TRUE);
    gluQuadricNormals(disk, GLU_SMOOTH);
    gluCylinder(quadratic, 0.15f, 0.15f, 0.1f, 32, 32);
    gluDisk(disk, 0, 0.15, 32, 32);
    glTranslatef(0,0,0.1);
    gluDisk(disk, 0, 0.15, 32, 32);
    glTranslatef(0,0,-0.1);

    glTranslatef(-0.75,0,0);
    glRotatef(0.0f, 90.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.15f, 0.15f, 0.1f, 32, 32);
    gluDisk(disk, 0, 0.15, 32, 32);
    glTranslatef(0,0,0.1);
    gluDisk(disk, 0, 0.15, 32, 32);
    glTranslatef(0,0,-0.1);

    glTranslatef(0,0,-0.5);
    glRotatef(0.0f, 90.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.15f, 0.15f, 0.1f, 32, 32);
    gluQuadricOrientation(disk, GLU_OUTSIDE);
    gluDisk(disk, 0, 0.15, 32, 32);
    glTranslatef(0,0,0.1);
    gluDisk(disk, 0, 0.15, 32, 32);
    glTranslatef(0,0,-0.1);

    glTranslatef(0.75,0,0);
    glRotatef(0.0f, 90.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.15f, 0.15f, 0.1f, 32, 32);
    gluDisk(disk, 0, 0.15, 32, 32);
    glTranslatef(0,0,0.1);
    gluDisk(disk, 0, 0.15, 32, 32);
    glTranslatef(0,0,-0.1);

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

void init(void) {
    glEnable(GL_DEPTH_TEST);
    make_tex();
    glEnable(GL_TEXTURE_2D);
}

void keyPressed (unsigned char key, int x, int y) {  
    if (key == 'a') {
        yRotated -= 1;
    } else if (key == 'd') {
        yRotated += 1;
    } else if (key == 'w') {
        xRotated -= 1;
    } else if (key == 's') {
        xRotated += 1;
    } else if (key == 'e') {
        zRotated -= 1;
    } else if (key == 'q') {
        zRotated += 1;
    } else if (key == '=') {
        scale += 0.05;
    } else if (key == '-') {
        scale -= 0.05;
    }
}

int main(int argc,char** argv) {
	glutInit(&argc,argv);
    glutInitWindowSize (640,480);
    glutInitWindowPosition (200,200);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
    xRotated = 10.0;
    yRotated = 30.0;
    zRotated = 0.0;
    scale = 1;
	glutCreateWindow("MOBILBOXBANGST");
    glutDisplayFunc(display);
    glutReshapeFunc (myReshape);
    fuckingshitwtf();
    glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses  
	glutIdleFunc(idle);
    init();
    glutMainLoop();
}
