package cli.menu;

import java.util.Scanner;

import cli.entery.CLIConstructors;
import dao.CRUDController;
import dao.Library;

import obj.clients.Client;
import obj.libraryitems.LibraryItem;

import dio.DataLoader;

public class MainMenu extends ChoiceMenu{
    Library library;
    CRUDMenu<Client> clientMenu;
    CRUDMenu<LibraryItem> itemMenu;
    RelMenu relMenu;

    public MainMenu(){
        super("Main Menu",new Scanner(System.in));

        library = new Library();
        
        clientMenu = new CRUDMenu<>(
            new CRUDController<>(
                library.getClientContainer(),
                CLIConstructors::constructClientFromCLI,
                library::canModifyClient,
                "Client"),
                "Client CRUD","client",sc);
        
        itemMenu = new CRUDMenu<>(
            new CRUDController<>(
                library.getItemContainer(),
                this::constructItemFromCLI,
                library::canModifyItem,
                "Item"),
                "Item CRUD","item",sc);
        
        relMenu = new RelMenu(library, sc);
        DataLoader.addFakeData(library);

        options.add(new Choice("manage library clients", clientMenu::runMenu));
        options.add(new Choice("manage library items", itemMenu::runMenu));
        options.add(new Choice("manage library relations", relMenu::runMenu));
        updateOptionString();
    }

    // Necessary to maintain
    private LibraryItem constructItemFromCLI(Scanner sc,int id){
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
                item = CLIConstructors.constructMagazineFromCLI(sc, id);
                break;
            case "2":
                item = CLIConstructors.constructBookFromCLI(sc, id);
                break;
        }
        
        return item;
    }
}
