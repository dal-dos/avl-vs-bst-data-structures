//main 12 o'clock at night @ atvar
#include <iostream>
#include <algorithm>
#include <fstream>
#include "AvlTree.h"
#include "BinarySearchTree.h"
using namespace std;

double elapsed_time(clock_t start, clock_t finish) {
    // returns elapsed time in milliseconds
    return (finish - start) / (double)(CLOCKS_PER_SEC / 1000);
}

// Test program
int main()
{   
    BinarySearchTree<int> r;
    AvlTree<int> t;
    clock_t start, finish;
    int NUMS = 1000;
    int N = 3000;
    const int GAP = 3;
    const int CAP = 1000;
    int key;
    ofstream myFile;
    myFile.open("Data.csv");
    myFile << "Type,Trial,Size,Height,Average node depth,Average time(ms) \n";
    cout << "Type,Trial,Size,Height,Average node depth,Average time(ms) \n";

    key = CAP / 2;
    for (int i = 1; i <= NUMS; i++) {
        key = (key + GAP) % CAP;
        r.insert(key);
    }

    for (int k = 0; k < 5; ++k) {
        start = clock();
        for (int i = 1; i <= NUMS; i++) {
            key = (key + GAP) % (CAP + (k * 1000));
            r.insert(key);
        }
        for (int i = 1; i <= NUMS/2; ++i) {
          key = (key + GAP) % (CAP + (k * 500));
          r.remove(key);
        }
        for (int i = 1; i <= NUMS; ++i) {
          key = (key + GAP) % (CAP + (k * 100));
          r.contains(key);
        }
        finish = clock();

        myFile << "BST," << (k+1) << "," << r.getSize() << "," << r.getHeight() << "," << r.averageNodeDepth() << "," << elapsed_time(start, finish) / ((NUMS * 2) + (NUMS/2)) << "\n";
        cout << "BST," << (k + 1) << "," << r.getSize() << "," << r.getHeight() << "," << r.averageNodeDepth() << "," << elapsed_time(start, finish) / ((NUMS * 2) + (NUMS/2)) << "\n";
    }



    key = CAP / 2;
    for (int i = 1; i <= NUMS; i++) {
        key = (key + GAP) % CAP;
        t.insert(key);
    }

    for (int k = 0; k < 5; ++k) {
        start = clock();
        for (int i = 1; i <= NUMS; i++) {
          key = (key + GAP) % (CAP+(k* 1000));
          t.insert(key);
        }
        for (int i = 1; i <= NUMS/2; ++i) {
          key = (key + GAP) % (CAP + (k * 500));
          t.remove(key);
        }
        for (int i = 1; i <= NUMS; ++i) {
          key = (key + GAP) % (CAP + (k * 100));
          t.contains(key);
        }
        finish = clock();
        myFile << "AVL," << (k + 1) << "," << t.getSize() << "," << t.getHeight() << "," << t.averageNodeDepth() << "," << elapsed_time(start, finish) / ((NUMS * 2) + (NUMS / 2)) << "\n";
        cout << "AVL," << (k+1) << "," << t.getSize() << "," << t.getHeight() << "," << t.averageNodeDepth() << "," << elapsed_time(start, finish) / ((NUMS * 2) + (NUMS / 2)) << "\n";
    }
    

    

    myFile.close();

    return 0;
}
