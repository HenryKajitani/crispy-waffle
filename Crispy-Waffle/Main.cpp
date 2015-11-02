#include <cmath>
#include <vector>
#include <Windows.h>

#include <GL/glut.h>

#include "Enemy.h"
#include "Gamepad.h"
#include "Vector2.h"

using namespace std;

// Prototypes
//--------------------------//
void init(void);
void displayFunc(void);
void timerFunc(int);

// Variables
//--------------------------//
vector<Enemy> enemies;

// Main
//--------------------------//
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(1280, 600);

	glutCreateWindow("Crispy-Waffle");

	initOpenGL();
	glutDisplayFunc(displayFunc);
	glutTimerFunc(20, timerFunc, 0);
	glutMainLoop();
}

// OpenGL functions
//--------------------------//
void initOpenGL(void)
{
	//Set up the window
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1280, 600, 0);
	glMatrixMode(GL_MODELVIEW);
}

Vector2 location;

void displayFunc()
{
	//Clear the window
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, 1280, 600);

	glLoadIdentity();
	glTranslatef(location.X, location.Y, 0);
	glScalef(8, 8, 0);

	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);
	{
		glVertex2d(-1, 1);
		glVertex2d(-1, -1);
		glVertex2d(1, -1);
		glVertex2d(1, 1);
	}
	glEnd();

	glFlush();

	//Swap frame buffer (vsync)
	glutSwapBuffers();
}

Gamepad controller = Gamepad(1);

void timerFunc(int n)
{
	checkController();

	glutPostRedisplay();
	glutTimerFunc(17, timerFunc, 0);
}

// Game Functions
//--------------------------//

void checkController()
{
	controller.Update(); // Update the gamepad

	// Get stick input as a normalized vector
	Vector2 leftStick = Vector2(controller.LeftStick_X(), -controller.LeftStick_Y()).Normal();
	Vector2 rightStick = Vector2(controller.RightStick_X(), -controller.RightStick_Y()).Normal();

	// Move the player
	if (leftStick.Magnitude() > .1) // Deadzone
		location += leftStick * 5;

	controller.RefreshState();
}

void spawnEnemy(Enemy e, int chance)
{
	if (rand() % chance == 0)
		enemies.push_back(e);
}