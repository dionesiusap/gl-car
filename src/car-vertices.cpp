#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795

bool mouseClick = false;

float rot_x = 0.0f;
float rot_y = 0.0f;

float dx = 0.0f;
float dy = 0.0f;

// Initializes OpenGL
bool init(float r, float g, float b)
{
    GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = {-2.0, 2.0, 2.0, 0.0};

    glClearColor(r, g, b, 0.0);
    glClearDepth(1.0f);

    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    return true;
}

// function to draw cube
void DrawCar(void)
{

    glTranslatef(0, -0.75, 0);
    glBegin(GL_QUADS);
    glPolygonMode(GL_FRONT, GL_FILL);
    glColor3f(0.0f, 0.0f, 1.0f);

    // BOTTOM
    glVertex3f(-0.5f, 0.0f, 0.875f);
    glVertex3f(-0.5f, 0.0f, -0.875f);
    glVertex3f(2.0f, 0.0f, -0.875f);
    glVertex3f(2.0f, 0.0f, 0.875f);

    // TOP
    glVertex3f(0.0f, 1.5f, 0.875f);
    glVertex3f(2.0f, 1.5f, 0.875f);
    glVertex3f(2.0f, 1.5f, -0.875f);
    glVertex3f(0.0f, 1.5f, -0.875f);

    // FRONT
    glVertex3f(-0.5f, 0.0f, 0.875f);
    glVertex3f(0.0f, 1.5f, 0.875f);
    glVertex3f(0.0f, 1.5f, -0.875f);
    glVertex3f(-0.5f, 0.0f, -0.875f);

    // BACK
    glVertex3f(2.0f, 0.0f, 0.875f);
    glVertex3f(2.0f, 0.0f, -0.875f);
    glVertex3f(2.0f, 1.5f, -0.875f);
    glVertex3f(2.0f, 1.5f, 0.875f);

    // LEFT
    glVertex3f(-0.5f, 0.0f, -0.875f);
    glVertex3f(2.0f, 0.0f, -0.875f);
    glVertex3f(2.0f, 1.5f, -0.875f);
    glVertex3f(0.0f, 1.5f, -0.875f);

    // RIGHT
    glVertex3f(-0.5f, 0.0f, 0.875f);
    glVertex3f(0.0f, 1.5f, 0.875f);
    glVertex3f(2.0f, 1.5f, 0.875f);
    glVertex3f(2.0f, 0.0f, 0.875f);
    glEnd();

    glBegin(GL_QUADS);
    glPolygonMode(GL_FRONT, GL_FILL);
    glColor3f(0.0f, 0.0f, 1.0f);

    // BOTTOM
    glVertex3f(-1.0f, 0.0f, 0.875f);
    glVertex3f(-1.0f, 0.0f, -0.875f);
    glVertex3f(0.0f, 0.0f, -0.875f);
    glVertex3f(0.0f, 0.0f, 0.875f);

    // TOP
    glVertex3f(-1.0f, 0.65f, 0.875f);
    glVertex3f(0.0f, 0.9f, 0.875f);
    glVertex3f(0.0f, 0.9f, -0.875f);
    glVertex3f(-1.0f, 0.65f, -0.875f);

    // FRONT
    glVertex3f(-1.0f, 0.0f, 0.875f);
    glVertex3f(-1.0f, 0.65f, 0.875f);
    glVertex3f(-1.0f, 0.65f, -0.875f);
    glVertex3f(-1.0f, 0.0f, -0.875f);

    // BACK
    glVertex3f(0.0f, 0.0f, 0.875f);
    glVertex3f(0.0f, 0.0f, -0.875f);
    glVertex3f(0.0f, 0.9f, -0.875f);
    glVertex3f(0.0f, 0.9f, 0.875f);

    // LEFT
    glVertex3f(-1.0f, 0.0f, -0.875f);
    glVertex3f(0.0f, 0.0f, -0.875f);
    glVertex3f(0.0f, 0.9f, -0.875f);
    glVertex3f(-1.0f, 0.65f, -0.875f);

    // RIGHT
    glVertex3f(-1.0f, 0.0f, 0.875f);
    glVertex3f(-1.0f, 0.65f, 0.875f);
    glVertex3f(0.0f, 0.9f, 0.875f);
    glVertex3f(0.0f, 0.0f, 0.875f);
    glEnd();
}

// callback function for glutDisplayFunc()
// will display a rotating cube with circle on the background
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    gluLookAt(
        0.0f, 0.0f, 3.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f);

    glRotatef(rot_x, 0.0f, 1.0f, 0.0f);
    glRotatef(rot_y, 1.0f, 0.0f, 0.0f);

    DrawCar();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

// callback function for glutReshapeFunc()
void reshape(int w, int h)
{
    // transformation will be applied on projection matrix
    // switch to projection matrix stack
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);

    gluPerspective(63.4f, 1.0f * w / h, 1.0f, 100.0f);

    // switch back to modelview matrix stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// callback function for glutMouseFunc()
// checks if left button is clicked or not
void onMouseClick(int button, int state, int x, int y)
{
    // if left button is clicked
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseClick = true;

        dx = x - rot_x;
        dy = -y + rot_y;
    }
    else
    {
        mouseClick = false;
    }
}

// callback function for glutMotionFunc()
void mouseMovement(int x, int y)
{
    // if left button is clicked then rotate cube based on movement
    if (mouseClick)
    {
        rot_x = x - dx;
        rot_y = y + dy;

        glutPostRedisplay();
    }
}

// if idle (mouse not cliked) add a little rotation to the cube
void rotateIdle(void)
{
    if (!mouseClick)
    {
        rot_x += 0.3f;
        rot_y += 0.0f;
    }

    glutPostRedisplay();
}

// callback function for glutKeyboardFunc()
void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(1);
        break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitWindowPosition(50, 50);
    glutInitWindowSize(640, 480);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutCreateWindow("Rotating Cube");

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(onMouseClick);
    glutMotionFunc(mouseMovement);
    glutReshapeFunc(reshape);
    glutIdleFunc(rotateIdle);

    if (!init(0.0f, 0.0f, 0.0f))
    {
        return 1;
    }

    glutMainLoop();

    return 0;
}
