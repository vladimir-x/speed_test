public class Main {

    public static void main(String[] args) {

        long st = System.currentTimeMillis();

        String func = args[0];
        long a = Long.parseLong(args[1]);
        long p = Long.parseLong(args[2]);

        Calculator.run(func, a, p);
        Crc.run(func, a, p);
        Collections.run(func, a, p);

        long en = System.currentTimeMillis();

        System.out.printf(">>> lang: JAVA; func: %s; argA: %d; argP: %d; time: %d;\n", func, a , p, (en - st));

    }

}
