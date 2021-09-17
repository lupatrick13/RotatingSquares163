/*
 * box.cpp
 *
 *  Created on: Sep 12, 2021
 *      Author: lupat
 */
#include <GL/glut.h>
#include <utility>
#include <iostream>
#include "util.h"

using namespace std;

#ifndef BOX_H_
#define BOX_H_


void make_box_it()
{
	vector<float> positions
	{
			-0.75f, -0.75f,
			-0.75f, 0.75f,
			0.75f, 0.75f,
			0.75f, -0.75f
	};
	// Define anchor point
	float anchorx = .5, anchory = .5;
	vector<float> temp;

	float r = RNG_REAL(0, 1), g = RNG_REAL(0, 1), b = RNG_REAL(0, 1);
	glColor3f(r,g,b);

    for(int i = 0; i<60; i++)
    {
    	glColor3f(r,g,b);
		glBegin(GL_LINES);
			// line 1
			glVertex2f(positions[0] + anchorx, positions[1]+ anchory);
			glVertex2f(positions[2]+ anchorx, positions[3]+ anchory);
			// line 2
			glVertex2f(positions[2]+ anchorx, positions[3]+ anchory);
			glVertex2f(positions[4]+ anchorx, positions[5]+ anchory);
			// line 3
			glVertex2f(positions[4]+ anchorx, positions[5]+ anchory);
			glVertex2f(positions[6]+ anchorx, positions[7]+ anchory);
			// line 4
			glVertex2f(positions[0]+ anchorx, positions[1]+ anchory);
			glVertex2f(positions[6]+ anchorx, positions[7]+ anchory);
		glEnd();
		glColor3f(1,0,0);

		glBegin(GL_LINES);
			// line 1
			glVertex2f(positions[0] + anchorx/3, positions[1]+ anchory/-5);
			glVertex2f(positions[2]+ anchorx/3, positions[3]+ anchory/-5);
			// line 2
			glVertex2f(positions[2]+ anchorx/3, positions[3]+ anchory/-5);
			glVertex2f(positions[4]+ anchorx/3, positions[5]+ anchory/-5);
			// line 3
			glVertex2f(positions[4]+ anchorx/3, positions[5]+ anchory/-5);
			glVertex2f(positions[6]+ anchorx/3, positions[7]+ anchory/-5);
			// line 4
			glVertex2f(positions[0]+ anchorx/3, positions[1]+ anchory/-5);
			glVertex2f(positions[6]+ anchorx/3, positions[7]+ anchory/-5);
		glEnd();
		for(int j= 0; j < 8; j+=2)
		{
			pair<float, float> newp1 = resize(positions[j], positions[j+1],
											  positions[(j+2)%8], positions[(j+3)%8], 0.05);
			temp.push_back(newp1.first);
			temp.push_back(newp1.second);
		}
		positions = temp;
		temp.clear();
    }
}

#endif /* BOX_CPP_ */
