% Assignment 18
% Name:  Michael Jeffrey Flynt
% email: mflynt@asu.edu
% Description:


% parent_of(P_Calvin, calvin).
% parent_of(P_Alice, alice), parent_of(P_Floyd, floyd).
% parent_of(Parent, _).

female(jane).
female(mary).
female(clare).
female(vivian).
female(alice).
female(sarah).
female(rachel).
 
male(floyd).
male(tom).
male(richard).
male(calvin).
male(john).
male(andrew).
 
parent_of(tom, richard).
parent_of(tom, jane).
parent_of(mary, calvin).
parent_of(mary, alice).
parent_of(clare, john).
parent_of(clare, tom).
parent_of(john, alice).
parent_of(john, calvin).
parent_of(richard, vivian).
parent_of(richard, floyd).
parent_of(jane, sarah).
parent_of(jane, rachel).
parent_of(jane, andrew).

grandparent_of(X, Y) :- parent_of(X, Z) , parent_of(Z, Y).
grandfather_of(X, Y) :- grandparent_of(X, Y), male(X).
sibling_of(X, Y) :- parent_of(P, X), parent_of(P, Y), X \= Y,!.
sister_of(X, Y) :- sibling_of(X, Y), female(X).
aunt_of(X, Y) :- sister_of(X, Z), parent_of(Z, Y).