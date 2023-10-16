// Thuat toan sap xep vun dong
// Hàm vun d?ng cho m?t d?nh
void heapify(int arr[], int n, int i){  // m?ng arr, n - s? ph?n t?, i - d?nh c?n vun d?ng
    int max =i;    // Luu v? trí d?nh max ban d?u
    int l = i*2 +1;   // V? trí con trái
    int r = l+1;    // V? trí con ph?i
    if(l<n && arr[l] > arr[max]){   // N?u t?n t?i con trái l?n hon cha, gán max = L
        max = l;
    }
    
    if(r<n && arr[r] > arr[max]){   // N?u t?n t?i con ph?i l?n hon arr[max], gán max = r
        max = r;
    }
    if(max != i){      // N?u max != i, t?c là cha không ph?i l?n nh?t
        swap(arr[i], arr[max]);   // Ð?i ch? cho ph?n t? l?n nh?t làm cha
        heapify(arr ,n , max);    // Ð? quy vun các node phía du?i
    }
    
}

// Ham sap xep vun dong
void heapSort(int arr[], int n){
    
    // vun dong tu duoi len len de thanh heap
    for(int i = n/2 - 1; i>=0; i--)   // i ch?y t? n/2 - 1 v? 0 s? có n/2 d?nh nhé!
        heapify(arr,n, i);   // Vun t?ng d?nh
    
    // Vòng l?p d? th?c hi?n vun d?ng và l?y ph?n t?
    for(int j = n-1 ; j>0; j--){   // ch?y h?t j == 1 s? d?ng
                // m?i l?n j - 1, tuong duong v?i k xét ph?n t? cu?i 
        swap(arr[0], arr[j] );  // d?i ch? ph?n t? l?n nh?t
             heapify(arr, j, 0);    // vun l?i d?ng, 
    }
}
