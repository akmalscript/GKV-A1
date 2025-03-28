/* KELOMPOK 1
 * 1) Akmal Fauzan Azima (24060123120022)
 * 2) Amara Putri Soniaji (24060123120004)
 * 3) Brilianita Eva Syafitri (24060123130051)
 * 4) Cacania Pasu Nalaung Siregar (24060123120033)
 * 
 * Deskripsi: membuat objek utama
 */

#include <math.h>
#include <stdio.h>
#include <GL/glut.h>

double rx = 0.0;
double ry = 0.0;

// objek yang akan digambar
void draw()
{
    glutSolidCube(40);
}

void render()
{
    glClearColor(0.0, 0.6, 0.9, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0.5, 0.5, 0.5); // warna lantai
    glBegin(GL_QUADS);
        glVertex3f(-1300.0, -60.1, 1300.0);
        glVertex3f(1300.0, -60.1, 1300.0);
        glVertex3f(1300.0, -60.1, -1300.0);
        glVertex3f(-1300.0, -60.1, -1300.0);
    glEnd();

    // kubus
    glPushMatrix();
        glRotatef(ry, 0, 1, 0);
        glRotatef(rx, 1, 0, 0);
        glColor3f(0.5, 0, 0.5); // warna kubus
        draw();
    glPopMatrix();

    // tambahkan garis tepi berwarna
    glPushMatrix();
        glRotatef(ry, 0, 1, 0);
        glRotatef(rx, 1, 0, 0);
        glColor3f(1, 0.5, 1);  // warna tepi
        glLineWidth(3.0); // ketebalan garis tepi
        glutWireCube(60.0);
    glPopMatrix();

    glutSwapBuffers();
}

// pergerakan objek (kubus)
void idle()
{
    rx += 0.03;
    ry += 0.03;
    render();
}

// mempertahankan aspek rasio ketika full-screen
void resize(int w, int h)
{
    if (h == 0) h = 1;
    float aspect = (float)w / (float)h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, aspect, 1.0, 400.0);
    
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300, 30);
    glutCreateWindow("Objek Utama");
    glutReshapeFunc(resize);
    glutReshapeWindow(400, 400);
    glutDisplayFunc(render);
    glutIdleFunc(idle);

    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(60.0f, 1.0, 1.0, 400.0);

    // Reset koordinat sebelum dimodifikasi/diubah
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -185.0);

    glutMainLoop();
    return 0;
}
