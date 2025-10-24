def quicksort(arr):
    def sort(l, r):
        if l >= r:
            return
        pivot = arr[(l + r) // 2]
        i, j = l, r
        while i <= j:
            while arr[i] < pivot:
                i += 1
            while arr[j] > pivot:
                j -= 1
            if i <= j:
                arr[i], arr[j] = arr[j], arr[i]
                i, j = i + 1, j - 1
        sort(l, j)
        sort(i, r)
    sort(0, len(arr) - 1)
    return arr


