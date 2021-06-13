#include "../includes/linear.h"

void PrintMatrix(const vector<vector<double>>& pmatrix) {
    for_each(pmatrix.begin(), pmatrix.end(), [](vector<double> pvec) {
        for_each(pvec.begin(), pvec.end(), [](double p) {
            cout << left << setw(5) << p;
        });
        cout << endl;
    });
}

vector<vector<double>> MakeMatrix(const size_t num_rows,
                                  const size_t num_col,
                                  const function<double(int, int)> func ) {
    
    vector<vector<double>> res_matrix(num_rows);
    for (size_t i = 0; i < num_rows; ++i) {
        res_matrix[i].resize(num_col);
        for (size_t j = 0; j < num_col; ++j) {
            res_matrix[i][j] = func(i, j);
        }
    }

    return res_matrix;
}

ShapeMatrix Shape(vector<vector<double>>& m) {
    ShapeMatrix shape;
    shape.num_rows = m.size();
    shape.num_cols = m[0].size();

    return shape;
}

vector<double> GetRow(vector<vector<double>>& m, int row) {
    return m[row];
}

vector<double> GetColumn(vector<vector<double>>& m, int col) {
    // size_t size_column = m.size();
    vector<double> column;

    for (auto v : m){
        double i = v[col];
        column.push_back(i);
    }

    return column;
}