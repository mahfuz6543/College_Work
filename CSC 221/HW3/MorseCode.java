public class MorseCode {
    private char character; //character values
    private String encoding; //encoding values
    public MorseCode(char character, String encoding) throws Exception{ //non default constructor
        int ascii=character;
        if ((ascii>=32&&ascii<=90)&&(encoding!=null && encoding.length()>=1)){ //Morse character as an ASCII code between 32 and 90 and an encoding value that cannot be 𝑁𝑈𝐿𝐿 or empty
            this.character=character;
            this.encoding=encoding;
        }
        else{
            throw new Exception("The character "+character+" with conversion"+encoding+" is invalid.");
        }
    }
    public char getCharacter(){
        return character;
    }
    public String getEncoding(){
        return encoding;
    }
}