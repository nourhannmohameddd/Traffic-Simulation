#include <windows.h> // for MS Windows
#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;

#define PI 3.14159265358979323846

GLfloat x, y, radius, twicePi; // for circle
int triangleAmount;

int frameNumber = 1; // for windmill

GLfloat position_b1 = -0.5f; // for boat1
GLfloat speed_b1 = 0.002f;

GLfloat position_r = -0.1f; // for river
GLfloat speed_r = 0.01f;

GLfloat position_c1 = 1.6f; // for car 1
GLfloat speed_c1 = 0.01f;

GLfloat position_c2 = 2.4f; // for car 2
GLfloat speed_c2 = 0.01f;

GLfloat position_c3 = -0.9f; // for car 3
GLfloat speed_c3 = 0.01f;

GLfloat position_c4 = 0.9f; // for car 4
GLfloat speed_c4 = 0.01f;

GLfloat position_rain = 0.0f; // for rain
GLfloat speed_rain = 0.05f;
GLfloat position_rain2 = 2.0f; // for rain
GLfloat speed_rain2 = 0.05f;

int cnt = 0, flag = 0, r = 0;

char *c;
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void windmill()
{
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    glTranslatef(1.6, 0.3, 0.0);
    glColor3ub(255, 102, 102); // base
    glBegin(GL_POLYGON);
    glVertex2f(-0.80f, 0.275f);
    glVertex2f(-0.80f, 0.25f);
    glVertex2f(-0.65f, 0.25f);
    glVertex2f(-0.65f, 0.275f);

    glEnd();

    glColor3ub(255, 255, 255); // body
    glBegin(GL_POLYGON);
    glVertex2f(-0.775f, 0.5f);
    glVertex2f(-0.79f, 0.275f);
    glVertex2f(-0.66f, 0.275f);
    glVertex2f(-0.675f, 0.5f);

    glEnd();

    glColor3ub(51, 153, 255); // door
    glBegin(GL_POLYGON);
    glVertex2f(-0.71f, 0.35f);
    glVertex2f(-0.71f, 0.275f);
    glVertex2f(-0.74f, 0.275f);
    glVertex2f(-0.74f, 0.35f);

    glEnd();

    glColor3ub(51, 153, 255); // window
    glBegin(GL_POLYGON);
    glVertex2f(-0.71f, 0.45f);
    glVertex2f(-0.71f, 0.4f);
    glVertex2f(-0.74f, 0.4f);
    glVertex2f(-0.74f, 0.45f);

    glEnd();

    glColor3ub(00, 102, 204); // head
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.79f, 0.5f);
    glVertex2f(-0.725f, 0.63f);
    glVertex2f(-0.66f, 0.5f);

    glEnd();

    glTranslatef(-0.725f, 0.55f, 0.0f);
    glRotated(frameNumber * (-180.0 / 500), 0, 0, 1);

    glColor3ub(204, 229, 255); // wing1
    glBegin(GL_POLYGON);
    glVertex2f(0.00f, 0.01f);
    glVertex2f(0.00f, 0.00f);
    glVertex2f(0.20f, 0.00f);
    glVertex2f(0.20f, 0.01f);
    glEnd();

    glColor3ub(255, 51, 51);
    glBegin(GL_POLYGON);
    glVertex2f(0.03f, 0.05f);
    glVertex2f(0.03f, 0.01f);
    glVertex2f(0.20f, 0.01f);
    glVertex2f(0.20f, 0.05f);
    glEnd();

    glColor3ub(204, 229, 255); // wing2
    glBegin(GL_POLYGON);
    glVertex2f(0.00f, 0.01f);
    glVertex2f(0.00f, 0.00f);
    glVertex2f(-0.20f, 0.00f);
    glVertex2f(-0.20f, 0.01f);
    glEnd();

    glColor3ub(255, 51, 51);
    glBegin(GL_POLYGON);
    glVertex2f(-0.03f, -0.04f);
    glVertex2f(-0.03f, -0.00f);
    glVertex2f(-0.20f, -0.00f);
    glVertex2f(-0.20f, -0.04f);
    glEnd();

    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glColor3ub(204, 229, 255); // wing3
    glBegin(GL_POLYGON);
    glVertex2f(0.00f, 0.01f);
    glVertex2f(0.00f, 0.00f);
    glVertex2f(0.20f, 0.00f);
    glVertex2f(0.20f, 0.01f);
    glEnd();

    glColor3ub(255, 51, 51);
    glBegin(GL_POLYGON);
    glVertex2f(0.03f, 0.05f);
    glVertex2f(0.03f, 0.01f);
    glVertex2f(0.20f, 0.01f);
    glVertex2f(0.20f, 0.05f);
    glEnd();

    glColor3ub(204, 229, 255); // wing4
    glBegin(GL_POLYGON);
    glVertex2f(0.00f, 0.01f);
    glVertex2f(0.00f, 0.00f);
    glVertex2f(-0.20f, 0.00f);
    glVertex2f(-0.20f, 0.01f);
    glEnd();

    glColor3ub(255, 51, 51);
    glBegin(GL_POLYGON);
    glVertex2f(-0.03f, -0.04f);
    glVertex2f(-0.03f, -0.00f);
    glVertex2f(-0.20f, -0.00f);
    glVertex2f(-0.20f, -0.04f);
    glEnd();

    x = -0.0f;
    y = 0.0f;
    radius = .02f;
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(255, 51, 51);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    glLoadIdentity();
}
void house()
{
    // left house start
    glBegin(GL_POLYGON); // body
    glColor3ub(224, 228, 231);
    glVertex2f(-1.4f, 0.5f);
    glVertex2f(-1.4f, 1.0f);
    glVertex2f(-0.9f, 1.0f);
    glVertex2f(-0.9f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON); // bottom-window 1
    glColor3ub(179, 230, 255);
    glVertex2f(-1.35f, 0.55f);
    glVertex2f(-1.35f, 0.65f);
    glColor3ub(0, 230, 230);
    glVertex2f(-1.25f, 0.65f);
    glVertex2f(-1.25f, 0.55f);
    glEnd();
    glBegin(GL_POLYGON); // bottom-window 2
    glColor3ub(179, 230, 255);
    glVertex2f(-1.05f, 0.55f);
    glVertex2f(-1.05f, 0.65f);
    glColor3ub(0, 230, 230);
    glVertex2f(-0.95f, 0.65f);
    glVertex2f(-0.95f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON); // top-window 1
    glColor3ub(179, 230, 255);
    glVertex2f(-1.35f, 0.85f);
    glVertex2f(-1.35f, 0.95f);
    glColor3ub(0, 230, 230);
    glVertex2f(-1.25f, 0.95f);
    glVertex2f(-1.25f, 0.85f);
    glEnd();
    glBegin(GL_POLYGON); // top-window 2
    glColor3ub(179, 230, 255);
    glVertex2f(-1.2f, 0.85f);
    glVertex2f(-1.2f, 0.95f);
    glColor3ub(0, 230, 230);
    glVertex2f(-1.1f, 0.95f);
    glVertex2f(-1.1f, 0.85f);
    glEnd();
    glBegin(GL_POLYGON); // top-window 3
    glColor3ub(179, 230, 255);
    glVertex2f(-1.05f, 0.85f);
    glVertex2f(-1.05f, 0.95f);
    glColor3ub(0, 230, 230);
    glVertex2f(-0.95f, 0.95f);
    glVertex2f(-0.95f, 0.85f);
    glEnd();

    glBegin(GL_POLYGON); // door
    glColor3ub(153, 153, 153);
    glVertex2f(-1.2f, 0.5f);
    glVertex2f(-1.2f, 0.65f);
    glVertex2f(-1.1f, 0.65f);
    glVertex2f(-1.1f, 0.5f);
    glEnd();

    glPointSize(5.0); // door handle
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.17f, 0.58f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(77, 195, 255);
    glVertex2f(-1.35f, 0.55f); // bottom-window 1
    glVertex2f(-1.35f, 0.65f);

    glVertex2f(-1.35f, 0.65f);
    glVertex2f(-1.25f, 0.65f);

    glVertex2f(-1.25f, 0.65f);
    glVertex2f(-1.25f, 0.55f);

    glVertex2f(-1.25f, 0.55f);
    glVertex2f(-1.35f, 0.55f);

    glVertex2f(-1.25f, 0.6f);
    glVertex2f(-1.35f, 0.6f);

    glVertex2f(-1.05f, 0.55f); // bottom-window 2
    glVertex2f(-1.05f, 0.65f);

    glVertex2f(-1.05f, 0.65f);
    glVertex2f(-0.95f, 0.65f);

    glVertex2f(-0.95f, 0.65f);
    glVertex2f(-0.95f, 0.55f);

    glVertex2f(-0.95f, 0.55f);
    glVertex2f(-1.05f, 0.55f);

    glVertex2f(-0.95f, 0.6f);
    glVertex2f(-1.05f, 0.6f);

    glVertex2f(-1.35f, 0.85f); // top-window 1
    glVertex2f(-1.35f, 0.95f);

    glVertex2f(-1.35f, 0.95f);
    glVertex2f(-1.25f, 0.95f);

    glVertex2f(-1.25f, 0.95f);
    glVertex2f(-1.25f, 0.85f);

    glVertex2f(-1.25f, 0.85f);
    glVertex2f(-1.35f, 0.85f);

    glVertex2f(-1.25f, 0.9f);
    glVertex2f(-1.35f, 0.9f);

    glVertex2f(-1.2f, 0.85f); // top-window 2
    glVertex2f(-1.2f, 0.95f);

    glVertex2f(-1.2f, 0.95f);
    glVertex2f(-1.1f, 0.95f);

    glVertex2f(-1.1f, 0.95f);
    glVertex2f(-1.1f, 0.85f);

    glVertex2f(-1.1f, 0.85f);
    glVertex2f(-1.2f, 0.85f);

    glVertex2f(-1.1f, 0.9f);
    glVertex2f(-1.2f, 0.9f);

    glVertex2f(-1.05f, 0.85f); // top-window 3
    glVertex2f(-1.05f, 0.95f);

    glVertex2f(-1.05f, 0.95f);
    glVertex2f(-0.95f, 0.95f);

    glVertex2f(-0.95f, 0.95f);
    glVertex2f(-0.95f, 0.85f);

    glVertex2f(-0.95f, 0.85f);
    glVertex2f(-1.05f, 0.85f);

    glVertex2f(-0.95f, 0.9f);
    glVertex2f(-1.05f, 0.9f);

    glVertex2f(-1.2f, 0.5f); // door
    glVertex2f(-1.2f, 0.65f);

    glVertex2f(-1.2f, 0.65f);
    glVertex2f(-1.1f, 0.65f);

    glVertex2f(-1.1f, 0.65f);
    glVertex2f(-1.1f, 0.5f);

    glVertex2f(-1.1f, 0.5f);
    glVertex2f(-1.2f, 0.5f);

    // body
    glColor3ub(128, 128, 128);

    glVertex2f(-1.4f, 0.5f);
    glVertex2f(-1.4f, 1.0f);

    glVertex2f(-1.4f, 1.0f);
    glVertex2f(-0.9f, 1.0f);

    glVertex2f(-0.9f, 1.0f);
    glVertex2f(-0.9f, 0.5f);

    glColor3ub(128, 0, 0);
    glVertex2f(-0.87f, 0.5f);
    glVertex2f(-1.43f, 0.5f);

    glVertex2f(-0.87f, 0.504f);
    glVertex2f(-1.43f, 0.504f);
    glEnd();

    glBegin(GL_POLYGON); // shelter
    glColor3ub(76, 174, 218);
    glVertex2f(-1.4f, 0.8f);
    glVertex2f(-1.45f, 0.75f);
    glVertex2f(-1.45f, 0.7f);
    glVertex2f(-0.85f, 0.7f);
    glVertex2f(-0.85f, 0.75f);
    glVertex2f(-0.9f, 0.8f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-1.4f, 0.8f);
    glVertex2f(-1.45f, 0.75f);

    glVertex2f(-1.45f, 0.75f);
    glVertex2f(-1.45f, 0.7f);

    glVertex2f(-1.45f, 0.7f);
    glVertex2f(-0.85f, 0.7f);

    glVertex2f(-0.85f, 0.7f);
    glVertex2f(-0.85f, 0.75f);

    glVertex2f(-0.85f, 0.75f);
    glVertex2f(-0.9f, 0.8f);

    glVertex2f(-0.9f, 0.8f);
    glVertex2f(-1.4f, 0.8f);
    glEnd();
    // left house end

    // right house start
    glBegin(GL_POLYGON); // body
    glColor3ub(153, 51, 0);
    glVertex2f(-0.15f, 0.5f);
    glVertex2f(-0.15f, 0.8f);
    glVertex2f(0.35f, 0.8f);
    glVertex2f(0.35f, 0.5f);
    glEnd();
    glBegin(GL_POLYGON); // store room
    glColor3ub(153, 51, 0);
    glVertex2f(0.05f, 0.8f);
    glVertex2f(0.05f, 0.99f);
    glVertex2f(0.35f, 0.99f);
    glVertex2f(0.35f, 0.8f);
    glEnd();

    glBegin(GL_POLYGON); // window 1
    glColor3ub(77, 184, 255);
    glVertex2f(0.05f, 0.6f);
    glVertex2f(0.05f, 0.7f);
    glColor3ub(26, 140, 255);
    glVertex2f(0.15f, 0.7f);
    glVertex2f(0.15f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON); // window 2
    glColor3ub(77, 184, 255);
    glVertex2f(0.2f, 0.6f);
    glVertex2f(0.2f, 0.7f);
    glColor3ub(26, 140, 255);
    glVertex2f(0.3f, 0.7f);
    glVertex2f(0.3f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON); // store room window
    glColor3ub(77, 184, 255);
    glVertex2f(0.15f, 0.85f);
    glVertex2f(0.15f, 0.95f);
    glColor3ub(26, 140, 255);
    glVertex2f(0.25f, 0.95f);
    glVertex2f(0.25f, 0.85f);
    glEnd();

    glBegin(GL_POLYGON); // door
    glColor3ub(77, 77, 77);
    glVertex2f(-0.1f, 0.5f);
    glVertex2f(-0.1f, 0.65f);
    glVertex2f(0.0f, 0.65f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glPointSize(5.0); // door handle
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.03f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON); // door shelter
    glColor3ub(230, 115, 0);
    glVertex2f(0.02f, 0.65f);
    glVertex2f(-0.05f, 0.7f);
    glVertex2f(-0.12f, 0.65f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.15f, 0.85f); // store room window
    glVertex2f(0.15f, 0.95f);

    glVertex2f(0.15f, 0.95f);
    glVertex2f(0.25f, 0.95f);

    glVertex2f(0.25f, 0.95f);
    glVertex2f(0.25f, 0.85f);

    glVertex2f(0.25f, 0.85f);
    glVertex2f(0.15f, 0.85f);

    glVertex2f(0.05f, 0.6f); // window 1
    glVertex2f(0.05f, 0.7f);

    glVertex2f(0.05f, 0.7f);
    glVertex2f(0.15f, 0.7f);

    glVertex2f(0.15f, 0.7f);
    glVertex2f(0.15f, 0.6f);

    glVertex2f(0.15f, 0.6f);
    glVertex2f(0.05f, 0.6f);

    glVertex2f(0.2f, 0.6f); // window 2
    glVertex2f(0.2f, 0.7f);

    glVertex2f(0.2f, 0.7f);
    glVertex2f(0.3f, 0.7f);

    glVertex2f(0.3f, 0.7f);
    glVertex2f(0.3f, 0.6f);

    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.2f, 0.6f);

    glColor3ub(255, 153, 51);
    glVertex2f(-0.1f, 0.5f); // door
    glVertex2f(-0.1f, 0.65f);

    glVertex2f(-0.1f, 0.65f);
    glVertex2f(0.0f, 0.65f);

    glVertex2f(0.0f, 0.65f);
    glVertex2f(0.0f, 0.5f);

    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.1f, 0.5f);

    glVertex2f(0.02f, 0.65f); // door shelter
    glVertex2f(-0.05f, 0.7f);

    glVertex2f(-0.05f, 0.7f);
    glVertex2f(-0.12f, 0.65f);

    glVertex2f(-0.12f, 0.65f);
    glVertex2f(0.02f, 0.65f);

    glVertex2f(0.36f, 0.8f); // roof railing
    glVertex2f(-0.16f, 0.8f);

    glVertex2f(0.36f, 0.84f);
    glVertex2f(-0.16f, 0.84f);

    glVertex2f(-0.14f, 0.8f);
    glVertex2f(-0.14f, 0.84f);

    glVertex2f(-0.1f, 0.8f);
    glVertex2f(-0.1f, 0.84f);

    glVertex2f(-0.05f, 0.8f);
    glVertex2f(-0.05f, 0.84f);

    glVertex2f(-0.0f, 0.8f);
    glVertex2f(-0.0f, 0.84f);

    glVertex2f(0.05f, 0.8f);
    glVertex2f(0.05f, 0.84f);

    glVertex2f(0.1f, 0.8f);
    glVertex2f(0.1f, 0.84f);

    glVertex2f(0.15f, 0.8f);
    glVertex2f(0.15f, 0.84f);

    glVertex2f(0.2f, 0.8f);
    glVertex2f(0.2f, 0.84f);

    glVertex2f(0.25f, 0.8f);
    glVertex2f(0.25f, 0.84f);

    glVertex2f(0.3f, 0.8f);
    glVertex2f(0.3f, 0.84f);

    glVertex2f(0.35f, 0.8f);
    glVertex2f(0.35f, 0.84f);

    glVertex2f(-0.16f, 0.504f); // ground
    glVertex2f(0.36f, 0.504f);

    glVertex2f(-0.16f, 0.5f);
    glVertex2f(0.36f, 0.5f);

    glVertex2f(0.04f, 0.99f); // top roof
    glVertex2f(0.36f, 0.99f);

    glVertex2f(0.04f, 0.985f);
    glVertex2f(0.36f, 0.985f);
    glEnd();

    // right house end
}
void factory()
{
    // funnel
    glBegin(GL_POLYGON);
    glColor3ub(163, 136, 151);
    glVertex2f(1.5f, -0.8f);
    glVertex2f(1.55f, -0.4f);
    glVertex2f(1.65f, -0.4f);
    glVertex2f(1.7f, -0.8f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(231, 222, 225);
    glVertex2f(1.54f, -0.5f);
    glVertex2f(1.55f, -0.45f);
    glVertex2f(1.65f, -0.45f);
    glVertex2f(1.66f, -0.5f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(128, 0, 0);
    glVertex2f(1.5f, -0.8f);
    glVertex2f(1.55f, -0.4f);

    glVertex2f(1.55f, -0.4f);
    glVertex2f(1.65f, -0.4f);

    glVertex2f(1.65f, -0.4f);
    glVertex2f(1.7f, -0.8f);

    glVertex2f(1.7f, -0.8f);
    glVertex2f(1.5f, -0.8f);
    glEnd();

    // body start
    glBegin(GL_POLYGON);
    glColor3ub(220, 170, 159);
    glVertex2f(1.45f, -2.0f);
    glVertex2f(1.45f, -0.7f);
    glVertex2f(1.65f, -0.55f);
    glVertex2f(1.65f, -2.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(220, 170, 159);
    glVertex2f(1.65f, -2.0f);
    glVertex2f(1.65f, -0.7f);
    glVertex2f(1.85f, -0.55f);
    glVertex2f(1.85f, -2.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(220, 170, 159);
    glVertex2f(1.85f, -2.0f);
    glVertex2f(1.85f, -0.7f);
    glVertex2f(2.05f, -0.55f);
    glVertex2f(2.05f, -2.0f);
    glEnd();
    // body end

    // roof
    glBegin(GL_POLYGON);
    glColor3ub(192, 117, 124);
    glVertex2f(1.45f, -0.7f);
    glVertex2f(1.45f, -0.66f);
    glVertex2f(1.6f, -0.55f);
    glVertex2f(1.65f, -0.55f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(192, 117, 124);
    glVertex2f(1.65f, -0.7f);
    glVertex2f(1.65f, -0.66f);
    glVertex2f(1.8f, -0.55f);
    glVertex2f(1.85f, -0.55f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(192, 117, 124);
    glVertex2f(1.85f, -0.7f);
    glVertex2f(1.85f, -0.66f);
    glVertex2f(2.0f, -0.55f);
    glVertex2f(2.05f, -0.55f);
    glEnd();

    glBegin(GL_POLYGON); // window 1
    glColor3ub(96, 82, 118);
    glVertex2f(1.5f, -0.78f);
    glVertex2f(1.5f, -0.7f);
    glVertex2f(1.6f, -0.7f);
    glVertex2f(1.6f, -0.78f);
    glEnd();

    glBegin(GL_POLYGON); // window 2
    glColor3ub(96, 82, 118);
    glVertex2f(1.7f, -0.78f);
    glVertex2f(1.7f, -0.7f);
    glVertex2f(1.8f, -0.7f);
    glVertex2f(1.8f, -0.78f);
    glEnd();

    glBegin(GL_POLYGON); // window 3
    glColor3ub(96, 82, 118);
    glVertex2f(1.9f, -0.78f);
    glVertex2f(1.9f, -0.7f);
    glVertex2f(1.99f, -0.7f);
    glVertex2f(1.99f, -0.78f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128, 0, 0);
    glVertex2f(1.45f, -2.0f); // body
    glVertex2f(1.45f, -0.7f);

    glVertex2f(1.45f, -0.7f);
    glVertex2f(1.65f, -0.55f);

    glVertex2f(1.65f, -0.55f);
    glVertex2f(1.65f, -0.7f);

    glVertex2f(1.65f, -0.7f);
    glVertex2f(1.85f, -0.55f);

    glVertex2f(1.85f, -0.55f);
    glVertex2f(1.85f, -0.7f);

    glVertex2f(1.85f, -0.7f);
    glVertex2f(2.05f, -0.55f);

    glVertex2f(2.05f, -0.55f);
    glVertex2f(2.05f, -0.7f);

    glVertex2f(1.45f, -0.7f); // roof
    glVertex2f(1.45f, -0.66f);

    glVertex2f(1.45f, -0.66f);
    glVertex2f(1.6f, -0.55f);

    glVertex2f(1.6f, -0.55f);
    glVertex2f(1.65f, -0.55f);

    glVertex2f(1.65f, -0.55f);
    glVertex2f(1.45f, -0.7f);

    glVertex2f(1.65f, -0.7f);
    glVertex2f(1.65f, -0.66f);

    glVertex2f(1.65f, -0.66f);
    glVertex2f(1.8f, -0.55f);

    glVertex2f(1.8f, -0.55f);
    glVertex2f(1.85f, -0.55f);

    glVertex2f(1.85f, -0.55f);
    glVertex2f(1.65f, -0.7f);

    glVertex2f(1.85f, -0.7f);
    glVertex2f(1.85f, -0.66f);

    glVertex2f(1.85f, -0.66f);
    glVertex2f(2.0f, -0.55f);

    glVertex2f(2.0f, -0.55f);
    glVertex2f(2.05f, -0.55f);

    glVertex2f(2.05f, -0.55f);
    glVertex2f(1.85f, -0.7f);

    glColor3ub(217, 217, 217);
    glVertex2f(1.5f, -0.78f); // window 1
    glVertex2f(1.5f, -0.7f);

    glVertex2f(1.5f, -0.7f);
    glVertex2f(1.6f, -0.7f);

    glVertex2f(1.6f, -0.7f);
    glVertex2f(1.6f, -0.78f);

    glVertex2f(1.6f, -0.78f);
    glVertex2f(1.5f, -0.78f);

    glVertex2f(1.6f, -0.74f);
    glVertex2f(1.5f, -0.74f);

    glVertex2f(1.55f, -0.7f);
    glVertex2f(1.55f, -0.78f);

    glVertex2f(1.7f, -0.78f); // window 2
    glVertex2f(1.7f, -0.7f);

    glVertex2f(1.7f, -0.7f);
    glVertex2f(1.8f, -0.7f);

    glVertex2f(1.8f, -0.7f);
    glVertex2f(1.8f, -0.78f);

    glVertex2f(1.8f, -0.78f);
    glVertex2f(1.7f, -0.78f);

    glVertex2f(1.8f, -0.74f);
    glVertex2f(1.7f, -0.74f);

    glVertex2f(1.75f, -0.7f);
    glVertex2f(1.75f, -0.78f);

    glVertex2f(1.9f, -0.78f); // window 3
    glVertex2f(1.9f, -0.7f);

    glVertex2f(1.9f, -0.7f);
    glVertex2f(1.99f, -0.7f);

    glVertex2f(1.99f, -0.7f);
    glVertex2f(1.99f, -0.78f);

    glVertex2f(1.99f, -0.78f);
    glVertex2f(1.9f, -0.78f);

    glVertex2f(1.99f, -0.74f);
    glVertex2f(1.9f, -0.74f);

    glVertex2f(1.95f, -0.7f);
    glVertex2f(1.95f, -0.78f);
    glEnd();

    glColor3ub(255, 217, 179);
    const char *P = "F A C T O R Y";
    glRasterPos2f(1.55f, -0.9);
    for (int i = 0; P[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, P[i]);
}
void road_footpath()
{
    // road
    glBegin(GL_POLYGON);
    glColor3ub(95, 96, 91);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(2.0f, 0.5f);
    glVertex2f(2.0f, -0.5f);
    glVertex2f(-2.0f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(95, 96, 91);
    glVertex2f(0.4f, 1.0f);
    glVertex2f(1.4f, 1.0f);
    glVertex2f(1.4f, -1.0f);
    glVertex2f(0.4f, -1.0f);
    glEnd();

    // footpath
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(-2.0f, 0.3f);
    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.6f, 0.5f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(-2.0f, -0.5f);
    glVertex2f(-2.0f, -0.3f);
    glVertex2f(0.6f, -0.3f);
    glVertex2f(0.6f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(2.0f, -0.5f);
    glVertex2f(2.0f, -0.3f);
    glVertex2f(1.2f, -0.3f);
    glVertex2f(1.2f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(2.0f, 0.5f);
    glVertex2f(2.0f, 0.3f);
    glVertex2f(1.2f, 0.3f);
    glVertex2f(1.2f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(0.4f, -1.0f);
    glVertex2f(0.6f, -1.0f);
    glVertex2f(0.6f, -0.3f);
    glVertex2f(0.4f, -0.3f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(1.2f, -1.0f);
    glVertex2f(1.4f, -1.0f);
    glVertex2f(1.4f, -0.3f);
    glVertex2f(1.2f, -0.3f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(1.2f, 1.0f);
    glVertex2f(1.4f, 1.0f);
    glVertex2f(1.4f, 0.3f);
    glVertex2f(1.2f, 0.3f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(0.4f, 1.0f);
    glVertex2f(0.6f, 1.0f);
    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.4f, 0.3f);
    glEnd();

    // divider
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-2.0f, 0.0f);
    glVertex2f(-1.8f, 0.0f);

    glVertex2f(-1.7f, 0.0f);
    glVertex2f(-1.5f, 0.0f);

    glVertex2f(-1.4f, 0.0f);
    glVertex2f(-1.2f, 0.0f);

    glVertex2f(-1.1f, 0.0f);
    glVertex2f(-0.9f, 0.0f);

    glVertex2f(-0.8f, 0.0f);
    glVertex2f(-0.6f, 0.0f);

    glVertex2f(-0.5f, 0.0f);
    glVertex2f(-0.3f, 0.0f);

    glVertex2f(-0.2f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    glVertex2f(1.7f, 0.0f);
    glVertex2f(1.9f, 0.0f);

    glVertex2f(0.9f, 0.8f);
    glVertex2f(0.9f, 0.97f);

    glVertex2f(0.9f, -0.97f);
    glVertex2f(0.9f, -0.8f);
    glEnd();

    // zebra-crossing start
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, -0.3f);

    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.4f, 0.3f);

    glVertex2f(0.6f, 0.5f);
    glVertex2f(1.2f, 0.5f);

    glVertex2f(0.6f, 0.7f);
    glVertex2f(1.2f, 0.7f);

    glVertex2f(1.4f, 0.3f);
    glVertex2f(1.4f, -0.3f);

    glVertex2f(1.6f, 0.3f);
    glVertex2f(1.6f, -0.3f);

    glVertex2f(0.6f, -0.5f);
    glVertex2f(1.2f, -0.5f);

    glVertex2f(0.6f, -0.7f);
    glVertex2f(1.2f, -0.7f);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    // left cross
    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.4f, 0.2f);

    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.4f, 0.1f);

    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.4f, 0.0f);

    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.4f, -0.1f);

    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.4f, -0.2f);

    // right cross
    glVertex2f(1.4f, 0.2f);
    glVertex2f(1.6f, 0.2f);

    glVertex2f(1.4f, 0.1f);
    glVertex2f(1.6f, 0.1f);

    glVertex2f(1.4f, 0.0f);
    glVertex2f(1.6f, 0.0f);

    glVertex2f(1.4f, -0.1f);
    glVertex2f(1.6f, -0.1f);

    glVertex2f(1.4f, -0.2f);
    glVertex2f(1.6f, -0.2f);

    // bottom cross
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.7f, -0.7f);

    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.8f, -0.7f);

    glVertex2f(0.9f, -0.5f);
    glVertex2f(0.9f, -0.7f);

    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -0.7f);

    glVertex2f(1.1f, -0.5f);
    glVertex2f(1.1f, -0.7f);

    // top cross
    glVertex2f(0.7f, 0.5f);
    glVertex2f(0.7f, 0.7f);

    glVertex2f(0.8f, 0.5f);
    glVertex2f(0.8f, 0.7f);

    glVertex2f(0.9f, 0.5f);
    glVertex2f(0.9f, 0.7f);

    glVertex2f(1.0f, 0.5f);
    glVertex2f(1.0f, 0.7f);

    glVertex2f(1.1f, 0.5f);
    glVertex2f(1.1f, 0.7f);
    glEnd();
    // zebra-crossing end

    // road border
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(102, 102, 102);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(0.4f, 0.5f);

    glVertex2f(0.4f, 0.5f);
    glVertex2f(0.4f, 1.0f);

    glVertex2f(1.4f, 1.0f);
    glVertex2f(1.4f, 0.5f);

    glVertex2f(1.4f, 0.5f);
    glVertex2f(2.0f, 0.5f);

    glVertex2f(2.0f, -0.5f);
    glVertex2f(1.4f, -0.5f);

    glVertex2f(1.4f, -0.5f);
    glVertex2f(1.4f, -1.0f);

    glVertex2f(0.4f, -1.0f);
    glVertex2f(0.4f, -0.5f);

    glVertex2f(0.4f, -0.5f);
    glVertex2f(-2.0f, -0.5f);

    glColor3ub(230, 230, 230);
    glVertex2f(-2.0f, 0.3f);
    glVertex2f(0.6f, 0.3f);

    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.6f, 1.0f);

    glVertex2f(1.2f, 1.0f);
    glVertex2f(1.2f, 0.3f);

    glVertex2f(1.2f, 0.3f);
    glVertex2f(2.0f, 0.3f);

    glVertex2f(2.0f, -0.3f);
    glVertex2f(1.2f, -0.3f);

    glVertex2f(1.2f, -0.3f);
    glVertex2f(1.2f, -1.0f);

    glVertex2f(0.6f, -1.0f);
    glVertex2f(0.6f, -0.3f);

    glVertex2f(0.6f, -0.3f);
    glVertex2f(-2.0f, -0.3f);
    glEnd();
}
void traffic_light1()
{
    // stand
    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 0);
    glVertex2f(0.45f, 0.38f);
    glVertex2f(0.45f, 0.42f);
    glVertex2f(0.55f, 0.42f);
    glVertex2f(0.55f, 0.38f);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(153, 0, 0);
    glVertex2f(0.55f, 0.4f);
    glVertex2f(0.7f, 0.4f);

    glVertex2f(0.7f, 0.4f);
    glVertex2f(0.7f, 0.15f);
    glEnd();

    // light start
    glBegin(GL_POLYGON);
    glColor3ub(204, 122, 0);
    glVertex2f(0.65f, 0.15f);
    glVertex2f(0.75f, 0.15f);
    glVertex2f(0.75f, -0.05f);
    glVertex2f(0.65f, -0.05f);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.65f, 0.15f);
    glVertex2f(0.75f, 0.15f);

    glVertex2f(0.75f, 0.15f);
    glVertex2f(0.75f, -0.05f);

    glVertex2f(0.75f, -0.05f);
    glVertex2f(0.65f, -0.05f);

    glVertex2f(0.65f, -0.05f);
    glVertex2f(0.65f, 0.15f);
    // side
    glVertex2f(0.65f, 0.1f);
    glVertex2f(0.6f, 0.1f);

    glVertex2f(0.65f, 0.05f);
    glVertex2f(0.62f, 0.05f);

    glVertex2f(0.65f, 0.0f);
    glVertex2f(0.63f, 0.0f);

    glVertex2f(0.75f, 0.1f);
    glVertex2f(0.8f, 0.1f);

    glVertex2f(0.75f, 0.05f);
    glVertex2f(0.78f, 0.05f);

    glVertex2f(0.75f, 0.0f);
    glVertex2f(0.77f, 0.0f);
    glEnd();

    x = 0.7f;
    y = 0.1f;
    radius = .02f; // red
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(204, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.7f;
    y = 0.05f;
    radius = .02f; // yellow
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(255, 204, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.7f;
    y = 0.0f;
    radius = .02f; // green
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    // light end
}
void traffic_light2()
{
    // stand
    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 0);
    glVertex2f(1.28f, -0.35f);
    glVertex2f(1.32f, -0.35f);
    glVertex2f(1.32f, -0.45f);
    glVertex2f(1.28f, -0.45f);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(153, 0, 0);
    glVertex2f(1.3f, -0.35f);
    glVertex2f(1.3f, -0.2f);

    glVertex2f(1.3f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glEnd();

    // light start
    glBegin(GL_POLYGON);
    glColor3ub(204, 122, 0);
    glVertex2f(0.9f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(0.9f, -0.3f);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.9f, -0.1f);
    glVertex2f(1.0f, -0.1f);

    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, -0.3f);

    glVertex2f(1.0f, -0.3f);
    glVertex2f(0.9f, -0.3f);

    glVertex2f(0.9f, -0.3f);
    glVertex2f(0.9f, -0.1f);
    // side
    glVertex2f(0.9f, -0.15f);
    glVertex2f(0.85f, -0.15f);

    glVertex2f(0.9f, -0.2f);
    glVertex2f(0.87f, -0.2f);

    glVertex2f(0.9f, -0.25f);
    glVertex2f(0.88f, -0.25f);

    glVertex2f(1.0f, -0.15f);
    glVertex2f(1.05f, -0.15f);

    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.03f, -0.2f);

    glVertex2f(1.0f, -0.25f);
    glVertex2f(1.02f, -0.25f);
    glEnd();

    x = 0.95f;
    y = -0.15f;
    radius = .02f; // red
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(204, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.95f;
    y = -0.2f;
    radius = .02f; // yellow
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(255, 204, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.95f;
    y = -0.25f;
    radius = .02f; // green
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    // light end
}
void road_light()
{
    glLineWidth(3.0f);
    // left-up
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-1.9f, 0.4f);
    glVertex2f(-1.8f, 0.4f);

    glVertex2f(-1.8f, 0.4f);
    glVertex2f(-1.8f, 0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(-1.85f, 0.25f);
    glVertex2f(-1.8f, 0.25f);
    glVertex2f(-1.8f, 0.1f);
    glVertex2f(-1.85f, 0.1f);
    glEnd();
    glPointSize(10.0); //
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(-1.9f, 0.4f);
    glEnd();

    for (int i = 0; i < 3; i++)
    {
        glTranslated(0.6, 0.0, 0.0);
        glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.9f, 0.4f);
        glVertex2f(-1.8f, 0.4f);

        glVertex2f(-1.8f, 0.4f);
        glVertex2f(-1.8f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(191, 191, 191);
        glVertex2f(-1.85f, 0.25f);
        glVertex2f(-1.8f, 0.25f);
        glVertex2f(-1.8f, 0.1f);
        glVertex2f(-1.85f, 0.1f);
        glEnd();
        glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(-1.9f, 0.4f);
        glEnd();
    }

    // left-down
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-1.6f, -0.4f);
    glVertex2f(-1.5f, -0.4f);

    glVertex2f(-1.5f, -0.4f);
    glVertex2f(-1.5f, -0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(-1.5f, -0.1f);
    glVertex2f(-1.55f, -0.1f);
    glVertex2f(-1.55f, -0.25f);
    glVertex2f(-1.5f, -0.25f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(-1.6f, -0.4f);
    glEnd();

    for (int i = 0; i < 3; i++)
    {
        glTranslated(-0.6, 0.0, 0.0);
        glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.6f, -0.4f);
        glVertex2f(-1.5f, -0.4f);

        glVertex2f(-1.5f, -0.4f);
        glVertex2f(-1.5f, -0.1f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(191, 191, 191);
        glVertex2f(-1.5f, -0.1f);
        glVertex2f(-1.55f, -0.1f);
        glVertex2f(-1.55f, -0.25f);
        glVertex2f(-1.5f, -0.25f);
        glEnd();
        glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(-1.6f, -0.4f);
        glEnd();
    }

    // right-up
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.4f, 0.4f);
    glVertex2f(1.5f, 0.4f);

    glVertex2f(1.5f, 0.4f);
    glVertex2f(1.5f, 0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(1.5f, 0.1f);
    glVertex2f(1.45f, 0.1f);
    glVertex2f(1.45f, 0.25f);
    glVertex2f(1.5f, 0.25f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(1.4f, 0.4f);
    glEnd();

    // right-down
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.7f, -0.4f);
    glVertex2f(1.8f, -0.4f);

    glVertex2f(1.8f, -0.4f);
    glVertex2f(1.8f, -0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(1.8f, -0.1f);
    glVertex2f(1.75f, -0.1f);
    glVertex2f(1.75f, -0.25f);
    glVertex2f(1.8f, -0.25f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(1.7f, -0.4f);
    glEnd();

    // bottom-left
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(0.5f, -0.7f);
    glVertex2f(0.5f, -0.6f);

    glVertex2f(0.5f, -0.6f);
    glVertex2f(0.8f, -0.6f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(0.8f, -0.6f);
    glVertex2f(0.8f, -0.65f);
    glVertex2f(0.65f, -0.65f);
    glVertex2f(0.65f, -0.6f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(0.5f, -0.7f);
    glEnd();

    // bottom-right
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.3f, -1.0f);
    glVertex2f(1.3f, -0.9f);

    glVertex2f(1.3f, -0.9f);
    glVertex2f(1.0f, -0.9f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(1.0f, -0.9f);
    glVertex2f(1.0f, -0.95f);
    glVertex2f(1.15f, -0.95f);
    glVertex2f(1.15f, -0.9f);
    glEnd();

    // top-left
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(0.5f, 0.8f);
    glVertex2f(0.5f, 0.9f);

    glVertex2f(0.5f, 0.9f);
    glVertex2f(0.8f, 0.9f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(0.8f, 0.9f);
    glVertex2f(0.8f, 0.85f);
    glVertex2f(0.65f, 0.85f);
    glVertex2f(0.65f, 0.9f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(0.5f, 0.8f);
    glEnd();

    // top-right
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.3f, 0.5f);
    glVertex2f(1.3f, 0.6f);

    glVertex2f(1.3f, 0.6f);
    glVertex2f(1.0f, 0.6f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(1.0f, 0.55f);
    glVertex2f(1.15f, 0.55f);
    glVertex2f(1.15f, 0.6f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(1.3f, 0.5f);
    glEnd();
}
void boat1()
{
    glPushMatrix();
    glTranslatef(position_b1, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(255, 140, 26);
    glVertex2f(-0.05f, -0.75f);
    glVertex2f(-0.05f, -0.8f);
    glVertex2f(0.1f, -0.8f);
    glVertex2f(0.1f, -0.75f);
    glEnd();

    x = 0.1f;
    y = -0.8f;
    radius = .05f;
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(255, 140, 26);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = -0.05f;
    y = -0.8f;
    radius = .05f;
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(179, 89, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.25f, -0.8f);
    glVertex2f(0.25f, -0.8f);
    glVertex2f(0.15f, -0.85f);
    glVertex2f(-0.15f, -0.85f);
    glEnd();
    glPopMatrix();
}
void car1()
{
    glPushMatrix();
    glTranslatef(position_c1, 0.0f, 0.0f);
    glBegin(GL_POLYGON); // body
    glColor3ub(230, 0, 0);
    glVertex2f(-0.2f, 0.25f);
    glVertex2f(0.07f, 0.25f);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.07f, 0.05f);
    glVertex2f(-0.2f, 0.05f);
    glVertex2f(-0.22f, 0.07f);
    glVertex2f(-0.22f, 0.23f);
    glEnd();

    glBegin(GL_POLYGON); // window
    glColor3ub(0, 0, 0);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.07f, 0.06f);
    glVertex2f(-0.18f, 0.06f);
    glVertex2f(-0.18f, 0.24f);
    glEnd();
    glBegin(GL_POLYGON); // roof
    glColor3ub(230, 0, 0);
    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.03f, 0.21f);
    glVertex2f(-0.15f, 0.21f);
    glVertex2f(-0.15f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.14f, 0.2f);
    glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.14f, 0.1f);
    glVertex2f(0.14f, 0.07f);
    glEnd();

    if (flag != 0)
    {
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.23f);
        glVertex2f(0.45f, 0.3f);
        glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.07f);
        glVertex2f(0.45f, 0.0f);
        glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_LINES);
    glColor3ub(230, 0, 0);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.03f, 0.21f);

    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.07f, 0.06f);

    glVertex2f(-0.18f, 0.06f);
    glVertex2f(-0.15f, 0.09f);

    glVertex2f(-0.15f, 0.21f);
    glVertex2f(-0.18f, 0.24f);

    glVertex2f(-0.06f, 0.24f);
    glVertex2f(-0.06f, 0.21f);

    glVertex2f(-0.06f, 0.09f);
    glVertex2f(-0.06f, 0.06f);
    glEnd();

    glPopMatrix();
}
void car2()
{
    glPushMatrix();
    glTranslatef(position_c2, 0.0f, 0.0f);
    glRotatef(180, 0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON); // body
    glColor3ub(255, 204, 0);
    glVertex2f(-0.04f, 0.25f);
    glVertex2f(0.07f, 0.25f);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.07f, 0.05f);
    glVertex2f(-0.04f, 0.05f);
    glEnd();

    glBegin(GL_POLYGON); // window
    glColor3ub(0, 0, 0);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.07f, 0.06f);
    glVertex2f(-0.03f, 0.06f);
    glVertex2f(-0.03f, 0.24f);
    glEnd();
    glBegin(GL_POLYGON); // roof
    glColor3ub(255, 204, 0);
    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.03f, 0.21f);
    glVertex2f(-0.07f, 0.21f);
    glVertex2f(-0.07f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.14f, 0.2f);
    glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.14f, 0.1f);
    glVertex2f(0.14f, 0.07f);
    glEnd();

    if (flag != 0)
    {
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.23f);
        glVertex2f(0.45f, 0.3f);
        glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.07f);
        glVertex2f(0.45f, 0.0f);
        glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_POLYGON); // lorry
    glColor3ub(242, 242, 242);
    glVertex2f(-0.06f, 0.25f);
    glVertex2f(-0.06f, 0.05f);
    glVertex2f(-0.5f, 0.05f);
    glVertex2f(-0.5f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 204, 0);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.03f, 0.21f);

    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.07f, 0.06f);

    glVertex2f(-0.03f, 0.24f);
    glVertex2f(-0.03f, 0.21f);

    glVertex2f(-0.03f, 0.09f);
    glVertex2f(-0.03f, 0.06f);

    glColor3ub(217, 217, 217);
    glVertex2f(-0.06f, 0.25f);
    glVertex2f(-0.06f, 0.05f);

    glVertex2f(-0.06f, 0.05f);
    glVertex2f(-0.5f, 0.05f);

    glVertex2f(-0.5f, 0.05f);
    glVertex2f(-0.5f, 0.25f);

    glVertex2f(-0.5f, 0.25f);
    glVertex2f(-0.06f, 0.25f);
    glEnd();

    glPopMatrix();
}
void car3()
{
    glPushMatrix();
    glTranslatef(0.9, position_c3, 0.0f);
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON); // body
    glColor3ub(255, 255, 255);
    glVertex2f(-0.13f, 0.25f);
    glVertex2f(0.07f, 0.25f);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.07f, 0.05f);
    glVertex2f(-0.13f, 0.05f);
    glVertex2f(-0.15f, 0.07f);
    glVertex2f(-0.15f, 0.23f);
    glEnd();

    glBegin(GL_POLYGON); // window
    glColor3ub(0, 0, 0);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.07f, 0.06f);
    glVertex2f(-0.13f, 0.06f);
    glVertex2f(-0.13f, 0.24f);
    glEnd();
    glBegin(GL_POLYGON); // roof
    glColor3ub(255, 255, 255);
    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.03f, 0.21f);
    glVertex2f(-0.1f, 0.21f);
    glVertex2f(-0.1f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.14f, 0.2f);
    glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.14f, 0.1f);
    glVertex2f(0.14f, 0.07f);
    glEnd();

    if (flag != 0)
    {
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.23f);
        glVertex2f(0.45f, 0.3f);
        glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.07f);
        glVertex2f(0.45f, 0.0f);
        glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.03f, 0.21f);

    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.07f, 0.06f);

    glVertex2f(-0.13f, 0.06f);
    glVertex2f(-0.1f, 0.09f);

    glVertex2f(-0.1f, 0.21f);
    glVertex2f(-0.13f, 0.24f);

    glVertex2f(-0.03f, 0.24f);
    glVertex2f(-0.03f, 0.21f);

    glVertex2f(-0.03f, 0.09f);
    glVertex2f(-0.03f, 0.06f);
    glEnd();

    glPopMatrix();
}
void car4()
{
    glPushMatrix();
    glTranslatef(0.9f, position_c4, 0.0f);
    glRotatef(270, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON); // body
    glColor3ub(51, 102, 255);
    glVertex2f(-0.13f, 0.25f);
    glVertex2f(0.07f, 0.25f);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.07f, 0.05f);
    glVertex2f(-0.13f, 0.05f);
    glVertex2f(-0.15f, 0.07f);
    glVertex2f(-0.15f, 0.23f);
    glEnd();

    glBegin(GL_POLYGON); // window
    glColor3ub(0, 0, 0);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.07f, 0.06f);
    glVertex2f(-0.13f, 0.06f);
    glVertex2f(-0.13f, 0.24f);
    glEnd();
    glBegin(GL_POLYGON); // roof
    glColor3ub(51, 102, 255);
    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.03f, 0.21f);
    glVertex2f(-0.1f, 0.21f);
    glVertex2f(-0.1f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.14f, 0.2f);
    glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.14f, 0.1f);
    glVertex2f(0.14f, 0.07f);
    glEnd();

    if (flag != 0)
    {
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.23f);
        glVertex2f(0.45f, 0.3f);
        glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.07f);
        glVertex2f(0.45f, 0.0f);
        glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_LINES);
    glColor3ub(51, 102, 255);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.03f, 0.21f);

    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.07f, 0.06f);

    glVertex2f(-0.13f, 0.06f);
    glVertex2f(-0.1f, 0.09f);

    glVertex2f(-0.1f, 0.21f);
    glVertex2f(-0.13f, 0.24f);

    glVertex2f(-0.03f, 0.24f);
    glVertex2f(-0.03f, 0.21f);

    glVertex2f(-0.03f, 0.09f);
    glVertex2f(-0.03f, 0.06f);
    glEnd();

    glPopMatrix();
}
void river()
{
    glBegin(GL_POLYGON);
    glColor3ub(51, 204, 255);
    glVertex2f(-2.0f, -1.0f);
    glVertex2f(-2.0f, -0.55f);
    glVertex2f(0.35f, -0.55f);
    glVertex2f(0.35f, -2.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(position_r, 0.0f, 0.0f);

    x = 1.0f;
    y = -1.3f;
    radius = 0.6f;
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 191, 255);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.5f;
    y = -1.3f;
    radius = 0.6f;
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 191, 255);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = 0.0f;
    y = -1.3f;
    radius = 0.6f;
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 191, 255);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = -0.5f;
    y = -1.3f;
    radius = 0.6f;
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 191, 255);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = -1.0f;
    y = -1.3f;
    radius = 0.6f;
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 191, 255);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = -1.5f;
    y = -1.3f;
    radius = 0.6f;
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 191, 255);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    x = -2.0f;
    y = -1.3f;
    radius = 0.6f;
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 191, 255);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glPopMatrix();
}
void redgreen1()
{
    x = 0.7f;
    y = 0.1f;
    radius = .02f; // red
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(255, 51, 51);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.95f;
    y = -0.25f;
    radius = .02f; // green
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 255, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}
void redgreen2()
{
    x = 0.7f;
    y = 0.0f;
    radius = .02f; // green
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 255, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x = 0.95f;
    y = -0.15f;
    radius = .02f; // red
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(255, 51, 51);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}
void rain()
{
    glPushMatrix();
    glTranslatef(position_rain2, position_rain, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.9f);
    glVertex2f(0.05f, 0.85f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.7f);
    glVertex2f(0.05f, 0.65f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.05f, 0.45f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(0.05f, 0.25f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.1f);
    glVertex2f(0.05f, 0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.05f, -0.9f);
    glVertex2f(0.0f, -0.85f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.05f, -0.7f);
    glVertex2f(0.0f, -0.65f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.05f, -0.5f);
    glVertex2f(0.0f, -0.45f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.05f, -0.3f);
    glVertex2f(0.0f, -0.25f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.05f, -0.1f);
    glVertex2f(0.0f, -0.05f);
    glEnd();

    for (int i = 0; i < 100; i++)
    {
        glTranslatef(-0.2, 0.0, 0.0f);
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.9f);
        glVertex2f(0.05f, 0.85f);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.7f);
        glVertex2f(0.05f, 0.65f);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.05f, 0.45f);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.3f);
        glVertex2f(0.05f, 0.25f);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.1f);
        glVertex2f(0.05f, 0.05f);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.9f);
        glVertex2f(0.0f, -0.85f);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.7f);
        glVertex2f(0.0f, -0.65f);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.5f);
        glVertex2f(0.0f, -0.45f);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.3f);
        glVertex2f(0.0f, -0.25f);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.1f);
        glVertex2f(0.0f, -0.05f);
        glEnd();
    }

    glPopMatrix();
}
void start()
{
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-2.0f, 2.0f);
    glColor3ub(147, 112, 219);
    glVertex2f(2.0f, 2.0f);
    glColor3ub(30, 144, 255);
    glVertex2f(2.0f, -2.0f);
    glColor3ub(70, 130, 180);
    glVertex2f(-2.0f, -2.0f);
    glEnd();

    glColor3ub(255, 255, 255);
    const char *y = "Traffic  Signal  In  The  City";
    glRasterPos2f(-0.3, 0.7);
    for (int i = 0; y[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, y[i]);

    glColor3ub(0, 0, 0);
    const char *u = "Feature: \n-> Press 'R' = Turn on RED signal for HORIZONTAL road and Turn on GREEN signal for VERTICAL road. \n-> Press 'G' = Turn on GREEN signal for HORIZONTAL road and Turn on RED signal for VERTICAL road.";
    float x = 0.3f;
    glRasterPos2f(-1.5, 0.3);
    for (int i = 0; u[i] != '\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, u[i]);
        if (u[i] == '\n')
            glRasterPos2f(-1.5, x = x - 0.1);
    }

    glColor3ub(0, 0, 0);
    const char *k = "-> Press 'D' = Switch to DAY view. \n-> Press 'N' = Switch to NIGHT view. \n-> Press 'LMB' = Start RAIN. \n-> Press 'RMB' = Stop RAIN.";
    glRasterPos2f(-1.5, x = x - 0.1);
    for (int i = 0; k[i] != '\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, k[i]);
        if (k[i] == '\n')
            glRasterPos2f(-1.5, x = x - 0.1);
    }

    glColor3ub(255, 0, 0);
    const char *s = "Press F to START the project";
    glRasterPos2f(-0.3, -0.7);
    for (int i = 0; s[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);

    glFlush();
}
void day()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    // Background
    glBegin(GL_POLYGON);
    glColor3ub(51, 204, 51);
    glVertex2f(2.0f, 1.0f);
    glVertex2f(2.0f, -1.0f);
    glVertex2f(-2.0f, -1.0f);
    glVertex2f(-2.0f, 1.0f);
    glEnd();

    river();

    glBegin(GL_POLYGON);
    glColor3ub(51, 204, 51);
    glVertex2f(0.35f, -0.5f);
    glVertex2f(1.9f, -0.5f);
    glVertex2f(1.9f, -1.0f);
    glVertex2f(0.35f, -1.0f);
    glEnd();
    // Objects
    road_footpath();
    car1();
    car2();
    car3();
    car4();
    traffic_light1();
    traffic_light2();
    road_light();
    factory();

    glPushMatrix();
    windmill();
    glPopMatrix();
    house();
    boat1();

    if (cnt == 0)
        redgreen2();
    else
        redgreen1();

    if (r != 0)
        rain();

    glFlush();
}
void night()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    // Background
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(2.0f, 1.0f);
    glVertex2f(2.0f, -1.0f);
    glVertex2f(-2.0f, -1.0f);
    glVertex2f(-2.0f, 1.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(0.35f, -0.5f);
    glVertex2f(1.9f, -0.5f);
    glVertex2f(1.9f, -1.0f);
    glVertex2f(0.35f, -1.0f);
    glEnd();

    river();

    glBegin(GL_POLYGON);
    glColor3ub(51, 204, 51); // Still daytime color ground/river
    glVertex2f(0.35f, -0.5f);
    glVertex2f(1.9f, -0.5f);
    glVertex2f(1.9f, -1.0f);
    glVertex2f(0.35f, -1.0f);
    glEnd();

    road_footpath();
    car1();
    car2();
    car3();
    car4();
    traffic_light1();
    traffic_light2();
    road_light();
    factory();

    glPushMatrix();
    windmill();
    glPopMatrix();

    house();
    /// road-light start
    glLineWidth(3.0f);
    // left-up
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-1.9f, 0.4f);
    glVertex2f(-1.8f, 0.4f);

    glVertex2f(-1.8f, 0.4f);
    glVertex2f(-1.8f, 0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-1.85f, 0.25f);
    glVertex2f(-1.8f, 0.25f);
    glVertex2f(-1.8f, 0.1f);
    glVertex2f(-1.85f, 0.1f);
    glEnd();
    glPointSize(10.0); //
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(-1.9f, 0.4f);
    glEnd();

    for (int i = 0; i < 3; i++)
    {
        glTranslated(0.6, 0.0, 0.0);
        glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.9f, 0.4f);
        glVertex2f(-1.8f, 0.4f);

        glVertex2f(-1.8f, 0.4f);
        glVertex2f(-1.8f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2f(-1.85f, 0.25f);
        glVertex2f(-1.8f, 0.25f);
        glVertex2f(-1.8f, 0.1f);
        glVertex2f(-1.85f, 0.1f);
        glEnd();
        glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(-1.9f, 0.4f);
        glEnd();
    }

    // left-down
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-1.6f, -0.4f);
    glVertex2f(-1.5f, -0.4f);

    glVertex2f(-1.5f, -0.4f);
    glVertex2f(-1.5f, -0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-1.5f, -0.1f);
    glVertex2f(-1.55f, -0.1f);
    glVertex2f(-1.55f, -0.25f);
    glVertex2f(-1.5f, -0.25f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(-1.6f, -0.4f);
    glEnd();

    for (int i = 0; i < 3; i++)
    {
        glTranslated(-0.6, 0.0, 0.0);
        glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.6f, -0.4f);
        glVertex2f(-1.5f, -0.4f);

        glVertex2f(-1.5f, -0.4f);
        glVertex2f(-1.5f, -0.1f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2f(-1.5f, -0.1f);
        glVertex2f(-1.55f, -0.1f);
        glVertex2f(-1.55f, -0.25f);
        glVertex2f(-1.5f, -0.25f);
        glEnd();
        glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(-1.6f, -0.4f);
        glEnd();
    }

    // right-up
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.4f, 0.4f);
    glVertex2f(1.5f, 0.4f);

    glVertex2f(1.5f, 0.4f);
    glVertex2f(1.5f, 0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(1.5f, 0.1f);
    glVertex2f(1.45f, 0.1f);
    glVertex2f(1.45f, 0.25f);
    glVertex2f(1.5f, 0.25f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(1.4f, 0.4f);
    glEnd();

    // right-down
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.7f, -0.4f);
    glVertex2f(1.8f, -0.4f);

    glVertex2f(1.8f, -0.4f);
    glVertex2f(1.8f, -0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(1.8f, -0.1f);
    glVertex2f(1.75f, -0.1f);
    glVertex2f(1.75f, -0.25f);
    glVertex2f(1.8f, -0.25f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(1.7f, -0.4f);
    glEnd();

    // bottom-left
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(0.5f, -0.7f);
    glVertex2f(0.5f, -0.6f);

    glVertex2f(0.5f, -0.6f);
    glVertex2f(0.8f, -0.6f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(0.8f, -0.6f);
    glVertex2f(0.8f, -0.65f);
    glVertex2f(0.65f, -0.65f);
    glVertex2f(0.65f, -0.6f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(0.5f, -0.7f);
    glEnd();

    // bottom-right
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.3f, -1.0f);
    glVertex2f(1.3f, -0.9f);

    glVertex2f(1.3f, -0.9f);
    glVertex2f(1.0f, -0.9f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(1.0f, -0.9f);
    glVertex2f(1.0f, -0.95f);
    glVertex2f(1.15f, -0.95f);
    glVertex2f(1.15f, -0.9f);
    glEnd();

    // top-left
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(0.5f, 0.8f);
    glVertex2f(0.5f, 0.9f);

    glVertex2f(0.5f, 0.9f);
    glVertex2f(0.8f, 0.9f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(0.8f, 0.9f);
    glVertex2f(0.8f, 0.85f);
    glVertex2f(0.65f, 0.85f);
    glVertex2f(0.65f, 0.9f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(0.5f, 0.8f);
    glEnd();

    // top-right
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.3f, 0.5f);
    glVertex2f(1.3f, 0.6f);

    glVertex2f(1.3f, 0.6f);
    glVertex2f(1.0f, 0.6f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(1.0f, 0.55f);
    glVertex2f(1.15f, 0.55f);
    glVertex2f(1.15f, 0.6f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(1.3f, 0.5f);
    glEnd();
    /// road-light end

    // Boat could have lights reflecting on water
    boat1();

    // Change traffic lights to night mode (red, green for night)
    if (cnt == 0)
        redgreen2();
    else
        redgreen1();

    if (r != 0)
        rain();

    glFlush();
}
void update_car1(int value)
{
    if (cnt == 0)
    {
        speed_c1 = 0.01f;
        if (position_c1 > 2.7)
            position_c1 = -2.7f;

        position_c1 += speed_c1;
    }

    else
    {
        if (position_c1 > 0.0)
        {
            speed_c1 = 0.0f;
            position_c1 = 0.0;
        }
        position_c1 += speed_c1;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update_car1, 0);
}
void update_car2(int value)
{
    if (cnt == 0)
    {
        speed_c2 = 0.01f;
        if (position_c2 < -2.7)
            position_c2 = 2.7f;

        position_c2 -= speed_c2;
    }
    else
    {
        if (position_c2 < 1.8)
        {
            speed_c2 = 0.0f;
            position_c2 = 1.8;
        }
        position_c2 -= speed_c2;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update_car2, 0);
}
void update_car3(int value)
{
    if (cnt == 0)
    {
        if (position_c3 > -0.9)
        {
            speed_c3 = 0.0f;
            position_c3 = -0.9;
        }
        position_c3 += speed_c3;
    }

    else
    {
        speed_c3 = 0.01f;
        if (position_c3 > 1.7)
            position_c3 = -1.7f;

        position_c3 += speed_c3;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update_car3, 0);
}
void update_car4(int value)
{
    if (cnt == 0)
    {
        if (position_c4 < 0.9)
        {
            speed_c4 = 0.0f;
            position_c4 = 0.9;
        }
        position_c4 -= speed_c4;
    }

    else
    {
        speed_c4 = 0.01f;
        if (position_c4 < -1.7)
            position_c4 = 1.7f;

        position_c4 -= speed_c4;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update_car4, 0);
}
void update_river(int value)
{
    if (position_r < -0.5)
        position_r = 0.0f;

    position_r -= speed_r;

    glutPostRedisplay();
    glutTimerFunc(100, update_river, 0);
}
void update_boat1(int value)
{
    if (position_b1 < -2.0)
        position_b1 = 0.0f;

    position_b1 -= speed_b1;

    glutPostRedisplay();
    glutTimerFunc(100, update_boat1, 0);
}
void update_rain(int value)
{
    if (position_rain < -0.1)
        position_rain = 0.3f;

    position_rain -= speed_rain;

    if (position_rain2 > 2.0)
        position_rain2 = 1.8f;

    position_rain2 += speed_rain2;

    glutPostRedisplay();
    glutTimerFunc(100, update_rain, 0);
}
void update_windmill(int v)
{
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30, update_windmill, 0);
}
void button(unsigned char key, int x, int y)
{

    switch (key)
    {
    case 'f':
        glutDisplayFunc(day);
        break;

    case 'r':
        cnt++;
        break;

    case 'g':
        cnt = 0;
        break;

    case 'n':
        flag++;
        glutDisplayFunc(night);
        glutPostRedisplay();
        break;

    case 'd':
        flag = 0;
        glutDisplayFunc(day);
        glutPostRedisplay();
        break;
    }
}
void rain_button(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        r++;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        r = 0;
    }
}
void inigl()
{
    gluOrtho2D(-2, 2, -1, 1); // Set range of axis of display (left, right, bottom, top)
}
// Main function: GLUT runs as a console application starting at main()
int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1430, 800); // Set the window's initial width & height
    glutInitWindowPosition(0, 0);  // Set the window position
    glutCreateWindow("cars");      // Create a window with the given title

    glutDisplayFunc(start);
    inigl();
    glutTimerFunc(30, update_windmill, 0);
    glutTimerFunc(100, update_boat1, 0);
    glutTimerFunc(100, update_river, 0);
    glutTimerFunc(10, update_car1, 0);
    glutTimerFunc(10, update_car2, 0);
    glutTimerFunc(10, update_car3, 0);
    glutTimerFunc(10, update_car4, 0);
    glutTimerFunc(100, update_rain, 0);

    glutKeyboardFunc(button);
    glutMouseFunc(rain_button);

    glutMainLoop();
    return 0;
}
