package cli.menu;

import java.util.Scanner;

import dao.Library;

import utl.exceptions.ItemBorrowException;
import utl.exceptions.ItemNotFoundException;
import utl.exceptions.ItemStockException;

public class RelMenu extends ChoiceMenu{
    
    private Library library;

    RelMenu(Library library, Scanner sc){
        super("Relations Menu", sc);
        this.library = library;
        options.add(new Choice("borrow item", this::borrowMenu));
        options.add(new Choice("return item", this::returnMenu));
        updateOptionString();
    }

    private int[] dataEntry(){
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

    private void borrowMenu(){
        int[] data = dataEntry();
        try {
            library.borrowItem(data[0],data[1]);
            System.out.println("Item Borrowed Successfuly");
        } catch (ItemNotFoundException e) {
            System.out.println("either the item or client doesn't exist");
        } catch (ItemStockException e) {
            System.out.println("no more of this item is available");
        } catch (ItemBorrowException e) {
            System.out.println("Client already has  item");
        }
    }
    private void returnMenu(){
        int[] data = dataEntry();
        try {
            library.returnItem(data[0],data[1]);
            System.out.println("Item Returned Successfuly");
        } catch (ItemNotFoundException e) {
            System.out.println("either the item or client doesn't exist");
        } catch (ItemStockException e) {
            System.out.println("Item is already at full capacity");
        } catch (ItemBorrowException e) {
            System.out.println("client doesn't posess item");
        }
    }
}