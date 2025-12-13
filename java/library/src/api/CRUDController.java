package api;

import java.util.Scanner;

import cli.entery.CLIConstructor;
import utl.exceptions.ItemAlreadyExistsException;
import utl.exceptions.ItemNotFoundException;
import utl.interfaces.Identifiable;

public class CRUDController<Entity extends Identifiable>{
    private CRUDContainer<Entity> container;
    private CLIConstructor<Entity> cliConstructor;
    private String entityName;

    public CRUDController(CRUDContainer<Entity> container, CLIConstructor<Entity> cliConstructor,String entityName){
        this.container = container;
        this.cliConstructor = cliConstructor;
        this.entityName = entityName;
    }
    
    public void create(Scanner sc, int id) throws IllegalArgumentException {
        try {
            container.add(cliConstructor.constructFromCLI(sc, id) );    
        } catch (ItemAlreadyExistsException e) {
            throw new IllegalArgumentException(entityName + " already exists");
        }

        System.out.println(entityName + " added Successfuly!");
    }

    public void review(int id) throws IllegalArgumentException{
        try {
            System.out.println(container.get(id).getDetails());    
        } catch (ItemNotFoundException e) {
            throw new IllegalArgumentException(entityName + " doesn't exist");
        }
    }

    public void update(Scanner sc, int id) throws IllegalArgumentException{
        try {
            container.update(cliConstructor.constructFromCLI(sc, id));
        } catch (ItemNotFoundException e) {
            throw new IllegalArgumentException(entityName + " doesn't exist");
        }
    }

    public void delete(int id) throws IllegalArgumentException{
        try {
            container.delete(id);
        } catch (ItemNotFoundException e) {
            throw new IllegalArgumentException(entityName + " doesn't exist");
        }
    }

    public void search(String regex) throws IllegalArgumentException{
        try {
            "".matches(regex);
        } catch (Exception e) {
            throw new IllegalArgumentException("not a valid regex");
        }
        container.getAllAvailableIds().stream().map((id)->{
            try { // necessry to handle error (even though it shouldn't happen)
                return container.get(id);    
            } catch (Exception e) {
                e.printStackTrace();
            }
            return null;
        }).filter((obj)->obj.getSearchableString().matches(regex)).map(Entity::getDetails).forEach(System.out::println);
    }
}
