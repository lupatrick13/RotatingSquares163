/*
 * fractal.h
 *
 *  Created on: Sep 12, 2021
 *      Author: lupat
 */
#include "util.h"
#ifndef FRACTAL_H_
#define FRACTAL_H_


void make_branch(float px1, float py1, float len, int iter = 3,  int base_deg = 360)
{
	if(iter > 0)
	{
		int degree_rotate = 42;
		float r = RNG_REAL(0, 1), g = RNG_REAL(0,1), b = RNG_REAL(0, 1);
		glColor3f(r, g, b);
		pair<float, float> angledpos = rotate(0, len, base_deg);
		pair<float, float> newpos = resize(px1, py1, angledpos.first+px1, angledpos.second+py1, 0.8);

		for(int i = -1; i < 2; i++)
		{
			int curr_deg = i * degree_rotate;
			pair<float, float> temppos = rotate(newpos.first - px1, newpos.second - py1, curr_deg);

			temppos.first += px1;
			temppos.second += py1;

			glBegin(GL_LINES);
				glVertex2f(px1, py1);
				glVertex2f(temppos.first, temppos.second);
			glEnd();
			make_branch(temppos.first, temppos.second, distance(px1, py1, temppos.first, temppos.second), iter - 1, curr_deg +base_deg);
		}
	}
}

void make_fractal()
{
	float y_pos = RNG_REAL(-0.8, -0.44);
	float x_pos = RNG_REAL(-0.75, 0.75);

	// create the trunk at a random X_pos
	glBegin(GL_LINES);
        glVertex2f(x_pos, -1.0);
        glVertex2f(x_pos, y_pos);
    glEnd();

    make_branch(x_pos, y_pos,distance(x_pos, -1.0, x_pos, y_pos), 8);
}


#endif /* FRACTAL_H_ */
