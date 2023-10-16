void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* Tao cac mang tam */
    int L[n1], R[n2];
 
    /* Copy du lieu sang cac mang tam */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Gop hai mang tim vua roi vao mang arr*/
    i = 0; // Khoi tao chi so bat dau cua mang con dau tien
    j = 0; // Khoi tao chi so bat dau cua mang con thu hai
    k = l; // Khoi tao chi so bat dau cua mang luu ket qua
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy cac phan tu con lai cua mang L vào arr neu co */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy cac phan tu con lai cua mang R vào arr neu co */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

 
/* l là chi so trái và r là chi so phai cua mang con duoc sap xep */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Tuong tu (l+r)/2, nhung cách này tránh tràn so khi l và r lon
        int m = l+(r-l)/2;
 
        // Goi hàm de quy tiep tuc chia dôi tung nua mang
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
