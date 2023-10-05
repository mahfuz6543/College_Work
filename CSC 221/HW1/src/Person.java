import java.util.GregorianCalendar;
//class Person
public class Person {
    public static  void main(String[] args) {}
        private String fullName;//declaration of instance variables
        private int birthYear;
        private double height;
        private double weight;

    public Person() //default constructor
        {
            fullName = "";
            birthYear = -1;
            height = -1.0;
            weight = -1.0;
        }

    public Person(String fullName, int birthYear, double height, double weight)//non-default constructor
        {
            this.fullName = fullName;
            this.birthYear = birthYear;
            this.height = height;
            this.weight = weight;
        }

        public void setFullName (String fullName)//mutator method
        {
            this.fullName = fullName;
        }

        public String getFullName ()//accessor method
        {
            return this.fullName;
        }

        public void setBirthYear ( int birthYear)//mutator method
        {
            this.birthYear = birthYear;
        }

        public int getBirthYear ()//accessor method
        {
            return this.birthYear;
        }

        public void setHeight ( double height)//mutator method
        {
            this.height = height;
        }

        public double getHeight ()//accessor method
        {
            return this.height;
        }

        public void setWeight ( double weight)//mutator method
        {
            this.weight = weight;
        }

        public double getWeight ()//accessor method
        {
            return this.weight;
        }
        public int calculateAge ()//method to calculate age
        {
            int currentYear = new GregorianCalendar().get(GregorianCalendar.YEAR);
            return currentYear - birthYear;
        }
        public double calculateBMI ()//method to calculate BMI
        {
            return weight / (height * height);
        }
}

