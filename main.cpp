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

const int width = 1280;
const int height = 720;
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
    glColor3f(0.02f, 0.51f, 0.1f);
    glVertex3f(-1000.0, 0, -1000.0);

    glColor3f(0.02f, 0.51f, 0.1f);
    glVertex3f(1000.0, 0, -1000.0);

    glColor3f(0.02f, 0.51f, 0.1f);
    glVertex3f(1000.0, 0, 1000.0);

    glColor3f(0.02f, 0.51f, 0.1f);
    glVertex3f(-1000.0, 0, 1000.0);
    glEnd();
}
void ground2() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.53f, 0.0f);
    glVertex3f(-450.0, 0, -450.0);

    glColor3f(1.0f, 0.53f, 0.0f);
    glVertex3f(450.0, 0, -450.0);

    glColor3f(1.0f, 0.53f, 0.0f);
    glVertex3f(450.0, 0, 450.0);

    glColor3f(1.0f, 0.53f, 0.0f);
    glVertex3f(-450.0, 0, 450.0);
    glEnd();
}
void lantai_dasar() {
    glPushMatrix();
    glTranslatef(0, -511.5, 24);
    glColor3f(0.67f, 0.73f, 0.71f);
    glutSolidCube(1270.0);
    glPopMatrix();
    //tangga 1
    glPushMatrix();
    glTranslatef(0, -55.5, 533);
    glColor3f(0.8f, 0.84f, 0.8f);
    glutSolidCube(300.0);
    glPopMatrix();
    //tangga 2
    glPushMatrix();
    glTranslatef(0, -79.5, 564);
    glColor3f(0.83f, 0.85f, 0.84f);
    glutSolidCube(300.0);
    glPopMatrix();
    //tangga 3
    glPushMatrix();
    glTranslatef(0, -109.5, 603);
    glColor3f(0.85f, 0.87f, 0.85f);
    glutSolidCube(300.0);
    glPopMatrix();
    //tangga 4
    glPushMatrix();
    glTranslatef(0, -130.5, 654);
    glColor3f(0.9f, 0.9f, 0.9f);
    glutSolidCube(300.0);
    glPopMatrix();
    //tangga 5
    glPushMatrix();
    glTranslatef(0, -148.5, 711);
    glColor3f(0.89f, 0.91f, 0.89f);
    glutSolidCube(300.0);
    glPopMatrix();
    cout << "X_GESER =" << x_geser << " Y_GESER =" << y_geser << " Z_GESER =" << z_geser << endl;
    glFlush();
}
void atap() {
    glBegin(GL_TRIANGLES); //hitam
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(-550, 650, -516); //samping,tinggi,lebar 616
    glVertex3f(-550, 650, 504);
    glVertex3f(0, 800, 0);

    glEnd();

    glBegin(GL_TRIANGLES); //putih
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(-550, 650, 504);
    glVertex3f(550, 650, 504);
    glVertex3f(0, 800, 0);

    glEnd();

    glBegin(GL_TRIANGLES); //merah
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(550, 650, -516);
    glVertex3f(550, 650, 504);
    glVertex3f(0, 800, 0);
    glEnd();


    glBegin(GL_TRIANGLES); //biru
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(550, 650, -516);
    glVertex3f(-550, 650, -516);
    glVertex3f(0, 800, 0);

    glEnd();
}
void lantai1() {
    glPushMatrix();
    glTranslatef(0, 113, 0);
    glColor3f(0.78f, 0.78f, 0.78f);
    glutSolidCube(800.0);
    glColor3f(1.0f, 0.58f, 0.0f);
    glutWireCube(801.0);
    glPopMatrix();


    //lantai
    glPushMatrix();
    glTranslatef(0, 515, 0);
    ground2();
    glPopMatrix();
    //atap
    glPushMatrix();
    glTranslatef(0, -196, 0);
    atap();
    glPopMatrix();
    ground();
    //bulat 1
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(528, 403.5, 487);
    glutSolidSphere(50, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(51, 30, 15);

    glPopMatrix();
    //bulat 2
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(-548, 403.5, 501);
    glutSolidSphere(50, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(51, 30, 15);

    glPopMatrix();
    //bulat 3
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(-536, 402, -508);
    glutSolidSphere(50, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(51, 30, 15);

    glPopMatrix();
    //bulat4
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(544, 403.5, -519);
    glutSolidSphere(50, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(51, 30, 15);

    glPopMatrix();
    //bulat up 1
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(396, 925.5, -410);
    glutSolidSphere(40,30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(41, 30, 15);

    glPopMatrix();
    //bulat up 2
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(-399, 924, -412);
    glutSolidSphere(40, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(41, 30, 15);

    glPopMatrix();
    //bulat up 3
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(395, 921, 401);
    glutSolidSphere(40, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(41, 30, 15);

    glPopMatrix();
    //bulat up 4
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(-392, 924, 402);
    glutSolidSphere(40, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(41, 30, 15);

    glPopMatrix();
    //bulat up up 1
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(-340, 1315.5, -315);
    glutSolidSphere(35, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(36, 30, 15);
    glPopMatrix();

    //bulat up up 2
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(346, 1315.5, -313);
    glutSolidSphere(35, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(36, 30, 15);
    glPopMatrix();

    //bulat up up 3
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(-341, 1315.5, 296);
    glutSolidSphere(35, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(36, 30, 15);
    glPopMatrix();

    //bulat up up 4
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(349, 1314, 306);
    glutSolidSphere(35, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(36, 30, 15);
    glPopMatrix();

    //bulat up up up 1
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(-248, 1765.5, -284);
    glutSolidSphere(25, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(26, 30, 15);
    glPopMatrix();

    //bulat up up up 2
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(247, 1767, -278);
    glutSolidSphere(25, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(26, 30, 15);
    glPopMatrix();

    //bulat up up up 3
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(252, 1767, 236);
    glutSolidSphere(25, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(26, 30, 15);
    glPopMatrix();

    //bulat up up up 4
    glPushMatrix();
    glColor3f(0.89f, 0.2f, 0.2f);
    glTranslatef(-249, 1768.5, 245);
    glutSolidSphere(25, 30, 180);
    glColor3f(0.88f, 1.0f, 0.0f);
    glutWireSphere(26, 30, 15);
    glPopMatrix();

    //pintu
    glPushMatrix();
    glTranslatef( -21, 123, 151);
    glBegin(GL_QUADS);
    glColor3f(0.56f, 0.44f, 0.1f);
    glVertex3f(-30, 195, 250);
    glVertex3f(-30, 0, 250);
    glVertex3f(85, 0, 250);
    glVertex3f(85, 195, 250);
    glEnd();
    glPopMatrix();

    //pintu
    glPushMatrix();
    glTranslatef(-24, 516, 86);
    glBegin(GL_QUADS);
    glColor3f(0.56f, 0.44f, 0.1f);
    glVertex3f(-20, 185, 240);
    glVertex3f(-20, 0, 240);
    glVertex3f(75, 0, 240);
    glVertex3f(75, 185, 240);
    glEnd();
    glPopMatrix();

    //pintu
    glPushMatrix();
    glTranslatef(-26, 1033.5, -6);
    glBegin(GL_QUADS);
    glColor3f(0.56f, 0.44f, 0.1f);
    glVertex3f(-15, 185, 235);
    glVertex3f(-15, 0, 235);
    glVertex3f(65, 0, 235);
    glVertex3f(65, 185, 235);
    glEnd();
    glPopMatrix();

    //pintu
    glPushMatrix();
    glTranslatef(-24, 1423.5, 1);
    glBegin(GL_QUADS);
    glColor3f(0.56f, 0.44f, 0.1f);
    glVertex3f(-10, 185, 225);
    glVertex3f(-10, 0, 225);
    glVertex3f(55, 0, 225);
    glVertex3f(55, 185, 225);
    glEnd();
    glPopMatrix();

    // jendela
    glPushMatrix();
    glTranslatef(-195, 289.5, 152);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-70, 90, 250);
    glVertex3f(-70, 0, 250);
    glVertex3f(70, 0, 250);
    glVertex3f(70, 90, 250);
    glEnd();
    glPopMatrix();

    // jendela
    glPushMatrix();
    glTranslatef(211, 291, 151);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-70, 90, 250);
    glVertex3f(-70, 0, 250);
    glVertex3f(70, 0, 250);
    glVertex3f(70, 90, 250);
    glEnd();
    glPopMatrix();

    // jendela
    glPushMatrix();
    glTranslatef(-139, 748.5, 87);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-60, 90, 240);
    glVertex3f(-60, 0, 240);
    glVertex3f(60, 0, 240);
    glVertex3f(60, 90, 240);
    glEnd();
    glPopMatrix();

    // jendela
    glPushMatrix();
    glTranslatef(159, 742.5, 95);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-60, 90, 240);
    glVertex3f(-60, 0, 240);
    glVertex3f(60, 0, 240);
    glVertex3f(60, 90, 240);
    glEnd();
    glPopMatrix();

    // jendela
    glPushMatrix();
    glTranslatef(-97, 1242, -2);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-50, 90, 230);
    glVertex3f(-50, 0, 230);
    glVertex3f(50, 0, 230);
    glVertex3f(50, 90, 230);
    glEnd();
    glPopMatrix();

    // jendela
    glPushMatrix();
    glTranslatef(87, 1240.5, 1);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-50, 90, 230);
    glVertex3f(-50, 0, 230);
    glVertex3f(50, 0, 230);
    glVertex3f(50, 90, 230);
    glEnd();
    glPopMatrix();

    // jendela
    glPushMatrix();
    glTranslatef(-95, 1632, 6);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-40, 90, 220);
    glVertex3f(-40, 0, 220);
    glVertex3f(40, 0, 220);
    glVertex3f(40, 90, 220);
    glEnd();
    glPopMatrix();

    // jendela
    glPushMatrix();
    glTranslatef(97, 1632, 6);
    glBegin(GL_QUADS);
    glColor3f(0.92f, 0.96f, 0.84f);
    glVertex3f(-40, 90, 220);
    glVertex3f(-40, 0, 220);
    glVertex3f(40, 0, 220);
    glVertex3f(40, 90, 220);
    glEnd();
    glPopMatrix();

    cout << "X_GESER =" << x_geser << " Y_GESER =" << y_geser << " Z_GESER =" << z_geser << endl;
    glFlush();
}
void ground3() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.53f, 0.0f);
    glVertex3f(-350.0, 0, -350.0);

    glColor3f(1.0f, 0.53f, 0.0f);
    glVertex3f(350.0, 0, -350.0);

    glColor3f(1.0f, 0.53f, 0.0f);
    glVertex3f(350.0, 0, 350.0);

    glColor3f(1.0f, 0.53f, 0.0f);
    glVertex3f(-350.0, 0, 350.0);
    glEnd();
}
void atap2() {
    glBegin(GL_TRIANGLES); //hitam
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(-400, 650, -416); //samping,tinggi,lebar 616
    glVertex3f(-400, 650, 404);
    glVertex3f(0, 800, 0);

    glEnd();

    glBegin(GL_TRIANGLES); //putih
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(-400, 650, 404);
    glVertex3f(400, 650, 404);
    glVertex3f(0, 800, 0);

    glEnd();

    glBegin(GL_TRIANGLES); //merah
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(400, 650, -416);
    glVertex3f(400, 650, 404);
    glVertex3f(0, 800, 0);
    glEnd();


    glBegin(GL_TRIANGLES); //biru
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(400, 650, -416);
    glVertex3f(-400, 650, -416);
    glVertex3f(0, 800, 0);

    glEnd();
}
void lantai2() {
    glPushMatrix();
    glTranslatef(0, 709, 0);
    glColor3f(0.78f, 0.78f, 0.78f);
   glutSolidCube(650.0);
    glColor3f(1.0f, 0.58f, 0.0f);
    glutWireCube(651.0);
    glPopMatrix();
    //lantai
    glPushMatrix();
    glTranslatef(0, 1035,0);
    ground3();
    glPopMatrix();
    //atap
    glPushMatrix();
    glTranslatef(0, 315, 0);
    atap2();
    glPopMatrix();

    cout << "X_GESER =" << x_geser << " Y_GESER =" << y_geser << " Z_GESER =" << z_geser << endl;
    glFlush();
}
void ground4() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.53f, 0.0f);
    glVertex3f(-350.0, 0, -350.0);

    glColor3f(1.0f, 0.53f, 0.0f);
    glVertex3f(350.0, 0, -350.0);

    glColor3f(1.0f, 0.53f, 0.0f);
    glVertex3f(350.0, 0, 350.0);

    glColor3f(1.0f, 0.53f, 0.0f);
    glVertex3f(-350.0, 0, 350.0);
    glEnd();
}
void atap3() {
    glBegin(GL_TRIANGLES); //hitam
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(-350, 650, -316);
    glVertex3f(-350, 650, 304);
    glVertex3f(0, 800, 0);

    glEnd();

    glBegin(GL_TRIANGLES); //putih
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(-350, 650, 304);
    glVertex3f(350, 650, 304);
    glVertex3f(0, 800, 0);

    glEnd();

    glBegin(GL_TRIANGLES); //merah
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(350, 650, -316);
    glVertex3f(350, 650, 304);
    glVertex3f(0, 800, 0);
    glEnd();


    glBegin(GL_TRIANGLES); //biru
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(350, 650, -316);
    glVertex3f(-350, 650, -316);
    glVertex3f(0, 800, 0);

    glEnd();
}
void lantai3(){
    glPushMatrix();
    glTranslatef(0, 1192, 0);
    glColor3f(0.78f, 0.78f, 0.78f);
    glutWireCube(450.0);
    glutSolidCube(450.0);
    glColor3f(1.0f, 0.58f, 0.0f);
    glutWireCube(451.0);
    glPopMatrix();
    //lantai
    glPushMatrix();
    glTranslatef(0, 1426, 0);
    ground4();
    glPopMatrix();
    //atap
    glPushMatrix();
    glTranslatef(0, 700.5, 0);
    atap3();
    glPopMatrix();
    cout << "X_GESER =" << x_geser << " Y_GESER =" << y_geser << " Z_GESER =" << z_geser << endl;
    glFlush();
}
void atap4() {
    glBegin(GL_TRIANGLES); //hitam
    glColor3f(0.0f, 0.6f, 0.32f);
    glVertex3f(-250, 700, -316);
    glVertex3f(-250, 700, 204);
    glVertex3f(0, 800, 0);

    glEnd();

    glBegin(GL_TRIANGLES); //putih
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(-250, 700, 204);
    glVertex3f(250, 700, 204);
    glVertex3f(0, 800, 0);

    glEnd();

    glBegin(GL_TRIANGLES); //merah
    glColor3f(0.0f, 0.6f, 0.32f);
    glVertex3f(250, 700, -316);
    glVertex3f(250, 700, 204);
    glVertex3f(0, 800, 0);
    glEnd();


    glBegin(GL_TRIANGLES); //biru
    glColor3f(0.0f, 0.6f, 0.37f);
    glVertex3f(250, 700, -316);
    glVertex3f(-250, 700, -316);
    glVertex3f(0, 800, 0);

    glEnd();
}
void lantai4() {
    glPushMatrix();
    glTranslatef(0, 1600, 0);
    glColor3f(0.78f, 0.78f, 0.78f);
    glutSolidCube(400.0);
    glColor3f(1.0f, 0.58f, 0.0f);
    glutWireCube(401.0);
    glPopMatrix();
    //atap
    glPushMatrix();
    glTranslatef( 0, 1093.5, 35);
    atap4();
    glPopMatrix();
    cout << "X_GESER =" << x_geser << " Y_GESER =" << y_geser << " Z_GESER =" << z_geser << endl;
    glFlush();
}
void draw() {
    lantai_dasar();
    lantai1();
    lantai2();
    lantai3();
    lantai4();
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
        y_geser += 1.5;
        break;
    case '2':
        y_geser -= 1.5;
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