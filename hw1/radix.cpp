void radixSort(vector<int> &arr)
{
    int max = arr[0];
    // Tìm giá tr? l?n nh?t trong m?ng
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];
    
    // Th?c hi?n s?p x?p t?ng ch? s?
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        vector<int> output(arr.size());
        int count[10] = {0};
        
        // Ð?m s? l?n xu?t hi?n c?a m?i ch? s?
        for (int i = 0; i < arr.size(); i++)
            count[(arr[i] / exp) % 10]++;
        
        // Tính t?ng các s? d?m
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        
        // Chuy?n v? trí các ph?n t? trong m?ng d?u ra
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        
        // Gán m?ng d?u ra vào m?ng ban d?u
        for (int i = 0; i < arr.size(); i++)
            arr[i] = output[i];
    }
}

