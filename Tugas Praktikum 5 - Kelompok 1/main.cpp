#include <GL/glut.h>

// Definisi warna
GLfloat ungu[] = {0.5, 0.0, 0.5, 1.0}; // Ungu
GLfloat biruMetalik[] = {0.0, 0.2, 0.8, 1.0}; // Biru Metalik
GLfloat putih[] = {1.0, 1.0, 1.0, 1.0};       // Putih
GLfloat hitam[] = {0.0, 0.0, 0.0, 1.0};       // Hitam
GLfloat abu[] = {0.5, 0.5, 0.5, 1.0};         // Abu-abu
GLfloat silver[] = {0.75, 0.75, 0.75, 1.0};   // Silver
GLfloat merah[] = {1.0, 0.0, 0.0, 1.0}; 
GLfloat biruLangit[] = {0.53, 0.81, 0.92, 1.0}; // Biru Langit

// Variabel untuk rotasi
float angleX = 0.0;
float angleY = 0.0;

// Fungsi untuk membuat roda
void buatRoda(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    
    // Ban (silinder hitam)
    glColor3fv(hitam);
    glutSolidTorus(0.08, 0.18, 20, 20);
    
    // Pelek (silinder perak)
    glColor3fv(abu);
    glutSolidTorus(0.04, 0.13, 10, 10);
    
    glPopMatrix();
}

// Fungsi untuk membuat mobil
void buatMobil() {
    // Bodi utama mobil (kotak)
    glPushMatrix();
    glColor3fv(ungu);
    glScalef(2.0, 0.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Bagian kabin mobil (kotak) - Struktur ungu
    glPushMatrix();
    glColor3fv(ungu);
    glTranslatef(-0.2, 0.4, 0.0);
    glScalef(1.0, 0.4, 0.8);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kaca depan (trapesium)
    glPushMatrix();
    glColor3fv(putih);
    glTranslatef(0.3, 0.35, 0.0);
    glRotatef(-45.0, 0.0, 0.0, 1.0);
    glScalef(0.45, 0.25, 0.75);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kaca samping kiri - Tambahan
    glPushMatrix();
    glColor3fv(putih);
    glTranslatef(-0.2, 0.4, 0.4);
    glScalef(0.9, 0.35, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kaca samping kanan - Tambahan
    glPushMatrix();
    glColor3fv(putih);
    glTranslatef(-0.2, 0.4, -0.4);
    glScalef(0.9, 0.35, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Moncong/hidung mobil
    glPushMatrix();
    glColor3fv(ungu);
    glTranslatef(0.8, 0.0, 0.0);
    glScalef(0.6, 0.4, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Lampu depan (bola)
    glPushMatrix();
    glColor3fv(silver);
    glTranslatef(1.1, 0.1, 0.3);
    glutSolidSphere(0.1, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
    glColor3fv(silver);
    glTranslatef(1.1, 0.1, -0.3);
    glutSolidSphere(0.1, 10, 10);
    glPopMatrix();
    
    // Bagian belakang mobil
    glPushMatrix();
    glColor3fv(ungu);
    glTranslatef(-0.9, 0.0, 0.0);
    glScalef(0.4, 0.4, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Lampu belakang (bola)
    glPushMatrix();
    glColor3fv(merah);
    glTranslatef(-1.1, 0.1, 0.3);
    glutSolidSphere(0.08, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
    glColor3fv(merah);
    glTranslatef(-1.1, 0.1, -0.3);
    glutSolidSphere(0.08, 10, 10);
    glPopMatrix();

    // Roda (4 buah) - Posisi diperbaiki
    // Roda depan
    buatRoda(0.6, -0.15, 0.5);
    buatRoda(0.6, -0.15, -0.5);
    // Roda belakang
    buatRoda(-0.6, -0.15, 0.5);
    buatRoda(-0.6, -0.15, -0.5);
}

void display() {
    // Mengubah warna background menjadi biru langit
    glClearColor(biruLangit[0], biruLangit[1], biruLangit[2], biruLangit[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Atur posisi kamera
    gluLookAt(
        3.0, 2.0, 5.0,  // Posisi kamera
        0.0, 0.0, 0.0,  // Titik yang dilihat
        0.0, 1.0, 0.0   // Vektor up
    );
    
    // Atur pencahayaan
    GLfloat posisiCahaya[] = {5.0, 5.0, 5.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, posisiCahaya);
    
    // Rotasi mobil
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    
    // Buat mobil
    buatMobil();
    
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27) // ESC
        exit(0);
}

void specialKeys(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_UP:
            angleX += 5.0;
            break;
        case GLUT_KEY_DOWN:
            angleX -= 5.0;
            break;
        case GLUT_KEY_RIGHT:
            angleY += 5.0;
            break;
        case GLUT_KEY_LEFT:
            angleY -= 5.0;
            break;
    }
    glutPostRedisplay();
}

void idle() {
    angleY += 0.09;
    if (angleY > 360)
        angleY -= 360;
    
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("objek utama");
    
    // Mengaktifkan fitur 3D
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutIdleFunc(idle);
    
    glutMainLoop();
    return 0;
}
