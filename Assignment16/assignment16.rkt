; Assignment 16
; Name:  Michael Jeffrey Flynt
; email: mflynt@asu.edu

; Description: Create a Racket procedure called “string_toupper” that takes a string consisting 
; of alphabet letters, converts each character to upper case, and displays it. You should make 
; use of the “char_toupper” procedure that was created in the previous assignment.

(define char_toupper (lambda (achar) ; function to take a char and upcase it
                       (if (not (or (char<? achar #\a) (char>? achar #\z))) ; De Morgan's Law test for if the char is a lowercase char
                           (integer->char (- (char->integer achar) (- (char->integer #\a) (char->integer #\A)))) ; and if so transform into uppercase
                           achar ; otherwise just return the char
                           )
                       )
  )

(define string_toupper (lambda (astring) ; function to uppercase all lowercase alpha chars in string
                         (if (> (string-length astring) 0) ; test for terminating condition
                              ; if not terminating then upcase 1st char and reapply on remainder of string.
                             (string-append (string (char_toupper (string-ref astring 0))) (string_toupper (substring astring 1 (string-length astring)))) 
                             "" ; otherwise return a terminating empty string
                             ) 
                         )
  )

(display (string_toupper (read-line))) ; display the result of uppercasing the read in string

