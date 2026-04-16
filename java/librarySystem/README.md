### Overview
This is an attempt at a design patterns assignment 

### Quick Note
I'd like to apologize in advance. I struggled a lot with understanding the reqruirements
for this excercise. I had to make a lot of assumptions and modifications.

I Also realized that splitting the book into a pure data model and having the borrowable
functionality be its own class. However,that felt like it was fundementally changing the architecture too much.

### Issues and Assumptions
This isn't an exhaustive list but I figured it's best to state some of these out loud:
- Given the amount of files I had to restructure the whole wokspace
- There was no ID provided, so I assumed titles are unique
- Given the amount of book types that are non-conflicting I figured this follows the decorator pattern explained for pizzas quite well, but there were also conflicting ones (EBook vs Physical)
- I decided I can't follow the logic of this toy example, because how does one borrow an E-Book?
- There was no where to save the number of days so I added it to the book. While it would be preferable to add a separate class for that, it seems from the start that books are intended as borrowables, so I decided to treat the book as a borrowable item.
- I assumed that the printing that was done was made to represent funcitionality of each book, as such each book would first say it's borrowed, but then specify if extra functionality was specified/declare its type
- There is an issue with how responsibility is defined. Do we want the responsibility of borrowal based on user info to fall on the books? this feels like unnecessary coupling
- I suppose my biggest issue here is the coupling of system responsibility (such as borrowing capability andextensibility) with the data model (Book)

### Requirements
- Q.1: added singlton Guard in LibraryService:
	- could have used a static method but it works out the same
- Q.2: added BookBuilder that can create different book types:
	- I think it technicaly violates open/close principle by having all the types in there
	- But the requirement said "separate different book type creation outside the current code"
- Q.3: added extensible interface and gave it to PremiumBook
	- Since borrowal immutable we create a new borrowal and modify the time
- Q.4: used an exception to make borrowing fet rejected for certain book-user combinations
	- to avoid liskov problems, either the book class needs to fundmentally change to accommodate the new additional restriction, and the library needs to manually check tomaintain compliance.
- Q.5: added approval chain of responsibility
- Q.6: No Idea what this requirement is.
	- Book Borrowal is handled over a few stages confirming if the book can be borrowed, and then the rest is handled by the book class
- Q.7: Honestly not certain what this has to do with design patterns.
	- It's likely the builder should have te JSON funcitonality
	- If the idea here is parsing should be separated, then I suppose it comming from an external library is enough as a form of separation of concern.
	- I suppose just in case we needed multiple parsers, creating a generic book parser inerface might've made more sense.
	- I avoided getting the JAVA library however cause that sounded both time consuming and adding extra complication withaout adding much value
- Q.8: I made it so a notifier is attached automatically if a user tries to borrow an unavailable book.
	- Used the observer pattern