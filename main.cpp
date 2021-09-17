#include <iostream>

#include "UnionFind.h"

int main(){
    srand(time(NULL));
    UnionFind *unionFind = new UnionFind();
    unionFind->run();

    return 0;
}