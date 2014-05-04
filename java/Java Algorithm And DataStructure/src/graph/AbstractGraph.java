package graph;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Administrator
 * @param <V>
 */
public abstract class AbstractGraph<V> implements Graph<V> {
	protected List<V> vertices;
	protected List<List<Integer>> neighbors;

	// construct a graph from edges and vertices stored in arrays.
	protected AbstractGraph(int[][] edges, V[] vertices) {
		this.vertices = new ArrayList<V>();
		for (V v : vertices) {
			this.vertices.add(v);
		}
		createAdjacencyLists(edges, vertices.length);
	}

	// construct a graph from edges and vertices stored in list
	protected AbstractGraph(List<Edge> edges, List<V> vertices) {
		this.vertices = vertices;
		createAdjacencyLists(edges, vertices.size());
	}

	@SuppressWarnings("unchecked")
	protected AbstractGraph(List<Edge> edges, int numberOfVertices) {
		vertices = new ArrayList<V>();
		for (int i = 0; i < numberOfVertices; i++) {
			vertices.add((V) (new Integer(i)));
		}
		createAdjacencyLists(edges, numberOfVertices);
	}

	@SuppressWarnings("unchecked")
	protected AbstractGraph(int[][] edges, int numberOfVertices) {
		vertices = new ArrayList<V>(); // Create vertices
		for (int i = 0; i < numberOfVertices; i++) {
			vertices.add((V) (new Integer(i))); // vertices is {0, 1, ...}
		}
		createAdjacencyLists(edges, numberOfVertices);
	}

	// create adjacency lists for each vertex.
	private void createAdjacencyLists(int[][] edges, int numberOfVertices) {
		neighbors = new ArrayList<List<Integer>>();
		for (int i = 0; i < numberOfVertices; i++) {
			neighbors.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < edges.length; i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			neighbors.get(u).add(v);
		}
	}

	/** Create adjacency lists for each vertex */
	private void createAdjacencyLists(List<Edge> edges, int numberOfVertices) {
		// Create a linked list
		neighbors = new ArrayList<List<Integer>>();
		for (int i = 0; i < numberOfVertices; i++) {
			neighbors.add(new ArrayList<Integer>());
		}

		for (Edge edge : edges) {
			neighbors.get(edge.u).add(edge.v);
		}
	}

	@Override
	public int getSize() {
		return vertices.size();
	}

	@Override
	public List<V> getVertices() {
		return vertices;
	}

	@Override
	public V getVertex(int index) {
		return vertices.get(index);
	}

	@Override
	public int gerIndex(V v) {
		return vertices.indexOf(v);
	}

	@Override
	public List<Integer> getNeighbors(int index) {
		return neighbors.get(index);
	}

	@Override
	public int getDegree(int index) {
		return neighbors.get(index).size();
		// return getNeighbors(index).size();
	}

	@Override
	public int[][] getAdjacencyMatrix() {
		int[][] adjacencyMatrix = new int[getSize()][getSize()];
		for (int i = 0; i < neighbors.size(); i++) {
			for (int j = 0; j < neighbors.get(i).size(); j++) {
				int v = neighbors.get(i).get(j);
				adjacencyMatrix[i][v] = 1;
			}
		}
		return adjacencyMatrix;
	}

	@Override
	public void printAdjacencyMatrix() {
		int[][] adjacencyMatrix = getAdjacencyMatrix();
		for (int i = 0; i < adjacencyMatrix.length; i++) {
			for (int j = 0; j < adjacencyMatrix[0].length; j++) {
				System.out.print(adjacencyMatrix[i][j] + " ");
			}
			System.out.println();
		}
	}

	@Override
	public void printEdges() {
		for (int u = 0; u < neighbors.size(); u++) {
			System.out.print("Vertex " + u + ": ");
			for (int j = 0; j < neighbors.get(u).size(); j++) {
				System.out.print("(" + u + ", " + neighbors.get(u).get(j)
						+ ") ");
			}
			System.out.println();
		}
	}

	/**
	 * @author Administrator
	 * @description inner class Edge in AbstractGraph.
	 */
	public static class Edge {
		public int u;
		public int v;

		public Edge(int u, int v) {
			this.u = u;
			this.v = v;
		}
	}

	/**
	 * @author Administrator
	 * @description Tree class defined in AbstractGraph<V>.
	 */
	public class Tree {
		private int root;
		private int[] parent;
		private List<Integer> searchOrders;

		public Tree(int root, int[] parent, List<Integer> searchOrders) {
			this.root = root;
			this.parent = parent;
			this.searchOrders = searchOrders;
		}

		public Tree(int root, int[] parent) {
			this.root = root;
			this.parent = parent;
		}

		public int getRoot() {
			return root;
		}

		public int getParent(int v) {
			return parent[v];
		}

		public List<Integer> getSearchOrders() {
			return searchOrders;
		}

		public int getNumberOfVerticesFound() {
			return searchOrders.size();
		}

		/** Return the path of vertices from a vertex index to the root */
		public List<V> getPath(int index) {
			ArrayList<V> path = new ArrayList<V>();

			do {
				path.add(vertices.get(index));
				index = parent[index];
			} while (index != -1);

			return path;
		}

		/** Print a path from the root to vertex v */
		public void printPath(int index) {
			List<V> path = getPath(index);
			System.out.print("A path from " + vertices.get(root) + " to "
					+ vertices.get(index) + ": ");
			for (int i = path.size() - 1; i >= 0; i--)
				System.out.print(path.get(i) + " ");
		}

		/** Print the whole tree */
		public void printTree() {
			System.out.println("Root is: " + vertices.get(root));
			System.out.print("Edges: ");
			for (int i = 0; i < parent.length; i++) {
				if (parent[i] != -1) {
					// Display an edge
					System.out.print("(" + vertices.get(parent[i]) + ", "
							+ vertices.get(i) + ") ");
				}
			}
			System.out.println();
		}

	}
}
