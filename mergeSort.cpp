#include<iostream>

int aux[N];
const int N = 9;
using namespace std;

static void merge(int *a, int *aux, int lo, int mid, int hi) {
    //将数组a[lo..mid]和数组a[mid+1..hi]进行归并
    int i = lo;       //第一组
    int j = mid + 1;    //第二组

    //将该分段放入辅助数组
    for (int k = lo; k <= hi; k++) {
        aux[k] = a[k];
    }

    //将分段按顺序放回
    for (int k = lo; k <= hi; k++) {
        if (i > mid) {                  //第一组是否遍历结束
            a[k] = aux[j++];
        } else if (j > hi) {            //第二组是否遍历结束
            a[k] = aux[i++];
        } else if (aux[i] < aux[j]) {   //比较两组各值的大小
            a[k] = aux[i++];
        } else {
            a[k] = aux[j++];
        }
    }
}

static void sort(int *a, int *aux, int lo, int hi) {
    //将数组a[lo..hi]进行排序
    if (hi <= lo)
        return;

//    防止int的溢出
    int mid = lo + (hi - lo) / 2;

    sort(a, aux, lo, mid);
    sort(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}

static void mergeSort(int *a) {
    sort(a, aux, 0, N - 1);
}


int main() {
    //测试数组
    int a[N] = {41, 2, 1, 3, 22, 91, 88, 42, 3};

    //使用归并排序
    mergeSort(a);

    //输出
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    return 0;

}
