#include <windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
//chresto tumbilung_672020229
void init() {
    glClearColor(0.83, 0.85, 0.95, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    gluOrtho2D(0.0, 1280, 0.0, 720);
}

void lingkaran(int sisi, int x, int y) {
    glBegin(GL_POLYGON);
    int r = 30;
    for (int i = 0; i < sisi; i++) {
        glVertex2f((r * cos(2 * 3.14159265 * i / sisi)) + x, (r * sin(2 * 3.14159265 * i / sisi)) + y);
    }
    glEnd();
}
void lingkaran2(int sisi, int x, int y) {
    glBegin(GL_POLYGON);
    int r = 45;
    for (int i = 0; i < sisi; i++) {
        glVertex2f((r * cos(2 * 3.14159265 * i / sisi)) + x, (r * sin(2 * 3.14159265 * i / sisi)) + y);
    }
    glEnd();
}
void lingkaran3(int sisi, int x, int y) {
    glBegin(GL_POLYGON);
    int r = 60;
    for (int i = 0; i < sisi; i++) {
        glVertex2f((r * cos(2 * 3.14159265 * i / sisi)) + x, (r * sin(2 * 3.14159265 * i / sisi)) + y);
    }
    glEnd();
}
void lingkaran4(int sisi, int x, int y) {
    glBegin(GL_POLYGON);
    int r = 20;
    for (int i = 0; i < sisi; i++) {
        glVertex2f((r * cos(2 * 3.14159265 * i / sisi)) + x, (r * sin(2 * 3.14159265 * i / sisi)) + y);
    }
    glEnd();
}
void lingkaran5(int sisi, int x, int y) {
    glBegin(GL_POLYGON);
    int r = 30;
    for (int i = 0; i < sisi; i++) {
        glVertex2f((r * cos(2 * 3.14159265 * i / sisi)) + x, (r * sin(2 * 3.14159265 * i / sisi)) + y);
    }
    glEnd();

}
void lingkaran6(int sisi, int x, int y) {
    glBegin(GL_POLYGON);
    int r = 40;
    for (int i = 0; i < sisi; i++) {
        glVertex2f((r * cos(2 * 3.14159265 * i / sisi)) + x, (r * sin(2 * 3.14159265 * i / sisi)) + y);
    }
    glEnd();
}
void objek() {
    glClear(GL_COLOR_BUFFER_BIT);
    //langit1
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.45f, 0.0f);
    glVertex2f(0, 405); //a
    glColor3f(0.98f, 0.75f, 0.56f);
    glVertex2f(0, 720); //b
    glColor3f(1.0f, 0.45f, 0.0f);
    glVertex2f(485, 480); //c
    glEnd();
    //langit2
    glBegin(GL_TRIANGLES);
    glColor3f(0.98f, 0.75f, 0.56f);
    glVertex2f(0, 720); //a
    glColor3f(1.0f, 0.45f, 0.0f);
    glVertex2f(485, 480); //b
    glColor3f(0.98f, 0.75f, 0.56f);
    glVertex2f(1280, 720); //c
    glEnd();
    //langit3 
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.45f, 0.0f);
    glVertex2f(485, 480); //a
    glColor3f(0.98f, 0.75f, 0.56f);
    glVertex2f(1280, 720); //b
    glColor3f(0.98f, 0.75f, 0.56f);
    glVertex2f(1280, 405); //c
    glEnd();
    //matahari 3
    glBegin(GL_POLYGON);
    glColor3f(0.96f, 0.65f, 0.3f);
    lingkaran3(15, 485, 495);
    glEnd();
    //matahari 2
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.91f, 0.68f);
    lingkaran2(15, 485, 495);
    glEnd();
    //matahari 
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    lingkaran(50, 485, 495);
    glEnd();
    //gunung
    glBegin(GL_TRIANGLES);
    glColor3f(0.1f, 0.08f, 0.06f);
    glVertex2f(0, 405); //a
    glColor3f(0.98f, 0.75f, 0.56f);
    glVertex2f(300, 600); //b
    glColor3f(0.79f, 0.44f, 0.01f);
    glVertex2f(600, 405); //c
    glEnd();
    //gunung2
    glBegin(GL_TRIANGLES);
    glColor3f(0.98f, 0.75f, 0.56f);
    glVertex2f(700, 500); //a
    glColor3f(0.98f, 0.75f, 0.56f);
    glVertex2f(850, 650); //b
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1000, 500); //c
    glEnd();
    //gunung3
    glBegin(GL_TRIANGLES);
    glColor3f(0.1f, 0.08f, 0.06f);
    glVertex2f(700, 405); //a
    glColor3f(0.98f, 0.75f, 0.56f);
    glVertex2f(950, 670); //b
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1280, 405); //c
    glEnd();
    //gunung4
    glBegin(GL_TRIANGLES);
    glColor3f(0.79f, 0.44f, 0.01f);
    glVertex2f(400, 400); //a
    glColor3f(0.98f, 0.75f, 0.56f);
    glVertex2f(695, 695); //b
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1000, 400); //c
    glEnd();
    //rumput
    glBegin(GL_TRIANGLES);
    glColor3f(0.93f, 0.53f, 0.03f);
    glVertex2f(0, 200); //a
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 405); //b
    glColor3f(0.93f, 0.53f, 0.03f);
    glVertex2f(640, 405); //c
    glEnd();
    //rumput2
    glBegin(GL_TRIANGLES);
    glColor3f(0.93f, 0.53f, 0.03f);
    glVertex2f(640, 405); //a
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1280, 405); //b
    glColor3f(0.93f, 0.53f, 0.03f);
    glVertex2f(1280, 200); //c
    glEnd();
    //bayangan gunung 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 405); //a
    glColor3f(0.53f, 0.31f, 0.05f);
    glVertex2f(300, 350); //b
    glColor3f(0.93f, 0.53f, 0.03f);
    glVertex2f(600, 405); //c
    glEnd();
    //bayangan gunung 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.53f, 0.31f, 0.05f);
    glVertex2f(700, 405); //a
    glColor3f(0.53f, 0.31f, 0.05f);
    glVertex2f(950, 350); //b
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1280, 405); //c
    glEnd();
    //bayangan gunung 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.53f, 0.31f, 0.05f);
    glVertex2f(405, 405); //a
    glColor3f(0.93f, 0.53f, 0.03f);
    glVertex2f(695, 230); //b
    glColor3f(0.53f, 0.31f, 0.05f);
    glVertex2f(995, 405); //c
    glEnd();
    //bayangan gunung 4
    glBegin(GL_TRIANGLES);
    glColor3f(0.53f, 0.31f, 0.05f);
    glVertex2f(405, 405); //a
    glVertex2f(453, 376); //b
    glVertex2f(600, 405); //c
    glEnd();
    //bayangan gunung 5
    glBegin(GL_TRIANGLES);
    glColor3f(0.51, 0.3, 0.05f);
    glVertex2f(785, 405); //a
    glVertex2f(915, 358); //b
    glVertex2f(995, 405); //c
    glEnd();
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    //jalan
    glBegin(GL_TRIANGLES);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(200, 0); //a
    glVertex2f(640, 405); //b
    glVertex2f(1080, 0); //c
    glEnd();
    //jalan2
    glBegin(GL_TRIANGLES);
    glColor3f(0.23f, 0.23f, 0.23f);
    glVertex2f(100, 0); //a
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(640, 405); //b
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(200, 0); //c
    glEnd();
    //jalan3
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1080, 0); //a
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(640, 405); //b
    glColor3f(0.23f, 0.23f, 0.23f);
    glVertex2f(1180, 0); //c
    glEnd();
    //jalan4
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 0); //a
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(640, 405); //b
    glColor3f(0.23f, 0.23f, 0.23f);
    glVertex2f(100, 0); //c
    glEnd();
    //jalan5
    glBegin(GL_TRIANGLES);
    glColor3f(0.23f, 0.23f, 0.23f);
    glVertex2f(1180, 0); //a
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(640, 405); //b
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1280, 0); //b
    glEnd();
    //jalan6
    glBegin(GL_TRIANGLES);
    glColor3f(0.23f, 0.23f, 0.23f);
    glVertex2f(0, 180); //a
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(640, 405); //b
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 0); //c
    glEnd();
    //jalan7
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1280, 0); //a
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(640, 405); //b
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1280, 180); //c
    glEnd();
    //jalan8
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 190); //a
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(640, 405); //b
    glColor3f(0.23f, 0.23f, 0.23f);
    glVertex2f(0, 180); //c
    glEnd();
    //jalan9
    glBegin(GL_TRIANGLES);
    glColor3f(0.23f, 0.23f, 0.23f);
    glVertex2f(1280, 180); //a
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(640, 405); //b
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1280, 190); //c
    glEnd();
    //jalan10
    glBegin(GL_TRIANGLES);
    glColor3f(0.23f, 0.23f, 0.23f);
    glVertex2f(0, 215); //a
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(640, 405); //b
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 190); //c
    glEnd();
    //jalan11
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1280, 190); //a
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(640, 405); //b
    glColor3f(0.23f, 0.23f, 0.23f);
    glVertex2f(1280, 215); //c
    glEnd();
    //jalan12
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0, 235); //a
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(640, 405); //b
    glColor3f(0.23f, 0.23f, 0.23f);
    glVertex2f(0, 215); //c
    glEnd();
    //jalan13
    glBegin(GL_TRIANGLES);
    glColor3f(0.23f, 0.23f, 0.23f);
    glVertex2f(1280, 215); //a
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(640, 405); //b
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1280, 235); //c
    glEnd();
    //jalan14
    glBegin(GL_TRIANGLES); 
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(280, 0); //a
    glColor3f(0.22f, 0.22f, 0.22f);
    glVertex2f(640, 405); //b
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(1000, 0); //c
    glEnd();
    //jalan15
    glBegin(GL_TRIANGLES);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(300, 0); //a
    glVertex2f(640, 405); //b
    glVertex2f(980, 0); //c
    glEnd();
    //garis
    glBegin(GL_TRIANGLES);
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(620, 280); //a
    glColor3f(0.22f, 0.22f, 0.22f);
    glVertex2f(640, 405); //b
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(660, 280); //c
    glEnd();
    //garis2
    glBegin(GL_QUADS);
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(595, 120);//a
    glColor3f(0.22f, 0.22f, 0.22f);
    glVertex2f(620, 270);//b
    glColor3f(0.22f, 0.22f, 0.22f);
    glVertex2f(660, 270);//c
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(685, 120);//d
    glEnd();
    //garis3
    glBegin(GL_QUADS);
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(565, 0);//a
    glColor3f(0.22f, 0.22f, 0.22f);
    glVertex2f(595, 110);//b
    glColor3f(0.22f, 0.22f, 0.22f);
    glVertex2f(685, 110);//c
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(715, 0);//d
    glEnd();

    //tiang1
    glBegin(GL_QUADS);
    glColor3f(0.22f, 0.22f, 0.22f);
    glVertex2f(320, 200);//a
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(320, 600);//b
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(330, 600);//c
    glColor3f(0.22f, 0.22f, 0.22f);
    glVertex2f(330, 200);//d
    glEnd();
    glFlush();
    //tiang11
    glBegin(GL_QUADS);
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(320, 600);//a
    glColor3f(0.22f, 0.22f, 0.22f);
    glVertex2f(410, 600);//b
    glColor3f(0.22f, 0.22f, 0.22f);
    glVertex2f(410, 590);//c
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(320, 590);//d
    glEnd();

    //lampu3
    glBegin(GL_POLYGON);
    glColor3f(0.96f, 0.65f, 0.3f);
    lingkaran6(15, 380, 550);
    glEnd();
    //lampu2
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.91f, 0.68f);
    lingkaran5(25, 380, 550);
    glEnd();
    //lampu1
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    lingkaran4(50, 380, 550);
    glEnd();
    //lampu5
    glBegin(GL_TRIANGLES);
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(358, 550); //a
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(380, 590); //b
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(402, 550); //c
    glEnd();


    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1280, 700);
    glutCreateWindow("Materi 1 Grafkom G-H");
    init();
    glutDisplayFunc(objek);
    //glutFullScreen();
    glutMainLoop();
}