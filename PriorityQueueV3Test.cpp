#include "PriorityQueueV3.cpp"
#include <ctime>
#include <random>

class PriorityQueueV3Test {
private:
    PriorityQueueV3 *pq;
    unsigned int start, end;
public:
    PriorityQueueV3Test() {
        pq = new PriorityQueueV3();
    }

    ~PriorityQueueV3Test() {
        delete pq;
    }

    void testTime() {
        using namespace std;
        srand(time(0));

        start = clock();

        for (int i = 0; i < 30000000; ++i) {
            pq->push(rand());
        }

        end = clock();
        cout << "PUSH x30M: " << end - start << "ms" << endl;


        start = clock();

        for (int i = 0; i < 100000; ++i) {
            pq->push(rand());
            pq->pop();
        }

        end = clock();
        cout << "POP-PUSH x10K: " << end - start << "ms" << endl;
    }

    void testCorrectness() {
        using namespace std;

        cout << "10 First: ";
        pq->print10First();

        cout << "10 Middle: ";
        pq->print10Middle();

        cout << "10 Last: ";
        pq->print10Last();
    }
};