from collections import defaultdict
import sys

def is_strongly_connected(graph, n):
    visited = [False] * n
    def dfs(v):
        visited[v] = True
        for next in graph[v]:
            if not visited[next]:
                dfs(next)
    
    dfs(0)

    for i in range(n):
        if len(graph[i]) > 0 and not visited[i]:
            return False
    
    transposed_graph = defaultdict(list)
    for u in range(n):
        for v in graph[u]:
            transposed_graph[v].append(u)
    
    visited = [False] * n
    
    dfs(0)
    for i in range(n):
        if len(transposed_graph[i]) > 0 and not visited[i]:
            return False
            
    return True

def eulerian(n, m, edges):
    graph = defaultdict(list)
    in_degree = [0] * n
    out_degree = [0] * n
    
    for u, v in edges:
        graph[u].append(v)
        out_degree[u] += 1
        in_degree[v] += 1
    
    for i in range(n):
        if in_degree[i] != out_degree[i]:
            return "Eulerian Circuit does not exist."
    
    if is_strongly_connected(graph, n):
        return "Eulerian Circuit exists."
    
    return "Eulerian Circuit does not exist."


if __name__ == "__main__":
    input_data = sys.stdin.read().strip().splitlines()
    
    n = int(input_data[0])
    m = int(input_data[1])
    
    edges = []
    
    for i in range(2, 2 + m):
        u, v = map(int, input_data[i].split())
        edges.append((u, v))

    result = eulerian(n, m, edges)
    print(result)