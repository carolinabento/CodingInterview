/**
 * This class implements the methods that, given a MxN matrix
 * if any of its cells has a zero, then the entire row and column is set to zero
 * @author carolinabento
 *
 */
public class SetToZeroMatrix {
	int[][] matrix;
	int M;
	int N;

	/**
	 * Initializes a MxN matrix
	 * @param M number of rows
	 * @param N number of columns
	 */
	public SetToZeroMatrix(int m, int n){
		this.matrix = new int[m][n];
		this.M = m;
		this.N = n;
	}

	/**
	 * Verifies if the array already has the given element 
	 * @param array the array to examine
	 * @param value the value we want to check if is present in the array
	 * @return true if the value is already in the array, false otherwise
	 */
	public boolean containsElement(int[] array, int colIndex, int value){
		boolean duplicate = false;
		for(int i = 0; i <= colIndex; i++){
			if(array[i] == value){
				return true;
			}
		}
		return duplicate;
	}

	/**
	 * Replaces each cell of a row in the given matrix with the value zero
	 * @param mat the given matrix
	 * @param rowIndex the index of the row who's cells will be replaced with the value zero
	 * @return the matrix with all cells in the specified rowIndex set to zero
	 */
	public int[][] replaceRow(int[][] mat, int rowIndex){
		for(int i = 0; i < N; i++){
			mat[rowIndex][i] = 0;
		}

		return mat;
	}

	/**
	 * Replaces each cell of in a column with the value zero, given a matrix and a set of columns
	 * @param mat the given matrix
	 * @param colArray the 
	 * @return the matrix with all the cells in the given columns set to zero
	 */
	public int[][] replaceColumn(int[][] mat, int[] colArray, int colIndex){
		for(int column = 0; column <= colIndex; column++){
			for(int i = 0; i < M ; i++){
				mat[i][colArray[column]] = 0;
			}
		}
		return mat;
	}

	/**
	 * Traverses a matrix and if a cell contains the value zero, replaces each cell in the respective
	 * row and column with the value zero 
	 * @param mat the matrix who's cells will be replaced with the value zero
	 * @return
	 */
	public int[][] setToZero(){
		int[][] result = new int[M][N];
		int[] columns = new int[N];

		int lastMarked = 0;
		int colIndex = -1;

		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				if(columns[lastMarked] != j || colIndex == -1){
					if(this.matrix[i][j] == 0){
						//marking the column to replace with zeros
						if(!containsElement(columns,colIndex,j)){
							colIndex++;
							columns[colIndex] = j;
						}
						result = replaceRow(result,i);
						lastMarked = colIndex;
					}else{
						result[i][j] = this.matrix[i][j];
					}
				}
			}
		}
		return result = replaceColumn(result,columns,colIndex);
	}
}
