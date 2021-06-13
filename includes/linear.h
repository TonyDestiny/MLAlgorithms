#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <functional>

using namespace std;

#ifndef LINEAR_H
# define LINEAR_H

# define SQRT_TWO_PI sqrt(2 * M_PI)

/**********************************/
/* Функции для работы с векторами */
/**********************************/

struct ShapeMatrix {
    int num_rows;
    int num_cols;
};

vector<vector<double>>  MakeMatrix(const size_t num_rows, const size_t num_col,
                                  const function<double(int, int)> func);

vector<double>          AddTwoVectors(const vector<double>& v, const vector<double> w);
vector<double>          SubstractTwoVectors(const vector<double>& v, const vector<double>& w);
vector<double>          VectorsSum(const vector< vector<double> >& vectors);
vector<double>          ScalarMultiply(double scalar, const vector<double>& v);
vector<double>          VectorMean(const vector< vector<double> >& vectors);
vector<double>          GetRow(vector<vector<double>>& m, int row);
vector<double>          GetColumn(vector<vector<double>>& m, int col);

ShapeMatrix             Shape(vector<vector<double>>& m);

// double                  Distance1(const vector<double>& v, const vector<double>& w);
double                  Distance(const vector<double>& v, const vector<double>& w);
double                  SquaredDistance(const vector<double>& v, const vector<double>& w);
double                  Magnitude(const vector<double>& v);
double                  SumOfSquares(const vector<double>& v);
double                  Dot(const vector<double>& v, const vector<double>& w);

void                    PrintMatrix(const vector<vector<double>>& pmatrix);

/**************************/
/* Статистические функции */
/**************************/

double                  Mean(vector<double>& x);
double                  Median(vector<double> v);
double                  Quantile(vector<double> v, double p);
double                  DataRange( vector<double> v);
double                  Variance(vector<double>& v);
double                  StandartDeviation(vector<double>& v);
double                  InterquantileRange(vector<double> v);

vector<double>          Mode(vector<double> v);
double                  Covariance(vector<double> xs, vector<double> ys);
double                  Correlation(vector<double> xs, vector<double> ys);

/**********************/
/* Теория вероятности */
/**********************/

double                  UniformPDF(double x);
double                  UniformCDF(double x);
double                  NormalPDF(double x, double mu = 0, double sigma = 1);
double                  NormalCDF(double x, double mu = 0, double sigma = 1);
double                  InverseNormalCDF(double p, double mu = 0, 
                            double sigma = 1, double tolerance = 0.00001);

#endif
