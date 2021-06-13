#include "../includes/linear.h"

double Mean(vector<double>& x) {
    double sum = 0;
    int size = x.size();

    for (auto& i : x) { sum += i; }
    double res = sum / size;
    
    return res;
}

double Median(vector<double> v) {
    size_t vector_size = v.size();
    long midpoint = vector_size / 2;
    sort(begin(v), end(v));

    if (vector_size % 2 == 0) {
        return (v[midpoint - 1] + v[midpoint]) / 2;
    } else {
        return v[midpoint];
    }
}

double Quantile(vector<double> v, double p) {
    sort(begin(v), end(v));

    int p_index = p * v.size();
    return v[p_index];
}

vector<double> Mode(vector<double> v) {

    vector<double> mods;
    sort( v.begin(), v.end() );

    int max = 0;

    for (int i = 0, j; i < v.size(); i = j){
        j = i + 1;
        while (v[j] == v[i]) ++j;

        if (max <= j - i) {
            if (max != 1) {
                if (max < j-i) {
                    max = j - i;
                    mods.assign(1, v[i]);
                } else {
                    mods.push_back(v[i]);
                }
            }
        }
    }

    return mods;

}

double DataRange( vector<double> v) {
    // Вариация данных в виде размаха
    sort(begin(v), end(v));

    return v[0] - v[v.size() - 1];
}

////////////////////////////////////////////////////////////////////////////
// Вычисление Дисперсии
////////////////////////////////////////////////////////////////////////////
vector<double> DeviationsMean(vector<double>& v) {
    //Транслировать v путем вычитания его среднего
    double v_bar = Mean(v);
    vector<double> res;
    
    for (auto& r : v) {
        double x = r - v_bar;
        res.push_back(x);
    }
    return res;
}

double Variance(vector<double>& v) {
    if (v.size() < 2) {
        cout << "Дисперсия требует наличия не менее двух элементов." << endl;
        exit(-1);
    }

    int n = v.size();
    vector<double> deviations = DeviationsMean(v);
    return SumOfSquares(deviations) / (n - 1);
}
/////////////////////////////////////////////////////////////////////////

double StandartDeviation(vector<double>& v) {
    return sqrt(Variance(v));
}

double InterquantileRange(vector<double> v) {
    return Quantile(v, 0.75) - Quantile(v, 0.25);
}


double Covariance(vector<double> xs, vector<double> ys) {
    if (xs.size() != ys.size()) {
        cout << "Covariance error:\nvector must have same size!!!" << endl;
    }

    return Dot(DeviationsMean(xs), DeviationsMean(ys)) / (xs.size() - 1);
}

double Correlation(vector<double> xs, vector<double> ys) {
    double stdev_x = StandartDeviation(xs);
    double stdev_y = StandartDeviation(ys);

    if (stdev_x > 0 && stdev_y > 0) {
        return Covariance(xs, ys) / stdev_x / stdev_y;
    } else {
        return 0;
    }
}

double UniformPDF(double x) {
    // Плотность равномерного распределения
    return 1 ? x >= 0 and x < 1 : 0;
}

double UniformCDF(double x) {
    // Cumulative distribution function
    if (x < 0) {
        return 0;
    } else if (x < 1) {
        return x;
    } else {
        return 1;
    }
}

double NormalPDF(double x, double mu, double sigma) {
    // Плотность нормального распределения
    double x_mult_mu = pow(-(x - mu), 2);
    return (exp(x_mult_mu / 2 / pow(sigma, 2)) / SQRT_TWO_PI * sigma);
}

double NormalCDF(double x, double mu, double sigma) {
    return (1 + erf((x - mu) / sqrt(2) / sigma)) / 2;
}

double InverseNormalCDF(double p, double mu, 
                    double sigma, double tolerance) {
    // Отыскать приближенную версию используя бинарный поиск
    // Если не стандартная, то вычислить стандартную и перешкалировать
    if (mu != 0 || sigma != 1) {
        return mu + sigma * InverseNormalCDF(p, tolerance=tolerance);
    }

    double low_z = -10, hi_z = 10;
    double mid_z = 0;
    while (hi_z - low_z > tolerance) {
        mid_z = (low_z + hi_z) / 2;
        double mid_p = NormalCDF(mid_z);
        if (mid_p < p) {
            low_z = mid_z;
        } else {
            hi_z = mid_z;
        }
    }
    return mid_z;
}

