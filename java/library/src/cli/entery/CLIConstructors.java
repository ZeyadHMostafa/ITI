package cli.entery;

import java.util.Scanner;

import obj.clients.Client;
import obj.libraryitems.Book;
import obj.libraryitems.LibraryItem;
import obj.libraryitems.Magazine;

public class CLIConstructors{
    //should do this for the others too, but mail is most important
    final static String mailRegex = "[a-zA-z0-9]+@[a-zA-z0-9]+(\\.[a-zA-z]+)*";
    public static Client constructClientFromCLI(Scanner sc, int id){
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
    
    public static LibraryItem constructBookFromCLI(Scanner sc, int id){
        String input;
        String title;
        int stock;

        System.out.println("Please enter item title");
        input = sc.nextLine();
        if (!input.matches("^[a-zA-z0-9 ]+$")) {
            throw new IllegalArgumentException("please only use alphanumeric characters");
        }
        title = input;

        System.out.println("Please Copy Count");
        input = sc.nextLine();
        if (!input.matches("^[0-9]+$")) {
            throw new IllegalArgumentException("please only use alphanumeric characters");
        }
        stock = Integer.parseInt(input);

        return new Book(id,title,stock);
    }


    public static LibraryItem constructMagazineFromCLI(Scanner sc, int id){
        String input;
        String title;
        int stock;

        System.out.println("Please enter item title");
        input = sc.nextLine();
        if (!input.matches("[a-zA-z0-9 ]+")) {
            throw new IllegalArgumentException("please only use alphanumeric characters");
        }
        title = input;

        System.out.println("Please Copy Count");
        input = sc.nextLine();
        if (!input.matches("^[0-9]+$")) {
            throw new IllegalArgumentException("please only use alphanumeric characters");
        }
        stock = Integer.parseInt(input);

        return new Magazine(id,title,stock);
    }
}