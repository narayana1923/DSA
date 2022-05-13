class node:
    def __init__(
        self,
        emp_id: int = 0,
        emp_mobileno: int = 0,
        emp_sal: float = 0.0,
        emp_dept: str = "",
        nxt=None,
        prev=None,
    ):
        self.emp_id, self.emp_mobileno, self.emp_sal = emp_id, emp_mobileno, emp_sal
        self.emp_dept, self.nxt, self.prev = emp_dept, nxt, prev


class DLL:
    def __init__(self):
        self.head = self.last = None
        self.count = 0

    def create(self):
        emp_id = int(input("Enter employee id : "))
        if self.searchNode(emp_id) is not None:
            print("\nEmployee already exists in DLL\n")
            return None
        emp_mobileno, emp_sal, emp_dept = (
            int(input("Enter employee mobile no : ")),
            float(input("Enter employee salary: ")),
            input("Enter employee dept : "),
        )
        temp = node(emp_id, emp_mobileno, emp_sal, emp_dept)
        self.count += 1
        return temp

    def searchNode(self, emp_id):
        temp, ptr = None, self.head
        while ptr:
            if ptr.emp_id == emp_id:
                temp = ptr
                break
            ptr = ptr.nxt
        return temp

    def add(self):
        i = 1
        n = int(input("Enter number of employees you want to add: "))
        if self.head == None:
            self.last = self.head = self.create()
            i += 1
            print()
        while i <= n:
            print("---------------Enter Employee - %d details---------------\n" % i)
            self.insertAtEnd()
            i += 1
        print("Successfully updated the DLL\n")

    def displayDLL(self):
        temp = self.head
        print(
            "\n%-10s%-15s%-13s%s\n" % ("Emp id", "Emp_mobileno", "Emp sal", "Emp dept")
        )
        while temp:
            print(
                "%-10d%-15d%-13.2f%s"
                % (temp.emp_id, temp.emp_mobileno, temp.emp_sal, temp.emp_dept)
            )
            temp = temp.nxt
        print()

    def insertAtEnd(self):
        temp = self.create()
        if temp is None:
            return
        self.last.nxt = temp
        temp = self.last
        self.last = self.last.nxt
        self.last.prev = temp

    def deleteaAtEnd(self):
        if self.last.prev is not None:
            self.last = self.last.prev
            self.last.nxt = None
        else:
            self.head = self.last = None
        self.count -= 1
        print("\nDeleted successfully\n")

    def deleteAtFront(self):
        if self.head.nxt:
            self.head = self.head.nxt
            self.head.prev = None
        else:
            self.head = None
        self.count -= 1
        print("Deleted successfully\n")

    def insertAtFront(self):
        temp = self.create()
        if temp is None:
            return
        temp.nxt = self.head
        self.head.prev = temp
        self.head = temp
        print("Successfully updated the DLL\n")

    def insert(self):
        emp_id = int(input("Enter employee id after which you want to insert : "))
        temp = self.searchNode(emp_id)
        if temp is None:
            print("\nEmployee id entered doesn't exist in DLL\n")
        else:
            if temp.nxt != None:
                temp1 = self.create()
                if temp1 is None:
                    return
                temp1.nxt = temp.nxt
                temp1.prev = temp
                temp.nxt = temp1
                temp1.nxt.prev = temp1
            else:
                self.insertAtEnd()
            print("Successfully updated the DLL\n")

    def delet(self):
        emp_id = int(input("Enter employee id you want to delete : "))
        temp = self.searchNode(emp_id)
        if temp is None:
            print("Employee id entered doesn't exist in DLL\n")
        else:
            if temp.nxt is None:
                self.deleteaAtEnd()
            elif temp.prev is None:
                self.deleteAtFront()
            else:
                temp.prev.nxt = temp.nxt
                temp.nxt.prev = temp.prev
                self.count -= 1
            print("\nDeleted successfully\n")

    def todo(self, option):
        if option in range(1, 11):
            if option == 1:
                self.add()
            elif option == 2:
                print("Total members in DLL is %d" % self.count)
            elif option == 3:
                if self.count == 0:
                    print("There are no employees in DLL\n")
                else:
                    self.displayDLL()
            elif option == 4:
                if self.count == 0:
                    print("There are no employees in DLL\n")
                else:
                    self.insertAtFront()
            elif option == 5:
                if self.count == 0:
                    print("There are no employees in DLL\n")
                else:
                    self.insertAtEnd()
            elif option == 6:
                if self.count == 0:
                    print("There are no employees in DLL\n")
                else:
                    self.insert()
            elif option == 7:
                if self.count == 0:
                    print("There are no employees in DLL to delete\n")
                else:
                    self.deleteAtFront()
            elif option == 8:
                if self.count == 0:
                    print("There are no employees in DLL to delete\n")
                else:
                    self.deleteaAtEnd()
            elif option == 9:
                if self.count == 0:
                    print("There are no employees in DLL to delete\n")
                else:
                    self.delet()
            elif option == 10:
                print("\n------------------------Program ends------------------------")
        else:
            print("Enter a valid option !!\n")

    def operations(self):
        option = 0
        while option != 10:
            print(
                "\n1. Add members\n"
                + "2.  Count of nodes in DLL\n"
                + "3.  Display Employee data in DLL\n"
                "4.  Insert Employee at Front of the DLL\n"
                + "5.  Insert Employee at End of the DLL\n"
                + "6.  Insert Employee at a specific position in DLL\n"
                + "7.  Delete Employee at Front of the DLL\n"
                + "8.  Delete Employee at End of the DLL\n"
                + "9.  Delete Employee at a specific position in DLL\n"
                + "10. Exit\n"
            )
            option = int(input("\nEnter your option: "))
            self.todo(option)


if __name__ == "__main__":
    print("------------------------Program starts------------------------\n\n")
    l = DLL()
    l.operations()
