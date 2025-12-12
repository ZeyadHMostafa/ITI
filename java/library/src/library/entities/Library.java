package library.entities;

import java.util.Set;
import java.util.TreeMap;

import clients.Client;
import library.exceptions.*;

public class Library {
    private TreeMap<Integer,LibraryItem> items = new TreeMap<>();
    private TreeMap<Integer,Client> clients = new TreeMap<>();

    public <T extends LibraryItem> void addItem(T item) throws ItemAlreadyExistsException{
        if (items.containsKey(item.getId())){
        throw new ItemAlreadyExistsException();
        }

        items.put(item.getId(), item);
    }

    public <T extends Client> void addClient(T client) throws ItemAlreadyExistsException{
        
        if (clients.containsKey(client.getId())){
        throw new ItemAlreadyExistsException();
        }

        clients.put(client.getId(), client);
    }

    public <T extends Client> void updateClient(T client) throws ItemNotFoundException{
        if (!clients.containsKey(client.getId())){
        throw new ItemNotFoundException();
        }

        clients.put(client.getId(), client);
    }

    public <T extends LibraryItem> void updateItem(T item) throws ItemNotFoundException{
        if (!items.containsKey(item.getId())){
        throw new ItemNotFoundException();
        }

        items.put(item.getId(), item);
    }

    public LibraryItem getItem(int id) throws ItemNotFoundException{
        if (!items.containsKey(id)){
        throw new ItemNotFoundException();
        }

        return items.get(id);
    }

    public Client getClient(int id) throws ItemNotFoundException{
        if (!clients.containsKey(id)){
        throw new ItemNotFoundException();
        }

        return clients.get(id);
    }

    public LibraryItem deleteItem(int id) throws ItemNotFoundException{
        if (!items.containsKey(id)){
        throw new ItemNotFoundException();
        }

        return items.remove(id);
    }

    public Client deleteClient(int id) throws ItemNotFoundException{
        if (!clients.containsKey(id)){
        throw new ItemNotFoundException();
        }

        return clients.remove(id);
    }

    public Set<Integer> getAllAvailableItemIds(){
        return items.keySet();
    }

    public Set<Integer> getAllAvailableClientIds(){
        return clients.keySet();
    }

    public void displayItem(int id) throws ItemNotFoundException{
        if (!items.containsKey(id)){
        throw new ItemNotFoundException();
        }

        System.out.println(items.get(id));
    }

    public void borrowItem(int clientId, int itemId) throws ItemNotFoundException, ItemStockException, ItemBorrowException{
        LibraryItem item = getItem(itemId);
        Client client = getClient(clientId);
        if (client.getBorrowedItemIds().contains(itemId)){
            throw new ItemBorrowException(); // only capable of borrowing one of each item
        }
        client.addBorrowedItem(item);
        item.takeFromStock();
    }

    public void returnItem(int clientId, int itemId) throws ItemNotFoundException, ItemStockException, ItemBorrowException{
        LibraryItem item = getItem(itemId);
        Client client = getClient(clientId);
        if (!client.getBorrowedItemIds().contains(itemId)){
            throw new ItemBorrowException(); // Item not borrowed
        }
        item.returnToStock();
        client.removeBorrowedItem(item);
    }
}
