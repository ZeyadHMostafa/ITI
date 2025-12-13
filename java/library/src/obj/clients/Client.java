package obj.clients;

import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;

import obj.libraryitems.LibraryItem;
import utl.interfaces.Identifiable;

public class Client implements Identifiable{
    private int id;
    public int getId(){return id;}

    private String name;
    public String getName(){return name;}
    public String getSearchableString() {return name;}
    
    private String mail;
    public String getMail(){return mail;}

    private TreeMap<Integer,LibraryItem> borrowedItems;
    public Set<Integer> getBorrowedItemIds(){return borrowedItems.keySet();}
    public void addBorrowedItem(LibraryItem item){borrowedItems.put(item.getId(),item);}
    public void removeBorrowedItem(LibraryItem item){borrowedItems.remove(item.getId());}

    //should do this for the others too, but mail is most important
    final static String mailRegex = "[a-zA-z0-9]+@[a-zA-z0-9]+(\\.[a-zA-z]+)*";

    public String getClientDetails(){
        StringBuffer details = new StringBuffer();
        details.append("-----------------------\n"
        +"Name: " + name + "\nMail: " + mail + "\nID: " + id + "\nBorrowed Items:\n");
        // add items using stream
        borrowedItems.values().stream().map(LibraryItem::getItemDetails).forEach((itemDetails)->{
            details.append(itemDetails);
            details.append("\n");
        });
        return details.toString();
    }
    public String getDetails(){return getClientDetails();} // Alias

    public Client(int id, String name, String mail){
        this.id = id;
        this.name= name;
        this.mail = mail;
        borrowedItems = new TreeMap<>();
    }

    public static Client constructFromCLI(Scanner sc, int id){
        String input;
        String name;
        String mail;

        System.out.println("Please enter Client Name");
        input = sc.nextLine();
        if (!input.matches("[a-zA-z ]+")) {
            throw new IllegalArgumentException("please only use alphabetical letters");
        }
        name = input;

        System.out.println("Please Client Mail");
        input = sc.nextLine();
        if (!input.matches(mailRegex)) {
            throw new IllegalArgumentException("Bad Input. Input format: user@website.domain");
        }
        mail = input;
        return new Client(id, name, mail);
    }
}
