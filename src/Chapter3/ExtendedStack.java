package Chapter3;

import java.util.Arrays;

public class ExtendedStack {
	private int[] stackArray;
	private int[] minArray;
	private int minArrayPos;
	private int stackPos;
	private int size = 10;
	private int min;

	public ExtendedStack(){
		stackPos = 0;
		minArrayPos = 0;
		stackArray = null;
		minArray = new int[size];
		min = Integer.MAX_VALUE;
	}

	public boolean isEmpty(){
		if(stackArray == null){
			return true;
		}else{
			if(stackArray != null && stackArray[0] == -1){
				return true;
			}else{
				return false;
			}
		}
	}

	private void resize(){
		if(isEmpty() == false){
			int[] copy = stackArray;			
			size = size*2;

			stackArray = new int[size];

			for(int i = 0; i < stackPos; i++){
				stackArray[i] = copy[i];
			}
		}
	}

	private void updateMin(){
		if(minArrayPos <= 1){					
			min = minArray[0];					
		}else{
			minArrayPos--;
			minArrayPos--;
			min = minArray[minArrayPos];
		}
		minArrayPos++;
	}
	
	public void push(int element){
		if(isEmpty() == false){
			if(stackPos == size/2){
				resize();
			}
		}else{
			stackArray = new int[size];
		}

		stackArray[stackPos] = element;
		stackPos++;

		if(element < min){
			min = element;
			minArray[minArrayPos] = min;
			minArrayPos++;
		}
	}

	public int pop(){
		if(isEmpty() == false){
			stackPos--;
			int element = stackArray[stackPos];
			stackArray[stackPos] = -1;

			if(element == min){
				updateMin();
			}	
			
			return element;
		}else{
			throw new UnsupportedOperationException();
		}

	}

	public void peek(){
		if(isEmpty() == false){
			System.out.println(stackArray[stackPos-1]);
		}else{
			throw new UnsupportedOperationException();
		}
	}

	public int getMin(){		
			return min;
	}
}
