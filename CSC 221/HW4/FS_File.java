import org.jetbrains.annotations.NotNull;
import java.util.Date;

abstract class FS_File extends FS_Entry {
    protected long size;

    public FS_File(long size, int id, FS_Directory parent, String name, Date createdDate, boolean hidden) {
        super(id, parent, name, createdDate, hidden);
        this.size = size;
    }

    @Override
    long getSize() {
        return size;
    }

    @Override
    public String toString() {
        return super.toString() + " " + size;
    }

    @Override
    public int compareTo(@NotNull Object o) {
        FS_File fs_file = (FS_File) o;
        if (super.compareTo(o) == 0 && getSize() == fs_file.getSize()) {
            return 0;
        }
        return 1;
    }

    public void setSize(long size) {
        this.size = size;
    }
}