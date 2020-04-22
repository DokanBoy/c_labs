#include <vector>
#include <iostream>


template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> *matrix{};
public:
    Matrix(unsigned int defCapacity) {
        matrix = new std::vector<std::vector<T>>(defCapacity);
    }

    ~Matrix() {
        for (std::vector<T> vec : matrix) {
            vec.clear();
        }
    }

    std::vector<std::vector<T>> *getMatrix() {
        return matrix;
    }

    std::vector<std::vector<T>> getRowByIndex(unsigned int index) {
        return matrix->getByIndex(index);
    }

    void pushRow(std::vector<T> row) {
        matrix->push_back(row);
    }

    std::vector<std::vector<T>> topRow() {
        matrix->at(matrix->size() - 1);
    }

    std::vector<std::vector<T>> popRow() {
        matrix->pop_back();
    }

    void print() {
        for (int i = 0; i < matrix->size(); ++i) {
            std::vector<T> vec = matrix->at(i);
            std::cout << "ROW #" << i << ": ";
            for (int j = 0; j < vec->size(); ++j) {
                std::cout << vec->at(j) << " ";
            }
            std::cout << std::endl;
            vec.clear();
        }
    }
};