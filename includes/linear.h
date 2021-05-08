#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#ifndef LINEAR_H
# define LINEAR_H

/**********************************/
/* Функции для работы с векторами */
/**********************************/
vector<double>      AddTwoVectors(const vector<double>& v, const vector<double> w);
vector<double>      SubstractTwoVectors(const vector<double>& v, const vector<double>& w);
vector<double>      VectorsSum(const vector< vector<double> >& vectors);
vector<double>      ScalarMultiply(double scalar, const vector<double>& v);
vector<double>      VectorMean(const vector< vector<double> >& vectors);

// double              Distance1(const vector<double>& v, const vector<double>& w);
double              Distance(const vector<double>& v, const vector<double>& w);
double              SquaredDistance(const vector<double>& v, const vector<double>& w);
double              Magnitude(const vector<double>& v);
double              SumOfSquares(const vector<double>& v);
double              Dot(const vector<double>& v, const vector<double>& w);

/**************************/
/* Статистические функции */
/**************************/

/**********************/
/* Теория вероятности */
/**********************/

#endif
