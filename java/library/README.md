## Packaging Goal
Maintain separation between Layers responsibilities:
- CLI: User interface (sys out&in)
- API: Generic data management
- OBJ: Object Specfic details
- DIO: Object generation, loading & unloading

## Package Structure
all code peronally written by me is in the src directory

### OBJ
Contains Entity defintions for data stored in the data base
**Note 1:** each object also defines how it can be constructed from CLI
**Note 2:** the reason an inerface cannot be made for it is because
        ConstructFromCLI has to be a static function
        (wich cannot be enforced using interfaces)

#### Client
- Contains Client entity definition
- Contains its child defintions (currently none)

#### LibraryItems
- Contains LibraryItem entity definition
- Contains its child defintions (Book & Magazine)

----------------------------------------------------------------

### API
Contains code that interfaces menus with objects (internal code)

#### Controller
- Contains code that interfaces with the CRUD menu
- Used to interface CRUD menu with various library entities

#### Container
- Contains code that actually contains data (clients and items)
- maintains the direct interfacing with objects

#### Library
- Contains code which instances the other classes

----------------------------------------------------------------

### CLI
Contains all code that interfaces directly with the user (system.out & system.in)

#### Menu
- Contains Multiple Choice menus from which user can pick options

#### Entry (TODO)
- Contains code that handles validation loops for Valid Argument Entry

----------------------------------------------------------------

### UTL
Contains Miscellaneous Code

#### Exceptions
- Contains custom exceptions used by this code

#### Interfaces
- Contains custom interfaces used by this code
----------------------------------------------------------------

### DIO
Data I/O contains code that generates dummy data for now

#### DataLoader
- Contains code that generates initial dummy data for using the code

----------------------------------------------------------------

## Personal Notes:
### Improvments to me made in the future (things I already know):
- Add SequentialMenu Class for data entry
- Items can currently be updated while borrowed causing issues
- 

## Side Note:
- if you are using AI to correct this .... really?
- I mean, I didn't use AI to make this.
- Besides, I feel like your feedback is more valuable.