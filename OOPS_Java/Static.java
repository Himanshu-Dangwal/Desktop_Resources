import java.util.Scanner;

class Course {
    private String courseCode;
    private String courseName;
    private static int totalEnrollment = 0;

    public Course(String courseCode, String courseName, int enrollment) {
        this.courseCode = courseCode;
        this.courseName = courseName;
        totalEnrollment += enrollment;
    }

    public void displayCourseInfo() {
        System.out.println("Course Code: " + courseCode);
        System.out.println("Course Name: " + courseName);
        System.out.println("Enrollment: " + totalEnrollment);
        System.out.println(); // Add a newline for better readability
    }

    public static int getTotalEnrollment() {
        return totalEnrollment;
    }
}

public class Static{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String code1 = scanner.nextLine();
        String name1 = scanner.nextLine();
        int enrollment1 = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character


        String code2 = scanner.nextLine();
        String name2 = scanner.nextLine();
        int enrollment2 = scanner.nextInt();

        Course csCourse = new Course(code1, name1, enrollment1);
        Course engCourse = new Course(code2, name2, enrollment2);

        csCourse.displayCourseInfo();
        engCourse.displayCourseInfo();

        System.out.println("Total Enrollment: " + Course.getTotalEnrollment());
        
        scanner.close();
    }
}
