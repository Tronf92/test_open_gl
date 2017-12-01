#include <GL\freeglut.h>
#include <GL\glut.h>

const int NumVertices = 36;
float theta= 1.0;

void display(){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glDrawArrays( GL_TRIANGLES, 0, NumVertices);
	glRotatef(theta,1.0,2.0,3.0);
	glBegin(GL_TRIANGLES);
	glColor3f(1.2f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
                glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);
	
	theta+=1.1;
	glEnd();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x,int y){
	switch ( key )
	{
	case 033: case 'q': case 'Q' :
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char **argv){
	glutInit( &argc, argv);
	glutInitDisplayMode(GLUT_RGBA  | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Color Cube");
	
	glutDisplayFunc( display );
	glutKeyboardFunc( keyboard );
	glutMainLoop();
	
	return 0;

}