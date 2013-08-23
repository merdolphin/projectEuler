package problem083;

/***
 * Written by lina <lina.oahz@gmail.com> 
 * start: Thu Aug 22 22:45:54 SGT 2013
 * end: Sat Aug 24 00:56:10 SGT 2013
 */

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;
import problem083.DijkstraAlgorithmEngine;
import problem083.Element;

public class Problem083 {
	
	private static int GridSize = 80;

	private static int[][] readFileToMatrix(String fileName){
		try{
			
			File file = new File (fileName);
			FileReader reader = new FileReader(file);
			BufferedReader in = new BufferedReader(reader);
			
			int [][] matrix = new int[GridSize][GridSize];
			
			String line;
			int i = 0;
			while( (line = in.readLine()) != null ){
				int j = 0;
				for(String date : line.split(",")){
					matrix[i][j++] = Integer.parseInt(date);
				}
				i++;
			}
			in.close();
			
			return extracted(matrix);
			
		} catch (IOException e){
			e.printStackTrace();
		}
		return null;		
	}
	
	
	private static int[][] extracted(int[][] matrix) {
		return matrix;
	}
	
	
	public static void main(String[] args) {
		
		int[][] myMatrix = new int [GridSize][GridSize]; 	
		
		myMatrix = readFileToMatrix("test_data//matrix.txt");
	
		DijkstraAlgorithmEngine dijkstra = new DijkstraAlgorithmEngine(myMatrix);
		Element start = new Element(0,0, myMatrix[0][0]);
		Element destination = new Element(GridSize-1, GridSize-1, myMatrix[GridSize-1][GridSize-1]);
		dijkstra.execute(start, destination);
	}
}
