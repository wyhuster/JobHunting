package graph;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import static net.mindview.util.Print.*;

public class UnweightedGraph<V> extends AbstractGraph<V> {

	protected UnweightedGraph(int[][] edges, V[] vertices) {
		super(edges, vertices);
	}

	protected UnweightedGraph(List<Edge> edges, List<V> vertices) {
		super(edges, vertices);
	}

	protected UnweightedGraph(List<Edge> edges, int numberOfVertices) {
		super(edges, numberOfVertices);
	}

	protected UnweightedGraph(int[][] edges, int numberOfVertices) {
		super(edges, numberOfVertices);
	}

	public static void main(String[] args) {
		String[] vertices = { "Seattle", "San Francisco", "Los Angeles",
				"Denver", "Kansas City", "Chicago", "Boston", "New York",
				"Atlanta", "Miami", "Dallas", "Houston" };
		print(vertices.length);

		int[][] edges = { { 0, 1 }, { 0, 3 }, { 0, 5 }, { 1, 0 }, { 1, 2 },
				{ 1, 3 }, { 2, 1 }, { 2, 3 }, { 2, 4 }, { 2, 10 }, { 3, 0 },
				{ 3, 1 }, { 3, 2 }, { 3, 4 }, { 3, 5 }, { 4, 2 }, { 4, 3 },
				{ 4, 5 }, { 4, 7 }, { 4, 8 }, { 4, 10 }, { 5, 0 }, { 5, 3 },
				{ 5, 4 }, { 5, 6 }, { 5, 7 }, { 6, 5 }, { 6, 7 }, { 7, 4 },
				{ 7, 5 }, { 7, 6 }, { 7, 8 }, { 8, 4 }, { 8, 7 }, { 8, 9 },
				{ 8, 10 }, { 8, 11 }, { 9, 8 }, { 9, 11 }, { 10, 2 },
				{ 10, 4 }, { 10, 8 }, { 10, 11 }, { 11, 8 }, { 11, 9 },
				{ 11, 10 } };

		Graph<String> graph1 = new UnweightedGraph<String>(edges, vertices);
		print("graph1's vertices size is : " + graph1.getSize());
		print("the first vertice in graph1 is  : " + graph1.getVertex(1));
		print("the degree of the first vertice in graph1 is  : "
				+ graph1.getDegree(1));

		// now create a List contains five vertices.
		String[] names = { "Peter", "Jane", "Mark", "Cindy", "Wendy" };
		List<Edge> edgeList = new ArrayList<Edge>();
		edgeList.add(new Edge(0, 2));
		edgeList.add(new Edge(1, 2));
		edgeList.add(new Edge(2, 4));
		edgeList.add(new Edge(3, 4));
		Graph<String> graph2 = new UnweightedGraph<String>(edgeList,
				Arrays.asList(names));
		print("graph2's vertices size is : " + graph2.getSize());
		print("The edges for graph2:");
		graph2.printAdjacencyMatrix();
		graph2.printEdges();
		graph2.bfs(0).printTree();
	}

}
