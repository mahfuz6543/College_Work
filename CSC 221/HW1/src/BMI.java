//class BMI
public class BMI {
    public static String classifyBMI(double bmi) //method to calculate classifications
    {
        if (bmi<=18.5)
            return "underweight";
        else if (bmi>18.5 && bmi<=25)
            return "normal weight";
        else if (bmi>25 && bmi<=30)
            return "over weight";
        else if (bmi>30)
            return "obese";
        else
            return "error";
    }
}
