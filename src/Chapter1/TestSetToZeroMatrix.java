import org.junit.*;
import static org.junit.Assert.*;

public class TestSetToZeroMatrix {

	@Test
	public void testConstructor(){
		SetToZeroMatrix stm = new SetToZeroMatrix(4, 3);
		
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 3; j++){
				assertTrue(stm.matrix[i][j] == 0);
			}
		}
	}
	
	@Test
	public void testReplaceI(){
		SetToZeroMatrix stm = new SetToZeroMatrix(4, 3);
		
		stm.matrix[0][0] = 1;
		stm.matrix[0][1] = 0;
		stm.matrix[0][2] = 2;	
		
		stm.matrix[1][0] = 0;
		stm.matrix[1][1] = 3;
		stm.matrix[1][2] = 4;
		
		stm.matrix[2][0] = 5;
		stm.matrix[2][1] = 6;
		stm.matrix[2][2] = 7;
		
		stm.matrix[3][0] = 8;
		stm.matrix[3][1] = 9;
		stm.matrix[3][2] = 0;
		
		int[][] replacedMat = stm.setToZero();
		
		int[][] result = new int[4][3];
		
		result[0][0] = 0;
		result[0][1] = 0;
		result[0][2] = 0;
		
		result[1][0] = 0;
		result[1][1] = 0;
		result[1][2] = 0;
		
		result[2][0] = 0;
		result[2][1] = 0;
		result[2][2] = 0;
		
		result[3][0] = 0;
		result[3][1] = 0;
		result[3][2] = 0;

		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 3; j++){
				assertTrue(replacedMat[i][j] == result[i][j]);
			}
		}	
	}
	
	@Test
	public void testReplaceII(){
		SetToZeroMatrix stm = new SetToZeroMatrix(4, 3);
		
		stm.matrix[0][0] = 1;
		stm.matrix[0][1] = 2;
		stm.matrix[0][2] = 0;	
		
		stm.matrix[1][0] = 3;
		stm.matrix[1][1] = 4;
		stm.matrix[1][2] = 5;
		
		stm.matrix[2][0] = 5;
		stm.matrix[2][1] = 0;
		stm.matrix[2][2] = 6;
		
		stm.matrix[3][0] = 8;
		stm.matrix[3][1] = 9;
		stm.matrix[3][2] = 0;
		
		int[][] replacedMat = stm.setToZero();
		
		int[][] result = new int[4][3];
		
		result[0][0] = 0;
		result[0][1] = 0;
		result[0][2] = 0;
		
		result[1][0] = 3;
		result[1][1] = 0;
		result[1][2] = 0;
		
		result[2][0] = 0;
		result[2][1] = 0;
		result[2][2] = 0;
		
		result[3][0] = 0;
		result[3][1] = 0;
		result[3][2] = 0;

		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 3; j++){
				assertTrue(replacedMat[i][j] == result[i][j]);
			}
		}	
	}
	
	@Test
	public void testReplaceIII(){
		SetToZeroMatrix stm = new SetToZeroMatrix(3, 4);
		
		stm.matrix[0][0] = 1;
		stm.matrix[0][1] = 2;
		stm.matrix[0][2] = 0;
		stm.matrix[0][3] = 0;
		
		stm.matrix[1][0] = 3;
		stm.matrix[1][1] = 4;
		stm.matrix[1][2] = 5;
		stm.matrix[1][3] = 6;
		
		stm.matrix[2][0] = 7;
		stm.matrix[2][1] = 8;
		stm.matrix[2][2] = 9;
		stm.matrix[2][3] = 10;
		
		int[][] replacedMat = stm.setToZero();
		
		int[][] result = new int[3][4];
		
		result[0][0] = 0;
		result[0][1] = 0;
		result[0][2] = 0;
		result[0][3] = 0;
		
		result[1][0] = 3;
		result[1][1] = 4;
		result[1][2] = 0;
		result[1][3] = 0;
		
		result[2][0] = 7;
		result[2][1] = 8;
		result[2][2] = 0;
		result[2][3] = 0;
		

		
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 4; j++){
				assertTrue(replacedMat[i][j] == result[i][j]);
			}
		}	
	}
}
