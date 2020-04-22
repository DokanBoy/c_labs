#include <iostream>
#include <ctime>
#include "Horse.cpp"

class HorseTest {
private:
    Horse *horse;
    unsigned int start, end;
public:
    HorseTest() {
        horse = new Horse();
    }

    ~HorseTest() {
        delete horse;
    }

    void test() {
        using namespace std;
        srand(time(0));

        start = clock();

        int result = horse->move(1, 1, 3);

        end = clock();

        cout << "Find the moves: " << result << endl;
        cout << end - start << "ms" << endl;
        horse->print();
    }
};