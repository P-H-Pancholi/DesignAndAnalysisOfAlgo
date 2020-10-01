import java.util.Stack;
import edu.princeton.cs.algs4.Queue;

public class DepthFirstSearch {

    private boolean[] marked;
    private int[] edgeTo;
    public Queue<Integer> post = new Queue<>();
    public Queue<Integer> pre = new Queue<>();
    private int s;

    public DepthFirstSearch(Digraph G, int s) {
        marked = new boolean[G.V()];
        edgeTo = new int[G.V()];
        this.s = s;
        dfs(G, s);
    }

    public DepthFirstSearch(Digraph G, Iterable<Integer> set) {
        marked = new boolean[G.V()];
        edgeTo = new int[G.V()];
        this.s = s;
        for (int i : set) {
            if (!marked[i])
                dfs(G, i);
        }
    }

    private void dfs(Digraph G, int v) {
        marked[v] = true;
        for (int w : G.adj(v))
            if (!marked[w]){
                pre.enqueue(w);
                dfs(G, w);
                post.enqueue(w);
                edgeTo[w] = v;
            }
    }

    public boolean hasPathTo(int v) {
        return marked[v];
    }

    public Iterable<Integer> pathTo(int v) {

        if (!marked[v]) return null;

        Stack<Integer> stack = new Stack<Integer>();
        for (int i = v; i != s; i = edgeTo[i]) {
            stack.push(i);
        }
        stack.push(s);
        return stack;
    }
}
