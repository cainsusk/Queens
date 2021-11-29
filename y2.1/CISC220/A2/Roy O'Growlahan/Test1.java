public class Test1 {

    public static void recurse(int n) {
        if (n == 0) {
            return;
        }
        recurse(n - 1);
    }
}

