import java.util.Arrays;
import java.util.Random;

public class Sorting{
    public static void main(String[] args) throws Exception{
        Random rand = new Random();
        long Timestart;
        long Timeend;
        long runningTime;
        final int size[]={10,100,1000,10000,100000,1000000};

        for (int i=0; i<size.length; i++)
        {
            int A[]=new int[size[i]];
            for (int j=0;j< A.length; j++) {
                A[j] = rand.nextInt(1000)+1;
            }
            System.out.println("Array Size of " + A.length + ":");

            //running time for insertion sort
            System.out.print("Running time for Insertion Sort: ");
            int temp1[] = new int[A.length];
            for (int k = 0; k < temp1.length; k++) {
                temp1[k] = A[k];}
            Timestart=System.nanoTime();
            InsertionSort(temp1);
            Timeend=System.nanoTime();
            runningTime =Timeend-Timestart;
            System.out.println(runningTime + " Nano seconds");

            //running time for merge sort
            System.out.print("Running time for Merge Sort: ");
            int temp2[]=new int[A.length];
            for (int k =0;k<temp2.length; k++) {
                temp2[k]=A[k];
            }
            Timestart=System.nanoTime();
            MergeSort(temp2);
            Timeend=System.nanoTime();
            runningTime=Timeend-Timestart;
            System.out.println(runningTime + " Nano seconds");

            //running time for heap sort
            System.out.print("Running time for Heap Sort: ");
            int temp3[]=new int[A.length];
            for (int k=0;k<temp3.length; k++) {
                temp3[k]=A[k];}
            Timestart= System.nanoTime();
            HeapSort(temp3);
            Timeend=System.nanoTime();
            runningTime=Timeend-Timestart;
            System.out.println(runningTime + " Nano seconds");

            //running time for QuickSort
            System.out.print("Running time for Quick Sort: ");
            int temp4[] = new int[A.length];
            for (int k = 0;k<temp4.length; k++) {
                temp4[k] = A[k];}
            Timestart= System.nanoTime();
            quickSort(temp4);
            Timeend= System.nanoTime();
            runningTime=Timeend-Timestart;
            System.out.println(runningTime + " Nano seconds");

            //running time for QuickSortRandom
            System.out.print("Running time for Quick Randomized Sort: ");
            int temp5[]=new int[A.length];
            for (int k=0;k<temp5.length; k++) {
                temp5[k]=A[k];}
            Timestart= System.nanoTime();
            RandomQuickSort(temp5);
            Timeend=System.nanoTime();
            runningTime=Timeend-Timestart;
            System.out.println(runningTime + " Nano seconds");

            //running time for Radix Random
            System.out.print("Running time for Radix Sort: ");
            int temp6[]=new int[A.length];
            for (int k=0;k<temp6.length; k++) {
                temp6[k] = A[k];}
            Timestart= System.nanoTime();
            Radixsort(temp6);
            Timeend= System.nanoTime();
            runningTime =Timeend-Timestart;
            System.out.println(runningTime + " Nano seconds");
            System.out.println("\n");
        }
    }
    // Insertion sort
    public static void InsertionSort(int[]A){
        for (int j=1;j<A.length;j++){
            int key=A[j];
            int i=j-1;
            while(i>=0&&A[i]>key){
                A[i+1]=A[i];
                i=i-1;
            }
            A[i+1]=key;
        }
    }

    // Merge Sort
    public static void MergeSort(int A[]) {
        MergeSort(A, 0, A.length-1);
    }
    private static void MergeSort(int[] A, int left, int right) {
        if (left < right) {
            int mid = (left + right)/2;
            MergeSort(A,left, mid);
            MergeSort(A, mid+1,right);
            Merge(A,left,mid,right);
        }
    }
    private static void Merge(int A[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int L[] = new int[n1];
        int R[] = new int[n2];
        for (int i=0;i<n1;i++) {
            L[i]=A[left+i];
        }
        for (int i=0;i<n2;i++) {
            R[i] = A[mid+i+1];
        }
        int i = 0, j = 0, k = left;
        while (i < n1 && j<n2) {
            if (L[i]<R[j]) {
                A[k]=L[i];
                i++;
            }
            else {
                A[k]=R[j];
                j++;
            }
            k++;
        }
        while (i<n1) {
            A[k]=L[i];
            i++;
            k++;
        }
        while (j<n2) {
            A[k]=R[j];
            k++;
            j++;
        }
    }

    // Heap sort
    public static void HeapSort(int[]A) {
        int n=A.length;
        // to build max heap
        for (int i=n/2-1;i>=0;i--){
            heapify(A,n,i);
        }
        for (int i= n-1;i>=0;i--){
            swap(A,0,i);
            heapify(A,i,0);
        }
    }
    private static void heapify(int[] A, int n, int i) {
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;

        if (l < n && A[l] > A[largest]) {
            largest = l;
        }
        else largest = i;
        if (r < n && A[r] > A[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(A, i, largest);
            heapify(A, n, largest);
        }
    }

    // Quick sort
    public static void quickSort(int A[]) {
        quickSort(A, 0, A.length - 1);
    }
    private static void quickSort(int A[], int left, int right) {
        if (left < right) {
            int pt = partition(A, left, right);
            quickSort(A, left, pt - 1);
            quickSort(A, pt + 1, right);
        }
    }
    private static int partition(int[]A,int left,int right) {
        int x=A[right];
        int i=left-1;
        for (int j=left;j<right;j++){
            if (A[j]<x) {
                i=i+1;
                swap(A,i,j);
            }
        }
        i = i + 1;
        swap(A, i, right);
        return i;
    }

    // Random Quick sort
    public static void RandomQuickSort(int A[]) {
        RandomQuickSort(A, 0, A.length-1);
    }
    private static void RandomQuickSort(int A[],int left,int right)
    {
        if (right-left <= 0)
            return;
        else {
            Random rand = new Random();
            int index = left + rand.nextInt(right - left + 1);
            swap(A, index, right);
            int x = A[right];
            int partition = partitionIt(A, left, right, x);
            RandomQuickSort(A, left,partition - 1);
            RandomQuickSort(A,partition + 1, right);
        }
    }
    private static int partitionIt(int A[],int left,int right,long x) {
        int lPtr=left - 1;
        int rPtr=right;
        while (true) {
            while (A[++lPtr]<x);
            while (rPtr >0 && A[--rPtr]>x);
            if (lPtr>=rPtr)
                break;
            else
                swap(A,lPtr,rPtr);
        }
        swap(A,lPtr,right);
        return lPtr;
    }
    private static void swap(int A[],int d1,int d2){
        int temp = A[d1];
        A[d1] = A[d2];
        A[d2] = temp;
    }

    // Radix Sort
    public static void Radixsort(int[] A) {
        Radixsort(A, A.length);
    }
    private static void Radixsort(int A[], int n) {
        int m = getMax(A, n);
        for (int exp = 1; m / exp > 0; exp *= 10)
            countSort(A, n, exp);
    }
    private static void countSort(int A[], int n, int exp) {
        int output[] = new int[n]; // output array
        int j;
        int count[] = new int[10];
        Arrays.fill(count, 0);
        for (j = 0; j < n; j++)
            count[(A[j] / exp) % 10]++;
        for (j = 1; j < 10; j++)
            count[j] += count[j - 1];
        for (j = n - 1; j >= 0; j--) {
            output[count[(A[j]/exp)% 10]-1]=A[j];
            count[(A[j]/exp) % 10]--;
        }
        for (j = 0; j < n; j++)
            A[j] = output[j];
    }
    // function find the largest value
    private static int getMax(int A[],int n) {
        int mx=A[0];
        for (int i=1;i<n;i++)
            if (A[i]>mx)
                mx=A[i];
        return mx;
    }
}
