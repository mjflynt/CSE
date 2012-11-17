; Assignment 13
; Name:  Michael Jeffrey Flynt
; email: mflynt@asu.edu

; Description: Create a Racket procedure remove_at that reads a list and the index of element to 
; be removed from the list, and returns the result list after removing the element at the index. 
; The first element in the list is considered to be located at the index 0. Also, if the index 
; entered by a user is out of the bound of the list, then display “not found”.

(define (remove_at thelist theindex)
  (if (or (> theindex (- (length thelist) 1)) (< theindex 0)) ; if the index is out of bounds
      "not found" ; then reply that it isn't found
       (if (= theindex 0) ; else if the index is the first char of the string
          (cdr thelist) ; then just return the remainder of the string
          ; otherwise return the first char of the string, and apply the function 
          ;recursively on the remainder of the string
          (append (list(car thelist)) (remove_at (cdr thelist) (- theindex 1))) 
          )
       )
  )

(display (remove_at (read) (read))) ; call the procedure with the two read parameters