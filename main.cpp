/* ----------------------------------------------------------*
 * Program name: RotateSquares_Tree; Coded by: Patrick Lu    *
 * Date        : 9/11/2021;        Version : 0x1.0;          *
 * Status      : Tested;                                     *
 * Note        : 1. Compatible with Windows 10, need glut    *
 *               Youtube Installation Guide:                 *
 *               https://www.youtube.com/watch?v=qFlJXMpxAO4 *
 *               2. Linker Libraries: freeglut, opengl32,    *
 *               	glu32                                    *
 *               3. Eclipse IDE                              *
 * ----------------------------------------------------------*
 **/
// TODO: (9/16/2021) (HL) Change algorithm for rotating squares to one without trig. -Done

#include "box.h"
#include "fractal.h"

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
//    	make_fractal();
    	make_box_it();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
