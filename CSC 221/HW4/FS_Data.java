import java.util.Date;

public class FS_Data extends FS_File {
    public FS_Data(long size, int id, FS_Directory parent, String name, Date createdDate, boolean hidden) {
        super(size, id, parent, name, createdDate, hidden);
        this.size = size;
    }


}
