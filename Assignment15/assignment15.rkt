; Assignment 15
; Name:  Michael Jeffrey Flynt
; email: mflynt@asu.edu

; Description: Create a Racket procedure called “char_toupper” that takes a character and 
; converts it to its upper case. If the entered character is already of upper case, then it 
; should display itself.


(define char_toupper (lambda (achar) ; function to take a char and upcase it
                       (if (not (or (char<? achar #\a) (char>? achar #\z))) ; De Morgan's Law test for if the char is a lowercase char
                           (integer->char (- (char->integer achar) (- (char->integer #\a) (char->integer #\A)))) ; and if so transform into uppercase
                           achar ; otherwise just return the char
                           )
                       )
  )
                           

(display (char_toupper (read))) ; call the procedure with a read char and display results