/*** Written by lina <lina.oahz@gmail.com>
 *   Start on: Sat Aug 17 23:56:26 SGT 2013
 *   End on: Sun Aug 18 23:30:40 SGT 2013
 *   last minor modification on Mon Aug 19 11:26:19 SGT 2013
 *   last minor modification on Mon Aug 19 23:22:24 SGT 2013
 *   
 *   "I used to think life is deterministic, 
 *   and today I started to realize 
 *   it is very stochastically deterministic." 
 */

package problem082;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;


public class Problem082 {
	

	
	private static int size = 80;


	private static int[][] readFileToMatrix(String fileName){
		try{
			
			File file = new File (fileName);
			FileReader reader = new FileReader(file);
			BufferedReader in = new BufferedReader(reader);
			
			int [][] matrix = new int[size][size];
			
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
		int [] sol = new int[size];

		// initilization sol to the left-est columns.
		for(i=0; i<size; i++){
			sol[i] = arr2d[i][size-1];
		}
		
		//From left to right
		for(j=size-2; j>=0; j--){
			
			sol[0] += arr2d[0][j];
			sol[size-1] += arr2d[size-1][j];
			for(i=1;i<size-1;i++){
				sol[i] = Math.min(sol[i-1]+arr2d[i][j], sol[i]+arr2d[i][j]);
			}
			
			for(i=size-2; i>0; i--){
				sol[i] = Math.min(sol[i+1]+arr2d[i][j], sol[i]);
			}
			
			//for(i=0; i<size; i++){
			//	System.out.println(j + " " + sol[i]);
			//}
		}
		
		System.out.println();
		
		int min = sol[0];
		for(i=1; i<size; i++){
			//System.out.print(sol[i] + " ");
			min = min<sol[i]?min:sol[i]; 
		}
			System.out.println("The answer is: " + min);
	}
	
	
	public static void main(String[] args) {
		//System.out.println(System.getProperty("user.dir"));
	
		miniPath(readFileToMatrix("test_data//matrix.txt"));
	}

}
