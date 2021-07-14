void swap(int i, int j, int arr[]) {
    int h = arr[i];
    arr[i] = arr[j];
    arr[j] = h;
}

void quickSort(int length, int arr[]) {
    int boundary;
    if(length <= 1) {
        return;
    }
    boundary = partition(length, arr);
    quickSort(boundary, arr);
    quickSort(length - boundary - 1, &arr[boundary + 1]);
}

int partition(int length, int arr[]) {
    int left = 0;
    int right = length;
    int pivot = arr[0];
    while(left < right) {
        while((left < right) && (arr[left] <= pivot)) {
            left++;
        }

        while((left < right) && (pivot < arr[right-1])) {
            right--;
        }

        if(left < right) {
            right--;
            swap(left, right, arr);
            left++;
        }
    }
    left--;
    arr[0] = arr[left];
    arr[left] = pivot;
    return left;
}
