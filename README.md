Video-Rental-Store
==================

Assignment from CSS343: Math, Algorithms, and Data structures

The purpose of this program is to use inheritance and the factory pattern to create a program for a video store. 

The store's inventory is populated from the txt files data4movies.txt, store commands from data4commands.txt, and 
customers from data4customers.txt.

There are three types of movies implemented: Comedy (F), Classic (C), and Drama (D). They all have different sorting
criteria, and are represented in data4movies.txt differently.

Dramas have a director, a title, and a year. Dramas are sorted by director, then title.

Example Drama: D Barry Levinson, Good Morning Vietnam, 1988

Comedies have a title, director, and year. Comedies are sorted by title, then year.

Example Comedy: F Todd Phillips, The Hangover, 2009

Classics have a director, title, lead performer, month, and year.

Example Classic:C Frank Capra, It's a Wonderful Life, Donna Reed 11 1946


Implementation Notes:
All movies inherit from the product class, and are required to have boolean comparison operators, a create() method,
and various display methods (Movies are displayed differently if viewed from the inventory, 
or from a customer's order history).

In my product factory, I has the first char of a line from data4movies.txt to create either a comedy, drama, or a classic.
I then use the pure virtual method from the product class, setdata(ifstream&), to create a movie. 

If the video
rental store also wanted to carry action movies, the only re-factoring required would be minimally modifiying 
productfactory.cpp so that hashing 'A' would create a new action movie. 

