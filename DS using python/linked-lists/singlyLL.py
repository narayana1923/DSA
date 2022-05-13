class Node:
    def __init__(self, name="", rollnumber="", next=None):
        self.name = name
        self.rollnumber = rollnumber
        self.next = next


class LinkedList:
    def __init__(self):
        self.head = None
        self.first = None
        self.last = None

    def searchNode(self, rollnumber):
        temp = None
        ptr = self.head
        while ptr:
            if ptr.rollnumber.upper() == rollnumber.upper():
                temp = ptr
                break
            ptr = ptr.next
        return temp

    def add(self):
        rollnumber = input("Enter the roll number of student : ")
        if self.searchNode(rollnumber):
            print("Student is already in the readers club\n")
            return
        name = input("Enter the name of student : ")
        if self.head == None:
            self.first.name, self.first.rollnumber = name, rollnumber
            self.head = self.first
            self.head.next = None
            print("\nSuccessfully added the student to readers club\n")
            return

        if self.head.next is None:
            self.last = Node(name, rollnumber)
            self.head.next = self.last
            print("\nSuccessfully added the student to readers club\n")
            return
        temp = self.head
        while temp.next != self.last:
            temp = temp.next
        temp.next = Node(name, rollnumber, self.last)
        print("\nSuccessfully added the student to readers club\n")

    def delete(self):
        if self.totalMembers() == 0:
            print("\nThere are no members in readers club\n")
            return
        rollnumber = input("Enter the roll number of student you want to delete : ")
        if self.searchNode(rollnumber) is None:
            print("\nMember not found in readers club\n")
            return
        if self.head.rollnumber == rollnumber:
            self.head = self.head.next
            self.last = None
            print("\nThe student you entered has been removed form readers club\n")
            return
        temp = self.head
        prev = temp
        while temp != None and temp.rollnumber != rollnumber:
            prev = temp
            temp = temp.next
        if temp.rollnumber == rollnumber:
            prev.next = temp.next
            temp.next = None
        print("\nThe student you entered has been removed form readers club\n")

    def totalMembers(self):
        n = 0
        temp = self.head
        while temp:
            temp = temp.next
            n += 1
        return n

    def displayMembers(self):
        temp = self.head
        print("\n%-30s%s\n" % ("Name", "Roll Number"))
        while temp:
            print("%-30s%s\n" % (temp.name, temp.rollnumber))
            temp = temp.next
        print()

    def displayReverse(self, head):
        if head.next is not None:
            self.displayReverse(head.next)
        print("%-30s%s\n" % (head.name, head.rollnumber))

    def sort(self):
        temp = self.head
        while temp.next is not None:
            min = temp
            temp1 = temp.next
            while temp1 is not None:
                if temp1.name.upper() < min.name.upper():
                    min = temp1
                temp1 = temp1.next
            temp.name, temp.rollnumber, min.name, min.rollnumber = (
                min.name,
                min.rollnumber,
                temp.name,
                temp.rollnumber,
            )
            temp = temp.next

    def todo(self, option):
        if option in range(1, 7):
            if option == 1:
                self.add()
            elif option == 2:
                self.delete()
            elif option == 3:
                print(
                    "\nTotal number of members in readers club are %d\n\n"
                    % (self.totalMembers())
                )
            elif option == 4:
                if self.totalMembers() == 0:
                    print("\nThere are no members in readers club")
                else:
                    self.displayMembers()
            elif option == 5:
                if self.totalMembers() == 0:
                    print("\nThere are no members in readers club")
                else:
                    print("\n%s%30s\n\n" % ("Name", "Roll Number"))
                    self.displayReverse(self.head)
            elif option == 6:
                if self.totalMembers() == 0:
                    print("\nThere are no members in readers club")
                else:
                    self.sort()
                    print("\nSorted the list successfully\n")
            elif option == 7:
                print("Program ended!!\n")
        elif option not in range(1, 8):
            print("Invalid option, please try again\n")

    def operation(self):
        option = 0
        while option < 7:
            print(
                "1. Add a member\n"
                + "2. Delete a members\n"
                + "3. Count of students in readers club\n"
                + "4. Display All members in readers club\n"
                + "5. Display all the members in reverse order\n"
                + "6. sort the list\n"
                + "7. To exit Enter 7 or any number >7\n"
            )
            option = int(input("Enter your option: "))
            self.todo(option)

    def intialization(self):
        self.first = Node(
            input("Enter the name of Reader's club head : "),
            input("Enter the roll number of Reader's club head: "),
        )
        self.last = Node(
            input("Enter the name of Reader's club in-charge : "),
            input("Enter the roll number of Reader's club in-charge : "),
        )
        self.first.next = self.last
        self.head = self.first


if __name__ == "__main__":
    l = LinkedList()
    l.intialization()
    print()
    l.operation()
