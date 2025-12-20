package dao;

import java.util.Scanner;
import java.util.function.Predicate;

import cli.entery.CLIConstructor;
import utl.exceptions.ItemAlreadyExistsException;
import utl.exceptions.ItemNotFoundException;
import utl.interfaces.Identifiable;

public class CRUDController<Entity extends Identifiable>{
    private CRUDContainer<Entity> container;
    private CLIConstructor<Entity> cliConstructor;
    private Predicate<Entity> canModify;
    private String entityName;

    public CRUDController(
        CRUDContainer<Entity> container, CLIConstructor<Entity> cliConstructor,
        Predicate<Entity> canModify,  String entityName){
        this.container = container;
        this.cliConstructor = cliConstructor;
        this.entityName = entityName;
        this.canModify = canModify;
    }
    
    public void create(Scanner sc, int id) throws IllegalArgumentException {
        try {
            container.testAdd(id);
            container.add(cliConstructor.constructFromCLI(sc, id) );    
        } catch (ItemAlreadyExistsException e) {
            throw new IllegalArgumentException(entityName + " already exists");
        }
    }

    public String review(int id) throws IllegalArgumentException{
        try {
            return container.display(id);    
        } catch (ItemNotFoundException e) {
            throw new IllegalArgumentException(entityName + " doesn't exist");
        }
    }

    public void update(Scanner sc, int id) throws IllegalArgumentException{
        try {
            Entity entity = container.get(id);
            if (!canModify.test(entity)){
                throw new IllegalArgumentException(entityName + " cannot be modified due to connections");
            }
            container.update(cliConstructor.constructFromCLI(sc, id));
        } catch (ItemNotFoundException e) {
            throw new IllegalArgumentException(entityName + " doesn't exist");
        }
    }

    public void delete(int id) throws IllegalArgumentException{
        try {
            Entity entity = container.get(id);
            if (!canModify.test(entity)){
                throw new IllegalArgumentException(entityName + " cannot be modified due to connections");
            }
            container.delete(id);
        } catch (ItemNotFoundException e) {
            throw new IllegalArgumentException(entityName + " doesn't exist");
        }
    }

    public String search(String regex) throws IllegalArgumentException{
        try {
            "".matches(regex);
        } catch (Exception e) {
            throw new IllegalArgumentException("not a valid regex");
        }
        StringBuffer report = new StringBuffer();
        container.getAllAvailableIds().stream().map((id)->{
            try { // necessary to handle error (even though it shouldn't happen)
                return container.get(id);    
            } catch (Exception e) {
                e.printStackTrace();
            }
            return null;
        }).filter((obj)->obj
            .getSearchableString()
            .matches(regex))
            .map(Entity::getDetails)
            .forEach((s)->{report.append(s); report.append("\n");});
        return report.toString();
    }
}
