package menu;

import java.util.Scanner;

import library.entities.Book;
import library.entities.Library;
import library.entities.LibraryItem;
import library.entities.Magazine;
import library.exceptions.ItemAlreadyExistsException;
import library.exceptions.ItemNotFoundException;
import util.CRUDController;

class LibraryItemMenuController implements CRUDController{
    private Library library;
    
    LibraryItemMenuController(Library library){
        this.library = library;
    }

    private LibraryItem constructLibraryItem(Scanner sc,int id){
        System.out.println("Please pick a type");
        System.out.println("1) Magazine");
        System.out.println("2) Book");
        
        String input = sc.nextLine();
        if (!input.matches("[12]")) {
            throw new IllegalArgumentException("please pick a suitable option");
        }
        LibraryItem item = null;
        switch(input){
            case "1":
                item = Magazine.constructFromCLI(sc, id);
                break;
            case "2":
                item = Book.constructFromCLI(sc, id);
                break;
        }
        
        return item;
    }

    @Override
    public void create(Scanner sc, int id) throws IllegalArgumentException {
        try {
            library.addItem(constructLibraryItem(sc, id) );    
        } catch (ItemAlreadyExistsException e) {
            throw new IllegalArgumentException("Client already exists");
        }

        System.out.println("Client added Successfuly!");
    }

    @Override
    public void review(int id) throws IllegalArgumentException{
        try {
            System.out.println(library.getItem(id).getItemDetails());    
        } catch (ItemNotFoundException e) {
            throw new IllegalArgumentException("Client doesn't exist");
        }
    }

    @Override
    public void update(Scanner sc, int id) throws IllegalArgumentException{
        try {
            library.updateItem(constructLibraryItem(sc, id));
        } catch (ItemNotFoundException e) {
            throw new IllegalArgumentException("Client doesn't exist");
        }
    }

    @Override
    public void delete(int id) throws IllegalArgumentException{
        try {
            library.deleteItem(id);
        } catch (ItemNotFoundException e) {
            throw new IllegalArgumentException("Client doesn't exist");
        }
    }


    @Override
    public void search(String regex) throws IllegalArgumentException{
        try {
            "".matches(regex);
        } catch (Exception e) {
            throw new IllegalArgumentException("not a valid regex");
        }
        library.getAllAvailableItemIds().stream().map((id)->{
            try { // necessry to handle error (even though it shouldn't happen)
                return library.getItem(id);    
            } catch (Exception e) {
                e.printStackTrace();
            }
            return null;
        }).filter((obj)->obj.getTitle().matches(regex)).map(LibraryItem::getItemDetails).forEach(System.out::println);
    }
}