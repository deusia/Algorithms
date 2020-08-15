#include<iostream>

const int N = 9;
using namespace std;
int aux[N];

//对数组元素进行交换
void exch(int *a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;

}

void shellSort(int *a, int n) {
    //将a[]升序排列
    int h = 1;
    //将数组变为h个一组为有序
    while (h < n / 3)
        h = 3 * h + 1;    // 3x+1 increment sequence:  1, 4, 13, 40, 121, 364, 1093, ...

    while (h >= 1) {
//        拿每个序列的同一位置的元素进行排序
        for (int i = h; i < n; ++i) {
//            内嵌的插入排序
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h) {
                exch(a, j, j - h);
            }
        }
        h = h / 3;
    }
}

int main() {
    //测试数组
    int a[N] = {41, 2, 1, 3, 22, 91, 88, 42, 3};

    //使用希尔排序
    shellSort(a, N);
    //输出
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    return 0;

}
