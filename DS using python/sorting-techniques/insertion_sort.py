def insertion_sort(a):
    for i in range(1, len(a)):
        t = a[i]
        j = i
        while a[j - 1] > t and j >= 1:
            a[j] = a[j - 1]
            j -= 1
        a[j] = t


a = list(map(int, input("Enter elements of array seperated by space: ").split()))
insertion_sort(a)
print(a)
