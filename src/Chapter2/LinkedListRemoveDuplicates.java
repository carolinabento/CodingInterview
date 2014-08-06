package Chapter2;

/**
 * 
 * @author carolinabento
 *
 * @param <T>
 */
public class LinkedListRemoveDuplicates<T>{

	public LinkedListRemoveDuplicates(){}

	public boolean contains(T[] buff, T value, int index){
		boolean result = false;
		for(int i = 0; i <= index; i++){
			if(buff[i] == value){
				return true;
			}
		}
		return result;
	}
	
	public LinkedList<T> remove(LinkedList<T> list){
		T[] buffer = (T[]) new Object[list.size()];
		
		if(list.isEmpty()){
			throw new NullPointerException();
		}else{
			Node<T> current = list.getHead();
			Node<T> prev = null;
			int index = 0;
			while(current.next != null){
				if(!contains(buffer,(T) current.value, index)){
					buffer[index++] = (T) current.value;
					prev = current;
					current = current.next;
				}else{
					Node<T> nextNode = current.next;
					prev.next = nextNode;
					current.next = null;
					current = nextNode;
				}
			}
		}
			
		return list;
	}
}
