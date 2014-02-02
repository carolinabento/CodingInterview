package Chapter3;

import java.util.Arrays;

public class Stack<T> {
	T[] stackArray;
	int stackPos;
	int size = 10;		
	
	public Stack(){
		stackPos = 0;
		stackArray = (T[]) new Object[size];
	}
	
	public boolean isEmpty(){
		if(stackArray[0] == null){
			return true;
		}else{
			return false;
		}
	}
	
	private void resize(){
		T[] copy = stackArray;
		size = size*2;
		
		stackArray = (T[]) new Object[size];
		
		for(int i = 0; i < size; i++){
			stackArray[i] = copy[i];
		}
	}
	
	public void push(T element){
		if(stackPos == size/2){
			resize();
		}
		
		stackArray[stackPos] = element;
		stackPos++;
	}
	
	public T pop(){
		stackPos--;
		T element = stackArray[stackPos];
		stackArray[stackPos] = null;		
		return element;
	}
	
	public void peek(){
		System.out.println(stackArray[stackPos-1]);
	}
	
	public int getSize(){
		return stackPos;
	}
}
