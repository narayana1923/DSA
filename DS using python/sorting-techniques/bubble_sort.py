def Bubblesort(a, n):
    for i in range(n - 1):
        for j in range(i + 1, n):
            if a[i] > a[j]:
                temp = a[i]
                a[i] = a[j]
                a[j] = temp


array = [int(x) for x in input("Enter elements seperated by space").split()]
Bubblesort(array, len(array))
print("Array after sorting is", array)
