/*** Written by lina <lina.oahz@gmail.com>
 *   Start on: Sat Aug 17 23:56:26 SGT 2013
 *   End on: 
 *   
 *   "I used to think life is deterministic, 
 *   and today I started to realize 
 *   it is very stochastically deterministic." 
 */

package Problem082;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList; 
import java.util.Scanner;
import Problem082.GV;


public class Problem082 {
	

	private static void readFile(String fileName){
		try{
			
			File file = new File (fileName);
			FileReader reader = new FileReader(file);
			BufferedReader in = new BufferedReader(reader);
			
			String[][] matrix = new String[GV.size][GV.size];
			
			String line;
			int i = 0;
			while( (line = in.readLine()) != null ){
				matrix[i++] = line.split(",");
			}
			in.close();
			
			miniPath(matrix);
			
		} catch (IOException e){
			e.printStackTrace();
		}
		
	}
	
	public static void miniPath(String[][]arr2d){
		int i;
		int j;
		
		for(i=0; i<GV.size; i++){
			for(j=0; j<arr2d[0].length; j++){
				System.out.print(Integer.parseInt(arr2d[i][j]) - 1 + " ");
			}
			System.out.println();
		}
		
	}
	
	
	public static void main(String[] args) {
		//System.out.println(System.getProperty("user.dir"));
		
		readFile("test.txt");
	}

}
