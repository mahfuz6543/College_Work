import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Translator {
    private final ArrayList<MorseCode> listMorseCodes;
    public Translator(String fileName) { //non default constructor
        listMorseCodes=new ArrayList<MorseCode>();
        Scanner file=null; //Create a new instance of the Scanner class and set its initial value to null.
        try{
            file = new Scanner(new FileInputStream(new File(fileName)));
            while (file.hasNext()) { //When the file is successfully opened, read all of the lines.
                String[] line=file.nextLine().split("\t"); //A tab separates the lines in the split method.
                if(line.length==2){ //if array contains two elements..
                    try {
                        char character=line[0].charAt(0); //change the character's datatype from String to char
                        MorseCode object=new MorseCode(character,line[0]); //construct a MorseCode object with the character and the correspond additional code
                        listMorseCodes.add(object); //add each valid line to the 𝐴𝑟𝑟𝑎𝑦𝐿𝑖𝑠t
                    }
                    catch (Exception ex){ //The MorseCode will throw an exception if a character is invalid.
                        System.err.println(ex.toString()); //And it will print the error
                    }
                }
                else if(line[0].length()!=0){
                    System.out.println("Got an invalid line:"+line[0]); //print out the invalid line
                }
            }
        }
        catch(FileNotFoundException fe){ //Throw an exception if the file cannot be found
            System.err.println("Failed to open file: "+fileName);
        }
    }
    public void printList(){ //The content of the ArrayList is formatted and printed.
        for (MorseCode object:listMorseCodes){
            System.out.println(object.getCharacter()+"\t"+object.getEncoding());
        }
    }
    public String get(char character){ //For the char input parameter, returns the associated MorseCode object.
        if(character==' '){
            return "  ";
        }
        for (MorseCode object:listMorseCodes){ //loops that iterate the list
            if(object.getCharacter()==character){ //determine whether the input can be converted to correspond morse code
                return object.getEncoding()+"  "; //return the morse code
            }
        }
        return "null"; //If the character is not found, return 𝑛𝑢𝑙𝑙
    }
    public String convert(String line){ //convert a string to its morse code
        if(line==" "||line == null){
            System.out.println(" ");
        }
        else {
            for (int i=0;i<line.length();i++){
                char character=Character.toUpperCase(line.charAt(i));
                String encoding=convert(String.valueOf(character));
                System.out.print(encoding);
            }
            System.out.println("");
        }
        return line;
    }
    public void convertFile(String fileName) throws Exception{
        Scanner file=null;
        try{
            file=new Scanner(new FileInputStream(new File(fileName)));
            while (file.hasNext()){
                convert(file.nextLine()); //To convert each line of the file to morse code
            }
        }
        catch(FileNotFoundException fe){ //If the file open fails, an exception is thrown with the message
            throw new Exception("Failed to open file:  " + fileName);
        }
    }
}
