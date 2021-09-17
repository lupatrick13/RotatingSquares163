/*
 * util.cpp
 *
 *  Created on: Sep 12, 2021
 *      Author: lupat
 */

#include "util.h"


float RNG_REAL(float lower, float upper)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distrib(lower, upper);

    return distrib(gen);
}

pair<float, float> rotate(float x, float y, float alpha)
{
	float degree = alpha * PI / 180.0;
	float newx = x * cos(degree) - y * sin(degree);
	float newy = x * sin(degree) + y * cos(degree);

	return make_pair(newx, newy);
}

pair<float, float> resize(float px1, float py1, float px2, float py2, float alpha)
{
	float newx = px1 + alpha * (px2 - px1);
	float newy = py1 + alpha * (py2 - py1);
	return make_pair(newx, newy);
}

vector<float> rotate_polygon(vector<float> positions, int edges)
{
	vector<float> results;
	int it = edges*2;
	for(int i = 0; i < it; i+=2)
	{
		pair<float, float> newp1 = resize(positions[i], positions[i+1],
										  positions[(i+2)%it], positions[(i+3)%it], 0.95);
		results.push_back(newp1.first);
		results.push_back(newp1.second);
	}
	return results;
}
float distance(float px1, float py1, float px2, float py2)
{
	float deltax = pow(px2-px1, 2);
	float deltay = pow(py2-py1, 2);
	return sqrt(deltax+ deltay);
}

