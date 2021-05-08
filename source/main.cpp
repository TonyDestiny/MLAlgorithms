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
    cout << "Substract vectors:\n{ 1 2 3 }\n    +\n{ 4 5 6 }\n    =\n{ ";
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
    
    return 0;
}