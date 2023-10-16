
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

/* H�m th?c hi?n gi?i thu?t quick sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi l� ch? s? noi ph?n t? n�y d� d?ng d�ng v? tr�
         v� l� ph?n t? chia m?ng l�m 2 m?ng con tr�i & ph?i */
        int pi = partition(arr, low, high);

        // G?i d? quy s?p x?p 2 m?ng con tr�i v� ph?i
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
