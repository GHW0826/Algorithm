#include <iostream>
#include <vector>
using namespace std;

// permutation (순열)
// 1. (순서 O, 중복 X)
int permutation_r = 5;
int permutation_n = 5;
vector<int>  permutation_arr(permutation_n + 1, 0);
vector<bool>  permutation_visit(permutation_n + 1, 0);

void permutation(int depth) {
    if (depth == permutation_r)
        return;

    for (int i = 1; i <= permutation_n; ++i) {
        if (permutation_visit[i] == false) {
            permutation_visit[i] = true;
            permutation_arr[depth] = i;
            permutation(depth + 1);
            permutation_visit[i] = false;
        }
    }
}
/*
    1 2 3
    1 2 4
    1 3 2
    1 3 4
    1 4 2 
    1 4 3
    2 1 3
    2 1 4
    ...
*/

// 2. (순서 O, 중복 O)
int duplicatedPermutation_r = 5;
int duplicatedPermutation_n = 5;
vector<int> duplicatedPermutation_arr(duplicatedPermutation_n + 1, 0);
void duplicatedPermutation(int depth) {
    if (depth == duplicatedPermutation_r)
        return;

    for (int i = 1; i <= duplicatedPermutation_n; ++i) {
        duplicatedPermutation_arr[depth] = i;
        duplicatedPermutation(depth + 1);
    }
}
/*
    1 1 1
    1 1 2
    1 1 3
    1 1 4
    1 2 1
    1 2 2
    1 2 3
    1 2 4
    ...
*/

// combination
// 1. (순서 X, 중복 X)
int combination_r = 5;
int combination_n = 5;
vector<int> combination_arr(combination_n + 1, 0);
void combination(int depth, int next) {
    if (depth == combination_r)
        return;

    for (int i = next; i <= combination_n; ++i) {
        combination_arr[depth] = i;
        combination(depth + 1, i + 1);
    }
}
/*
    1 2 3
    1 2 4
    1 3 4
    2 3 4
*/

// 2. (순서 X, 중복 O)
int duplicatedCombination_r = 5;
int duplicatedCombination_n = 5;
vector<int> duplicatedCombination_arr(duplicatedCombination_n + 1, 0);
void duplicatedCombination(int depth, int next) {
    if (depth == duplicatedCombination_r)
        return;

    for (int i = next; i <= duplicatedCombination_n; ++i) {
        duplicatedCombination_arr[depth] = i;
        duplicatedCombination(depth + 1, i);
    }
}
/*
    1 1 1
    1 1 2
    1 1 3
    1 1 4
    1 2 2
    1 2 3
    1 2 4
    1 3 3
    ...
*/

int main()
{

    permutation(0);
    duplicatedPermutation(0);

    combination(0, 1);
    duplicatedCombination(0, 1);

    return 0;
}
