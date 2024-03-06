import java.io.*;
import java.util.*;
class GFG{
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0){
            String input_line[] = read.readLine().trim().split("\\s+");
            int N = Integer.parseInt(input_line[0]);
            int M = Integer.parseInt(input_line[1]);
            ArrayList<ArrayList<Integer>> Edges = new ArrayList<ArrayList<Integer>>();
            input_line = read.readLine().trim().split("\\s+");
            for(int i=0;i<M;i++)
            {
                ArrayList<Integer> e = new ArrayList<Integer>();
                e.add(Integer.parseInt(input_line[3*i]));
                e.add(Integer.parseInt(input_line[3*i+1]));
                e.add(Integer.parseInt(input_line[3*i+2]));
                Edges.add(e);
            }
            Solution ob = new Solution();
            int ans = ob.solve(N, M, Edges);
            System.out.println(ans);
        }
    }
}
class Solution
{
    int solve(int n, int m, ArrayList<ArrayList<Integer>> edges)
    {
        int g[][] = new int[n][n];
        for(int i=0;i<edges.size();i++){
            int u = edges.get(i).get(0)-1;
            int v = edges.get(i).get(1)-1;
            int w = edges.get(i).get(2);
            g[u][v]+=w;
            g[v][u]+=w;
        }
        return fordfulkerson(g,0,n-1,n);
    }
    static int fordfulkerson(int[][]graph,int source,int sink,int n){
        int[]parent=new int[n];
        Arrays.fill(parent,-1);
        int res=0;
        while(bfs(graph,parent,source,sink,n)!=0){
            int min=bfs(graph,parent,source,sink,n);
            res+=min;
            int v=sink;
            while(v!=source){
                int u=parent[v];
                graph[u][v]-=min;
                graph[v][u]+=min;
                v=u;
            }
        }
        return res;
    }
    static int bfs(int[][]graph,int[] parent,int source,int sink,int n){
        int min=Integer.MAX_VALUE;
        Arrays.fill(parent,-1);
        parent[source]=-2;
        boolean[]vis=new boolean[n];
        Queue<pair>q=new LinkedList<>();
        q.add(new pair(source,min));
        while(!q.isEmpty()){
            pair curr=q.poll();
            int node =curr.x;
            int flow=curr.y;
            for(int i=0;i<n;i++){
                if(graph[node][i]!=0){
                    if(parent[i]==-1){
                        parent[i]=node;
                        int new_flow=Math.min(flow,graph[node][i]);
                        if(i==sink)return new_flow;
                        q.add(new pair(i,new_flow));
                    }
                }
            }
        }
        return 0;
    }
}
class pair{
    int x,y;
    public pair(int x,int y){
        this.x=x;
        this.y=y;
    }
}