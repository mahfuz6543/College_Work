import java.util.Arrays;

public class MSDRadix{
    public static void main(String[] args) {
        String[] A = {"80","65","55","12","90","30","43"};
        System.out.println("Unsorted: "+ Arrays.toString(A));
        Radixsort(A);
        System.out.println("Sorted: "+ Arrays.toString(A));

    }
    private static final int Range= 256;
    public static void Radixsort(String[] A){
        int n = A.length;
        String[]a=new String[n];
        Radixsort(A,0,n-1,0,a);
    }

    private static int charAt(String s, int d){
        if (d == s.length())
            return -1;
        return s.charAt(d);
    }

    private static void Radixsort(String[]A,int lo,int hi,int d,String[]a) {
        if (hi<=lo) {
            MSD_Sort(A,lo,hi,d);
            return;
        }
        int[] count=new int[Range+2];
        for (int i=lo;i<=hi;i++){
            int c=charAt(A[i],d);
            count[c+2]++;
        }
        for (int r=0;r<Range+1;r++)
            count[r+1]+=count[r];

        for (int i=lo;i<=hi;i++){
            int c=charAt(A[i],d);
            a[count[c+1]++] = A[i];
        }
        for (int i=lo; i<=hi;i++)
            A[i]=a[i-lo];
        for (int r=0;r<Range;r++)
            Radixsort(A,lo+count[r],lo+count[r+1]-1,d+1,a);
    }
    private static void n1(String[]A,int i,int j) {
        String temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
    private static void MSD_Sort(String[]A,int lo,int hi,int d){
        for (int i = lo;i<=hi;i++)
            for (int j=i;j>lo && kit(A[j],A[j-1],d);j--)
                n1(A,j,j-1);
    }

    private static boolean kit(String e,String f,int d) {
        assert e.substring(0,d).equals(f.substring(0,d));
        return e.substring(d).compareTo(f.substring(d))<0;
    }
}