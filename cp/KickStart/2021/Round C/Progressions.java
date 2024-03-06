import java.util.*;
import java.lang.Math;
import java.util.stream.IntStream;
import static java.util.stream.Collectors.toList;

public class Progressions
{
    public static void main(String[] args)
    {
        List<List<Integer>> list = Calculate(15);
        System.out.print(list);
    }

    public static int Calculate(int s)
    {
        List<List<Integer>> list = new ArrayList<>();
        int p = 2*s;
        int nMax = (int)Math.sqrt(p);
        for (int n=2; n<=nMax; n++) {
            if(p % n == 0) {
                int q = p / n;
                if(((q - n) & 1) == 1) {          
                    int a = (q - n + 1) / 2;
                    list.add(range(a,n));
                }
            }
        }
        return size(list);
    }

    public static List<Integer> range(int a, int n) {
        return IntStream.range(a, a+n)
            .boxed()
            .collect(toList());
    }
}