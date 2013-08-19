/*** Written by lina <lina.oahz@gmail.com>
 *   Start on: Mon Aug 19 23:20:33 SGT 2013
 *   End on: 
 *   "Baby is afraid of betrayal. Baby feels hurt, disappointed and sad.
 *   and baby is very very silent."
 */

package problem083;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;


public class Problem083 {
	
	private static int GridSize = 5;



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
	
	
	public static void miniPath(int[][] arr2d){
		int i;
		int j;

		for(i=0; i<GridSize; i++){
			for(j=0; j<GridSize;j++){
				System.out.println(arr2d[i][j]);
			}
		}
	}
		


	public static void main(String[] args) {
	
		miniPath(readFileToMatrix("test_data//test_83.txt"));
	}
}
