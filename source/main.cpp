#include "../includes/linear.h"

int main() {
    vector<double> v = {1, 2, 3};
    vector<double> w = {4, 5, 6};

    vector<double> res_add_vectors = AddTwoVectors(v, w);
    cout << "Add vectors:\n{ 1 2 3 }\n    +\n{ 4 5 6 }\n    =\n{ ";
    for (auto i : res_add_vectors) {
        cout << i << " ";
    }
    cout << "}" << endl << endl;

    vector<double> res_substract_vectors = SubstractTwoVectors(v, w);
    cout << "Substract vectors:\n{ 1 2 3 }\n    -\n{ 4 5 6 }\n    =\n{ ";
    for (auto i : res_substract_vectors) {
        cout << i << " ";
    }
    cout << "}" << endl << endl;

    vector< vector<double> > sum_vect {
        {1, 2, 3}, 
        {3, 4, 5}, 
        {5, 6, 7}, 
        {7, 8, 9}
        };

    
    vector<double> res_vector_sum = VectorsSum(sum_vect);

    cout << "Vectors sum:\n{\n    { 1, 2, 3 }\n\t +\n    { 3, 4, 5 }\n\t +\n    { 5, 6, 7 }\n\t +\n    { 7, 8, 9 }\n}\n\t =\n    { ";
    for (const auto& v : res_vector_sum) {
        cout << v << " ";
    }
     cout << "}" << endl << endl;

    vector<double> res_scalar = ScalarMultiply(2, v);
    cout << "Scalar multiply:\n{ 1 2 3 } * 2\n    =\n{ ";
    for (const auto& v : res_scalar) {
        cout << v << ' ';
    }
    cout << "}" << endl;

    vector< vector<double> > vector_mean {
        {1, 2, 3}, 
        {3, 4, 5}, 
        {5, 6, 7}, 
        {7, 8, 9}
        };
    vector<double> res_vector_mean = VectorMean(vector_mean);
    cout << "Vector mean:\n{\n    { 1, 2, 3 }\n\t +\n    { 3, 4, 5 }\n\t +\n    { 5, 6, 7 }\n\t +\n    { 7, 8, 9 }\n}\n\t =\n    { ";
    for (auto& v : res_vector_mean) {
        cout << v << " ";
    }
    cout << "}\n";


    double res_dot = Dot(v, w);
    cout << "DOT:\n{ 1 2 3 }\n{ 4 5 6 }\n    =\n    " << res_dot << endl;


    double res_squer = SumOfSquares(v);
    cout << "Sum of square:\n{ 1 2 3 } = " << res_squer << endl;

    double res_magnitude = Magnitude(v);
    cout << "Sum of magnitude:\n{ 1 2 3 } = " << res_magnitude << endl;

    // double res_dis1 = Distance1(v, w);
    double res_dis = Distance(v, w);

    cout << "\nDISTANCE\n { 1 2 3 } between { 4 5 6 } = "  << res_dis << endl;

    cout << "!!!CREATING MATRIX!!!" << endl;
    vector<vector<double>> test_matrix = MakeMatrix(5, 5, [](int x, int y) { return 1 ? x == y : 0; });
    cout << "!!!DONE!!!\n\n!!!PRINT MATRIX!!!\n\n";
    PrintMatrix(test_matrix);

    cout << "Shape matrix: ( ";

    ShapeMatrix shape = Shape(test_matrix);
    cout << shape.num_rows << " " << shape.num_cols << " )" << endl;

    vector<double> row = GetRow(test_matrix, 2);
    cout << "Get row 2: ( ";
    for (auto& i : row) {
        cout << i << " ";
    }
    cout << ")" << endl;

    cout << "Get col 2:\n[\n";
    vector<double> column = GetColumn(test_matrix, 2);
    for (auto& i : column) {
        cout << "  " << i << endl;
    }
    cout << "]\n";

    double mean_v = Mean(v);
    cout << "Mean { 1 2 3 } = " << mean_v << endl;
    
    double median_v = Median(v);
    cout << "Median { 1 2 3 } = " << median_v << endl;


    vector<double> mode_vector = { 4, 8, 8, 4, 9 };
    vector<double> mods = Mode(mode_vector);

    cout << "Mode" << ( mods.size() == 1 ? ":" : "s:" );
    for ( int x : mods ) cout << ' ' << x;
    cout << '\n';

    double quantile = Quantile(mode_vector, 0.10);
    cout << "Quantile 10% = " << quantile << endl;
    quantile = Quantile(mode_vector, 0.50);
    cout << "Quantile 50% = " << quantile << endl;
    quantile = Quantile(mode_vector, 0.90);
    cout << "Quantile 90% = " << quantile << endl;

    double variance = Variance(mode_vector);
    cout << "Variance = " << variance << endl;

    double std_dev = StandartDeviation(mode_vector);
    cout << "Standart deviation = " << std_dev << endl;

    double interquantile = InterquantileRange(mode_vector);
    cout << "Interquantile range = " << interquantile << endl;

    double covariance = Covariance(v, w);
    cout << "Covariance = " << covariance << endl;

    double correlation = Correlation(v, w);
    cout << "Correlation = " << correlation << endl; 

    cout << rand() << endl;

    return 0;
}