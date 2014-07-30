import static org.junit.Assert.*;
import org.junit.Test;


public class TestRotateMatrix {

	@Test
	public void testRotateClockWise(){
		
		int[][] matrix = new int[3][3];
		
		matrix[0][0] = 1;
		matrix[0][1] = 2;
		matrix[0][2] = 3;
		matrix[1][0] = 4;
		matrix[1][1] = 5;
		matrix[1][2] = 6;
		matrix[2][0] = 7;
		matrix[2][1] = 8;
		matrix[2][2] = 9;
		
		
		int[][] answer = new int[3][3];
		
		answer[0][0] = 7;
		answer[0][1] = 4;
		answer[0][2] = 1;
		answer[1][0] = 8;
		answer[1][1] = 5;
		answer[1][2] = 2;
		answer[2][0] = 9;
		answer[2][1] = 6;
		answer[2][2] = 3;
		
		RotateMatrix rm = new RotateMatrix();
		
		int[][] rotatedMatrix = rm.rotate(matrix, 0);
		
		for(int i = 0; i < matrix.length; i++){
			for(int j = 0; j < matrix.length; j++){
				assertTrue(rotatedMatrix[i][j] == answer[i][j]);
			}
		}	
	}
	
	@Test
	public void testRotateCounterClockWise(){
		
		int[][] matrix = new int[3][3];
		
		matrix[0][0] = 1;
		matrix[0][1] = 2;
		matrix[0][2] = 3;
		matrix[1][0] = 4;
		matrix[1][1] = 5;
		matrix[1][2] = 6;
		matrix[2][0] = 7;
		matrix[2][1] = 8;
		matrix[2][2] = 9;
		
		
		int[][] answer = new int[3][3];
		
		answer[0][0] = 3;
		answer[0][1] = 6;
		answer[0][2] = 9;
		answer[1][0] = 2;
		answer[1][1] = 5;
		answer[1][2] = 8;
		answer[2][0] = 1;
		answer[2][1] = 4;
		answer[2][2] = 7;
		
		RotateMatrix rm = new RotateMatrix();
		
		//rotating counter clockwise
		int[][] rotatedMatrix = rm.rotate(matrix, 1);
		
		for(int i = 0; i < matrix.length; i++){
			for(int j = 0; j < matrix.length; j++){
				assertTrue(rotatedMatrix[i][j] == answer[i][j]);
			}
		}	
	}
	
	@Test
	public void testWrongRotate(){
		
		int[][] matrix = new int[3][3];
		
		matrix[0][0] = 1;
		matrix[0][1] = 2;
		matrix[0][2] = 3;
		matrix[1][0] = 4;
		matrix[1][1] = 5;
		matrix[1][2] = 6;
		matrix[2][0] = 7;
		matrix[2][1] = 8;
		matrix[2][2] = 9;
		
		
		int[][] answer = new int[3][3];
		
		answer[0][0] = 1;
		answer[0][1] = 2;
		answer[0][2] = 3;
		answer[1][0] = 4;
		answer[1][1] = 5;
		answer[1][2] = 6;
		answer[2][0] = 7;
		answer[2][1] = 8;
		answer[2][2] = 9;
		
		RotateMatrix rm = new RotateMatrix();
		
		//rotating counter clockwise
		int[][] rotatedMatrix = rm.rotate(matrix, 1);
		boolean result = true;
		
		for(int i = 0; i < matrix.length; i++){
			for(int j = 0; j < matrix.length; j++){
				result = result && (rotatedMatrix[i][j] == answer[i][j]);
			}
		}
		assertFalse(result);
	}
	
	
	@Test
	public void testWrongRotateI(){
		
		int[][] matrix = new int[3][3];
		
		matrix[0][0] = 1;
		matrix[0][1] = 2;
		matrix[0][2] = 3;
		matrix[1][0] = 4;
		matrix[1][1] = 5;
		matrix[1][2] = 6;
		matrix[2][0] = 7;
		matrix[2][1] = 8;
		matrix[2][2] = 9;
		
		
		int[][] answer = new int[3][3];
		
		answer[0][0] = 3;
		answer[0][1] = 2;
		answer[0][2] = 9;
		answer[1][0] = 6;
		answer[1][1] = 5;
		answer[1][2] = 8;
		answer[2][0] = 7;
		answer[2][1] = 4;
		answer[2][2] = 1;
		
		RotateMatrix rm = new RotateMatrix();
		
		//rotating counter clockwise
		int[][] rotatedMatrix = rm.rotate(matrix, 1);
		boolean result = true;
		
		for(int i = 0; i < matrix.length; i++){
			for(int j = 0; j < matrix.length; j++){
				result = result && (rotatedMatrix[i][j] == answer[i][j]);
			}
		}
		assertFalse(result);
	}
}
