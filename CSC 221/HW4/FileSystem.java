import java.text.SimpleDateFormat;
import java.util.TreeSet;

public class FileSystem extends TreeSet<FS_Entry> {
    private FS_Entry[] list;

    public FileSystem() {
    }
    public FS_Directory findById(int parseInt) {
    }
    public Object getSize() {
    }


    public FileSystem getDirectories() {
    }

    public FileSystem getFiles() {
    }

    public FileSystem getExecutables() {
    }
    public FileSystem getFS_Executable() {
        FileSystem executable = new FileSystem();
        for (FS_Entry i : this) {
            if (i instanceof FS_Executable) {
                executable.add(i);
            }
        }
        return executable;
    }
    public FileSystem getFS_Directory() {
        FileSystem directory = new FileSystem();
        for (FS_Entry i : this) {
            if (i instanceof FS_Directory) {
                directory.add(i);
            }
        }
        return directory;
    }
    public void printFormatted(){
        String border = "+-------+-------------+-------------+------------+--------------+----------+-------+------------+";
        System.out.println(border);
        System.out.printf("|%6s  |%4s  |%13s  |%17s |%6s |%4s |%5","id","name","size","Date Created","hidden","Full Path","To String");
        SimpleDateFormat formatter = new SimpleDateFormat("MM/dd/yy");
        for(FS_Entry sc: this.list) {
            System.out.println(border);
            System.out.printf("| %-6s", sc.getId());
            System.out.printf("| %-4d", sc.getName());
            System.out.printf("| $%,-13f", sc.getSize());
            //Convert the Date object into String
            String date = formatter.format(sc.getCreateDate());
            System.out.printf("| %-17s", date);
            System.out.printf("| %-16s", sc.getParent().isHidden());
            System.out.printf("|%4s ", sc.getParent().fullPath());
            //check if the Screen object belong to CRT class
            if(sc instanceof FS_File) {
                System.out.printf("|%5f ", ((FS_File)sc).getSize());
            }
            else {
                System.out.printf("|%6s ", " ");
            }
            System.out.printf("|%11s ", sc instanceof FS_File ? ((FS_File) sc).getSize() : " ");
            System.out.printf("|%n");
        }
        System.out.println(border);
    }


}