## bubble sort</br>
- O(n^2)
```cpp
void Bubble(vector<int>& arr)
{
    int size = arr.size();
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
```

## cocktail sort</br>
## selection sort</br>
- O(n^2)
```cpp
void Selection(vector<int>& arr)
{
    int size = arr.size();
    for (int i = 0; i < size - 1; ++i) {
        int min = INT_MAX, idx = -1;
        for (int j = i; j < size; ++j) {
            if (arr[j] < min) {
                min = arr[j];
                idx = j;
            }
        }
        swap(arr[i], arr[idx]);
    }
}
```

## double selection sort</br>
## insertion sort</br>
## binary insertion sort</br>
## merge sort</br>
## heap sort</br>
## quick sort</br>
## shell sort</br>
