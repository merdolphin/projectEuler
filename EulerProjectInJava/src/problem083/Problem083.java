/*** Written by lina <lina.oahz@gmail.com>
 *   Start on: Mon Aug 19 23:20:33 SGT 2013
 *   End on: 
 *   
 *   Reference:
 *   http://renaud.waldura.com/doc/java/dijkstra/
 *   http://www.vogella.com/articles/JavaAlgorithmsDijkstra/article.html
 *   https://www.youtube.com/watch?v=8Ls1RqHCOPw
 */

package problem083;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;
import problem083.Matrix;

public class Problem083 {
	
	private static int GridSize = 5;
	
	private static Set<Matrix> visited;
	private static Set<Matrix> unVisited;

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
	
	
	public static void excute(int[][] arr2d){
		int i, j;
		unVisited = new HashSet<Matrix>();
		visited = new HashSet<Matrix>();

		for(i=0; i<GridSize; i++){
			for(j=0; j<GridSize;j++){
				Matrix m = new Matrix(i,j,arr2d[i][j]);
				unVisited.add(m);
			}
		}
		while(unVisited.size()>0){
			Matrix next = getMinimum(unVisited);
			visited.add(next);
			unVisited.remove(next);
			findMinimum(next);
		}
		
	}
	
	private Matrix findMinimum()
		


	public static void main(String[] args) {
	
		miniPath(readFileToMatrix("test_data//test_83.txt"));
	}
}
