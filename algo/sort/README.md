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
