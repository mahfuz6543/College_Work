import java.util.Scanner;

public class TestA1 //tester class
{
    public static void main(String[] args)//main method
    {
        Scanner sc=new Scanner(System.in);//scanner class object
        String name;
        int year;
        double height, weight;
        Person p1=new Person();//creates object
        System.out.printf("First Instance Prompts");
        System.out.printf("\nEnter person's name: ");
        name= sc.nextLine();//Take input from user
        System.out.printf("Enter person's year of birth: ");
        year = sc.nextInt();
        System.out.printf("Enter peron's height in meters: ");
        height=sc.nextDouble();
        System.out.printf("Enter peron's weight in kilogram: ");
        weight=sc.nextDouble();
        p1.setFullName(name);//call method
        p1.setBirthYear(year);
        p1.setHeight(height);
        p1.setWeight(weight);
        System.out.printf("\nSecond Instance prompts");
        System.out.printf("\nEnter person's name: ");
        sc.nextLine();
        name= sc.nextLine();
        System.out.printf("Enter person's year of birth: ");
        year=sc.nextInt();
        System.out.printf("Enter peron's height in meters: ");
        height=sc.nextDouble();
        System.out.printf("Enter peron's weight in kilogram: ");
        weight=sc.nextDouble();
        Person p2=new Person(name,year,height,weight);
        System.out.printf("\n1st Instance Output");
        System.out.printf("\n\tFull Name: "+p1.getFullName());//This prints output
        System.out.printf("\n\t\tAge: "+p1.calculateAge());
        System.out.printf("\n\t\tHeight: "+p1.getHeight());
        System.out.printf("\n\tWeight: "+p1.getWeight());
        System.out.printf("\nClassification: "+ BMI.classifyBMI(p1.calculateBMI()));
        System.out.printf("\n\n2nd Instance Output");
        System.out.printf("\n\tFull Name: "+p2.getFullName());//This prints output
        System.out.printf("\n\t\tAge: "+p2.calculateAge());
        System.out.printf("\n\t\tHeight: "+p2.getHeight());
        System.out.printf("\n\tWeight: "+p2.getWeight());
        System.out.printf("\nClassification: "+BMI.classifyBMI(p2.calculateBMI()));
    }
}