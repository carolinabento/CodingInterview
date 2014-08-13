package Chapter2;

public class SumTwoNumbersLinkedList {

	private int length1;
	private int length2;

	private LinkedList<Integer> fList;
	private LinkedList<Integer> sList;

	public SumTwoNumbersLinkedList(LinkedList<Integer> list1, LinkedList<Integer> list2){
		this.fList = list1;
		this.sList = list2;

		this.length1 = list1.size();
		this.length2 = list2.size();
	}

	public LinkedList<Integer> sumNumbersReverseOrder(){
		LinkedList<Integer> result = new LinkedList<Integer>();			

		if(this.fList.isEmpty() && this.sList.isEmpty()){
			throw new NullPointerException();
		}else{
			if(this.fList.isEmpty() && !this.sList.isEmpty()){
				return this.sList;
			}else{
				if(!this.fList.isEmpty() && this.sList.isEmpty()){
					return this.fList;
				}else{

					//1 -> null + 1-> null
					Node<Integer> nodeL1 = this.fList.getHead();
					Node<Integer> nodeL2 = this.sList.getHead();
					int carry = 0;

					for(int countL1 = 0, countL2 = 0; countL1 < this.length1 && countL2 < this.length2; countL1++, countL2++){

						int val1 = (int) Math.pow(10, countL1) * (nodeL1.value) ;	
						int val2 = (int) Math.pow(10, countL2) * (nodeL2.value);
						int resVal = 0;
						
						if(countL1 == 0){
							resVal = (int)((val1 + val2) % Math.pow(10, countL1 + 1));
							carry = (int) ( Math.floor((val1 + val2) / Math.pow(10, countL1 + 1)));					
						}else{				
							resVal = (int)((val1/ Math.pow(10,countL1)) + (val2/ Math.pow(10,countL1)) + carry);

							if(resVal == Math.pow(10,1)){									
								int newResVal = (int) (resVal%Math.pow(10,1));

								carry = (int) (resVal/Math.pow(10,1));
								resVal = newResVal;									
							}else{
								if(resVal > Math.pow(10,1)){									
									int newResVal = (int) Math.floor(resVal/Math.pow(10,countL1));

									carry = (int) Math.floor(resVal/Math.pow(10,1));
									resVal = newResVal;									
								}else{
									carry = (int) ( Math.floor((val1/ Math.pow(10, countL1 +1)) + (val2/ Math.pow(10, countL1 + 1))) );						
								}
							}
						}

						result.append(resVal);																		

						nodeL1 = nodeL1.next;
						nodeL2 = nodeL2.next;
					}
					if(carry != 0){
						result.append(carry);
					}

				}
			}			
		}
		return result;
	}
}
