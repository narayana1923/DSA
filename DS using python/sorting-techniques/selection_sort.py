def selection_sort(a):
    n = len(a)
    for i in range(n):
        min = i
        for j in range(i + 1, n):
            if a[j] < a[min]:
                min = j
        temp = a[i]
        a[i] = a[min]
        a[min] = temp
    return a


print(
    "After sorting array is",
    selection_sort(
        [int(x) for x in input("Enter array elements seperated by space: ").split()]
    ),
)
