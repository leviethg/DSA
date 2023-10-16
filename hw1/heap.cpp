// Thuat toan sap xep vun dong
// H�m vun d?ng cho m?t d?nh
void heapify(int arr[], int n, int i){  // m?ng arr, n - s? ph?n t?, i - d?nh c?n vun d?ng
    int max =i;    // Luu v? tr� d?nh max ban d?u
    int l = i*2 +1;   // V? tr� con tr�i
    int r = l+1;    // V? tr� con ph?i
    if(l<n && arr[l] > arr[max]){   // N?u t?n t?i con tr�i l?n hon cha, g�n max = L
        max = l;
    }
    
    if(r<n && arr[r] > arr[max]){   // N?u t?n t?i con ph?i l?n hon arr[max], g�n max = r
        max = r;
    }
    if(max != i){      // N?u max != i, t?c l� cha kh�ng ph?i l?n nh?t
        swap(arr[i], arr[max]);   // �?i ch? cho ph?n t? l?n nh?t l�m cha
        heapify(arr ,n , max);    // �? quy vun c�c node ph�a du?i
    }
    
}

// Ham sap xep vun dong
void heapSort(int arr[], int n){
    
    // vun dong tu duoi len len de thanh heap
    for(int i = n/2 - 1; i>=0; i--)   // i ch?y t? n/2 - 1 v? 0 s? c� n/2 d?nh nh�!
        heapify(arr,n, i);   // Vun t?ng d?nh
    
    // V�ng l?p d? th?c hi?n vun d?ng v� l?y ph?n t?
    for(int j = n-1 ; j>0; j--){   // ch?y h?t j == 1 s? d?ng
                // m?i l?n j - 1, tuong duong v?i k x�t ph?n t? cu?i 
        swap(arr[0], arr[j] );  // d?i ch? ph?n t? l?n nh?t
             heapify(arr, j, 0);    // vun l?i d?ng, 
    }
}
