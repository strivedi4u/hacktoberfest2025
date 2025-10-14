class GraphBFS {
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

    bfs(start: number): number[] {
        const visited = new Set<number>();
        const queue: number[] = [start];
        const result: number[] = [];

        visited.add(start);

        while (queue.length) {
            const vertex = queue.shift()!;
            result.push(vertex);

            const neighbors = this.adjList.get(vertex) || [];
            for (const neighbor of neighbors) {
                if (!visited.has(neighbor)) {
                    visited.add(neighbor);
                    queue.push(neighbor);
                }
            }
        }

        return result;
    }
}

// Example usage
const graphBFS = new GraphBFS();
graphBFS.addVertex(1);
graphBFS.addVertex(2);
graphBFS.addVertex(3);
graphBFS.addEdge(1, 2);
graphBFS.addEdge(1, 3);
console.log(graphBFS.bfs(1)); // Output: [1, 2, 3] (or some other order depending on graph structure)
