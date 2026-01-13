class Book {
	#title;#numOfChapters;#author;#numOfPages;#Publisher;#numOfCopies
	constructor(title,numOfChapters,author,numOfPages,Publisher,numOfCopies) {
		this.#title = title;
		this.#numOfChapters = numOfChapters;
		this.#author = author;
		this.#numOfPages = numOfPages;
		this.#Publisher = Publisher;
		this.#numOfCopies = numOfCopies;
	}

	get title(){
		return this.#title;
	}
	get author(){
		return this.#title;
	}
	// ...
	// TODO: add other getters
	// not important to prove understanding
}

class Box {
	#length;#width;#height;
	#content;
	#material;
	
	// TODO, add validation
	// not important to prove understanding
	constructor(l,w,h, material) {
		this.#length=l;
		this.#width=w;
		this.#height=h;
		this.#content=[];
		this.#material = material;
	}

	get volume(){
		return this.#length*this.#width*this.#height
	}

	get numOfBooks(){
		return this.#content.length;
	}

	addBook(book){
		if (book.constructor != Book){
			throw new Error("can only add books");
		}
		this.#content.push(book);
	}

	removeBookByTitle(title){
		let index = this.#content.findIndex((book)=>book.title==title);
		let value = this.#content[index];
		this.#content.splice(index);
		return value;
	}

	valueOf(){
		return this.numOfBooks;
	}

	toString(){
		return `L:${this.#length},W:${this.#width},H:${this.#height}, count:${this.numOfBooks}`;
	}
}

let bookA = new Book("abraham my dude", 5, "abraham")
let bookB = new Book("bernice my girl", 5, "bernice")
let bookC = new Book("cameron my baby", 5, "cameron")

let box1 = new Box(1,2,3,"wood");
let box2 = new Box(3,4,5,"metal");

box1.addBook(bookA);
box1.addBook(bookB);
box2.addBook(bookC);

console.log(`box 1: ${box1.toString()}`);
console.log(`box 2: ${box2.toString()}`);
console.log(`num ofbooks: ${box1.numOfBooks}`);
console.log(`volume: ${box2.volume}`);
console.log(`sum: ${box1+box2}`);
console.log(`retrieve book: `)
console.log(box1.removeBookByTitle("bernice my girl"));
console.log(`box 1: ${box1.toString()}`);