class Shape {
	static #class_count= 0;
	#dim_major;

	constructor(major_dimension) {
		if (isNaN(major_dimension)||Number(major_dimension)<=0){
			throw new Error("Only positive numbers allowed");
		}
		this.#dim_major = major_dimension;
		Shape.#class_count+=1;
	}

	calculate_area(){
		return this.#dim_major*this.#dim_major;
	}

	calculate_perimeter(){
		return 4*this.#dim_major;
	}

	toString(){
		return `area = ${this.calculate_area()} perimeter = ${this.calculate_perimeter()}`;
	}

	get dim_major(){
		return this.#dim_major;
	}

	static get class_count(){
		return Shape.#class_count;
	}
}

class Square extends Shape{
	static #class_count= 0;
	constructor(major_dimension) {
		if (Square.#class_count>0){
			throw new Error("Only one may be created!");
		}
		Square.#class_count+=1;
		super(major_dimension);
	}
}

class Rectangle extends Shape{
	static #class_count= 0;
	#dim_minor
	constructor(major_dimension,minor_dimension) {
		if (isNaN(minor_dimension)||Number(minor_dimension)<=0){
			throw new Error("Only positive numbers allowed");
		}
		if (Rectangle.#class_count>0){
			throw new Error("Only one may be created!");
		}
		Rectangle.#class_count+=1;
		super(major_dimension);
		this.#dim_minor=minor_dimension;
	}

	get dim_minor(){
		return this.#dim_minor;
	}

	calculate_area(){
		return super.dim_major*this.#dim_minor;
	}

	calculate_perimeter(){
		return 2*(this.dim_major+this.#dim_minor);
	}
}

class Circle extends Shape{
	constructor(major_dimension,minor_dimension) {
		super(major_dimension);
	}

	calculate_area(){
		return Math.pi*super.dim_major*super.dim_major;
	}

	calculate_perimeter(){
		return 2*Math.PI*this.dim_major;
	}
}

let square = new Square(10);
// let square2 = new Square(10);
let circle = new Circle(10);
let rectangle = new Rectangle(10,5);
console.log(square.toString());
console.log(circle.toString());
console.log(rectangle.toString());
console.log(`class_count: ${Shape.class_count}`);