package cli.menu;

import java.util.Scanner;

import dao.CRUDController;
import utl.interfaces.Identifiable;

public class CRUDMenu<Entity extends Identifiable> extends ChoiceMenu{
    private String entityName;
    private CRUDController<Entity> controller;

    CRUDMenu(CRUDController<Entity> controller, String title, String entityName, Scanner sc){
        super(title,sc);
        this.entityName = entityName;
        this.controller = controller;
        options.add(new Choice("Create "+entityName, this::create));
        options.add(new Choice("Review "+entityName, this::review));
        options.add(new Choice("Update "+entityName, this::update));
        options.add(new Choice("Delete "+entityName, this::delete));
        options.add(new Choice("Search "+entityName, this::search));
        updateOptionString();
    }
    int readId(){
        String input;
        System.out.println("Please enter "+entityName+" ID:");
        input = sc.nextLine();
        if (!input.matches("^[0-9]+$")){
            System.out.println("<!> please enter a proper ID");
            return -1;
        } else {
            return Integer.parseInt(input);
        }
    }

    void create() throws IllegalArgumentException{
        int id = readId();
        if (id!=-1){controller.create(sc,id);}
        System.out.println(entityName + " added Successfuly!");
    }

    void review() throws IllegalArgumentException{
        int id = readId();
        if (id!=-1){System.out.println(controller.review(id));}
    }

    void update() throws IllegalArgumentException{
        int id = readId();
        if (id!=-1){controller.update(sc,id);}
        System.out.println(entityName + " updated Successfuly!");
    }

    void delete() throws IllegalArgumentException{
        int id = readId();
        if (id!=-1){controller.delete(id);}
        System.out.println(entityName + " deleted Successfuly!");
    }

    void search() throws IllegalArgumentException{
        String input;
        System.out.println("Please enter Search regex:");
        input = sc.nextLine();
        System.out.println(controller.search(input));
    }
}
