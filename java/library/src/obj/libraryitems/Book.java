package obj.libraryitems;

public class Book extends LibraryItem {

    // common constructor block
    {type = "Book";}

    public Book(int id, String title, int stock){
        super(id,title,stock);
    }

}
