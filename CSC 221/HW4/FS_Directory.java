import org.jetbrains.annotations.NotNull;
import java.util.Date;

public class FS_Directory extends FS_Entry {

    private int childCount;
    public FS_Directory(int childCount, int id, FS_Directory parent, String name, Date createDate, boolean hidden) {
        super(id, parent, name, createDate, hidden);
        this.childCount = childCount;
    }

    public int getChildCount() {
        return childCount;
    }

    public void setChildCount(int childCount) {
        this.childCount = childCount;
    }

    @Override
    long getSize() {
        return 0;
    }

    @Override
    public String toString() {
        return super.toString() + " " + childCount;
    }

    @Override
    public int compareTo(@NotNull Object o) {
        FS_Directory that = (FS_Directory) o;
        if (super.compareTo(o) == 0 && getChildCount() == that.getChildCount()) {
            return 0;
        }
        return 1;
    }
}
