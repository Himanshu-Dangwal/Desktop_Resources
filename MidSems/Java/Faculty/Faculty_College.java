import java.util.Scanner;

class Faculty {
    String name;
    private int basic;

    public Faculty(String name, int basic) {
        this.name = name;
        this.basic = basic;
    }

    public String getDetails() {
        return name + " " + getSalary();
    }

    public double getSalary() {
        return basic;
    }
}

class AssistantProfessor extends Faculty {
    private int DA;

    public AssistantProfessor(String name, int basic, int DA) {
        super(name, basic);
        this.DA = DA;
    }

    @Override
    public double getSalary() {
        return super.getSalary() + (super.getSalary() * DA / 100);
    }

    @Override
    public String getDetails() {
        return "AssiProf " + super.getDetails();
    }
}

class AssociateProfessor extends AssistantProfessor {
    private int MedAllowance;

    public AssociateProfessor(String name, int basic, int DA, int MedAllowance) {
        super(name, basic, DA);
        this.MedAllowance = MedAllowance;
    }

    @Override
    public double getSalary() {
        return super.getSalary() + MedAllowance;
    }

    @Override
    public String getDetails() {
        return "AssoProf " + super.getDetails();
    }
}

class Professor extends AssociateProfessor {
    private int OtherAllowance;

    public Professor(String name, int basic, int DA, int MedAllowance, int OtherAllowance) {
        super(name, basic, DA, MedAllowance);
        this.OtherAllowance = OtherAllowance;
    }

    @Override
    public double getSalary() {
        return super.getSalary() + (super.getSalary() * OtherAllowance / 100);
    }

    @Override
    public String getDetails() {
        return "Prof " + super.getDetails();
    }
}

public class Faculty_College {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int choice = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        String name = scanner.nextLine();
        int basic = scanner.nextInt();

        switch (choice) {
            case 1:
                int DA = scanner.nextInt();
                AssistantProfessor assistantProfessor = new AssistantProfessor(name, basic, DA);
                System.out.println(assistantProfessor.getDetails());
                break;
            case 2:
                int DA2 = scanner.nextInt();
                int MedAllowance = scanner.nextInt();
                AssociateProfessor associateProfessor = new AssociateProfessor(name, basic, DA2, MedAllowance);
                System.out.println(associateProfessor.getDetails());
                break;
            case 3:
                int DA3 = scanner.nextInt();
                int MedAllowance2 = scanner.nextInt();
                int OtherAllowance = scanner.nextInt();
                Professor professor = new Professor(name, basic, DA3, MedAllowance2, OtherAllowance);
                System.out.println(professor.getDetails());
                break;
        }
    }
}
