import org.jetbrains.annotations.NotNull;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Objects;
import java.util.Date;

public abstract class FS_Entry implements Comparable<FS_Entry> {
    protected int id;
    protected FS_Directory parent;
    protected String name;
    protected Date createDate;
    protected boolean hidden;

    public FS_Entry(int id,FS_Directory parent, String name, Date createDate, boolean hidden){
        this.id = id;
        this.parent = parent;
        this.name = name;
        this.createDate = createDate;
        this.hidden = hidden;
    }
    abstract long getSize();

    public String fullPath() {
        return parent.fullPath()+'/' +this.name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public FS_Directory getParent() {
        return parent;
    }

    public void setParent(FS_Directory parent) {
        this.parent = parent;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Date getCreateDate() {
        return createDate;
    }

    public void setCreateDate(Date createDate) {
        this.createDate = createDate;
    }

    public boolean isHidden() {
        return hidden;
    }

    public void setHidden(boolean hidden) {
        this.hidden = hidden;
    }

    @Override
    public int compareTo(@NotNull Object o) {
        FS_Entry fs_entry = (FS_Entry) o;
        if (getId() == fs_entry.getId() && isHidden() == fs_entry.isHidden() && Objects.equals(getParent(), fs_entry.getParent()) && Objects.equals(getName(), fs_entry.getName()) && createDate.compareTo(((FS_Entry) o).createDate) == 0) {
            return 0;
        }
        return 1;
    }

    @Override
    public String toString() {
        SimpleDateFormat dateFormat = new SimpleDateFormat("MM/dd/yy HH:mm:ss");
        String strDate = "";
        try {
            Date date = dateFormat.parse(String.valueOf(createDate));
            strDate = dateFormat.format(date);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return id + " " + name + " " + strDate + " " +(hidden ?"Y" : "N");
    }
}
