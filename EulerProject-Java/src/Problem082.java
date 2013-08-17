/*** Written by lina <lina.oahz@gmail.com>
 *   Start on: Sat Aug 17 23:56:26 SGT 2013
 *   End on: 
 *   
 *   "I used to think life is deterministic, 
 *   and today I started to realize 
 *   it is very stochastically deterministic." 
 */
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


public class Problem082 {


	private static void readFile(String fileName){
		try{
			
			File file = new File (fileName);
			FileReader reader = new FileReader(file);
			BufferedReader in = new BufferedReader(reader);
			
			String[][] matrix = new String[5][5];
			
			String line;
			int i = 0;
			while( (line = in.readLine()) != null ){
				
				matrix[i] = line.split(",");
				//matrix[i++] = Integer.parseInt();
				System.out.println(matrix[i][1]);
			}
			in.close();
		} catch (IOException e){
			e.printStackTrace();
		}
		
	}
	
	
	
	public static void main(String[] args) {
	
		if(args.length != 1){
			System.err.println("Usage: Java Textreader" + "file location");
			System.exit(0);
		}
		readFile(args[0]);
	}

}
