/*
 * util.cpp
 *
 *  Created on: Sep 12, 2021
 *      Author: lupat
 */
#include <random>

using namespace std;

#ifndef UTILL_H_
#define UTIL_H_

#define PI 3.14159
float RNG_REAL(float lower, float upper);

pair<float, float> rotate(float x, float y, float alpha);

pair<float, float> resize(float px1, float py1, float px2, float py2, float alpha);

vector<float> rotate_polygon(vector<float> positions, int edges);

float distance(float px1, float py1, float px2, float py2);
#endif
