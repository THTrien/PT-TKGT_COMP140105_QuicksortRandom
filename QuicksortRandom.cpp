#include <iostream>
#include <cstdlib>  // thư viện để sử dụng hàm rand()

using namespace std;

// Tạo hàm swap để tráo đổi các vị trí
void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

// Chọn một vị trí mốc ngẫu nhiên
int getRandomPivot(int arr[], int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    return randomIndex;
}

// Phân đoạn trong mảng
int partition(int arr[], int low, int high)
{
    int pivotIndex = getRandomPivot(arr, low, high);
    int pivot = arr[pivotIndex];

    // Đưa phần tử pivot về cuối mảng
    swap(arr[pivotIndex], arr[high]);

    int left = low;
    int right = high - 1;

    while (true) {
        while (left <= right && arr[left] < pivot)
            left++;
        while (right >= left && arr[right] > pivot)
            right--;

        if (left >= right)
            break;

        swap(arr[left], arr[right]);
        left++;
        right--;
    }

    swap(arr[left], arr[high]);
    return left;
}

// Hàm thực hiện giải thuật QuickSort
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Hàm xuất mảng
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    srand(time(NULL));  // Khởi tạo seed cho hàm rand() dựa trên thời gian hiện tại

    quickSort(arr, 0, n - 1);

    cout << "Mảng sau khi được sắp xếp: ";
    printArray(arr, n);

    return 0;
}


