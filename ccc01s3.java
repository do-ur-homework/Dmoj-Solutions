import java.util.*;

public class ccc01s3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String ipt = "";
        List<String> roads = new ArrayList<>();
        Map<Character, List<Character>> m = new HashMap<>();

        while (!(ipt = scanner.nextLine()).equals("**")) {
            roads.add(ipt);
        }

        for (String road : roads) {
            char start = road.charAt(0);
            char end = road.charAt(1);

            m.putIfAbsent(start, new ArrayList<>());
            m.get(start).add(end);

            m.putIfAbsent(end, new ArrayList<>());
            m.get(end).add(start);
        }

        List<String> success = new ArrayList<>();
        int total = 0;

        for (String road : roads) {
            if (bfs(road, m) == 1) {
                total++;
                success.add(road);
            }
        }

        for (String element : success) {
            System.out.println(element);
        }
        System.out.println("There are " + total + " disconnecting roads.");
    }

    private static int bfs(String road, Map<Character, List<Character>> m) {
        Map<Character, List<Character>> graph = new HashMap<>();
        for (Map.Entry<Character, List<Character>> entry : m.entrySet()) {
            graph.put(entry.getKey(), new ArrayList<>(entry.getValue()));
        }

        char start = road.charAt(0);
        char end = road.charAt(1);

        graph.get(start).remove((Character) end);
        graph.get(end).remove((Character) start);

        Queue<Character> queue = new LinkedList<>();
        Set<Character> explored = new HashSet<>();

        queue.add('A');

        while (!queue.isEmpty()) {
            char node = queue.poll();
            if (!explored.contains(node)) {
                explored.add(node);
                List<Character> neighbours = graph.getOrDefault(node, new ArrayList<>());
                for (char neighbour : neighbours) {
                    queue.add(neighbour);
                    if (neighbour == 'B') {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
}