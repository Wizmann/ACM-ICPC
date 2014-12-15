#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <ctime>

using namespace std;

#define input(x) cin >> x
#define print(x) cout << x << endl

static const int SIZE = 250000 + 123;

int partition(int array[], int st, int end) {
    if (end - st <= 1) {
        return st;
    }
    int pivot_idx = st + rand() % (end - st);
    swap(array[st], array[pivot_idx]);
    int pivot = array[st];
    
    int l = st, r = end - 1;
    int flag = 0;
    while (l <= r) {
        while (l <= r && array[l] <= pivot) {
            if (array[l] == pivot && flag == 0) {
                flag ^= 1;
            } else if (array[l] == pivot) {
                break;
            }
            l++;
        }
        while (l <= r && array[r] >= pivot) {
            if (array[r] == pivot && flag == 1) {
                flag ^= 1;
            } else if (array[r] == pivot) {
                break;
            }
            r--;
        }
        if (l <= r) {
            swap(array[l++], array[r--]);
        }
    }
    swap(array[st], array[r]);
    return r;
}

int kth_element(int array[], int st, int end, int k) {
    int pivot_idx = partition(array, st, end);
    if (pivot_idx - st + 1 == k) {
        return array[pivot_idx];
    }
    if (pivot_idx - st >= k) {
        return kth_element(array, st, pivot_idx, k);
    } else {
        return kth_element(array, pivot_idx + 1, end, k - (pivot_idx - st) - 1);
    }
}

int kth_element(int array[], int n, int k) {
    return kth_element(array, 0, n, k);
}

double find_median(int array[], int n) {
    if (n & 1) {
        return 1.0 * kth_element(array, n, n / 2 + 1);
    } else {
        int a = kth_element(array, n, n / 2 + 1);
        int b = kth_element(array, n, n / 2);
        return 0.5 * a + 0.5 * b;
    }
}

int nums[SIZE];

int main() {
    freopen("input.txt", "r", stdin);
    // srand(time(0));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    printf("%.1f\n", find_median(nums, n));
    return 0;
}
