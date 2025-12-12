package menu;

import java.util.Scanner;

import library.entities.Library;
import library.exceptions.ItemBorrowException;
import library.exceptions.ItemNotFoundException;
import library.exceptions.ItemStockException;

public class RelMenu{
    
    private Library library;

    RelMenu(Library library){
        this.library = library;
    }
    
    public void mainView(Scanner sc){
        final String menuString =
            "What would you like to do?\n"+
            "1) have client borrow book\n"+
            "2) have client return book\n"+
            "3) exit\n";

        while (true){
            System.out.print(menuString);
            String input;
            input = sc.nextLine();
            if (!input.matches("[1-3]")){
                System.out.println("invalid input");
                continue;
            }
            switch (input) {
                case "1":
                    borrowMenu(sc);               
                    break;
                case "2":
                    returnMenu(sc);
                    break;
                case "3":
                    return;
            }
        }
    }
    private int[] dataEntry(Scanner sc){
        String input;
        int clientId;
        int itemId;

        System.out.println("Please enter Client Id");
        input = sc.nextLine();
        if (!input.matches("[0-9]+")) {
            throw new IllegalArgumentException("please enter a valid ID");
        }
        clientId = Integer.parseInt(input);

        System.out.println("Please enter Item Id");
        input = sc.nextLine();
        if (!input.matches("[0-9]+")) {
            throw new IllegalArgumentException("please enter a valid ID");
        }
        itemId = Integer.parseInt(input);
        return new int[] {clientId,itemId};
    }

    private void borrowMenu(Scanner sc){
        int[] data = dataEntry(sc);
        try {
            library.borrowItem(data[0],data[1]);
        } catch (ItemNotFoundException e) {
            System.out.println("either the item or client doesn't exist");
        } catch (ItemStockException e) {
            System.out.println("no more of this item is available");
        } catch (ItemBorrowException e) {
            System.out.println("Client already has  item");
        }
    }
    private void returnMenu(Scanner sc){
        int[] data = dataEntry(sc);
        try {
            library.returnItem(data[0],data[1]);
        } catch (ItemNotFoundException e) {
            System.out.println("either the item or client doesn't exist");
        } catch (ItemStockException e) {
            System.out.println("Item is already at full capacity");
        } catch (ItemBorrowException e) {
            System.out.println("client doesn't posess item");
        }
    }
}