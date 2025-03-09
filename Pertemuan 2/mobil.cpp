/**
 * File      : mobil.cpp
 * Deskripsi : Program mobil 2D yang memanfaatkan object2 primitif,
 			   transformasi (translasi dan rotasi), serta penggunaan
               stack.
 * Object	 : Tesla Cybertruck
 * Tanggal   : 3 Maret 2025
 * NIM/Nama  : 24060123120022/Akmal Fauzan Azima
 */

#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926535898

void lingkaran(GLfloat x, GLfloat y, GLfloat radius, int circle_points) {
    glBegin(GL_TRIANGLE_FAN);
    
    glVertex2f(x, y);
    for (int i = 0; i <= circle_points; i++) {
        float angle = 2.0f * PI * i / circle_points;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    
    glEnd();
}

void mobil(float x, float y, float r, float g, float b) {
    glTranslatef(x, y, 0);

    // Badan mobil
    glBegin(GL_POLYGON);
	    glColor3f(r * 1.1, g * 1.1, b * 1.1);
	    glVertex2f(-0.40, -0.05);
	    glColor3f(r, g, b);
	    glVertex2f(-0.05, 0.15);
	    glVertex2f(0.40, 0.0);
	    glVertex2f(0.40, -0.15);
	    glVertex2f(-0.40, -0.15);
    glEnd();
    
    // Lampu putih
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(-0.40, -0.05, -0.35, -0.08);
    
	// Cahaya putih
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
		glColor4f(1.0f, 1.0f, 1.0f, 0.7f);
		glVertex2f(-0.80, 0.05);
		glVertex2f(-0.41, -0.05);
		glVertex2f(-0.41, -0.08);
		glVertex2f(-0.80, -0.13);
	glEnd();
	glDisable(GL_BLEND);
    
    // Lampu merah
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(0.35, 0.00, 0.40, -0.03);
    
    // Kaca mobil
    glBegin(GL_POLYGON);
    	glColor3f(0.1f, 0.1f, 0.1f);
    	glVertex2f(-0.31, -0.02);
    	glVertex2f(-0.05, 0.13);
    	glVertex2f(0.20, 0.04);
    	glVertex2f(0.20, 0.00);
    glEnd();
    
    // Pintu kiri
    glBegin(GL_LINE_LOOP);
    	glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(-0.20, -0.15);
    	glVertex2f(-0.20, 0.04);
    	glVertex2f(-0.05, 0.13);
    	glVertex2f(0.00, 0.11);
    	glVertex2f(0.00, -0.15);
    glEnd();
    
    // Pintu Kanan
    glBegin(GL_LINE_LOOP);
    	glColor3f(0.1f, 0.1f, 0.1f);
    	glVertex2f(0.00, -0.15);
    	glVertex2f(0.00, 0.11);
    	glVertex2f(0.20, 0.04);
    	glVertex2f(0.20, -0.15);
    glEnd();
    
    // Gagang pintu kiri
    glPushMatrix();
	    glTranslatef(-0.02, 0.02, 0);
	    glRotated(1.0, 0.0, 0.0, 1.0);
	    glBegin(GL_LINE_LOOP);
	        glColor3f(0.1f, 0.1f, 0.1f);
	        glVertex2f(-0.05, -0.05);
	        glVertex2f(-0.01, -0.05);
	        glVertex2f(-0.01, -0.07);
	        glVertex2f(-0.05, -0.07);
	    glEnd();
	glPopMatrix();
    
    // Gagang pintu kanan
    glPushMatrix();
	    glTranslatef (-0.01, 0.006, 0);
		glRotated (2.0, 0.0, 0.0, 1.0);
	    glBegin(GL_LINE_LOOP);
	    	glColor3f(0.1f, 0.1f, 0.1f);
	    	glVertex2f(0.14, -0.04);
	    	glVertex2f(0.18, -0.04);
	    	glVertex2f(0.18, -0.06);
	    	glVertex2f(0.14, -0.06);
	    glEnd();
	glPopMatrix();
    
    // Roda kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    lingkaran(-0.28, -0.15, 0.07, 50);
    glColor3f(1.0f, 1.0f, 1.0f);
    lingkaran(-0.28, -0.15, 0.027, 10);

    // Roda kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    lingkaran(0.28, -0.15, 0.07, 50);
    glColor3f(1.0f, 1.0f, 1.0f);
    lingkaran(0.28, -0.15, 0.027, 10);
}

void renderObjects() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Matahari
    glColor3f(0.9f, 0.8f, 0.1f);
    lingkaran(0.0, 0.0, 0.3, 100);
	
	// Air Pantai
	glColor3f(0.0f, 0.0f, 1.0f);
	glRectf(-1.0, 0.0, 1.0, -0.3);
	
	// Jalan
    glColor3f(0.4f, 0.4f, 0.4f);
    glRectf(-1.0, -0.3, 1.0, -1.0);
    
    // Pembatas jalan
    glPushAttrib(GL_LINE_BIT);
	    glColor3f(0.9, 0.9, 0.9);
	    glLineWidth(5.0f);
	    glBegin(GL_LINES);
		for (float x = -1.0f; x < 1.0f; x += 0.1f) {
		    glVertex2f(x, -0.2f);
		    glVertex2f(x + 0.1f, -0.2f);
		    
		    glVertex2f(x + 0.1f, -0.2f);
		    glVertex2f(x + 0.1f, -0.35f);
		}
		glEnd();
	glPopAttrib();
    
    // Mobil
    mobil(0.0f, -0.6f, 0.6f, 0.6f, 0.6f);
	
	glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(720, 480);
    glutInitWindowPosition(600, 0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas Praktikum 2");

    glutDisplayFunc(renderObjects);
    glClearColor(0.8f, 0.6f, 0.1f, 1.0f);  // Langit senja
    glutMainLoop();

    return 0;
}

