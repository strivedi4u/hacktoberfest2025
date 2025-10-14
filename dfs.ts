class Graph {
    private adjList: Map<number, number[]>;

    constructor() {
        this.adjList = new Map();
    }

    addVertex(vertex: number) {
        this.adjList.set(vertex, []);
    }

    addEdge(v1: number, v2: number) {
        this.adjList.get(v1)?.push(v2);
        this.adjList.get(v2)?.push(v1); // for undirected graph
    }

    dfs(start: number): number[] {
        const visited = new Set<number>();
        const result: number[] = [];

        const dfsHelper = (vertex: number) => {
            visited.add(vertex);
            result.push(vertex);
            const neighbors = this.adjList.get(vertex) || [];

            for (const neighbor of neighbors) {
                if (!visited.has(neighbor)) {
                    dfsHelper(neighbor);
                }
            }
        };

        dfsHelper(start);
        return result;
    }
}

// Example usage
const graph = new Graph();
graph.addVertex(1);
graph.addVertex(2);
graph.addVertex(3);
graph.addEdge(1, 2);
graph.addEdge(1, 3);
console.log(graph.dfs(1)); // Output: [1, 2, 3] (or some other order depending on graph structure)
