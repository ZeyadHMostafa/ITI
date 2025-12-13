package api;

import obj.clients.Client;
import obj.libraryitems.LibraryItem;
import utl.exceptions.*;

public class Library {
    private CRUDContainer<LibraryItem> itemContainer = new CRUDContainer<>();
    public CRUDContainer<LibraryItem> getItemContainer(){return itemContainer;}
    private CRUDContainer<Client> clientContainer = new CRUDContainer<>();
    public CRUDContainer<Client> getClientContainer(){return clientContainer;}


    public void borrowItem(int clientId, int itemId) throws ItemNotFoundException, ItemStockException, ItemBorrowException{
        LibraryItem item = itemContainer.get(itemId);
        Client client = clientContainer.get(clientId);
        if (client.getBorrowedItemIds().contains(itemId)){
            throw new ItemBorrowException(); // only capable of borrowing one of each item
        }
        client.addBorrowedItem(item);
        item.takeFromStock();
    }

    public void returnItem(int clientId, int itemId) throws ItemNotFoundException, ItemStockException, ItemBorrowException{
        LibraryItem item = itemContainer.get(itemId);
        Client client = clientContainer.get(clientId);
        if (!client.getBorrowedItemIds().contains(itemId)){
            throw new ItemBorrowException(); // Item not borrowed
        }
        item.returnToStock();
        client.removeBorrowedItem(item);
    }
}
