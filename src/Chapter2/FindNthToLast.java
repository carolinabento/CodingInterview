package Chapter2;
/**
 * This class finds the nth to last element in a singly-linked list
 * 
 * @author carolinabento
 *
 */
public class FindNthToLast<T> {

	public FindNthToLast(){}

	public Node<T> find(LinkedList<T> list, int n){
		int listSize = list.size();

		if(listSize > 0){

			Node<T> current = list.getHead();
			int count = 1;

			while(current.next != null && (listSize - n) > count){
				current = current.next;
				count++;
			}
			return current;
		}else{
			throw new NullPointerException();
		}
	}
}
