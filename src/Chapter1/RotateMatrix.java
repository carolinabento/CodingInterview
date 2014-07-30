/**
 * This class allows to rotate a NXN matrix by 90 degrees
 * 
 * @author carolinabento
 *
 */
public class RotateMatrix {

	//Empty Constructor
	public RotateMatrix(){}
	
	/**
	 * Rotates a NXN integer matrix by 90 degrees, either clockwise or counter-clockwise
	 * @param matrix the matrix to rotate
	 * @param side 0 to rotate clockwise, 1 to rotate counterclockwise
	 * @return the rotated matrix
	 */
	public int[][] rotate(int[][] matrix, int side){
		int len = matrix.length;
		int [][] result = new int[len][len];
		
		if(side == 0){
			for(int i = 0; i < len; i++){
				for(int j = 0; j < len; j++){
					result[j][Math.abs(len -i - 1)] = matrix[i][j];
				}
			}
		}else{
			for(int i = 0; i < len; i++){
				for(int j = 0; j < len; j++){
					result[Math.abs(len -j - 1)][i] = matrix[i][j];
				}
			}
		}
		return result;
	}
	
}
