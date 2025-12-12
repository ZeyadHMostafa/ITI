package menu;

import java.util.Scanner;

import clients.Client;
import library.entities.Library;
import library.exceptions.ItemAlreadyExistsException;
import library.exceptions.ItemNotFoundException;
import util.CRUDController;

class ClientMenuController implements CRUDController{
    private Library library;
    
    ClientMenuController(Library library){
        this.library = library;
    }
    
    @Override
    public void create(Scanner sc, int id) throws IllegalArgumentException {
        try {
            library.addClient(Client.constructFromCLI(sc, id) );    
        } catch (ItemAlreadyExistsException e) {
            throw new IllegalArgumentException("Client already exists");
        }

        System.out.println("Client added Successfuly!");
    }

    @Override
    public void review(int id) throws IllegalArgumentException{
        try {
            System.out.println(library.getClient(id).getClientDetails());    
        } catch (ItemNotFoundException e) {
            throw new IllegalArgumentException("Client doesn't exist");
        }
    }

    @Override
    public void update(Scanner sc, int id) throws IllegalArgumentException{
        try {
            library.updateClient(Client.constructFromCLI(sc, id));
        } catch (ItemNotFoundException e) {
            throw new IllegalArgumentException("Client doesn't exist");
        }
    }

    @Override
    public void delete(int id) throws IllegalArgumentException{
        try {
            library.deleteClient(id);
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
        library.getAllAvailableClientIds().stream().map((id)->{
            try { // necessry to handle error (even though it shouldn't happen)
                return library.getClient(id);    
            } catch (Exception e) {
                e.printStackTrace();
            }
            return null;
        }).filter((obj)->obj.getName().matches(regex)).map(Client::getClientDetails).forEach(System.out::println);
    }
}
