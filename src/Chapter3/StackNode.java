package Chapter3;

public class StackNode<T> {
	T value;
	StackNode<T> next;
	StackNode<T> prev;
	T min;
	
	public StackNode(T value){
		this.value = value;
		this.next = null;
		this.prev = null;
	}
}
