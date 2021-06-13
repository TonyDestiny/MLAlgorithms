#include "../includes/linear.h"

bool CheckSizeVectors(const vector<double>& v, const vector<double>& w) {
    if (v.size() != w.size()) {
        cout << "Векторы должны иметь одинаковую длину!\n"
             << "v.size() = " << v.size() << endl
             << "w.size() = " << w.size() << endl;
        
        return false;
    }

    return true;
}

vector<double> AddTwoVectors(const vector<double>& v, const vector<double> w) {

    if (!CheckSizeVectors(v, w)) {
        exit(-1);
    }

    vector<double> result;

    for (int i = 0; i < v.size(); ++i) {
        result.push_back(v[i] + w[i]);
    }

    return result;
}

vector<double> SubstractTwoVectors(const vector<double>& v, const vector<double>& w) {
    
    if (!CheckSizeVectors(v, w)) {
        exit(-1);
    }

    vector<double> result;

    for (int i = 0; i < v.size(); ++i) {
        result.push_back(v[i] - w[i]);
    }

    return result;
}

vector<double> VectorsSum(const vector< vector<double> >& vectors) {
    if (vectors.size() == 0) {
        cout << "Vectors was not provided!!!" << endl;
        exit(-1);
    }

    int size_vector = vectors[0].size();
    vector<double> sum_of_vectors(size_vector);

    for (auto& v : vectors) {
        if (v.size() != size_vector) {
            cout << "Vectors must be same size!" << endl;
        }
        for (int i = 0; i < size_vector; ++i) {
            sum_of_vectors[i] += v[i];
        }
    }

    return sum_of_vectors;

}

vector<double> ScalarMultiply(double scalar, const vector<double>& v) {
    vector<double> result;

    for (auto& elem : v) {
        result.push_back(scalar * elem);
    }

    return result;
}


vector<double> VectorMean(const vector< vector<double> >& vectors) {
    double n = vectors.size();
    double scalar = 1 / n;

    return ScalarMultiply(scalar, VectorsSum(vectors));

}

double Dot(const vector<double>& v, const vector<double>& w) {
    
    if (!CheckSizeVectors(v, w)) {
        exit(-1);
    }

    double result = 0;

    for (int i = 0; i < v.size(); ++i) {
        result += v[i] * w[i];
    }

    return result;
}

double SumOfSquares(const vector<double>& v) {
    return Dot(v, v);
}

double Magnitude(const vector<double>& v) {
    return sqrt(SumOfSquares(v));
}


/**/
/**/
/**/

double SquaredDistance(const vector<double>& v, const vector<double>& w) {
    return SumOfSquares(SubstractTwoVectors(v, w));
}

// double Distance1(const vector<double>& v, const vector<double>& w) {
//     return sqrt(SquaredDistance(v, w));
// }

double Distance(const vector<double>& v, const vector<double>& w) {
    return Magnitude(SubstractTwoVectors(v, w));
}