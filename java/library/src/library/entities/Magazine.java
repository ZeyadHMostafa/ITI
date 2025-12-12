package library.entities;

import java.util.Scanner;

public class Magazine extends LibraryItem {

    // common constructor block
    {type = "Magazine";}

    public Magazine(int id, String title, int stock){
        super(id,title,stock);
    }

    public static LibraryItem constructFromCLI(Scanner sc, int id){
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
