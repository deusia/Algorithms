#include<iostream>
const int N = 9;
using namespace std;

//分组，选取数组第一个元素作为基准值，把大于其的放在左边，小于其的放在它右边
int partition(int *a, int lo, int hi) {
    int i = lo;
    int j = hi + 1;
    int v = a[lo];

    while (true) {
//      左侧开始寻找大于基准值的，找到则停下，i为其下标
        while (a[++i] < v) {
            if (i == hi)break;
        }
//      右侧开始寻找小于基准值的，找到则停下，j为其下标
        while (v < a[--j]) {
            if (j == lo) break;
        }
//      检验是否找过头
        if (i >= j) break;

//      找到相应的元素后交换两个的位置
        exch(a, i, j);
    }
    exch(a, lo, j);
    return j;
}

//快速排序的核心函数，被递归调用
void quickSort(int *a, int lo, int hi) {
    if (lo >= hi) return;

    int j = partition(a, lo, hi);
    quickSort(a, lo, j - 1);
    quickSort(a, j + 1, hi);
}

/*
*用于包装void quickSort(int *a, int lo, int hi)
*易于使用者直接调用快速排序
*/
void qSort(int *a) {
    quickSort(a, 0, N - 1);
}


int main() {
//  测试数组
    int a[N] = {41, 2, 1, 3, 22, 91, 88, 42, 3};

//  使用快速排序
    qSort(a);
    //输出
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    return 0;

}
