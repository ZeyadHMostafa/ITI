package menu;

import java.util.Scanner;
import library.entities.Library;
import util.FakeData;

public class MainMenu {
    Library library;
    final private String mainMenuString = 
    "What would you like to do?\n"+
    "1) manage library clients\n"+
    "2) manage library items\n"+
    "3) manage library relations\n"+
    "4) exit\n";

    CRUDMenu clientMenu;
    CRUDMenu itemMenu;
    RelMenu relMenu;
    
    {
        library = new Library();
        clientMenu = new CRUDMenu(
        new ClientMenuController(library),
        "Client CRUD","client");
        itemMenu = new CRUDMenu(
        new LibraryItemMenuController(library),
        "Item CRUD","item");
        relMenu = new RelMenu(library);
        FakeData.addFakeData(library);
    }

    public MainMenu(){
        Scanner sc = new Scanner(System.in);
        mainloop: while (true){
            String input;
            System.out.print(mainMenuString);
            input = sc.nextLine();
            if (!input.matches("[1-4]")){
                System.out.println("invalid input");
                continue;
            }
            switch (input) {
                case "1":
                    clientMenu.mainView(sc);                
                    break;
                case "2":
                    itemMenu.mainView(sc);
                    break;
                case "3":
                    relMenu.mainView(sc);
                    break;
                case "4":
                    break mainloop;
            }
        }
        sc.close();
    }
}
