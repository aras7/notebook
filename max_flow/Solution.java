import java.util.*;
import java.util.Random;

class Graph {


   public Graph(int n) {
   }
}

class Pair {
  int key;
  int value;

  public Pair(int a, int b) {
    this.key = a;
    this.value = b;
  }

  public int getKey() { return key; }
  public int getValue() { return value; }
}

public class Solution {
    static int MAX = 10000000;
    static int VALUE = 4687;
    static int RESULT = VALUE * MAX * 1;

    static void test_hash_map() {
        long startTime = System.currentTimeMillis();
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int acm = 0;

        for(int i = 0; i < MAX; i++)
          map.put(i, VALUE);

        /*for(int i = 0; i < MAX; i++) {
          int r = map.get(i);
          acm += r;
        }*/

        for(Map.Entry<Integer, Integer> entry : map.entrySet()) {
          int key = entry.getKey();
          int value = entry.getValue();

          acm += value;
        }

        System.out.println("test_hash_map done! " + (acm == RESULT));
        System.out.println((System.currentTimeMillis() - startTime) / 1000.0);
    }

    static void test_tree_map() {
        long startTime = System.currentTimeMillis();

        Map<Integer, Integer> map = new TreeMap<Integer, Integer>();
        int acm = 0;

        for(int i = 0; i < MAX; i++)
          map.put(i, VALUE);

        /*for(int i = 0; i < MAX; i++) {
          int r = map.get(i);
          acm += r;
        }*/

        for(Map.Entry<Integer, Integer> entry : map.entrySet()) {
          int key = entry.getKey();
          int value = entry.getValue();

          acm += value;
        }

        System.out.println("test_tree_map done! " + (acm == RESULT));
        System.out.println((System.currentTimeMillis() - startTime) / 1000.0);
    }

    static void test_array_list() {
        long startTime = System.currentTimeMillis();

        List list = new ArrayList<Pair>();
        int acm = 0;


        for(int i = 0; i < MAX; i++)
            list.add(new Pair(i, VALUE));

        /*for(int i = 0; i < MAX; i++) {
          for (int j = 0; j < list.size(); j++) {
            if( ((Pair)list.get(j)).getKey() == i) {
              acm += ((Pair)list.get(j)).getValue();

              break;
            }
          }
        }*/

        for(Object entry : list) {
          int key = ((Pair)entry).getKey();
          int value = ((Pair)entry).getValue();

          acm += value;
        }

        System.out.println("test_array_list done! " + (acm == RESULT));
        System.out.println((System.currentTimeMillis() - startTime) / 1000.0);
    }

    public static void main(String[] args) {
        test_hash_map();
        test_tree_map();
        test_array_list();
    }
}
