import java.util.*;

public class Collections {

    long array_cp(int a, long p) {
        byte[] source = new byte[a];
        byte[] dest = new byte[a];

        for (long i = 0; i < p; ++i) {
            System.arraycopy(source, 0, dest, 0, a);
        }
        return dest[0];
    }

    static class CustomList {
        int store[] = new int[1000000];
        int size = 0;

        void listPush(int v) {
            store[size++] = v;
        }
        int listGet(int i) {
            return store[i];
        }

        void listClear() {
            size = 0;
        }
    }


    long list_custom_check_append_clear(long a, long p) {
        int res = 0;
        CustomList l = new CustomList();
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < a; ++j) {
                l.listPush(j);
            }
            res += l.listGet(3);
            l.listClear();
        }
        return res;
    }

    long list_custom_check_append_recreate(long a, long p) {
        int res = 0;
        for (int i = 0; i < p; ++i) {
            CustomList l = new CustomList();
            for (int j = 0; j < a; ++j) {
                l.listPush(j);
            }
            res += l.listGet(3);
        }
        return res;
    }

    long list_standart_check_append_clear(long a, long p) {
        List l = new ArrayList();
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < a; ++j) {
                l.add(j);
            }
            l.get(3);
            l.clear();
        }
        return a;
    }

    long list_standart_check_append_recreate(long a, long p) {
        int res = 0;
        for (int i = 0; i < p; ++i) {
            List l = new ArrayList();        // теряем время на создание и удаление объекта
            for (int j = 0; j < a; ++j) {
                l.add(j);
            }
            l.get(3);
        }
        return a;
    }

    long tree_set_standart(long a, long p) {
        var s = new TreeSet<Integer>();
        for (int i = 0; i < a; ++i) {
            s.add(i);

        }
        for (int j = 0; j < p; ++j) {
            s.contains(j);
        }
        return s.size();
    }

    long hash_set_standart(long a, long p) {
        var s = new HashSet<Integer>();
        for (int i = 0; i < a; ++i) {
            s.add(i);

        }
        int znct = 0;
        for (int j = 0; j < p; ++j) {
            if (!s.contains(j)){
                znct++;
            }
        }
        return znct;
    }

    long list_cp_prepare_to_qsort(long a, long p) {
        for (int i = 0; i < p; ++i) {
            var s = new ArrayList<Integer>();
            for (int j = 0; j < a; ++j) {
                s.add((j * j * 13) % 100000);
            }

        }

        return 0;
    }

    long array_cp_prepare_to_qsort(long a, long p) {
        for (int i = 0; i < p; ++i) {
            var s = new int[(int)a];
            for (int j = 0; j < a; ++j) {
                s[j]=((j * j * 13) % 100000);
            }

        }

        return 0;
    }

    long sort_standart_list(long a, long p) {
        for (int i = 0; i < p; ++i) {
            var s = new ArrayList<Integer>();
            for (int j = 0; j < a; ++j) {
                s.add((j * j * 13) % 100000);
            }

            java.util.Collections.sort(s);
        }

        return 0;
    }

    long sort_standart_array(long a, long p) {
        for (int i = 0; i < p; ++i) {
            var s = new int[(int)a];
            for (int j = 0; j < a; ++j) {
                s[j]=((j * j * 13) % 100000);
            }
            Arrays.sort(s);
        }

        return 0;
    }

    public static void run(String func, long a, long p) {
        Collections c = new Collections();
        if (func.equals("array_cp")) {
            c.array_cp((int) a, p);
        }
        if (func.equals("list_custom_check_append_clear")) {
            c.list_custom_check_append_clear(a, p);
        }
        if (func.equals("list_custom_check_append_recreate")) {
            c.list_custom_check_append_recreate(a, p);
        }
        if (func.equals("list_standart_check_append_clear")) {
             c.list_standart_check_append_clear(a, p);
        }
        if (func.equals("list_standart_check_append_recreate")) {
             c.list_standart_check_append_recreate(a, p);
        }
        if (func.equals("tree_set_standart")) {
            c.tree_set_standart(a, p);
        }
        if (func.equals("hash_set_standart")) {
            c.hash_set_standart(a, p);
        }
        if (func.equals("list_cp_prepare_to_qsort")) {
            c.list_cp_prepare_to_qsort(a, p);
        }
        if (func.equals("array_cp_prepare_to_qsort")) {
            c.array_cp_prepare_to_qsort(a, p);
        }
        if (func.equals("sort_standart_list")) {
            c.sort_standart_list(a, p);
        }
        if (func.equals("sort_standart_array")) {
            c.sort_standart_array(a, p);
        }
    }

}
