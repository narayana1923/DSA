def unodr_linear_search(a, b, n):
    for i in range(n):
        if a[i] == b:
            return 1
    return 0


array = [i.upper() for i in input("Enter roll numbers seperated by space : ").split()]
b = input("Enter the roll number you want to check: ").upper()
if unodr_linear_search(array, b, len(array)) == 1:
    print("Student with roll number", b, "attended for Placement training")
else:
    print("Student with Roll number ", b, "not attended for Placement training")
