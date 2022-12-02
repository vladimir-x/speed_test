public class Calculator {

    long incrementator(long a, long p) {
        long res = a;
        for (long i = 0; i < p; ++i) {
            res+=i+i;
        }
        return res;
    }


    long multiplier(long a, long p) {
        long res = a;
        for (long i = 1; i < p; ++i) {
            res*=i;
        }
        return res;
    }

    long divider(long a, long p) {
        long res = a;
        for (long i = 1; i < p; ++i) {
            res *= a / i;
        }
        return res;
    }

    long modder(long a, long p) {
        long res = 0;
        for (long i = 1; i < p; ++i) {
            res += a % i;
        }
        return res;
    }

    long xorder(long a, long p) {
        long res = 0;
        for (long i = 0; i < p; ++i) {
            res ^= i;
        }
        return res;
    }

    long factorial(long a) {
        if (a == 1) return 1;
        return a*factorial(a-1);
    }

    long factorialCycle(long a, long p) {
        long res = 0;
        for (long i = 0; i < p; ++i) {
            res += factorial(a);
        }
        return res;
    }

    public static void run(String func, long a, long p) {
        Calculator c = new Calculator();
        if (func.equals("incrementator")) {
            c.incrementator(a, p);
        }
        if (func.equals("multiplier")) {
            c.multiplier(a, p);
        }
        if (func.equals("divider")) {
            c.divider(a, p);
        }
        if (func.equals("modder")) {
            c.modder(a, p);
        }
        if (func.equals("xorder")) {
            c.xorder(a, p);
        }
        if (func.equals("factorial")) {
            c.factorialCycle(a, p);
        }
    }

}
