
int getPivot(vector<int> arr, int n){
    int start = 0;
    int end = n-1;
    while(start < end){
        int mid = start + (end-start)/2;
        if(arr[mid] >= arr[0]){
            start = mid+1;
        }
        else{
            end = mid;
        }
    }
    return start;
}

int binarySearch(vector<int> arr, int s, int e, int key){
    int start = s;
    int end = e;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else{
            start = mid +1;
        }
    }
    return -1;
}


int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int pivot = getPivot(arr, n);
    if(arr[pivot] <= k && k <= arr[n-1]){
        return binarySearch(arr, pivot, n-1, k);
    }
    else{
        return binarySearch(arr, 0, pivot-1, k);
    }
    return -1;
}

