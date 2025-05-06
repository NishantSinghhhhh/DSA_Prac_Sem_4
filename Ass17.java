// Department maintains student information. the file contains rollno, name, division, and address.
// Allow user to add, edit, delete, insert and search information of student. use sequential file to
// maintain the data

import java.io.*;
import java.util.*;

class Student {
    int rollNo;
    String name;
    String division;
    String address;

    public Student(int rollNo, String name, String division, String address) {
        this.rollNo = rollNo;
        this.name = name;
        this.division = division;
        this.address = address;
    }

    @Override
    public String toString() {
        return rollNo + "," + name + "," + division + "," + address;
    }

    static Student fromString(String data) {
        String[] parts = data.split(",");
        return new Student(
            Integer.parseInt(parts[0]),
            parts[1],
            parts[2],
            parts[3]
        );
    }
}

public class StudentFileManager {

    static final String FILE_NAME = "students.txt";

    // Add a new student record
    public static void addStudent(Student s) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_NAME, true));
        writer.write(s.toString());
        writer.newLine();
        writer.close();
    }

    // Display all records
    public static void displayAll() throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME));
        String line;
        System.out.println("\nRollNo\tName\tDivision\tAddress");
        while ((line = reader.readLine()) != null) {
            Student s = Student.fromString(line);
            System.out.println(s.rollNo + "\t" + s.name + "\t" + s.division + "\t\t" + s.address);
        }
        reader.close();
    }

    // Search student by roll number
    public static void search(int rollNo) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME));
        String line;
        boolean found = false;
        while ((line = reader.readLine()) != null) {
            Student s = Student.fromString(line);
            if (s.rollNo == rollNo) {
                System.out.println("\nRecord Found:");
                System.out.println("RollNo: " + s.rollNo);
                System.out.println("Name: " + s.name);
                System.out.println("Division: " + s.division);
                System.out.println("Address: " + s.address);
                found = true;
                break;
            }
        }
        if (!found) System.out.println("Record not found!");
        reader.close();
    }

    // Delete student by roll number
    public static void delete(int rollNo) throws IOException {
        File inputFile = new File(FILE_NAME);
        File tempFile = new File("temp.txt");

        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));

        String line;
        boolean deleted = false;
        while ((line = reader.readLine()) != null) {
            Student s = Student.fromString(line);
            if (s.rollNo == rollNo) {
                deleted = true;
                continue;
            }
            writer.write(line);
            writer.newLine();
        }
        writer.close();
        reader.close();

        inputFile.delete();
        tempFile.renameTo(inputFile);

        if (deleted) System.out.println("Record deleted successfully.");
        else System.out.println("Record not found!");
    }

    // Edit student by roll number
    public static void edit(int rollNo, Student newDetails) throws IOException {
        File inputFile = new File(FILE_NAME);
        File tempFile = new File("temp.txt");

        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));

        String line;
        boolean edited = false;
        while ((line = reader.readLine()) != null) {
            Student s = Student.fromString(line);
            if (s.rollNo == rollNo) {
                writer.write(newDetails.toString());
                edited = true;
            } else {
                writer.write(line);
            }
            writer.newLine();
        }

        writer.close();
        reader.close();

        inputFile.delete();
        tempFile.renameTo(inputFile);

        if (edited) System.out.println("Record updated successfully.");
        else System.out.println("Record not found!");
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n--- Student Record Manager ---");
            System.out.println("1. Add Student");
            System.out.println("2. Display All");
            System.out.println("3. Search by RollNo");
            System.out.println("4. Delete Record");
            System.out.println("5. Edit Record");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1 -> {
                    System.out.print("Roll No: "); int roll = sc.nextInt(); sc.nextLine();
                    System.out.print("Name: "); String name = sc.nextLine();
                    System.out.print("Division: "); String div = sc.nextLine();
                    System.out.print("Address: "); String addr = sc.nextLine();
                    addStudent(new Student(roll, name, div, addr));
                }
                case 2 -> displayAll();
                case 3 -> {
                    System.out.print("Enter RollNo to search: ");
                    int r = sc.nextInt();
                    search(r);
                }
                case 4 -> {
                    System.out.print("Enter RollNo to delete: ");
                    int r = sc.nextInt();
                    delete(r);
                }
                case 5 -> {
                    System.out.print("Roll No to Edit: "); int roll = sc.nextInt(); sc.nextLine();
                    System.out.print("New Name: "); String name = sc.nextLine();
                    System.out.print("New Division: "); String div = sc.nextLine();
                    System.out.print("New Address: "); String addr = sc.nextLine();
                    edit(roll, new Student(roll, name, div, addr));
                }
                case 6 -> System.out.println("Exiting...");
                default -> System.out.println("Invalid choice!");
            }

        } while (choice != 6);

        sc.close();
    }
}

// 1. Add Student
// > Roll No: 1
// > Name: John
// > Division: A
// > Address: Pune

// 2. Display All
// > RollNo Name Division Address
// > 1     John    A       Pune
