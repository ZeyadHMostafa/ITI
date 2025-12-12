package library.entities;

import library.exceptions.ItemStockException;

public abstract class LibraryItem {
    private int stock;
    public int getStock(){return stock;}

    private int available;
    public int getAvailable(){return stock;}
    public void takeFromStock()throws ItemStockException{
        if (available == 0) throw new ItemStockException();
        available-=1;
    }
    public void returnToStock()throws ItemStockException{
        if (available == stock) throw new ItemStockException();
        available+=1;
    }

    private int id;
    public int getId(){return id;};
    
    private String title;
    public String getTitle(){return title;};

    protected String type;
    public String getType(){return type;};

    public String getItemDetails(){
        return "Title: " + title + " | ID: " + id + " | Type: " + type + " | Stock: " + available+"/"+stock;
    }
    
    LibraryItem(int id, String title, int stock){
        this.title = title;
        this.id = id;
        this.stock = stock;
        available = stock;
    }

    LibraryItem(){
        this(0,"",1);
    }

}
