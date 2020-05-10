#include <iostream>
#include <ctime>
#include "Queen.cpp"

class QueenTest {
private:
    Queen *queen{};
    unsigned int start{}, end{};
public:
    QueenTest() {

    }

    ~QueenTest() {
        delete queen;
    }

    void test() {
        using namespace std;
        srand(time(0));

        start = clock();

        queen = new Queen();

        end = clock();
        cout << "Elapsed time: " << end - start << "ms" << endl;
    }
};