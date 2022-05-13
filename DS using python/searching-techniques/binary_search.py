def binary_search(a, b, n):
    low, mid, high = 0, 0, n - 1
    while low <= high:
        mid = (low + high) // 2
        if b == a[mid]:
            return 1
        elif b > a[mid]:
            low = mid + 1
        elif b < a[mid]:
            high = mid - 1
    return 0


array = [i.upper() for i in input("Enter roll numbers seperated by space : ").split()]
array.sort()
b = input("Enter the roll number you want to check: ").upper()
if binary_search(array, b, len(array)) == 1:
    print("Student with roll number", b, "attended for Placement training")
else:
    print("Student with Roll number ", b, "not attended for Placement training")
