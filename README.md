#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

#define FPS 120
#define TO_RADIANS 3.14/180.0

//  Anggota Kelompok X
//  Chresto Tumbilung (672020229)
//  Marcelinus Yusgon M. M. (672020328)
//  Jeremy Victorinda M. T. (672017228)
//  Erlangga Wisnu Murti (672017233)
//  Mario Philson Soparue (672017213)

const int width = 1000;
const int height = 600;
int i;
float sudut;
double x_geser, y_geser, z_geser;

float pitch = 0.0, yaw = 0.0;
float camX = 0.0, camZ = 0.0, terbang = 25.0;

void display();
void reshape(int w, int h);
void timer(int);
void passive_motion(int, int);
void camera();
void keyboard(unsigned char key, int x, int y);
void keyboard_up(unsigned char key, int x, int y);

struct Motion {
    bool Forward, Backward, Left, Right, Naik, Turun;
};
Motion motion = { false,false,false,false,false,false };

void init() {
    glClearColor(0.529, 0.807, 0.921, 0.0);
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}

void ground() {
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-1000.0, 0, -1000.0);

    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(1000.0, 0, -1000.0);

    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(1000.0, 0, 1000.0);

    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-1000.0, 0, 1000.0);
    glEnd();
}

void lantai1() {
    glColor3f(0.95f, 0.95f, 0.95f);
    glutWireCube(20.0);
    glutSolidCube(500.0);
    glColor3f(1.0f, 0.58f, 0.0f);
    glutWireCube(501.0);
    //pintu
    glPushMatrix();
    glTranslatef(-15, -7.5, 0.5);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.58f, 0.0f);
    glVertex3f(-30, 200, 250);
    glVertex3f(-30, 0, 250);
    glVertex3f(90, 0, 250);
    glVertex3f(90, 200, 250);
    glEnd();
    glPopMatrix();

    // kanan jendela
    glPushMatrix();
    glTranslatef(135.5, 92.5, 0.5);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-30, 100, 250);
    glVertex3f(-30, 0, 250);
    glVertex3f(80, 0, 250);
    glVertex3f(80, 100, 250);
    glEnd();
    glPopMatrix();

    // kiri jendela
    glPushMatrix();
    glTranslatef(-153.5, 92.5, 0.5);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-30, 100, 250);
    glVertex3f(-30, 0, 250);
    glVertex3f(80, 0, 250);
    glVertex3f(80, 100, 250);
    glEnd();
    glPopMatrix();
    ground();
    cout << "X_GESER =" << x_geser << " Y_GESER =" << y_geser << " Z_GESER =" << z_geser << endl;
    glFlush();
}

void pagar_lantai1() {

}

void lantai2(){
    glPushMatrix();
    glTranslatef(0,286, -49);
    glColor3f(0.96f, 0.96f, 0.96f);
    glutSolidCube(400.0);
    glColor3f(1.0f, 0.58f, 0.0f);
    glutWireCube(401.0);
    glPopMatrix();
    //jendela kiri
    glPushMatrix();
    glTranslatef(-141, 326,-98);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-30, 80, 250);
    glVertex3f(-30, 0, 250);
    glVertex3f(60, 0, 250);
    glVertex3f(60, 80, 250);
    glEnd();
    glPopMatrix();

    // kanan jendela
    glPushMatrix();
    glTranslatef(118, 327, -97);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-30, 80, 250);
    glVertex3f(-30, 0, 250);
    glVertex3f(60, 0, 250);
    glVertex3f(60, 80, 250);
    glEnd();
    glPopMatrix();
    //pintu
    glPushMatrix();
    glTranslatef(- 32, 167,-97);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.58f, 0.0f);
    glVertex3f(-30, 200, 250);
    glVertex3f(-30, 0, 250);
    glVertex3f(90, 0, 250);
    glVertex3f(90, 200, 250);
    glEnd();
    glPopMatrix();
    cout << "X_GESER =" << x_geser << " Y_GESER =" << y_geser << " Z_GESER =" << z_geser << endl;
    glFlush();
}
void lantai3() {
    glPushMatrix();
    glTranslatef(0, 540, - 56);
    glColor3f(0.97f, 0.97f, 0.97f);
    glutSolidCube(320.0);
    glColor3f(1.0f, 0.58f, 0.0f);
    glutWireCube(321.0);
    glPopMatrix();
    //jendela kiri
    glPushMatrix();
    glTranslatef(90, 595, -145);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-30, 50, 250);
    glVertex3f(-30, 0, 250);
    glVertex3f(50, 0, 250);
    glVertex3f(50, 50, 250);
    glEnd();
    glPopMatrix();
    // kanan jendela
    glPushMatrix();
    glTranslatef(-108, 595, -145);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-30, 50, 250);
    glVertex3f(-30, 0, 250);
    glVertex3f(50, 0, 250);
    glVertex3f(50, 50, 250);
    glEnd();
    glPopMatrix();
    //pintu
    glPushMatrix();
    glTranslatef(-29, 385, -145);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.58f, 0.0f);
    glVertex3f(-30, 195, 250);
    glVertex3f(-30, 0, 250);
    glVertex3f(85, 0, 250);
    glVertex3f(85, 195, 250);
    glEnd();
    glPopMatrix();

    cout << "X_GESER =" << x_geser << " Y_GESER =" << y_geser << " Z_GESER =" << z_geser << endl;
    glFlush();

}
void draw() {
    lantai1();
    lantai2();
    lantai3();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();
    draw();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 16.0 / 9.0, 2, 10000);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
    glutPostRedisplay();
    glutWarpPointer(width / 2, height / 2);
    glutTimerFunc(1000 / FPS, timer, 0);
}

void passive_motion(int x, int y) {
    int dev_x, dev_y;
    dev_x = (width / 2) - x;
    dev_y = (height / 2) - y;
    yaw += (float)dev_x / 20.0;
    pitch += (float)dev_y / 20.0;
}

void camera() {
    if (motion.Forward) {
        camX += cos((yaw + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90) * TO_RADIANS) * 2;
    }
    if (motion.Backward) {
        camX += cos((yaw + 90 + 180) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 180) * TO_RADIANS) * 2;
    }
    if (motion.Left) {
        camX += cos((yaw + 90 + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 90) * TO_RADIANS) * 2;
    }
    if (motion.Right) {
        camX += cos((yaw + 90 - 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 - 90) * TO_RADIANS) * 2;
    }
    if (motion.Naik) {
        terbang -= 2.0;
    }
    if (motion.Turun) {
        terbang += 2.0;
    }

    if (pitch >= 70)
        pitch = 70;
    if (pitch <= -90)
        pitch = -90;


    glRotatef(-pitch, 1.0, 0.0, 0.0);
    glRotatef(-yaw, 0.0, 1.0, 0.0);

    glTranslatef(-camX, -terbang, -350 - camZ);
    if (terbang < 25)
        terbang = 24;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = true;
        break;
    case 'A':
    case 'a':
        motion.Left = true;
        break;
    case 'S':
    case 's':
        motion.Backward = true;
        break;
    case 'D':
    case 'd':
        motion.Right = true;
        break;
    case 'E':
    case 'e':
        motion.Naik = true;
        break;
    case 'Q':
    case 'q':
        motion.Turun = true;
        break;
    case '=':
        x_geser += 1.0;
        break;
    case '-':
        x_geser -= 1.0;
        break;
    case '1':
        y_geser += 1.0;
        break;
    case '2':
        y_geser -= 1.0;
        break;
    case '3':
        z_geser -= 1.0;
        break;
    case '4':
        z_geser += 1.0;
        break;
    case '`': // KELUAR DARI PROGRAM
        exit(1);
    }
}

void keyboard_up(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = false;
        break;
    case 'A':
    case 'a':
        motion.Left = false;
        break;
    case 'S':
    case 's':
        motion.Backward = false;
        break;
    case 'D':
    case 'd':
        motion.Right = false;
        break;
    case 'E':
    case 'e':
        motion.Naik = false;
        break;
    case 'Q':
    case 'q':
        motion.Turun = false;
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("TR GRAFKOM KELOMPOK 9");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);

    glutMainLoop();
    return 0;
}
