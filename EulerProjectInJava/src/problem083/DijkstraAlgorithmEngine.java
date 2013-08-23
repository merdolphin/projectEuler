package problem083;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import problem083.Element;

public class DijkstraAlgorithmEngine{
	
	int [][] matrix;
	
	public DijkstraAlgorithmEngine(int [][] matrix){
		this.matrix = matrix;
	}
	
	//construct a Set of the visited Elements of the matrix;
	
	private final Set<Element> visitedNodes = new HashSet<Element>();
	
	private boolean isVisited(Element e){
		return visitedNodes.contains(e);
	}
	
	private final Set<Element> unSettledNodes = new HashSet<Element>();
			
	// Construct a map of each element shortest distance towards the starting point
	private final Map<Element, Integer>shortestDistance = new HashMap<Element, Integer>();
	
	private void setShortestDistance(Element element, int distance){
		shortestDistance.put(element, distance);
	}
	
	public int getShortestDistance(Element element){
		Integer d = shortestDistance.get(element);
		return (d == null) ? Integer.MAX_VALUE : d;
	}

	
	
	//Construct a map to map the element with it predecessor. No much use in this question
	private final Map<Element, Element> predecessor = new HashMap<Element, Element>();
	
	private void setPredecessor(Element a, Element b){
		predecessor.put(a, b);
	}
	
	public Element getPredecessor(Element e){
		return predecessor.get(e);
	}
	

	public void execute(Element start, Element destination){
				
		/**	Assign to every node a tentative distance value: 
		 * set it to zero for our initial node and to infinity for all other nodes.
		 * Mark all nodes unvisited. 
		 * Set the initial node as current. 
		 * Create a set of the unvisited nodes called the unvisited set 
		 * consisting of all the nodes except the initial node.
		 */	 
		Element currentNode = start;
		visitedNodes.add(start);
		int i, j;
		for(i=0; i<matrix[0].length; i++){
			for(j=0; j<matrix[0].length; j++){
				if(i == 0 && j == 0){
					setShortestDistance(start,matrix[i][j]);
				}else{
					Element tempE = new Element(i, j, matrix[i][j]);
					unSettledNodes.add(tempE);
					setShortestDistance(tempE,Integer.MAX_VALUE);
				}
			}
		}
		
		/***For the current node, consider all of its unvisited neighbors 
		 * and calculate their tentative distances. 
		 * If this distance is less than the previously recorded tentative distance of B, 
		 * then overwrite that distance. 
		 * Even though a neighbor has been examined, 
		 * it is not marked as "visited" at this time, 
		 * and it remains in the unvisited set.
		 * When we are done considering all of the neighbors of the current node, 
		 * mark the current node as visited and remove it from the unvisited set. 
		 * A visited node will never be checked again.
		 * If the destination node has been marked visited 
		 * (when planning a route between two specific nodes) or 
		 * if the smallest tentative distance among the nodes in the unvisited set is infinity 
		 * (when planning a complete traversal), then stop. 
		 * The algorithm has finished. 
		 * Select the unvisited node that is marked with 
		 * the smallest tentative distance, 
		 * and set it as the new "current node" then go back to step 3.
		 * ***/
		
		while(!unSettledNodes.isEmpty()){
									
			for(Element neighbor : getNeighbors(currentNode)){
				//System.out.println(neighbor);
				if( ! isVisited(neighbor)){
					//System.out.println(neighbor);
					if( getShortestDistance(neighbor) > neighbor.getValue() + getShortestDistance(currentNode)){
							shortestDistance.put(neighbor, neighbor.getValue() + getShortestDistance(currentNode));
							setPredecessor(neighbor, currentNode);
					}
				}
			}
				
			Element nextNode = getNextNode();
				
			if(nextNode.equals(destination)){
				break;
			}	
			
			visitedNodes.add(currentNode);
			unSettledNodes.remove(currentNode);
			currentNode = nextNode;
			
		}
			
			System.out.println("The answer for Question 83 is: " + getShortestDistance(destination));
	}
	

	private Element getNextNode(){
		
		int shortest = Integer.MAX_VALUE;	
		Element tempNode = null;
		for(Element k : shortestDistance.keySet()){
			if(!isVisited(k) && shortestDistance.get(k) < shortest){
				shortest = shortestDistance.get(k);
				tempNode = k;
			}
		}
		return tempNode;
	}

	
	private List<Element> getNeighbors(Element e){
		List<Element> neighbors = new ArrayList<Element>();
		int i = e.getRowidx();
		int j = e.getColidx();
		
		if( i + 1 < matrix.length){
			Element potentialE = new Element(i+1,j,matrix[i+1][j]);
				neighbors.add(potentialE);
		}
		
		if( i - 1 >= 0){
			Element potentialE = new Element(i-1,j,matrix[i-1][j]);
				neighbors.add(potentialE);
		}
		
		if( j + 1 < matrix.length){
			Element potentialE = new Element(i,j+1,matrix[i][j+1]);
				neighbors.add(potentialE);
		}
		
		
		if( j - 1 >= 0){
			Element potentialE = new Element(i,j-1,matrix[i][j-1]);
				neighbors.add(potentialE);
		}
				
		return neighbors;
	}
	
}
