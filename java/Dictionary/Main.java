import java.util.Scanner;
class Main {
	public static void main(String[] args){
		Dictionary dict = new Dictionary();
		dict.add("apple");
		dict.add("BoilerPlate");
		dict.add("age");
		System.out.print(dict.printDictionary());
		Scanner sc = new Scanner(System.in);
		while (true){
			System.out.println("Please enter a new word:");
			dict.add(sc.nextLine());
			System.out.println("Continue?(n: for no)");
			if (sc.nextLine().equals("n")){
				break;
			}
		}
		System.out.print(dict.printDictionary());
	}
}