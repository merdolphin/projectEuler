package problem083;


import java.util.List;
import java.util.Map;
import java.util.Set;

import problem083.Edge;
import problem083.Vertex;
import problem083.Graph;

public class DijkstraAlgorithm {

	private final List<Vertex> nodes;
	private final List<Edge> edges;
	private Set<Vertex> settledNodes;
	private Set<Vertex> unsettledNodes;
	private Map<Vertex, Vertex> predecessors;
	private Map<Vertex, Integer> distance;
	
	public DijkstraAlgorithm(Graph graph){
		this.nodes = new ArrayList<Vertex>(graph.getVertexes());
	}

}
