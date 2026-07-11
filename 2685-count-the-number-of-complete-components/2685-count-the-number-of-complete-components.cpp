class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Build adjacency list representation of the graph
        vector<vector<int>> adjacencyList(n);
        for (const auto& edge : edges) {
            int vertex1 = edge[0];
            int vertex2 = edge[1];
            adjacencyList[vertex1].push_back(vertex2);
            adjacencyList[vertex2].push_back(vertex1);
        }
      
        // Track visited vertices during DFS traversal
        vector<bool> visited(n, false);
      
        // DFS function to explore a connected component
        // Returns: pair<vertex_count, edge_count> in the component
        function<pair<int, int>(int)> dfs = [&](int currentVertex) -> pair<int, int> {
            visited[currentVertex] = true;
          
            // Initialize counts: 1 vertex (current), degree edges from current vertex
            int vertexCount = 1;
            int totalEdgeCount = adjacencyList[currentVertex].size();
          
            // Explore all neighbors
            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    auto [neighborVertices, neighborEdges] = dfs(neighbor);
                    vertexCount += neighborVertices;
                    totalEdgeCount += neighborEdges;
                }
            }
          
            return make_pair(vertexCount, totalEdgeCount);
        };
      
        int completeComponentCount = 0;
      
        // Process each connected component
        for (int vertex = 0; vertex < n; ++vertex) {
            if (!visited[vertex]) {
                auto [componentVertices, componentEdges] = dfs(vertex);
              
                // Check if component is complete
                // In a complete graph with v vertices, there are v*(v-1)/2 edges
                // Since we count each edge twice (from both endpoints), we have v*(v-1) total
                if (componentVertices * (componentVertices - 1) == componentEdges) {
                    ++completeComponentCount;
                }
            }
        }
      
        return completeComponentCount;
    }
};